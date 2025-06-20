#include <ostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using std::cout;
using std::vector;

int main(int argc, char** argv){   
  if (argc != 4){
    cout << "[error] syntax: ./cube2frame <Rows> <Columns> <Image_Path>\n";
    return -1;
  }

  // Type of the cube's matrix
  const unsigned short kCubeType = 3;

  const vector<Vec3b> kRubiksColors= {
    {255, 0, 0}, // Blue
    {0, 0, 255}, // Red
    {0, 165, 255}, // Orange
    {0, 255, 0}, // Green
    {0, 255, 255}, // Yellow
    {255, 255, 255}, // White
  };

  Mat rubiksColormap(256, 1, CV_8UC3);
  const int kColorDivisions = 256 / kRubiksColors.size();

  for(int i = 0; i < 256; ++i){
    int color_index = i / kColorDivisions;
    if(color_index >= kRubiksColors.size()){
      color_index = kRubiksColors.size() - 1;
    }
    rubiksColormap.at<Vec3b>(i, 0) = kRubiksColors[color_index];
  }

  int rows = atoi(argv[1]), columns = atoi(argv[2]);
  Mat input_image, output_image;

  input_image = imread(argv[3], IMREAD_COLOR_BGR);
  if(input_image.empty()) return -1;

  resize(input_image, input_image, Size(rows * kCubeType, columns * kCubeType), 0, 0, INTER_AREA);
  applyColorMap(input_image, input_image, rubiksColormap);

  resize(input_image, output_image, Size(), 100 / rows, 100 / columns, INTER_AREA);
  namedWindow("Cube2Frame", WINDOW_AUTOSIZE);
  imshow("Cube2Frame", output_image);
  waitKey(0);

  return 0;
}
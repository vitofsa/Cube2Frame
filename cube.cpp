#include <ostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

int main(int argc, char** argv) {   
  if (argc != 4){
    std::cout << "[error] syntax: ./cube2frame <Rows> <Columns> <Image_Path>\n";
    return -1;
}

  // Type of the cube's matrix
  const unsigned short kCubeType = 3;

  // Create the rubik's cube colors matrix from 0 - 256
  const std::vector<Vec3b> kRubiksColors = {
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
  
  const int kRows = atoi(argv[2]), kColumns = atoi(argv[1]);
  // Calculates the image size (width, height) based on the rows and columns
  std::vector<int> image_size = {
    kRows * kCubeType,
    kColumns * kCubeType
  };
  
  Mat input_image, output_image;

  input_image = imread(argv[3], IMREAD_COLOR_BGR);
  if(input_image.empty()) return -1;
  
  resize(input_image, input_image, Size(image_size[0] + kRows + 1, image_size[1] + kColumns + 1), 0, 0, INTER_AREA);
  applyColorMap(input_image, input_image, rubiksColormap);
  
  for(int i = 0; i < (input_image.size[0] / kCubeType) + 1; ++i)  {
    int line_x = (kCubeType + 1) * i;
    line(input_image, Point(line_x, 0), Point(line_x, input_image.size[1] + kColumns), Scalar(0, 0, 0), 1);
  }

  for(int k = 0; k < (input_image.size[1] / kCubeType) + 1; ++k)  {
    int line_y = (kCubeType + 1) * k;
    line(input_image, Point(0, line_y), Point(input_image.size[0] + kRows, line_y), Scalar(0, 0, 0), 1);
  }

  resize(input_image, output_image, Size(), 100 / kRows, 100 / kColumns, INTER_AREA);
  namedWindow("Cube2Frame", WINDOW_AUTOSIZE);
  imshow("Cube2Frame", output_image);
  waitKey(0);

  return 0;
}
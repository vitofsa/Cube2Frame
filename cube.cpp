#include <ostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <vector>
#include "./include/color_map.hpp"

using namespace cv;

int main(int argc, char** argv) {   
  if (argc != 4){
    std::cout << "[error] syntax: ./cube2frame <Rows> <Columns> <Image_Path>\n";
    return -1;
}

  // Type of the cube's matrix
  const unsigned short kCubeType = 3;
  
  const int kRows = atoi(argv[2]), kColumns = atoi(argv[1]);
  // Calculates the image size (width, height) based on the rows and columns
  std::vector<int> image_size = {
    kRows * kCubeType,
    kColumns * kCubeType
  };
  
  Mat input_image = imread(argv[3], IMREAD_COLOR_BGR);
  if(input_image.empty()) return -1;
  
  resize(input_image, input_image, Size(image_size[0] + kRows + 1, image_size[1] + kColumns + 1), 0, 0, INTER_AREA);
  applyColorMap(input_image, input_image, rubiksColorMap());
  
  const int vertical_lines = (input_image.size[0] / kCubeType) + 1;
  const int horizontal_lines = (input_image.size[1] / kCubeType) + 1;
  const int lines_spacing = kCubeType + 1;

  for(int i = 0; i < vertical_lines; ++i)  {
    int x = i * lines_spacing;
    line(input_image, Point(x, 0), Point(x, input_image.size[1] + kColumns), Scalar(0, 0, 0), 1);
  }

  for(int k = 0; k < horizontal_lines; ++k)  {
    int y = k * lines_spacing;
    line(input_image, Point(0, y), Point(input_image.size[0] + kRows, y), Scalar(0, 0, 0), 1);
  }

  resize(input_image, input_image, Size(), 100 / kRows, 100 / kColumns, INTER_AREA);
  namedWindow("Cube2Frame", WINDOW_AUTOSIZE);
  imshow("Cube2Frame", input_image);
  waitKey(0);

  return 0;
}
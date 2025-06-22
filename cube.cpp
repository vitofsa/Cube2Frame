#include <ostream>
#include <cstdlib>
#include <vector>
#include <string.h>

#include <opencv2/opencv.hpp>

#include "include/cube_mosaic.hpp"

using namespace cv;

const unsigned kCubeType = 3; // The size of single a cube, which in this case is 3x3x3

// Arguments syntax: <Rows> <Columns> <Image_Path>
bool CheckArguments(int* argc);

std::string GetParentDirectory(char* dir);

int main(int argc, char** argv) {   
  if  (CheckArguments(&argc)) {
    return -1;
  }
  
  // Creates a CubeMosaic object with the following arguments:
  // @ Image matrix returned by OpenCV
  // @ Size(rows * cubeType, columns * cubeType)
  // @ {rows, columns}
 CubeMosaic Mosaic {
    imread(argv[3], IMREAD_COLOR_BGR),
    Size(atoi(argv[2]) * kCubeType, atoi(argv[1]) * kCubeType),
    {atoi(argv[2]), atoi(argv[1])},
  };
  
  if  (Mosaic.GetImage().empty())  {
    return -1;
  }

  Mosaic.ResizePixelsToCubes();
  
  // resize(Mosaic.image, Mosaic.image, Size(image_size[0] + kRows + 1, image_size[1] + kColumns + 1), 0, 0, INTER_AREA);
  // applyColorMap(input_image, input_image, RubiksColorMap());
  
  
  //resize(input_image, input_image, Size(), 100 / kRows, 100 / kColumns, INTER_AREA);
  //namedWindow("Cube2Frame", WINDOW_AUTOSIZE);
  //imshow("Cube2Frame", Mosaic.GetImage());
  
  imwrite(GetParentDirectory(argv[3]) + "cube_output.png", Mosaic.GetImage());
  waitKey(0);

  return 0;
}

/*/////////////////
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
*///////////////////

inline bool CheckArguments(int* argc) {
  if (*argc != 4){
    std::cout << "[error] syntax: ./cube2frame <Rows> <Columns> <Image_Path>\n";
    return 1;
  }
  return 0;
}

inline std::string GetParentDirectory(char* dir) {
  char *image_exec = strrchr(dir, (int)'\\') + 1;
  int i = strlen(dir) - strlen(image_exec);
  while (i < strlen(dir))  {
    dir[i] = '\0';
    ++i;
  }
  return String(dir);
}
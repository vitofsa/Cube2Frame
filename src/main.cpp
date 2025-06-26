#include <iostream>
#include <cstdlib>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "cube_mosaic.hpp"
#include "color_map.hpp"

bool CheckArguments(int* argc, char** argv);

std::string GetParentDirectory(char* dir);

int main(int argc, char** argv) {   
  if (CheckArguments(&argc, argv)) {
    return -1;
  }

  // The size of single a cube, which in this case is 3x3x3 and is unchangeable
  // for now.
  const unsigned kCubeType = 3; 
  
  // Creates a CubeMosaic object with the following arguments:
  // @ Image matrix returned by OpenCV
  // @ Size(rows * cubeType, columns * cubeType)
  // @ {rows, columns}
 CubeMosaic Mosaic {
    cv::imread(argv[4], cv::IMREAD_COLOR_BGR),
    cv::Size(atoi(argv[2]) * kCubeType, 
             atoi(argv[1]) * kCubeType),
    {atoi(argv[2]), atoi(argv[1])},
  };
  
  if (Mosaic.GetImage().empty()) {
    std::cerr << "Image error: Failed to load image (check the PATH)!\n";
    return -1;
  }

  Mosaic.ResizePixelsToCubes();
  Mosaic.ApplyColorMask(cv::String(argv[3]));
  Mosaic.DrawGridLines(kCubeType);
  
  imwrite(GetParentDirectory(argv[4]) + "cube_output.png", Mosaic.GetImage());
  return 0;
}

bool CheckArguments(int* argc, char** argv) {
  if (*argc == 5){
    if (atoi(argv[1]) > 0 &&
        atoi(argv[2]) > 0) {
      if (PaletteExists(cv::String(argv[3]))) {
        return 0;
      } else {
        std::cerr << "Image process failed: Color palette does not exist!\n";
      }
    } else {
      std::cerr << "Image process failed: Matrix size cannot be NaN or 0!\n";
    }
  } else {
    if (*argc != 0) {
      std::cerr << "Usage: " << argv[0]
      << " <Rows> <Columns> <Color_Palette> <Image_Path>\n";
    } else {
      std::cerr << "Cube2frame failed: Do not double-click the executable!";
    }
  }
  return 1;
}

inline std::string GetParentDirectory(char* dir) {
  char *image_exec = strrchr(dir, (int)'\\') + 1;
  int i = strlen(dir) - strlen(image_exec);
  while (i < strlen(dir)) {
    dir[i] = '\0';
    ++i;
  }
  return cv::String(dir);
}
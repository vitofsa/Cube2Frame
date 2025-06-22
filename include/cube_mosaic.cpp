#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "cube_mosaic.hpp"
#include "color_map.hpp"

void DrawGridLines(){

}

void CubeMosaic::ResizePixelsToCubes() {
    //cv::resize(image, Mosaic.image, Size(image_size[0] + kRows + 1, image_size[1] + kColumns + 1), 0, 0, cv::INTER_AREA);

  // Scaling down the image will get the aproximate pixels each cube will be
  //  
  cv::resize(image, image, size, 0, 0, cv::INTER_AREA);
  if  (image.size() == size)  {
    cv::resize(image, image, size*3, 0, 0, cv::INTER_AREA);
  }
}

cv::Mat CubeMosaic::GetImage() {
  return image;
}
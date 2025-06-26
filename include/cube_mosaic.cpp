#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "cube_mosaic.hpp"
#include "color_map.hpp"

void CubeMosaic::DrawGridLines(int cube_type) {
  const int rows = kMatrix[0];
  const int columns = kMatrix[1];
  const int line_spacing = cube_type * zoom;
  const cv::Scalar line_color(0, 0, 0);

  for (int i = 0; i <= rows; ++i) {
    int x = i * line_spacing;
    cv::line(image, 
             cv::Point2d(x, 0),
             cv::Point2d(x, image.size[1]),
             line_color, 
             1);
  }

  for (int j = 0; j <= columns; ++j) {
    int y = j * line_spacing;
    cv::line(image, 
             cv::Point2d(0, y),
             cv::Point2d(image.size[0], y),
             cv::Scalar(0, 0, 0),
             1);
  }
}


void CubeMosaic::ApplyColorMask(std::string palette_name) {
  cv::Mat color_map = CreateCubeColorMap(palette_name);
  if (color_map.empty()) {
    color_map = CreateCubeColorMap("normal");
  }
  applyColorMap(image, image, color_map);
} 


// Scaling down the image will get the aproximate pixels each cube will be,
// then zooming into the resized image leads to a better visualisation of the cubes
void CubeMosaic::ResizePixelsToCubes() {
  cv::resize(image, image, size, 0, 0, cv::INTER_AREA);
  if  (image.size() == size)  {
    zoom = kMatrix[0] < 20 || kMatrix [1] < 20 ? 10 : 6;
    cv::resize(image,
               image,
               size * zoom,
               0,
               0,
               cv::INTER_AREA);
  }
}


cv::Mat CubeMosaic::GetImage() {
  return image;
}
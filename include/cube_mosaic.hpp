#ifndef CUBE_MOSAIC
#define CUBE_MOSAIC 

#include "color_map.hpp"

class CubeMosaic {
  public:
    void ResizePixelsToCubes();
    void ApplyColorMask(std::string palette_name);
    void DrawGridLines(int cube_type);
    cv::Mat GetImage();

    explicit CubeMosaic (cv::Mat img, 
                         cv::Size sz,
                         std::vector<int> mtx): 
        image(std::move(img)),
              size(std::move(sz)), 
              kMatrix(std::move(mtx)){};

  private:
    cv::Mat image; // Image matrix read by OpenCV
    cv::Size size; // Mosaic size in pixels
    int zoom; // Zoom-in factor of the resized image
    const std::vector<int> kMatrix; // Mosaic rows and columns
};

#endif // CUBE_MOSAIC
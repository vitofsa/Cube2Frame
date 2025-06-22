#pragma once

#include "color_map.hpp"

class CubeMosaic {
  public:
    explicit CubeMosaic (cv::Mat img, cv::Size sz, std::vector<int> mtx): 
        image(std::move(img)), size(std::move(sz)), kMatrix(std::move(mtx)){};

    void ResizePixelsToCubes();
    cv::Mat GetImage();

  private:
    cv::Mat image; // Image matrix read by OpenCV
    cv::Size size; // Mosaic size in pixels
    const std::vector<int> kMatrix; // Mosaic rows and columns

    void DrawGridLines();
};
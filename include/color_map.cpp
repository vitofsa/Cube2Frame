#include <vector>
#include <opencv2/core.hpp>

#include "color_map.hpp"

// Create the rubik's cube colors matrix from 0 - 256
const std::vector<cv::Vec3b> kRubiksColors = {
  {255, 0, 0}, // Blue
  {0, 0, 255}, // Red
  {0, 165, 255}, // Orange
  {0, 255, 0}, // Green
  {0, 255, 255}, // Yellow
  {255, 255, 255}, // White
};

cv::Mat RubiksColorMap()  {
  cv::Mat Colormap(256, 1, CV_8UC3);
  
  const int kColorDivisions = 256 / kRubiksColors.size();
  for(int i = 0; i < 256; ++i){
    int color_index = i / kColorDivisions;
    if(color_index >= kRubiksColors.size()){
      color_index = kRubiksColors.size() - 1;
    }
    Colormap.at<cv::Vec3b>(i, 0) = kRubiksColors[color_index];
  }

  return Colormap;
}
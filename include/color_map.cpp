#include <vector>
#include <string>
#include <unordered_map>
#include <opencv2/core.hpp>
#include "color_map.hpp"

// Create the rubik's cube colors matrix from 0 - 256
const std::unordered_map<std::string, std::vector<cv::Vec3b>> kRubiksPalletes = {
  { "normal", {
    {202, 71, 1},    // Blue
    {0, 2, 186},     // Red
    {1, 80, 222},    // Orange
    {1, 213, 1},     // Green
    {16, 213, 217},  // Yellow
    {237, 241, 232}, // White
  }},
  { "pastel", {
    {213, 201, 96},   // Blue
    {101, 72, 232},   // Red
    {204, 186, 233},  // Orange
    {231, 229, 175},  // Green
    {176, 229, 221},  // Yellow
    {237, 241, 232}   // White
  }}
};

bool PaletteExists(std::string palette_name) {
  if (kRubiksPalletes.find(palette_name) != kRubiksPalletes.end()) {
    return 1;
  }
  return 0;
}

std::vector<cv::Vec3b> GetColorPallete(std::string palette_name) {
  auto color_iterator = kRubiksPalletes.find(palette_name); 
  if (color_iterator != kRubiksPalletes.end()) {
    return color_iterator->second;
  } else {
    return std::vector<cv::Vec3b>{};
  }
}

cv::Mat CreateCubeColorMap(std::string palette_name) {
  cv::Mat Colormap(256, 1, CV_8UC3);
  auto color_pallete = GetColorPallete(palette_name);

  if (color_pallete.empty()) {
    return cv::Mat{};
  }
  
  const int kColorDivisions = 256 / color_pallete.size();
  for (int i = 0; i < 256; ++i)  {
    int color_index = i / kColorDivisions;
    if (color_index >= color_pallete.size()) {
      color_index = color_pallete.size() - 1;
    }
    Colormap.at<cv::Vec3b>(i, 0) = color_pallete[color_index];
  }
  return Colormap;
}
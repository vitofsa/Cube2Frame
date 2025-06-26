#ifndef CUBE_COLORMAP
#define CUBE_COLORMAP

cv::Mat CreateCubeColorMap(std::string palette_name);
bool PaletteExists(std::string palette_name);

#endif // CUBE_COLORMAP
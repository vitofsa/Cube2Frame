<div align="center">

![](LOGO_LINK)

![Language](https://img.shields.io/badge/Coded_in-C++-blue)
[![Build](https://img.shields.io/badge/Built_with-CMake-red)](https://cmake.org/ "CMake")
[![OpenCV](https://img.shields.io/badge/Using-OpenCV-yellow)](https://opencv.org/ "OpenCV")
</div>
Cube2Frame is a command-line cube mosaic generator for Rubik's cube enthusiast. Just like me 😅!

# 🖼️ Mosaic examples
<div style="display: flex; align-items: center; ">

<div>

![](SMALL_MOSAIC)
<br>[3 x 3] [Normal]
</div>

<div>

![](MOSAIC_NORMAL)
<br>[100 x 100] [Normal]
</div>

<div>

![](MOSAIC_PASTEL)
<br>[100 x 100] [Pastel]
</div>
</div>

# ⚙️ Building the Project
You'll need [Git](https://git-scm.com/), [CMake (4.0+)](https://cmake.org/) and [OpenCV (4.11.0+)](https://opencv.org/) (which implies that you use the same compiler of its binary on CMake) to build and run this repository. On your command-line do:

```sh
# Clone the repository
git clone https://github.com/vitofsa/Cube2Frame.git
# Enter the directory
cd Cube2Frame
```
And after:
```sh
# Create a new directory for the build
mkdir build
# Enter the directory
cd build
# Create a Makefile with CMake of the parent directory
cmake ../
# Build the Makefile
cmake --build ./
```

# 🔧 Usage

```sh
cube2frame <Rows> <Columns> <Color_Palette> <Image>
```

## Description

| Argument | Description |
|----------|-------------|
|Rows      | Number of rows on the mosaic. Needs to be more then 0.|
|Columns | Number of columns on the mosaic. Needs to be more then 0.|
|Color_Pallete | The color palette that the output image will be. Check current palettes here!|
|Image | The image source (with the extension). Ex: "C:/user/cube/im_a_example.png" |


# 🪄 Customization
Here you can customize the output image that you will have! 🤩
## 🎨 Color Palettes 
| Argument | Palette Demonstration |
|----------|-----------------------|
|normal    | ![](NORMAL_PALETTE) | 
|pastel    | ![](PASTEL_PALETTE) | 

## 👷‍♂️ Work in Progress
This is a small work in progress project to challenge my C++ knowledge. What new feature can I implement in the future? Let me know! 😉
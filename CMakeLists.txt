# Generated from rasterwindow.pro.

cmake_minimum_required(VERSION 3.16)

project(vcglearning LANGUAGES CXX)

# find_package(Qt CONFIG) 查找三方库
############### vcglib ########################
find_path(VCGLIB_INCLUDE_DIRS "img/img.h")


add_subdirectory(examples)

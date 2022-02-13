# CMakeList.txt: XCode 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("XCode")

# 将源代码添加到此项目的可执行文件。
#add_executable (XCode "01_datatype.cpp" "demo_common.h")
#add_executable (XCode "02_constexpr.cpp" "demo_common.h "03_class_base.cpp"")
add_executable (XCode "03_class_base.cpp" "demo_common.h")

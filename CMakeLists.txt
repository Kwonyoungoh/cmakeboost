# CMakeList.txt : 최상위 CMake 프로젝트 파일, 전역 구성을 수행하고
# 여기에 하위 프로젝트를 포함합니다.
#
cmake_minimum_required (VERSION 3.8)

# iostream 소스조차 열수 없다면 아래와 같이 설정해보자.
# CMake의 문제가아닌 c++ 컴파일러의 문제입니다.
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project ("wsltst")

# 하위 프로젝트를 포함합니다.
add_subdirectory ("wsltst")

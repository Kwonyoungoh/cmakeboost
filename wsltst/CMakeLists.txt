# CMakeList.txt: wsltst에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.


# 조건문 분기
if (WIN32)
# boost 설치 경로 지정
    set(BOOST_ROOT "C:/Users/rnjsd/lib/boost_1_81_0")
    find_package(Boost "1.74" REQUIRED)
else ()
# 무조건 저경로임
    set(BOOST_ROOT "/usr/include/boost")
    find_package(Boost "1.71" REQUIRED COMPONENTS system thread)
endif ()

# Boost 1.74.0 이상 지원한다는 뜻 
# [NOTE] 컴포넌트 지정시 window에서 에러
# https://stackoverflow.com/questions/71610458/could-not-find-boost-missing-system-found-suitable-versihow-on-1-78-0-min#comment126571332_71610458
# find_package(Boost "1.74" REQUIRED COMPONENTS system thread)

include_directories(${Boost_INCLUDE_DIRS})
# 이 프로젝트의 실행 파일에 소스를 추가합니다.
add_executable (wsltst "wsltst.cpp" "wsltst.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET wsltst PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(wsltst ${Boost_LIBRARIES})
# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.

cmake_minimum_required(VERSION 2.8)  

project(test_opencv)  

find_package( OpenCV REQUIRED )  

include_directories("${PROJECT_SOURCE_DIR}/include")

FILE(GLOB SC_FILES "impl/*.cpp" "include/*.h")

add_executable( test_opencv ${SC_FILES} )

target_link_libraries( test_opencv ${OpenCV_LIBS} )

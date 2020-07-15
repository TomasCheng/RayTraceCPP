cmake_minimum_required(VERSION 2.8)  

project(rayTrace)  

find_package( OpenCV REQUIRED )  

include_directories("${PROJECT_SOURCE_DIR}/include")

FILE(GLOB SC_FILES "include/*.h" "impl/*.cpp" )

add_executable( rayTrace ${SC_FILES} )

target_link_libraries( rayTrace ${OpenCV_LIBS} )


cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++ -std=c++11")

if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()

project(VtkImageShow)

set(VTK_DIR "/usr/local/vtk/lib/cmake/vtk-6.1")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(QT4 REQUIRED)
include(${QT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES  *.ui)
file(GLOB QT_WRAP   *.h)
file(GLOB CXX_FILES *.cxx)

QT4_WRAP_UI(UISrcs ${UI_FILES})
QT4_WRAP_CPP(MOCSrcs ${QT_WRAP})

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${CXX_FILES} ${UISrcs} ${MOCSrcs})

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})




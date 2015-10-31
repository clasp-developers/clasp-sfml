cmake_minimum_required(VERSION 2.8)

# define a macro that helps defining an option
macro(sfml_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# set a default build type if none was provided
# this has to be done before the project() instruction!
sfml_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

# project name
project(CLASP-SFML)

# setup version numbers
set(VERSION_MAJOR 2)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)

find_path(CLASP_INCLUDE_PATH clasp/clasp.h DOC "The include directory of clasp")
find_path(CLASP_LIB_PATH libclasp-clbind.so DOC "The lib path of clasp")
find_path(SFML_INCLUDE_PATH SFML/System.hpp DOC "The include directory of SFML")
#find_path(EXTERNALS_CLASP_PATH gc_cpp.h DOC "The directory of externals-clasp")

# add the SFML header path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CLASP_INCLUDE_PATH}
  ${SFML_INCLUDE_PATH}
  #${EXTERNALS_CLASP_PATH}/build/common/include
  #/home/flash/dev/externals-clasp/build/common/include
  #/home/flash/dev/clasp-src/include
  )

add_compile_options(-std=c++11
   -v 
   -fPIC
   -D_TARGET_OS_LINUX
   -DX86
   -DNDEBUG
   -DUSE_BOEHM
   -DUSE_ALLOCA_FOR_FRAME
   -D_ADDRESS_MODEL_64
   -Wl,--start-group
   ${CLASP_LIB_PATH}/libclasp-clbind.so
   -Wl,--end-group)
 
 set(BUILD_SHARED_LIBS TRUE)

 set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
 
 # add the subdirectories
 add_subdirectory(src/CLASP-SFML)
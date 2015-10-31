file(GLOB GRAPHICS_SOURCES *.cpp)
find_library(SFML_GRAPHICS libsfml-graphics.so DOC "The sfml graphics library")
add_library(clasp-sfml-graphics SHARED ${GRAPHICS_SOURCES})
target_link_libraries(clasp-sfml-graphics ${SFML_GRAPHICS})
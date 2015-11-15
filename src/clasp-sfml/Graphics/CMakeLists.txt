file(GLOB GRAPHICS_SOURCES *.cpp)
find_library(SFML_GRAPHICS sfml-graphics HINTS $ENV{SFML_LIB_DIR} DOC "The sfml graphics library")
add_library(clasp-sfml-graphics SHARED ${GRAPHICS_SOURCES})
target_link_libraries(clasp-sfml-graphics
  ${SFML_GRAPHICS}
  # -Wl,--start-group
  # ${CLASP_CLBIND_LIB}
  # -Wl,--end-group
  )
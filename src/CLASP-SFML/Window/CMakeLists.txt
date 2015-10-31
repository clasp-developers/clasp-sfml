file(GLOB WINDOW_SOURCES *.cpp)
find_library(SFML_WINDOW libsfml-window.so DOC "The sfml window library")
add_library(clasp-sfml-window SHARED ${WINDOW_SOURCES})
target_link_libraries(clasp-sfml-window
  ${SFML_WINDOW}  
  # -Wl,--start-group
  # ${CLASP_CLBIND_LIB}
  # -Wl,--end-group
  )
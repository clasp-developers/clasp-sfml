file(GLOB SYSTEM_SOURCES *.cpp)
find_library(SFML_SYSTEM libsfml-system.so DOC "The sfml system library")
add_library(clasp-sfml-system SHARED ${SYSTEM_SOURCES})
target_link_libraries(clasp-sfml-system
  ${SFML_SYSTEM}
  # -Wl,--start-group
  # ${CLASP_CLBIND_LIB}
  # -Wl,--end-group
  )
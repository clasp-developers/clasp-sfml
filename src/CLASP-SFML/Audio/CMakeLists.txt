file(GLOB AUDIO_SOURCES *.cpp)
find_library(SFML_AUDIO sfml-audio HINTS $ENV{SFML_LIB_DIR} DOC "The sfml audio library")
add_library(clasp-sfml-audio SHARED ${AUDIO_SOURCES})
target_link_libraries(clasp-sfml-audio
  ${SFML_AUDIO}
  # -Wl,--start-group
  # ${CLASP_CLBIND_LIB}
  # -Wl,--end-group
  )
file(GLOB AUDIO_SOURCES *.cpp)
find_library(SFML_AUDIO libsfml-audio.so DOC "The sfml audio library")
add_library(clasp-sfml-audio SHARED ${AUDIO_SOURCES})
target_link_libraries(clasp-sfml-audio ${SFML_AUDIO})
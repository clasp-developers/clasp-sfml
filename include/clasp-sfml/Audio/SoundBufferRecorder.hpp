#ifndef CS_SOUNDBUFFERRECORDER_HPP
#define CS_SOUNDBUFFERRECORDER_HPP

#include <SFML/Audio/SoundBufferRecorder.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::SoundBufferRecorder, sf::SoundRecorder> registerSoundBufferRecorder()
{
  return
    class_<sf::SoundBufferRecorder, sf::SoundRecorder>("sound-buffer-recorder")

    .def("get-buffer", &sf::SoundBufferRecorder::getBuffer,
	 policies<>(), "", "",
	 R"**(\brief Get the sound buffer containing the captured audio data

	      The sound buffer is valid only after the capture has ended.
	      This function provides a read-only access to the internal
	      sound buffer, but it can be copied if you need to
	      make any modification to it.

	      \return Read-only access to the sound buffer)**");

}

#endif //CS_SOUNDBUFFERRECORDER_HPP

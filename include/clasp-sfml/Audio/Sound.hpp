#ifndef CS_SOUND_HPP
#define CS_SOUND_HPP

#include <SFML/Audio/Sound.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Sound, sf::SoundSource> registerSound()
{
  return
    class_<sf::Sound, sf::SoundSource>("sound")
    .def_constructor("make-sound", constructor<const sf::SoundBuffer&>())
    .def_constructor("copy-sound", constructor<const sf::Sound&>())

    .def("play", &sf::Sound::play,
	 policies<>(), "", "",
	 R"**(\brief Start or resume playing the sound

	      This function starts the stream if it was stopped, resumes
	      it if it was paused, and restarts it from beginning if it
	      was it already playing.
	      This function uses its own thread so that it doesn't block
	      the rest of the program while the sound is played.

	      \see pause, stop)**")

    .def("pause", &sf::Sound::pause,
	 policies<>(), "", "",
	 R"**(\brief Pause the sound

	      This function pauses the sound if it was playing,
	      otherwise (sound already paused or stopped) it has no effect.

	      \see play, stop)**")

    .def("stop", &sf::Sound::stop,
	 policies<>(), "", "",
	 R"**(\brief stop playing the sound

	      This function stops the sound if it was playing or paused,
	      and does nothing if it was already stopped.
	      It also resets the playing position (unlike pause()).

	      \see play, pause)**")

    .def("set-buffer", &sf::Sound::setBuffer,
	 policies<>(), "", "",
	 R"**(\brief Set the source buffer containing the audio data to play

	      It is important to note that the sound buffer is not copied,
	      thus the sf::SoundBuffer instance must remain alive as long
	      as it is attached to the sound.

	      \param buffer Sound buffer to attach to the sound

	      \see getBuffer)**")

    .def("set-loop", &sf::Sound::setLoop,
	 policies<>(), "", "",
	 R"**(\brief Set whether or not the sound should loop after reaching the end

	      If set, the sound will restart from beginning after
	      reaching the end and so on, until it is stopped or
	      setLoop(false) is called.
	      The default looping state for sound is false.

	      \param loop True to play in loop, false to play once

	      \see getLoop)**")

    .def("set-playing-offset", &sf::Sound::setPlayingOffset,
	 policies<>(), "", "",
	 R"**(\brief Change the current playing position of the sound

	      The playing position can be changed when the sound is
	      either paused or playing. Changing the playing position
	      when the sound is stopped has no effect, since playing
	      the sound will reset its position.

	      \param timeOffset New playing position, from the beginning of the sound

	      \see getPlayingOffset)**")

    .def("get-buffer", &sf::Sound::getBuffer,
	 policies<>(), "", "",
	 R"**(\brief Get the audio buffer attached to the sound

	      \return Sound buffer attached to the sound (can be NULL))**")

    .def("get-loop", &sf::Sound::getLoop,
	 policies<>(), "", "",
	 R"**(\brief Tell whether or not the sound is in loop mode

	      \return True if the sound is looping, false otherwise

	      \see setLoop)**")

    .def("get-playing-offset", &sf::Sound::getPlayingOffset,
	 policies<>(), "", "",
	 R"**(\brief Get the current playing position of the sound

	      \return Current playing position, from the beginning of the sound

	      \see setPlayingOffset)**")

    .def("get-status", &sf::Sound::getStatus,
	 policies<>(), "", "",
	 R"**(\brief Get the current status of the sound (stopped, paused, playing)

	      \return Current status of the sound)**")

    .def("reset-buffer", &sf::Sound::resetBuffer,
	 policies<>(), "", "",
	 R"**(\brief Reset the internal buffer of the sound

	      This function is for internal use only, you don't have
	      to use it. It is called by the sf::SoundBuffer that
	      this sound uses, when it is destroyed in order to prevent
	      the sound from using a dead buffer.)**");

}

#endif //CS_SOUND_HPP

#ifndef CS_SOUNDSTREAM_HPP
#define CS_SOUNDSTREAM_HPP

#include <SFML/Audio/SoundStream.hpp>


#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

using namespace clbind;

inline class_<sf::SoundStream, sf::SoundSource> registerSoundStream()
{
  return
    class_<sf::SoundStream, sf::SoundSource>("sound-stream", no_default_constructor)

    .def("play", &sf::SoundStream::play,
	 policies<>(), "", "",
	 R"**(\brief Start or resume playing the audio stream

	      This function starts the stream if it was stopped, resumes
	      it if it was paused, and restarts it from the beginning if
	      it was already playing.
	      This function uses its own thread so that it doesn't block
	      the rest of the program while the stream is played.

	      \see pause, stop)**")

    .def("pause", &sf::SoundStream::pause,
	 policies<>(), "", "",
	 R"**(\brief Pause the audio stream

	      This function pauses the stream if it was playing,
	      otherwise (stream already paused or stopped) it has no effect.

	      \see play, stop)**")

    .def("stop", &sf::SoundStream::stop,
	 policies<>(), "", "",
	 R"**(\brief Stop playing the audio stream

	      This function stops the stream if it was playing or paused,
	      and does nothing if it was already stopped.
	      It also resets the playing position (unlike pause()).

	      \see play, pause)**")

    .def("get-channel-count", &sf::SoundStream::getChannelCount,
	 policies<>(), "", "",
	 R"**(\brief Return the number of channels of the stream

	      1 channel means a mono sound, 2 means stereo, etc.

	      \return Number of channels)**")

    .def("get-sample-rate", &sf::SoundStream::getSampleRate,
	 policies<>(), "", "",
	 R"**(\brief Get the stream sample rate of the stream

	      The sample rate is the number of audio samples played per
	      second. The higher, the better the quality.

	      \return Sample rate, in number of samples per second)**")

    .def("get-status", &sf::SoundStream::getStatus,
	 policies<>(), "", "",
	 R"**(\brief Get the current status of the stream (stopped, paused, playing)

	      \return Current status)**")

    .def("set-playing-offset", &sf::SoundStream::setPlayingOffset,
	 policies<>(), "", "",
	 R"**(\brief Change the current playing position of the stream

	      The playing position can be changed when the stream is
	      either paused or playing. Changing the playing position
	      when the stream is stopped has no effect, since playing
	      the stream would reset its position.

	      \param timeOffset New playing position, from the beginning of the stream

	      \see getPlayingOffset)**")

    .def("get-playing-offset", &sf::SoundStream::getPlayingOffset,
	 policies<>(), "", "",
	 R"**(\brief Get the current playing position of the stream

	      \return Current playing position, from the beginning of the stream

	      \see setPlayingOffset)**")

    .def("set-loop", &sf::SoundStream::setLoop,
	 policies<>(), "", "",
	 R"**(\brief Set whether or not the stream should loop after reaching the end

	      If set, the stream will restart from beginning after
	      reaching the end and so on, until it is stopped or
	      setLoop(false) is called.
	      The default looping state for streams is false.

	      \param loop True to play in loop, false to play once

	      \see getLoop)**")

    .def("get-loop", &sf::SoundStream::getLoop,
	 policies<>(), "", "",
	 R"**(\brief Tell whether or not the stream is in loop mode

	      \return True if the stream is looping, false otherwise

	      \see setLoop)**");
}

#endif //CS_SOUNDSTREAM_HPP

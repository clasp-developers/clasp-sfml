#ifndef CS_MUSIC_HPP
#define CS_MUSIC_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundStream.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;


inline class_<sf::Music, sf::SoundStream> registerMusic()
{
  return
    class_<sf::Music, sf::SoundStream>("music")
    .def_constructor("make-music", constructor<>())
    .def("open-from-file", &sf::Music::openFromFile,
	 policies<>(), "", "",
	 R"**(\brief Open a music from an audio file

	      This function doesn't start playing the music (call play()
	      to do so).
	      Here is a complete list of all the supported audio formats:
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.

	      \param filename Path of the music file to open

	      \return True if loading succeeded, false if it failed

	      \see openFromMemory, openFromStream)**")

    .def("open-from-memory", &sf::Music::openFromMemory,
	 policies<>(), "", "",
	 R"**(\brief Open a music from an audio file in memory

	      This function doesn't start playing the music (call play()
	      to do so).
	      Here is a complete list of all the supported audio formats:
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
	      Since the music is not loaded completely but rather streamed
	      continuously, the \a data must remain available as long as the
	      music is playing (i.e. you can't deallocate it right after calling
	      this function).

	      \param data        Pointer to the file data in memory
	      \param sizeInBytes Size of the data to load, in bytes

	      \return True if loading succeeded, false if it failed

	      \see openFromFile, openFromStream)**")

    .def("open-from-stream", &sf::Music::openFromStream,
	 policies<>(), "", "",
	 R"**(\brief Open a music from an audio file in a custom stream

	      This function doesn't start playing the music (call play()
	      to do so).
	      Here is a complete list of all the supported audio formats:
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
	      Since the music is not loaded completely but rather streamed
	      continuously, the \a stream must remain alive as long as the
	      music is playing (i.e. you can't destroy it right after calling
	      this function).

	      \param stream Source stream to read from

	      \return True if loading succeeded, false if it failed

	      \see openFromFile, openFromMemory)**")

    .def("get-duration", &sf::Music::getDuration,
	 policies<>(), "", "",
	 R"**(\brief Get the total duration of the music

	      \return Music duration)**")
    ;
}
#endif

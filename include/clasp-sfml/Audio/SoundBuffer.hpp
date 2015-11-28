#ifndef CS_SOUND_BUFFER_HPP
#define CS_SOUND_BUFFER_HPP

#include <SFML/Audio/SoundBuffer.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::SoundBuffer> registerSoundBuffer()
{
  return
    class_<sf::SoundBuffer>("sound-buffer", no_default_constructor)
    .def_constructor("make-sound-buffer", constructor<>())
    .def("load-from-file/sound-buffer", &sf::SoundBuffer::loadFromFile,
    	 policies<>(), "", "",
    	 R"**(\brief Load the sound buffer from a file

    	      Here is a complete list of all the supported audio formats:
    	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
    	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.

    	      \param filename Path of the sound file to load

    	      \return True if loading succeeded, false if it failed

    	      \see loadFromMemory, loadFromStream, loadFromSamples, saveToFile)**")

    .def("load-from-memory", &sf::SoundBuffer::loadFromMemory,
	 policies<>(), "", "",
	 R"**(\brief Load the sound buffer from a file in memory

	      Here is a complete list of all the supported audio formats
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64

	      \param data        Pointer to the file data in memor
	      \param sizeInBytes Size of the data to load, in byte

	      \return True if loading succeeded, false if it faile

	      \see loadFromFile, loadFromStream, loadFromSamples)**")

    .def("load-from-stream", &sf::SoundBuffer::loadFromStream,
	 policies<>(), "", "",
	 R"**(\brief Load the sound buffer from a custom stream

	      Here is a complete list of all the supported audio formats
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.

	      \param stream Source stream to read from

	      \return True if loading succeeded, false if it failed

	      \see loadFromFile, loadFromMemory, loadFromSamples)**")
	 
    // .def("load-from-samples", &sf::SoundBuffer::loadFromSamples,
    //      policies<>(), "", "",
    //      R"**(\brief Load the sound buffer from an array of audio samples

    //      The assumed format of the audio samples is 16 bits signed integer
    //      (sf::Int16).

    //      \param samples      Pointer to the array of samples in memory
    //      \param sampleCount  Number of samples in the array
    //      \param channelCount Number of channels (1 = mono, 2 = stereo, ...)
    //      \param sampleRate   Sample rate (number of samples to play per second)

    //      \return True if loading succeeded, false if it failed

    //      \see loadFromFile, loadFromMemory, saveToFile)**")

    .def("save-to-file", &sf::SoundBuffer::saveToFile,
	 policies<>(), "", "",
	 R"**(\brief Save the sound buffer to an audio file

	      Here is a complete list of all the supported audio formats:
	      ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
	      w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.

	      \param filename Path of the sound file to write

	      \return True if saving succeeded, false if it failed

	      \see loadFromFile, loadFromMemory, loadFromSamples)**")

    .def("get-samples", &sf::SoundBuffer::getSamples,
	 policies<>(), "", "",
	 R"**(\brief Get the array of audio samples stored in the buffer

	      The format of the returned samples is 16 bits signed integer
	      (sf::Int16). The total number of samples in this array
	      is given by the getSampleCount() function.

	      \return Read-only pointer to the array of sound samples

	      \see getSampleCount)**")

    .def("get-sample-count", &sf::SoundBuffer::getSampleCount,
	 policies<>(), "", "",
	 R"**(\brief Get the number of samples stored in the buffer

	      The array of samples can be accessed with the getSamples()
	      function.

	      \return Number of samples

	      \see getSamples)**")

    .def("get-sample-rate", &sf::SoundBuffer::getSampleRate,
	 policies<>(), "", "",
	 R"**(\brief Get the sample rate of the sound

	      The sample rate is the number of samples played per second.
	      The higher, the better the quality (for example, 44100
	      samples/s is CD quality).

	      \return Sample rate (number of samples per second)

	      \see getChannelCount, getDuration)**")

    .def("get-channel-count", &sf::SoundBuffer::getChannelCount,
	 policies<>(), "", "",
	 R"**(\brief Get the number of channels used by the sound

	      If the sound is mono then the number of channels will
	      be 1, 2 for stereo, etc.

	      \return Number of channels

	      \see getSampleRate, getDuration)**")

    .def("get-duration", &sf::SoundBuffer::getDuration,
	 policies<>(), "", "",
	 R"**(\brief Get the total duration of the sound

	      \return Sound duration

	      \see getSampleRate, getChannelCount)**")
	 
    //FIXME: missing assignment operator
    ;
}

#endif //CS_SOUND_BUFFER_HPP

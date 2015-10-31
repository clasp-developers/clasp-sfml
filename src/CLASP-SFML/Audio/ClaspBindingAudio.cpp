#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundRecorder.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <SFML/Audio/SoundStream.hpp>
#include <SFML/System/InputStream.hpp>
#include <CLASP-SFML/translators.hpp>


#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

#include <cstdlib>

#define EXPORT __attribute__((visibility("default")))


extern "C"
{
EXPORT
void CLASP_MAIN()
{
    using namespace clbind;
    package("SF")
	[
	 //class_<sf::Listener>("listener")
	 // def("listener/set-global-volume", &sf::Listener::setGlobalVolume,
	 //      policies<>(), "", "",
	 //      R"**(\brief Change the global volume of all the sounds and musics

	 //      The volume is a number between 0 and 100; it is combined with
	 //      the individual volume of each sound / music.
	 //      The default value for the volume is 100 (maximum).

	 //      \param volume New global volume, in the range [0, 100]

	 //      \see getGlobalVolume**)")

	 // ,def("listener/get-global-volume", &sf::Listener::getGlobalVolume,
	 //      policies<>(), "", "",
	 //      R"**(\brief Get the current value of the global volume

	 //      \return Current global volume, in the range [0, 100]

	 //      \see setGlobalVolume**)")

	 // ,def("listener/set-position", &sf::Listener::setPosition,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the position of the listener in the scene

	 //      The default listener's position is (0, 0, 0).

	 //      \param x X coordinate of the listener's position
	 //      \param y Y coordinate of the listener's position
	 //      \param z Z coordinate of the listener's position

	 //      \see getPosition, setDirection**)")

	 // ,def("listener/set-position", &sf::Listener::setPosition,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the position of the listener in the scene

	 //      The default listener's position is (0, 0, 0).

	 //      \param position New listener's position

	 //      \see getPosition, setDirection**)")

	 // ,def("listener/get-position", &sf::Listener::getPosition,
	 //      policies<>(), "", "",
	 //      R"**(\brief Get the current position of the listener in the scene

	 //      \return Listener's position

	 //      \see setPosition**)")

	 // ,def("listener/set-direction",
	 //      (void (sf::Listener::*)(float float float))
	 //      &sf::Listener::setDirection,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the forward vector of the listener in the scene

	 //      The direction (also called "at vector") is the vector
	 //      pointing forward from the listener's perspective. Together
	 //      with the up vector, it defines the 3D orientation of the
	 //      listener in the scene. The direction vector doesn't
	 //      have to be normalized.
	 //      The default listener's direction is (0, 0, -1).

	 //      \param x X coordinate of the listener's direction
	 //      \param y Y coordinate of the listener's direction
	 //      \param z Z coordinate of the listener's direction

	 //      \see getDirection, setUpVector, setPosition**)")

	 // ,def("listener/set-direction",
	 //      (void (sf::Listener::*)(const Vector3f &))
	 //      &sf::Listener::setDirection,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the forward vector of the listener in the scene

	 //      The direction (also called "at vector") is the vector
	 //      pointing forward from the listener's perspective. Together
	 //      with the up vector, it defines the 3D orientation of the
	 //      listener in the scene. The direction vector doesn't
	 //      have to be normalized.
	 //      The default listener's direction is (0, 0, -1).

	 //      \param direction New listener's direction

	 //      \see getDirection, setUpVector, setPosition**)")

	 // ,def("listener/get-direction", &sf::Listener::getDirection,
	 //      policies<>(), "", "",
	 //      R"**(\brief Get the current forward vector of the listener in the scene

	 //      \return Listener's forward vector (not normalized)

	 //      \see setDirection**)")

	 // ,def("listener/set-up-vector",
	 //      (float float float)
	 //      &sf::Listener::setUpVector,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the upward vector of the listener in the scene

	 //      The up vector is the vector that points upward from the
	 //      listener's perspective. Together with the direction, it
	 //      defines the 3D orientation of the listener in the scene.
	 //      The up vector doesn't have to be normalized.
	 //      The default listener's up vector is (0, 1, 0). It is usually
	 //      not necessary to change it, especially in 2D scenarios.

	 //      \param x X coordinate of the listener's up vector
	 //      \param y Y coordinate of the listener's up vector
	 //      \param z Z coordinate of the listener's up vector

	 //      \see getUpVector, setDirection, setPosition**)")

	 // ,def("listener/set-up-vector",
	 //      (void (sf::Listener::*)(const Vector3f &))
	 //      &sf::Listener::setUpVector,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the upward vector of the listener in the scene

	 //      The up vector is the vector that points upward from the
	 //      listener's perspective. Together with the direction, it
	 //      defines the 3D orientation of the listener in the scene.
	 //      The up vector doesn't have to be normalized.
	 //      The default listener's up vector is (0, 1, 0). It is usually
	 //      not necessary to change it, especially in 2D scenarios.

	 //      \param upVector New listener's up vector

	 //      \see getUpVector, setDirection, setPosition**)")

	 // ,def("listener/get-up-vector", &sf::Listener::getUpVector,
	 //      policies<>(), "", "",
	 //      R"**(\brief Get the current upward vector of the listener in the scene

	 //      \return Listener's upward vector (not normalized)

	 //      \see setUpVector**)")
	 
	 class_<sf::SoundBuffer>("sound-buffer")
	 .def_constructor("make-sound-buffer", constructor<const sf::SoundBuffer&>())
	 .def("load-from-file", &sf::SoundBuffer::loadFromFile,
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

	 ,
	 class_<sf::SoundRecorder>("sound-recorder", no_default_constructor)

	 .def("start", &sf::SoundRecorder::start,
	      policies<>(), "(self &optional (sample-rate 44100))", "",
	      R"**(\brief Start the capture

	      The \a sampleRate parameter defines the number of audio samples
	      captured per second. The higher, the better the quality
	      (for example, 44100 samples/sec is CD quality).
	      This function uses its own thread so that it doesn't block
	      the rest of the program while the capture runs.
	      Please note that only one capture can happen at the same time.
	      You can select which capture device will be used, by passing
	      the name to the setDevice() method. If none was selected
	      before, the default capture device will be used. You can get a
	      list of the names of all available capture devices by calling
	      getAvailableDevices().

	      \param sampleRate Desired capture rate, in number of samples per second

	      \return True, if start of capture was successful

	      \see stop, getAvailableDevices)**")

	 .def("stop", &sf::SoundRecorder::stop,
	      policies<>(), "", "",
	      R"**(\brief Stop the capture

	      \see start)**")

	 .def("get-sample-rate", &sf::SoundRecorder::getSampleRate,
	      policies<>(), "", "",
	      R"**(\brief Get the sample rate

The sample rate defines the number of audio samples
captured per second. The higher, the better the quality
(for example, 44100 samples/sec is CD quality).

\return Sample rate, in samples per second)**")

	 .def("set-device", &sf::SoundRecorder::setDevice,
	      policies<>(), "", "",
	      R"**(\brief Set the audio capture device

	      This function sets the audio capture device to the device
	      with the given \a name. It can be called on the fly (i.e:
	      while recording). If you do so while recording and
	      opening the device fails, it stops the recording.

	      \param name The name of the audio capture device

	      \return True, if it was able to set the requested device

	      \see getAvailableDevices, getDefaultDevice)**")

	 .def("get-device", &sf::SoundRecorder::getDevice,
	      policies<>(), "", "",
	      R"**(\brief Get the name of the current audio capture device

	      \return The name of the current audio capture device)**")
	 
	 ,def("sound-recorder/get-available-devices", &sf::SoundRecorder::getAvailableDevices,
	      policies<>(), "", "",
	      R"**(\brief Get a list of the names of all available audio capture devices

	      This function returns a vector of strings, containing
	      the names of all available audio capture devices.

	      \return A vector of strings containing the names)**")

	 ,def("sound-recorder/get-default-device", &sf::SoundRecorder::getDefaultDevice,
	      policies<>(), "", "",
	      R"**(\brief Get the name of the default audio capture device

	      This function returns the name of the default audio
	      capture device. If none is available, an empty string
	      is returned.

	      \return The name of the default audio capture device)**")

	 ,def("sound-recorder/is-available", &sf::SoundRecorder::isAvailable,
	      policies<>(), "", "",
	      R"**(\brief Check if the system supports audio capture

	      This function should always be called before using
	      the audio capture features. If it returns false, then
	      any attempt to use sf::SoundRecorder or one of its derived
	      classes will fail.

	      \return True if audio capture is supported, false otherwise)**")

	 ,
	 class_<sf::SoundSource>("sound-source", no_default_constructor)
	 // .enum_<sf::SoundSource::Status>(core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*"))
	 // [ value("stopped",sf::SoundSource::Status::Stopped),
	 //   value("paused",sf::SoundSource::Status::Paused),              
	 //   value("playing",sf::SoundSource::Status::Playing)
	 // ]
	 .def_constructor("copy-sound-source", constructor<const sf::SoundSource&>())

	 .def("set-pitch", &sf::SoundSource::setPitch,
	      policies<>(), "", "",
	      R"**(\brief Set the pitch of the sound

	      The pitch represents the perceived fundamental frequency
	      of a sound; thus you can make a sound more acute or grave
	      by changing its pitch. A side effect of changing the pitch
	      is to modify the playing speed of the sound as well.
	      The default value for the pitch is 1.

	      \param pitch New pitch to apply to the sound

	      \see getPitch)**")

	 .def("set-volume", &sf::SoundSource::setVolume,
	      policies<>(), "", "",
	      R"**(\brief Set the volume of the sound

	      The volume is a value between 0 (mute) and 100 (full volume).
	      The default value for the volume is 100.

	      \param volume Volume of the sound

	      \see getVolume)**")

	 .def("set-position-fff", (void (sf::SoundSource::*)(float, float, float))
	      &sf::SoundSource::setPosition,
	      policies<>(), "", "",
	      R"**(\brief Set the 3D position of the sound in the audio scene

	      Only sounds with one channel (mono sounds) can be
	      spatialized.
	      The default position of a sound is (0, 0, 0).

	      \param x X coordinate of the position of the sound in the scene
	      \param y Y coordinate of the position of the sound in the scene
	      \param z Z coordinate of the position of the sound in the scene

	      \see getPosition)**")

	 // .def("set-position", (void (sf::SoundSource::*)(const sf::Vector3f&))
	 //      &sf::SoundSource::setPosition,
	 //      policies<>(), "", "",
	 //      R"**(\brief Set the 3D position of the sound in the audio scene

	 //      Only sounds with one channel (mono sounds) can be
	 //      spatialized.
	 //      The default position of a sound is (0, 0, 0).

	 //      \param position Position of the sound in the scene

	 //      \see getPosition)**")

	 .def("set-relative-to-listener", &sf::SoundSource::setRelativeToListener,
	      policies<>(), "", "",
	      R"**(\brief Make the sound's position relative to the listener or absolute

	      Making a sound relative to the listener will ensure that it will always
	      be played the same way regardless of the position of the listener.
	      This can be useful for non-spatialized sounds, sounds that are
	      produced by the listener, or sounds attached to it.
	      The default value is false (position is absolute).

	      \param relative True to set the position relative, false to set it absolute

	      \see isRelativeToListener)**")

	 .def("set-min-distance", &sf::SoundSource::setMinDistance,
	      policies<>(), "", "",
	      R"**(\brief Set the minimum distance of the sound

	      The "minimum distance" of a sound is the maximum
	      distance at which it is heard at its maximum volume. Further
	      than the minimum distance, it will start to fade out according
	      to its attenuation factor. A value of 0 ("inside the head
	      of the listener") is an invalid value and is forbidden.
	      The default value of the minimum distance is 1.

	      \param distance New minimum distance of the sound

	      \see getMinDistance, setAttenuation)**")

	 .def("set-attenuation", &sf::SoundSource::setAttenuation,
	      policies<>(), "", "",
	      R"**(\brief Set the attenuation factor of the sound

	      The attenuation is a multiplicative factor which makes
	      the sound more or less loud according to its distance
	      from the listener. An attenuation of 0 will produce a
	      non-attenuated sound, i.e. its volume will always be the same
	      whether it is heard from near or from far. On the other hand,
	      an attenuation value such as 100 will make the sound fade out
	      very quickly as it gets further from the listener.
	      The default value of the attenuation is 1.

	      \param attenuation New attenuation factor of the sound

	      \see getAttenuation, setMinDistance)**")

	 .def("get-pitch", &sf::SoundSource::getPitch,
	      policies<>(), "", "",
	      R"**(\brief Get the pitch of the sound

	      \return Pitch of the sound

	      \see setPitch)**")

	 .def("get-volume", &sf::SoundSource::getVolume,
	      policies<>(), "", "",
	      R"**(\brief Get the volume of the sound

	      \return Volume of the sound, in the range [0, 100]

	      \see setVolume)**")

	 .def("get-position", &sf::SoundSource::getPosition,
	      policies<>(), "", "",
	      R"**(\brief Get the 3D position of the sound in the audio scene

	      \return Position of the sound

	      \see setPosition)**")

	 .def("is-relative-to-listener", &sf::SoundSource::isRelativeToListener,
	      policies<>(), "", "",
	      R"**(\brief Tell whether the sound's position is relative to the
	      listener or is absolute

	      \return True if the position is relative, false if it's absolute

	      \see setRelativeToListener)**")

	 .def("get-min-distance", &sf::SoundSource::getMinDistance,
	      policies<>(), "", "",
	      R"**(\brief Get the minimum distance of the sound

	      \return Minimum distance of the sound

	      \see setMinDistance, getAttenuation)**")

	 .def("get-attenuation", &sf::SoundSource::getAttenuation,
	      policies<>(), "", "",
	      R"**(\brief Get the attenuation factor of the sound

	      \return Attenuation factor of the sound

	      \see setAttenuation, getMinDistance)**")

	 ,
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

	      \see setLoop)**")

	 ,
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

	 ,
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
	      the sound from using a dead buffer.)**")

	 ,
	 class_<sf::SoundBufferRecorder, sf::SoundRecorder>("sound-buffer-recorder")

	 .def("get-buffer", &sf::SoundBufferRecorder::getBuffer,
	      policies<>(), "", "",
	      R"**(\brief Get the sound buffer containing the captured audio data

	      The sound buffer is valid only after the capture has ended.
	      This function provides a read-only access to the internal
	      sound buffer, but it can be copied if you need to
	      make any modification to it.

	      \return Read-only access to the sound buffer)**")

	];
    }
}

#ifndef CS_SOUND_RECORDER_HPP
#define CS_SOUND_RECORDER_HPP


#include <SFML/Audio/SoundRecorder.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::SoundRecorder> registerSoundRecorder()
{
  return
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
	 
    // ,def("sound-recorder/get-available-devices", &sf::SoundRecorder::getAvailableDevices,
    // 	 policies<>(), "", "",
    // 	 R"**(\brief Get a list of the names of all available audio capture devices

    // 	      This function returns a vector of strings, containing
    // 	      the names of all available audio capture devices.

    // 	      \return A vector of strings containing the names)**")

    // ,def("sound-recorder/get-default-device", &sf::SoundRecorder::getDefaultDevice,
    // 	 policies<>(), "", "",
    // 	 R"**(\brief Get the name of the default audio capture device

    // 	      This function returns the name of the default audio
    // 	      capture device. If none is available, an empty string
    // 	      is returned.

    // 	      \return The name of the default audio capture device)**")

    // ,def("sound-recorder/is-available", &sf::SoundRecorder::isAvailable,
    // 	 policies<>(), "", "",
    // 	 R"**(\brief Check if the system supports audio capture

    // 	      This function should always be called before using
    // 	      the audio capture features. If it returns false, then
    // 	      any attempt to use sf::SoundRecorder or one of its derived
    // 	      classes will fail.

    // 	      \return True if audio capture is supported, false otherwise)**")
    ;
}

#endif

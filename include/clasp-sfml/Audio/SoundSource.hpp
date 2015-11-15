#ifndef CS_SOUNDSOURCE_HPP
#define CS_SOUNDSOURCE_HPP

#include <SFML/Audio/SoundSource.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::SoundSource> registerSoundSource()
{
  return
    class_<sf::SoundSource>("sound-source", no_default_constructor)
    // .enum_<sf::SoundSource::Status>(core::lisp_intern("*ENUM-TO-SYMBOL-MAPPER*", "SFML"))
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

	      \see setAttenuation, getMinDistance)**");

}

#endif //CS_SOUNDSOURCE_HPP

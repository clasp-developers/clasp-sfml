#ifndef CS_LISTENER_HPP
#define CS_LISTENER_HPP

#include <SFML/Audio/Listener.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

// inline class_<sf::Listener> registerListener()
// {
//   return
    
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

	 //      \see setUpVector**)");

// }

#endif //CS_LISTENER_HPP

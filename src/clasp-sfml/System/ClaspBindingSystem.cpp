#include <SFML/System/Clock.hpp>
#include <SFML/System/InputStream.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/lispVector.h>
#include <clasp/core/vectorObjects.h>
#include <clasp/core/cons.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

#include <cstdlib>

#define EXPORT __attribute__((visibility("default")))

using namespace sf;

extern "C"
{
EXPORT
void CLASP_MAIN()
{
  using namespace clbind;
  package("SF")
    [
     class_<sf::Clock>("clock")

     .def("get-elapsed-time", &sf::Clock::getElapsedTime,
	  policies<>(), "", "",
	  R"**(\brief Get the elapsed time

	  This function returns the time elapsed since the last call
	  to restart() (or the construction of the instance if restart()
	  has not been called).

	  \return Time elapsed)**")

     .def("restart", &sf::Clock::restart,
	  policies<>(), "", "",
	  R"**(\brief Restart the clock

	  This function puts the time counter back to zero.
	  It also returns the time elapsed since the clock was started.

	  \return Time elapsed)**")

     ,class_<sf::InputStream>("input-stream", no_default_constructor)

     // .def("read", &sf::InputStream::read,
     // 	  policies<>(), "", "",
     // 	  R"**(\brief Read data from the stream

     // 	  After reading, the stream's reading position must be
     // 	  advanced by the amount of bytes read.

     // 	  \param data Buffer where to copy the read data
     // 	  \param size Desired number of bytes to read

     // 	  \return The number of bytes actually read, or -1 on error)**")

     // .def("seek", &sf::InputStream::seek,
     // 	  policies<>(), "", "",
     // 	  R"**(\brief Change the current reading position

     // 	  \param position The position to seek to, from the beginning

     // 	  \return The position actually sought to, or -1 on error)**")

     .def("tell", &sf::InputStream::tell,
	  policies<>(), "", "",
	  R"**(\brief Get the current reading position in the stream

	  \return The current position, or -1 on error.)**")

     .def("get-size", &sf::InputStream::getSize,
	  policies<>(), "", "",
	  R"**(\brief Return the size of the stream

	  \return The total number of bytes available in the stream, or -1 on error)**")

     ,class_<sf::Mutex>("mutex")

     .def("lock", &sf::Mutex::lock,
	  policies<>(), "", "",
	  R"**(\brief Lock the mutex

	  If the mutex is already locked in another thread,
	  this call will block the execution until the mutex
	  is released.

	  \see unlock)**")

     .def("unlock", &sf::Mutex::unlock,
	  policies<>(), "", "",
	  R"**(\brief Unlock the mutex

	  \see lock)**")

     // ,class_<sf::Lock>("lock")
     // .def_constructor("make-lock", constructor<sf::Mutex>())

     ,class_<sf::Time>("time")

     .def("as-seconds", &sf::Time::asSeconds,
	  policies<>(), "", "",
	  R"**(\brief Return the time value as a number of seconds

	  \return Time in seconds

	  \see asMilliseconds, asMicroseconds)**")

     .def("as-milliseconds", &sf::Time::asMilliseconds,
	  policies<>(), "", "",
	  R"**(\brief Return the time value as a number of milliseconds

	  \return Time in milliseconds

	  \see asSeconds, asMicroseconds)**")

     .def("as-microseconds", &sf::Time::asMicroseconds,
	  policies<>(), "", "",
	  R"**(\brief Return the time value as a number of microseconds

	  \return Time in microseconds

	  \see asSeconds, asMilliseconds)**")

     
   
     
     ];
}
}

#ifndef CLASP_SFML_CONTEXT_HPP
#define CLASP_SFML_CONTEXT_HPP

#include <SFML/Window/Context.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Context> registerContext()
{
  return
    class_<sf::Context>("context")
    .def("set-active", &sf::Context::setActive,
	 policies<>(), "", "",
	 R"**(\brief Activate or deactivate explicitly the context

		\param active True to activate, false to deactivate

		\return True on success, false on failure)**")

    //FIXME: missing ContextSettings
    ;
}

#endif //CLASP_SFML_CONTEXT_HPP

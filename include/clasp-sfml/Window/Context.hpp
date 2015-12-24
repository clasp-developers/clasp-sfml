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
	 R"**(Activate or deactivate explicitly the context
* Arguments
- ACTIVE :: to activate, false to deactivate
* Returns
True on success, false on failure)**")

    //FIXME: missing ContextSettings
    ;
}

#endif //CLASP_SFML_CONTEXT_HPP

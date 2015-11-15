#ifndef CLASP_SFML_MOUSE_HPP
#define CLASP_SFML_MOUSE_HPP


#include <SFML/Window/Mouse.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <>
  struct to_object<sf::Mouse::Button>
  {
    static core::T_sp convert(sf::Mouse::Button v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Mouse::Button>(v);
    }
  };

  template <>
  struct from_object<sf::Mouse::Button>
  {
    typedef sf::Mouse::Button DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
	{
	  if (sym.notnilp()) 
	    {
	      core::Symbol_sp converterSym = core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML");
	      core::SymbolToEnumConverter_sp converter = 
		converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	      this->_v = converter->enumForSymbol<sf::Mouse::Button>(sym);
	      return;
	    }
	}
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Mouse::Button") % _rep_(object) );
    }
  };

  template <>
  struct to_object<sf::Mouse::Wheel>
  {
    static core::T_sp convert(sf::Mouse::Wheel v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("SFML","*MOUSE-WHEEL-ENUM-MAPPER*");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Mouse::Wheel>(v);
    }
  };

  template <>
  struct from_object<sf::Mouse::Wheel>
  {
    typedef sf::Mouse::Wheel DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
	{
	  if (sym.notnilp()) 
	    {
	      core::Symbol_sp converterSym = core::lisp_intern("*MOUSE-WHEEL-ENUM-MAPPER*", "SFML");
	      core::SymbolToEnumConverter_sp converter = 
		converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	      this->_v = converter->enumForSymbol<sf::Mouse::Wheel>(sym);
	      return;
	    }
	}
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Mouse::Wheel") % _rep_(object) );
    }
  };

  
  
  
};


using namespace clbind;

inline class_<sf::Mouse> registerMouse()
{
  return
    class_<sf::Mouse>("mouse", no_default_constructor)
    .enum_<sf::Mouse::Button>(core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML"))
    [
     value("mouse-button/left", sf::Mouse::Button::Left),
     value("mouse-button/right", sf::Mouse::Button::Right),
     value("mouse-button/middle", sf::Mouse::Button::Middle),
     value("mouse-button/x-button1", sf::Mouse::Button::XButton1),
     value("mouse-button/x-button2", sf::Mouse::Button::XButton2),
     value("mouse-button/button-count", sf::Mouse::Button::ButtonCount)
     ]
    .enum_<sf::Mouse::Wheel>(core::lisp_intern("*MOUSE-WHEEL-ENUM-MAPPER*", "SFML"))
    [
     value("mouse/wheel/vertical-wheel", sf::Mouse::Wheel::VerticalWheel),
     value("mouse/wheel/horizontal-wheel", sf::Mouse::Wheel::HorizontalWheel)
     ];
}

inline scope registerMouseIsButtonPressed()
{
  return
    def("mouse/is-button-pressed", &sf::Mouse::isButtonPressed,
	policies<>(), "", "",
	R"**(\brief Check if a mouse button is pressed

     \param button Button to check

     \return True if the button is pressed, false otherwise)**");
}

inline scope registerMouseGetPosition()
{
  return
    def("mouse/get-position", (sf::Vector2i (*)())&sf::Mouse::getPosition,
	policies<>(), "", "",
	R"**(\brief Get the current position of the mouse in desktop coordinates

     This function returns the global position of the mouse
     cursor on the desktop.

     \return Current position of the mouse)**");
}

inline scope registerMouseGetPositionRelativeTo()
{
  return
    def("mouse/get-position-relative-to", (sf::Vector2i (*)(const sf::Window&))&sf::Mouse::getPosition,
	policies<>(), "", "",
	R"**(\brief Get the current position of the mouse in window coordinates

     This function returns the current position of the mouse
     cursor, relative to the given window.

     \param relativeTo Reference window

     \return Current position of the mouse)**");
}

inline scope registerMouseSetPosition()
{
  return
    def("mouse/set-position", (void (*)(const sf::Vector2i&))&sf::Mouse::setPosition,
	policies<>(), "", "",
	R"**(\brief Set the current position of the mouse in desktop coordinates

     This function sets the global position of the mouse
     cursor on the desktop.

     \param position New position of the mouse)**");
}

inline scope registerMouseSetPositionRelativeTo()
{
  return
    def("mouse/set-position-relative", (void (*)(const sf::Vector2i&, const sf::Window&))&sf::Mouse::setPosition,
	policies<>(), "", "",
	R"**(\brief Set the current position of the mouse in window coordinates

     This function sets the current position of the mouse
     cursor, relative to the given window.

     \param position New position of the mouse
     \param relativeTo Reference window)**");
}



#endif //CLASP_SFML_MOUSE_HPP

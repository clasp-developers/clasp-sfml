#ifndef CLASP_SFML_JOYSTICK_HPP
#define CLASP_SFML_JOYSTICK_HPP

#include <SFML/Window/Joystick.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  
  template <>
  struct to_object<sf::Joystick::Axis>
  {
    static core::T_sp convert(sf::Joystick::Axis v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*JOYSTICK-AXIS-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Joystick::Axis>(v);
    }
  };

  template <>
  struct from_object<sf::Joystick::Axis>
  {
    typedef sf::Joystick::Axis DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
	{
	  if (sym.notnilp()) 
	    {
	      core::Symbol_sp converterSym = core::lisp_intern("*JOYSTICK-AXIS-ENUM-MAPPER*", "SFML");
	      core::SymbolToEnumConverter_sp converter = 
		converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	      this->_v = converter->enumForSymbol<sf::Joystick::Axis>(sym);
	      return;
	    }
	}
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Joystick::Axis") % _rep_(object) );
    }
  };
  
};


using namespace clbind;

inline class_<sf::Joystick> registerJoystick()
{
  return
    class_<sf::Joystick>("joystick")
    .enum_<sf::Joystick::Axis>(core::lisp_intern("*JOYSTICK-AXIS-ENUM-MAPPER*", "SFML"))
    [
     value("joystick-axis/x", sf::Joystick::Axis::X),
     value("joystick-axis/y", sf::Joystick::Axis::Y),
     value("joystick-axis/z", sf::Joystick::Axis::Z),
     value("joystick-axis/r", sf::Joystick::Axis::R),
     value("joystick-axis/u", sf::Joystick::Axis::U),
     value("joystick-axis/v", sf::Joystick::Axis::V),
     value("joystick-axis/pov-x", sf::Joystick::Axis::PovX),
     value("joystick-axis/pov-y", sf::Joystick::Axis::PovY)
     ]

    //FIXME: Missing struct identification
    ;
}

inline scope registerJoystickIsConnected()
{
  return
    def("joystick/is-connected", &sf::Joystick::isConnected,
	policies<>(), "", "",
	R"**(Check if a joystick is connected
* Arguments
- JOYSTICK :: of the joystick to check
* Returns
True if the joystick is connected, false otherwise)**");
}

inline scope registerJoystickGetButtonCount()
{
  return
    def("joystick/get-button-count", &sf::Joystick::getButtonCount,
	policies<>(), "", "",
	R"**(Return the number of buttons supported by a joystick
If the joystick is not connected, this function returns 0.
* Arguments
- JOYSTICK :: of the joystick
* Returns
 Number of buttons supported by the joystick)**");
}

inline scope registerJoystickHasAxis()
{
  return
    def("joystick/has-axis", &sf::Joystick::hasAxis,
	policies<>(), "", "",
	R"**(Check if a joystick supports a given axis
If the joystick is not connected, this function returns false.
* Arguments
- JOYSTICK :: of the joystick
- AXIS :: Axis to check
* Returns
True if the joystick supports the axis, false otherwise)**");
}

inline scope registerJoystickIsButtonPressed()
{
  return
    def("joystick/is-button-pressed", &sf::Joystick::isButtonPressed,
	policies<>(), "", "",
	R"**(Check if a joystick button is pressed
If the joystick is not connected, this function returns false.
* Arguments
- JOYSTICK :: of the joystick
- BUTTON :: Button to check
* Returns
True if the button is pressed, false otherwise)**");
}

inline scope registerJoystickGetAxisPosition()
{
  return
    def("joystick/get-axis-position", &sf::Joystick::getAxisPosition,
	policies<>(), "", "",
	R"**(Get the current position of a joystick axis
If the joystick is not connected, this function returns 0.
* Arguments
- JOYSTICK :: of the joystick
- AXIS :: Axis to check
* Returns
Current position of the axis, in range [-100 .. 100])**");
}

inline scope registerJoystickGetIdentification()
{
  return
    def("joystick/get-identification", &sf::Joystick::getIdentification,
	policies<>(), "", "",
	R"**(Get the joystick information
* Arguments
- JOYSTICK :: of the joystick
* Returns
Structure containing joystick information.)**");
}

inline scope registerJoystickUpdate()
{
  return
    def("joystick/update", &sf::Joystick::update,
	policies<>(), "", "",
	R"**(Update the states of all joysticks
* Description
This function is used internally by SFML, so you normally
don't have to call it explicitly. However, you may need to
call it if you have no window yet (or no window at all):
in this case the joystick states are not updated automatically.)**");
}



#endif

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
#endif

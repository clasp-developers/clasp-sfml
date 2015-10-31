#ifndef CLASP_SFML_SENSOR_HPP
#define CLASP_SFML_SENSOR_HPP


#include <SFML/Window/Sensor.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <>
  struct to_object<sf::Sensor::Type>
  {
    static core::T_sp convert(sf::Sensor::Type v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*SENSOR-TYPE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Sensor::Type>(v);
    }
  };

  template <>
  struct from_object<sf::Sensor::Type>
  {
    typedef sf::Sensor::Type DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
      {
	if (sym.notnilp()) 
        {
	  core::Symbol_sp converterSym = core::lisp_intern("*SENSOR-TYPE-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = 
            converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Sensor::Type>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Sensor::Type") % _rep_(object) );
    }
  };

  

};

#endif //CLASP_SFML_SENSOR_HPP

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


using namespace clbind;

inline class_<sf::Sensor> registerSensor()
{
  return
    class_<sf::Sensor>("sensor", no_default_constructor)

    .enum_<sf::Sensor::Type>(core::lisp_intern("*SENSOR-TYPE-ENUM-MAPPER*", "SFML"))
    [
     value("sensor-type/accelerometer", sf::Sensor::Type::Accelerometer),
     value("sensor-type/gyroscope", sf::Sensor::Type::Gyroscope),
     value("sensor-type/magnetometer", sf::Sensor::Type::Magnetometer),
     value("sensor-type/gravity", sf::Sensor::Type::Gravity),
     value("sensor-type/user-acceleration", sf::Sensor::Type::UserAcceleration),
     value("sensor-type/orientation", sf::Sensor::Type::Orientation),
     value("sensor-type/count", sf::Sensor::Type::Count)
     ];
}


inline scope registerSensorIsAvailable()
{
  return
    def("sensor/is-available", &sf::Sensor::isAvailable,
	policies<>(), "", "",
	R"**(Check if a sensor is available on the underlying platform
* Arguments
- SENSOR :: to check
* Returns
True if the sensor is available, false otherwise)**");
}

inline scope registerSensorSetEnabled()
{
  return
    def("sensor/set-enabled", &sf::Sensor::setEnabled,
	policies<>(), "", "",
	R"**(Enable or disable a sensor
* Description
All sensors are disabled by default, to avoid consuming too
much battery power. Once a sensor is enabled, it starts
sending events of the corresponding type.

This function does nothing if the sensor is unavailable.
* Arguments
- SENSOR :: Sensor to enable
- ENABLED :: to enable, false to disable)**");
}

inline scope registerSensorGetValue()
{
  return
    def("sensor/get-value", &sf::Sensor::getValue,
	policies<>(), "", "",
	R"**(Get the current sensor value
* Arguments
- SENSOR :: to read
* Returns
The current sensor value)**");
}



#endif //CLASP_SFML_SENSOR_HPP

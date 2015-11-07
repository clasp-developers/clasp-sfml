#ifndef CLASP_SFML_EVENT_HPP
#define CLASP_SFML_EVENT_HPP

#include <SFML/Window/Event.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  
  template <>
  struct to_object<sf::Event::EventType>
  {
    static core::T_sp convert(sf::Event::EventType v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Event::EventType>(v);
    }
  };

 
  template <>
  struct to_object<sf::Event::EventType, adopt_pointer>
  {
    static core::T_sp convert(sf::Event::EventType v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Event::EventType>(v);
    }
  };
  
  template <>
  struct from_object<sf::Event::EventType>
  {
    typedef sf::Event::EventType DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
	if ( sym.notnilp() ) {
	  core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Event::EventType>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Event::EventType") % _rep_(object) );
    }
  };

}; //end namespace translate


using namespace clbind;

inline class_<sf::Event> registerEvent()
{
  return
    class_<sf::Event>("event")
    . def_constructor("make-event",constructor<>())	   
    . enum_<sf::Event::EventType>(core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML"))
    [ value("Closed",sf::Event::EventType::Closed) 
      , value("Resized",sf::Event::EventType::Resized)                
      , value("LostFocus",sf::Event::EventType::LostFocus)              
      , value("GainedFocus",sf::Event::EventType::GainedFocus)            
      , value("TextEntered",sf::Event::EventType::TextEntered)            
      , value("KeyPressed",sf::Event::EventType::KeyPressed)             
      , value("KeyReleased",sf::Event::EventType::KeyReleased)            
      , value("MouseWheelMoved",sf::Event::EventType::MouseWheelMoved)        
      , value("MouseButtonPressed",sf::Event::EventType::MouseButtonPressed)     
      , value("MouseButtonReleased",sf::Event::EventType::MouseButtonReleased)    
      , value("MouseMoved",sf::Event::EventType::MouseMoved)             
      , value("MouseEntered",sf::Event::EventType::MouseEntered)           
      , value("MouseLeft",sf::Event::EventType::MouseLeft)              
      , value("JoystickButtonPressed",sf::Event::EventType::JoystickButtonPressed)  
      , value("JoystickButtonReleased",sf::Event::EventType::JoystickButtonReleased) 
      , value("JoystickMoved",sf::Event::EventType::JoystickMoved)          
      , value("JoystickConnected",sf::Event::EventType::JoystickConnected)      
      , value("JoystickDisconnected",sf::Event::EventType::JoystickDisconnected)   
      , value("TouchBegan",sf::Event::EventType::TouchBegan)             
      , value("TouchMoved",sf::Event::EventType::TouchMoved)             
      , value("TouchEnded",sf::Event::EventType::TouchEnded)             
      , value("SensorChanged",sf::Event::EventType::SensorChanged)          
      , value("Count",sf::Event::EventType::Count)
      ]
    .def_readonly("type", &sf::Event::type)
    .def_readonly("size", &sf::Event::size)
    .def_readonly("key", &sf::Event::key)
    .def_readonly("text", &sf::Event::text)
    .def_readonly("mouse-move", &sf::Event::mouseMove)
    .def_readonly("mouse-button", &sf::Event::mouseButton)
    .def_readonly("mouse-wheel", &sf::Event::mouseWheel)
    .def_readonly("joystick-move", &sf::Event::joystickMove)
    .def_readonly("joystick-button", &sf::Event::joystickButton)
    .def_readonly("joystick-connect", &sf::Event::joystickConnect)
    .def_readonly("touch", &sf::Event::touch)
    .def_readonly("sensor", &sf::Event::sensor);
}

inline class_<sf::Event::SizeEvent> registerSizeEvent()
{
  return
    class_<sf::Event::SizeEvent>("event-size-event")
    .def_readonly("width", &sf::Event::SizeEvent::width)
    .def_readonly("height", &sf::Event::SizeEvent::height);
}

inline class_<sf::Event::KeyEvent> registerKeyEvent()
{
  return
    class_<sf::Event::KeyEvent>("event-key-event")
    .def_readonly("code", &sf::Event::KeyEvent::code)
    .def_readonly("alt", &sf::Event::KeyEvent::alt)
    .def_readonly("control", &sf::Event::KeyEvent::control)
    .def_readonly("shift", &sf::Event::KeyEvent::shift)
    .def_readonly("system", &sf::Event::KeyEvent::system);
}

inline class_<sf::Event::TextEvent> registerTextEvent()
{
  return
    class_<sf::Event::TextEvent>("event-text-event")
    .def_readonly("unicode", &sf::Event::TextEvent::unicode);
}

inline class_<sf::Event::MouseMoveEvent> registerMouseMoveEvent()
{
  return
    class_<sf::Event::MouseMoveEvent>("event-mouse-move-event")
    .def_readonly("x-mouse-move-event", &sf::Event::MouseMoveEvent::x)
    .def_readonly("y-mouse-move-event", &sf::Event::MouseMoveEvent::y);
}

inline class_<sf::Event::MouseButtonEvent> registerMouseButtonEvent()
{
  return
    class_<sf::Event::MouseButtonEvent>("event-mouse-button-event")
    .def_readonly("button", &sf::Event::MouseButtonEvent::button)
    .def_readonly("x-mouse-button-event", &sf::Event::MouseButtonEvent::x)
    .def_readonly("y-mouse-button-event", &sf::Event::MouseButtonEvent::y);
}

inline class_<sf::Event::MouseWheelEvent> registerMouseWheelEvent()
{
  return
    class_<sf::Event::MouseWheelEvent>("event-mouse-wheel-event")
    .def_readonly("delta", &sf::Event::MouseWheelEvent::delta)
    .def_readonly("x-mouse-wheel-event", &sf::Event::MouseWheelEvent::x)
    .def_readonly("y-mouse-wheel-event", &sf::Event::MouseWheelEvent::y);
}

inline class_<sf::Event::JoystickConnectEvent> registerJoystickConnectEvent()
{
  return
    class_<sf::Event::JoystickConnectEvent>("event-joystick-connect-event")
    .def_readonly("joystick-id", &sf::Event::JoystickConnectEvent::joystickId);
}

inline class_<sf::Event::JoystickMoveEvent> registerJoystickMoveEvent()
{
  return
    class_<sf::Event::JoystickMoveEvent>("event-joystick-move-event")
    .def_readonly("joystick-id", &sf::Event::JoystickMoveEvent::joystickId)
    .def_readonly("axis", &sf::Event::JoystickMoveEvent::axis)
    .def_readonly("position", &sf::Event::JoystickMoveEvent::position);
}

inline class_<sf::Event::JoystickButtonEvent> registerJoystickButtonEvent()
{
  return
    class_<sf::Event::JoystickButtonEvent>("event-joystick-button-event")
    .def_readonly("joystick-id", &sf::Event::JoystickButtonEvent::joystickId)
    .def_readonly("button", &sf::Event::JoystickButtonEvent::button);
}

inline class_<sf::Event::TouchEvent> registerTouchEvent()
{
  return
    class_<sf::Event::TouchEvent>("event-touch-event")
    .def_readonly("x-touch-event", &sf::Event::TouchEvent::x)
    .def_readonly("y-touch-event", &sf::Event::TouchEvent::y);
}

inline class_<sf::Event::SensorEvent> registerSensorEvent()
{
  return
    class_<sf::Event::SensorEvent>("event-sensor-event")
    .def_readonly("x-sensor-event", &sf::Event::SensorEvent::x)
    .def_readonly("y-sensor-event", &sf::Event::SensorEvent::y)
    .def_readonly("z-sensor-event", &sf::Event::SensorEvent::z);
}
	   


#endif //CLASP_SFML_EVENT_HPP

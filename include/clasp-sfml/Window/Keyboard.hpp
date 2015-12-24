#ifndef CLASP_SFML_KEYBOARD_HPP
#define CLASP_SFML_KEYBOARD_HPP

#include <SFML/Window/Keyboard.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <>
  struct to_object<sf::Keyboard::Key>
  {
    static core::T_sp convert(sf::Keyboard::Key v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Keyboard::Key>(v);
    }
  };

  
  template <>
  struct to_object<sf::Keyboard::Key, adopt_pointer>
  {
    static core::T_sp convert(sf::Keyboard::Key v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Keyboard::Key>(v);
    }
  };

  
  template <>
  struct from_object<sf::Keyboard::Key>
  {
    typedef sf::Keyboard::Key DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
	{
	  if (sym.notnilp()) 
	    {
	      core::Symbol_sp converterSym = core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
	      core::SymbolToEnumConverter_sp converter = 
		converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	      this->_v = converter->enumForSymbol<sf::Keyboard::Key>(sym);
	      return;
	    }
	}
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Keyboard::Key") % _rep_(object) );
    }
  };
  
};


using namespace clbind;

inline class_<sf::Keyboard> registerKeyboard()
{
  return

    class_<sf::Keyboard>("keybaord", no_default_constructor)
    .enum_<sf::Keyboard::Key>(core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML"))
    [
     value("keyboard-key/unknown", sf::Keyboard::Key::Unknown),
     value("keyboard-key/a", sf::Keyboard::Key::A),
     value("keyboard-key/b", sf::Keyboard::Key::B),
     value("keyboard-key/c", sf::Keyboard::Key::C),
     value("keyboard-key/d", sf::Keyboard::Key::D),
     value("keyboard-key/e", sf::Keyboard::Key::E),
     value("keyboard-key/f", sf::Keyboard::Key::F),
     value("keyboard-key/g", sf::Keyboard::Key::G),
     value("keyboard-key/h", sf::Keyboard::Key::H),
     value("keyboard-key/i", sf::Keyboard::Key::I),
     value("keyboard-key/j", sf::Keyboard::Key::J),
     value("keyboard-key/k", sf::Keyboard::Key::K),
     value("keyboard-key/l", sf::Keyboard::Key::L),
     value("keyboard-key/m", sf::Keyboard::Key::M),
     value("keyboard-key/n", sf::Keyboard::Key::N),
     value("keyboard-key/o", sf::Keyboard::Key::O),
     value("keyboard-key/p", sf::Keyboard::Key::P),
     value("keyboard-key/q", sf::Keyboard::Key::Q),
     value("keyboard-key/r", sf::Keyboard::Key::R),
     value("keyboard-key/s", sf::Keyboard::Key::S),
     value("keyboard-key/t", sf::Keyboard::Key::T),
     value("keyboard-key/u", sf::Keyboard::Key::U),
     value("keyboard-key/v", sf::Keyboard::Key::V),
     value("keyboard-key/w", sf::Keyboard::Key::W),
     value("keyboard-key/x", sf::Keyboard::Key::X),
     value("keyboard-key/y", sf::Keyboard::Key::Y),
     value("keyboard-key/z", sf::Keyboard::Key::Z),
     value("keyboard-key/num0", sf::Keyboard::Key::Num0),
     value("keyboard-key/num1", sf::Keyboard::Key::Num1),
     value("keyboard-key/num2", sf::Keyboard::Key::Num2),
     value("keyboard-key/num3", sf::Keyboard::Key::Num3),
     value("keyboard-key/num4", sf::Keyboard::Key::Num4),
     value("keyboard-key/num5", sf::Keyboard::Key::Num5),
     value("keyboard-key/num6", sf::Keyboard::Key::Num6),
     value("keyboard-key/num7", sf::Keyboard::Key::Num7),
     value("keyboard-key/num8", sf::Keyboard::Key::Num8),
     value("keyboard-key/num9", sf::Keyboard::Key::Num9),
     value("keyboard-key/escape", sf::Keyboard::Key::Escape),
     value("keyboard-key/l-control", sf::Keyboard::Key::LControl),
     value("keyboard-key/l-shift", sf::Keyboard::Key::LShift),
     value("keyboard-key/l-alt", sf::Keyboard::Key::LAlt),
     value("keyboard-key/l-system", sf::Keyboard::Key::LSystem),
     value("keyboard-key/r-control", sf::Keyboard::Key::RControl),
     value("keyboard-key/r-shift", sf::Keyboard::Key::RShift),
     value("keyboard-key/r-alt", sf::Keyboard::Key::RAlt),
     value("keyboard-key/r-system", sf::Keyboard::Key::RSystem),
     value("keyboard-key/menu", sf::Keyboard::Key::Menu),
     value("keyboard-key/l-bracket", sf::Keyboard::Key::LBracket),
     value("keyboard-key/r-bracket", sf::Keyboard::Key::RBracket),
     value("keyboard-key/semi-colon", sf::Keyboard::Key::SemiColon),
     value("keyboard-key/comma", sf::Keyboard::Key::Comma),
     value("keyboard-key/period", sf::Keyboard::Key::Period),
     value("keyboard-key/quote", sf::Keyboard::Key::Quote),
     value("keyboard-key/slash", sf::Keyboard::Key::Slash),
     value("keyboard-key/back-slash", sf::Keyboard::Key::BackSlash),
     value("keyboard-key/tilde", sf::Keyboard::Key::Tilde),
     value("keyboard-key/equal", sf::Keyboard::Key::Equal),
     value("keyboard-key/dash", sf::Keyboard::Key::Dash),
     value("keyboard-key/space", sf::Keyboard::Key::Space),
     value("keyboard-key/return", sf::Keyboard::Key::Return),
     value("keyboard-key/back-space", sf::Keyboard::Key::BackSpace),
     value("keyboard-key/tab", sf::Keyboard::Key::Tab),
     value("keyboard-key/page-up", sf::Keyboard::Key::PageUp),
     value("keyboard-key/page-down", sf::Keyboard::Key::PageDown),
     value("keyboard-key/end", sf::Keyboard::Key::End),
     value("keyboard-key/home", sf::Keyboard::Key::Home),
     value("keyboard-key/insert", sf::Keyboard::Key::Insert),
     value("keyboard-key/delete", sf::Keyboard::Key::Delete),
     value("keyboard-key/add", sf::Keyboard::Key::Add),
     value("keyboard-key/subtract", sf::Keyboard::Key::Subtract),
     value("keyboard-key/multiply", sf::Keyboard::Key::Multiply),
     value("keyboard-key/divide", sf::Keyboard::Key::Divide),
     value("keyboard-key/left", sf::Keyboard::Key::Left),
     value("keyboard-key/right", sf::Keyboard::Key::Right),
     value("keyboard-key/up", sf::Keyboard::Key::Up),
     value("keyboard-key/down", sf::Keyboard::Key::Down),
     value("keyboard-key/numpad0", sf::Keyboard::Key::Numpad0),
     value("keyboard-key/numpad1", sf::Keyboard::Key::Numpad1),
     value("keyboard-key/numpad2", sf::Keyboard::Key::Numpad2),
     value("keyboard-key/numpad3", sf::Keyboard::Key::Numpad3),
     value("keyboard-key/numpad4", sf::Keyboard::Key::Numpad4),
     value("keyboard-key/numpad5", sf::Keyboard::Key::Numpad5),
     value("keyboard-key/numpad6", sf::Keyboard::Key::Numpad6),
     value("keyboard-key/numpad7", sf::Keyboard::Key::Numpad7),
     value("keyboard-key/numpad8", sf::Keyboard::Key::Numpad8),
     value("keyboard-key/numpad9", sf::Keyboard::Key::Numpad9),
     value("keyboard-key/f1", sf::Keyboard::Key::F1),
     value("keyboard-key/f2", sf::Keyboard::Key::F2),
     value("keyboard-key/f3", sf::Keyboard::Key::F3),
     value("keyboard-key/f4", sf::Keyboard::Key::F4),
     value("keyboard-key/f5", sf::Keyboard::Key::F5),
     value("keyboard-key/f6", sf::Keyboard::Key::F6),
     value("keyboard-key/f7", sf::Keyboard::Key::F7),
     value("keyboard-key/f8", sf::Keyboard::Key::F8),
     value("keyboard-key/f9", sf::Keyboard::Key::F9),
     value("keyboard-key/f10", sf::Keyboard::Key::F10),
     value("keyboard-key/f11", sf::Keyboard::Key::F11),
     value("keyboard-key/f12", sf::Keyboard::Key::F12),
     value("keyboard-key/f13", sf::Keyboard::Key::F13),
     value("keyboard-key/f14", sf::Keyboard::Key::F14),
     value("keyboard-key/f15", sf::Keyboard::Key::F15),
     value("keyboard-key/pause", sf::Keyboard::Key::Pause)
     ];
}

inline scope registerKeyboardIsKeyPressed()
{
  return
    def("keyboard/is-key-pressed", &sf::Keyboard::isKeyPressed,
	policies<>(), "", "",
	R"**(Check if a key is pressed
* Arguments
- KEY :: to check
* Returns
True if the key is pressed, false otherwise)**");
}

inline scope registerKeyboardSetVirtualKeyboardVisible()
{
  return
    def("keyboard/set-virtual-keyboard-visible", &sf::Keyboard::setVirtualKeyboardVisible,
	policies<>(), "", "",
	R"**(Show or hide the virtual keyboard
* Description
Warning: the virtual keyboard is not supported on all
systems. It will typically be implemented on mobile OSes
Android, iOS) but not on desktop OSes (Windows, Linux, ...).

If the virtual keyboard is not available, this function does
nothing.
* Arguments
- VISIBLE :: to show, false to hide)**");
}



#endif //CLASP_SFML_KEYBOARD_HPP

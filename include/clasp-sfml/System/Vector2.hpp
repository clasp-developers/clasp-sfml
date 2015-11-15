#ifndef CLASP_SFML_VECTOR2_HPP
#define CLASP_SFML_VECTOR2_HPP

#include <SFML/System/Vector2.hpp>

#include <clasp/clbind/clbind.h>

#include <string>

namespace translate
{
  template <typename T> struct from_object<const sf::Vector2<T> &>
  {
    typedef sf::Vector2<T> DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( core::List_sp list = obj.asOrNull<core::List_V>() )
      {
	// Translate a CONS list into a Vector
	this->_v.x = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.y = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      }
      else
      {
	SIMPLE_ERROR(BF("Could not convert %s to sf::Vector2") % core::_rep_(obj));
      }
    }
  };
  
  template <typename T> struct from_object<sf::Vector2<T>>
  {
    typedef sf::Vector2<T> DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( core::List_sp list = obj.asOrNull<core::List_V>() )
      {
	// Translate a CONS list into a Vector
	this->_v.x = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.y = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      }
      else
      {
	SIMPLE_ERROR(BF("Could not convert %s to sf::Vector2") % core::_rep_(obj));
      }
    }
  };

  template <> struct from_object<const sf::Vector2f &>
  {
    typedef sf::Vector2f DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( core::List_sp list = obj.asOrNull<core::List_V>() )
      {
	// Translate a CONS list into a Vector
	this->_v.x = clasp_to_float(gc::As<core::Float_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.y = clasp_to_float(gc::As<core::Float_sp>(oCar(list)));
      }
      else
      {
	SIMPLE_ERROR(BF("Could not convert %s to sf::Vector2") % core::_rep_(obj));
      }
    }
  };
  
}; //end namespace translate


using namespace clbind;

template<typename T>
inline class_<sf::Vector2<T>> registerVector2(std::string tname)
{
  return
    class_<sf::Vector2<T>>((tname + "-vector2").c_str(), no_default_constructor)
    .def_constructor(("make-" + tname + "vector2").c_str(), constructor<T, T>(),
	 policies<>(), "", "",
	 R"**(\brief Construct the vector from its coordinates

	 \param X X coordinate
	 \param Y Y coordinate)**")
    //FIXME: use tname once def_readwrite is fixed with std::string
    .def_readwrite("vector-x", &sf::Vector2<T>::x)
    .def_readwrite("vector-y", &sf::Vector2<T>::y);
}

#endif //CLASP_SFML_VECTOR2_HPP

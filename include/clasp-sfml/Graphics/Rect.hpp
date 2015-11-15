#ifndef CLASP_SFML_RECT_HPP
#define CLASP_SFML_RECT_HPP

#include <SFML/Graphics/Rect.hpp>

#include <clasp/clbind/clbind.h>
#include <string>
#include <stdio.h>

namespace translate
{

  template <> struct from_object<const sf::IntRect&>
  {
    typedef sf::IntRect DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::IntRect") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate

using namespace clbind;

template<typename T>
inline class_<sf::Rect<T>> registerRect(std::string tname)
{
  //std::string tname = typeid(T).name();
  return
    class_<sf::Rect<T>>((tname + "-rect").c_str(), no_default_constructor)
    .def_constructor(("make-" + tname + "-rect").c_str(), constructor<T, T, T, T>(),
     policies<>(), "", "",
     R"**(\brief Construct the rectangle from its coordinates

     Be careful, the last two parameters are the width
     and height, not the right and bottom coordinates!

     \param rectLeft   Left coordinate of the rectangle
     \param rectTop    Top coordinate of the rectangle
     \param rectWidth  Width of the rectangle
     \param rectHeight Height of the rectangle)**")
    //FIXME: Three other constructors missing
    .def((tname + "-rect-contains-xy").c_str(), (bool (sf::Rect<T>::*)(T, T) const)&sf::Rect<T>::contains,
    	 policies<>(), "", "",
    	 R"**(\brief Check if a point is inside the rectangle's area

    	 \param x X coordinate of the point to test
    	 \param y Y coordinate of the point to test

    	 \return True if the point is inside, false otherwise

    	 \see intersects)**")
    .def((tname + "-rect-contains-point").c_str(), (bool (sf::Rect<T>::*)(const sf::Vector2<T>&) const)&sf::Rect<T>::contains,
    	 policies<>(), "", "",
    	 R"**(\brief Check if a point is inside the rectangle's area

    	 \param point Point to test

    	 \return True if the point is inside, false otherwise

    	 \see intersects)**")

    .def((tname + "-rect-intersects").c_str(), (bool (sf::Rect<T>::*)(const sf::Rect<T>&) const)&sf::Rect<T>::intersects,
    	 policies<>(), "", "",
    	 R"**(\brief Check the intersection between two rectangles

    	 \param rectangle Rectangle to test

    	 \return True if rectangles overlap, false otherwise

    	 \see contains)**")

    .def((tname + "-rect-intersects-area").c_str(), (bool (sf::Rect<T>::*)(const sf::Rect<T>&, sf::Rect<T>&) const)&sf::Rect<T>::intersects,
    	 policies<>(), "", "",
    	 R"**(\brief Check the intersection between two rectangles

    	 This overload returns the overlapped rectangle in the
    	 \a intersection parameter.

    	 \param rectangle    Rectangle to test
    	 \param intersection Rectangle to be filled with the intersection

    	 \return True if rectangles overlap, false otherwise

    	 \see contains)**")
    .def_readwrite((tname + "-rect-left").c_str(), &sf::Rect<T>::left)
    .def_readwrite((tname + "-rect-top").c_str(), &sf::Rect<T>::top)
    .def_readwrite((tname + "-rect-width").c_str(), &sf::Rect<T>::width)
    .def_readwrite((tname + "-rect-height").c_str(), &sf::Rect<T>::height)
    ;
}

#endif //CLASP_SFML_RECT_HPP

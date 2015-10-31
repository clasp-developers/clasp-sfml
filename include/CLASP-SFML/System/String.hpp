#ifndef CLASP_BINDING_STRING_HPP
#define CLASP_BINDING_STRING_HPP

#include <SFML/System/String.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
    
  template <>
  struct from_object<sf::String>
  {
    typedef sf::String DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };
  
  
  template <>
  struct from_object<sf::String&>
  {
    typedef sf::String DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };

  
  template <>
  struct from_object<const sf::String&>
  {
    typedef sf::String DeclareType;
    DeclareType _v;
    from_object(T_P o) : _v(str_get(o)) {};
  };

  
  // template <>
  // struct from_object<sf::String&,std::false_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v("") {};
  // };
  
}; //end namespace translate

#endif //CLASP_BINDING_STRING_HPP

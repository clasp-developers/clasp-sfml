#ifndef CLASP_SFML_GENERAL_TRANSLATORS_H
#define CLASP_SFML_GENERAL_TRANSLATORS_H

#include <limits>

#include <clasp/clbind/clbind.h>

namespace translate
{
    
  template <>
  struct from_object<const void *>
  {
    typedef	const void* DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if (core::Pointer_sp opointer = obj.asOrNull<core::Pointer_O>())
      {
        _v = opointer->ptr();
      }
      else
      {
        SIMPLE_ERROR(BF("Could not convert %s to const void*") % core::_rep_(obj));
      }
    };
  };

  
  template <>
  struct from_object<float>
  {
    typedef float DeclareType;
    DeclareType _v;
    from_object(core::T_sp o) : _v(clasp_to_float(gc::As<core::Number_sp>(o))){}
  };

  
  template <>
  struct to_object<float>
  {
    typedef float GivenType;
    static core::T_sp convert(GivenType v)
    {
      core::DoubleFloat_sp oi = core::DoubleFloat_O::create(v);
      return(oi);
    }
  };



  template <>
  struct from_object<unsigned char>
  {
    typedef unsigned char DeclareType;
    DeclareType _v;
    from_object(T_P o) :_v(clasp_toUint8(gc::As<core::Number_sp>(o))){}
  };
  
  template <>
  struct to_object<unsigned char>
  {
    typedef unsigned char GivenType;
    static core::T_sp convert(GivenType v)
    {
      core::Integer_sp oi = core::Integer_O::create((gc::Fixnum)v);
      return oi;
    }
  };


  
  template <>
  struct from_object<short int>
  {
    typedef short int DeclareType;
    DeclareType _v;
    from_object(T_P o)
    {
      if (o.fixnump()) {
	_v = o.asFixnum();
	return;
      } else if (core::Integer_sp i = o.asOrNull<core::Integer_O>()) {
	_v = i->as_int_();
	return;
      }
      SIMPLE_ERROR(BF("Add support to convert type: %s to short int") % _rep_(o));
    }
  };

    
}

#endif //CLASP_SFML_GENERAL_TRANSLATORS_H

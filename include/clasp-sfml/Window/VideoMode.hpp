#ifndef CLASP_BINDING_VIDEO_MODE_HPP
#define CLASP_BINDING_VIDEO_MODE_HPP

#include <SFML/Window/VideoMode.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  template <> struct from_object<sf::VideoMode>
  {
    typedef sf::VideoMode DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() )	{
	this->_v.width = 800;
	this->_v.height = 600;
	this->_v.bitsPerPixel = 32;
      } else if ( core::List_sp list = obj.asOrNull<core::List_V>() ) {
	// Translate a CONS list into a VideoMode
	this->_v.width = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.height = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.bitsPerPixel = (list.nilp())?
	  32 : clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      } else {
	SIMPLE_ERROR(BF("Could not convert %s to sf::VideoMode") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate


using namespace clbind;

inline class_<sf::VideoMode> registerVideoMode()
{
  return
    class_<sf::VideoMode>("video-mode")
    .def_constructor("make-video-mode", constructor<unsigned int, unsigned int, unsigned int>())
    .def("is-valid", &sf::VideoMode::isValid,
	 policies<>(), "", "",
	 R"**(\brief Tell whether or not the video mode is valid

		The validity of video modes is only relevant when using
		fullscreen windows; otherwise any video mode can be used
		with no restriction.

		\return True if the video mode is valid for fullscreen mode)**")
    
    .def_readonly("width", &sf::VideoMode::width)
    .def_readonly("height", &sf::VideoMode::height)
    .def_readonly("bits-per-pixel", &sf::VideoMode::bitsPerPixel);   
}

inline scope registerVideoModeGetDesktopMode()
{
  return
    def("video-mode/get-desktop-mode", &sf::VideoMode::getDesktopMode,
	policies<>(), "", "",
	R"**(\brief Get the current desktop video mode

     \return Current desktop video mode)**");
}

inline scope registerVideoModeGetFullscreenModes()
{
  return
    def("video-mode/get-fullscreen-modes", &sf::VideoMode::getFullscreenModes,
	policies<>(), "", "",
	R"**(\brief Retrieve all the video modes supported in fullscreen mode

     When creating a fullscreen window, the video mode is restricted
     to be compatible with what the graphics driver and monitor
     support. This function returns the complete list of all video
     modes that can be used in fullscreen mode.
     The returned array is sorted from best to worst, so that
     the first element will always give the best mode (higher
     width, height and bits-per-pixel).

     \return Array containing all the supported fullscreen modes)**");
}



#endif //CLASP_BINDING_VIDEO_MODE_HPP

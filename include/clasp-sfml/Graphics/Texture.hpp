#ifndef CLASP_SFML_TEXTURE_HPP
#define CLASP_SFML_TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/InputStream.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  template <>
  struct to_object<sf::Texture::CoordinateType>
  {
    static core::T_sp convert(sf::Texture::CoordinateType v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("SFML","*TEXTURE-COORDINATETYPE-ENUM-MAPPER*");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Texture::CoordinateType>(v);
    }
  };

  template <>
  struct from_object<sf::Texture::CoordinateType>
  {
    typedef sf::Texture::CoordinateType DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
	{
	  if (sym.notnilp()) 
	    {
	      core::Symbol_sp converterSym = core::lisp_intern("SFML","*TEXTURE-COORDINATETYPE-ENUM-MAPPER*");
	      core::SymbolToEnumConverter_sp converter = 
		converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	      this->_v = converter->enumForSymbol<sf::Texture::CoordinateType>(sym);
	      return;
	    }
	}
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Texture::CoordinateType") % _rep_(object) );
    }
  };

  
};

using namespace clbind;

inline class_<sf::Texture> registerTexture()
{
  using namespace sf;
  //FIXME:
  return
    class_<sf::Texture>("texture")
    . def_constructor("make-texture", constructor<>())
    . def_constructor("copy-texture", constructor<const sf::Texture &>())

    .enum_<sf::Texture::CoordinateType>(core::lisp_intern("*TEXTURE-COORDINATETYPE-ENUM-MAPPER*", "SFML"))
    [
     value("texture/coordinate-type/normalized", sf::Texture::CoordinateType::Normalized),
     value("texture/coordinate-type/pixels", sf::Texture::CoordinateType::Pixels)
     ]

    .def("create/texture", &sf::Texture::create,
	 policies<>(), "", "",
	 R"**(\brief Create the texture

	  If this function fails, the texture is left unchanged.

	  \param width  Width of the texture
	  \param height Height of the texture

	  \return True if creation was successful)**")

    .def("load-from-file/texture", &sf::Texture::loadFromFile,
	 policies<>(), "", "",
	 R"**(\brief Load the texture from a file on disk

     This function is a shortcut for the following code:
     \code
     sf::Image image;
     image.loadFromFile(filename);
     texture.loadFromImage(image, area);
     \endcode

     The \a area argument can be used to load only a sub-rectangle
     of the whole image. If you want the entire image then leave
     the default value (which is an empty IntRect).
     If the \a area rectangle crosses the bounds of the image, it
     is adjusted to fit the image size.

     The maximum size for a texture depends on the graphics
     driver and can be retrieved with the getMaximumSize function.

     If this function fails, the texture is left unchanged.

     \param filename Path of the image file to load
     \param area     Area of the image to load

     \return True if loading was successful

     \see loadFromMemory, loadFromStream, loadFromImage)**")

    .def("load-from-memory/texture", &sf::Texture::loadFromMemory,
	 policies<>(), "", "",
	 R"**(\brief Load the texture from a file in memory

	  This function is a shortcut for the following code:
	  \code
	  sf::Image image;
	  image.loadFromMemory(data, size);
	  texture.loadFromImage(image, area);
	  \endcode

	  The \a area argument can be used to load only a sub-rectangle
	  of the whole image. If you want the entire image then leave
	  the default value (which is an empty IntRect).
	  If the \a area rectangle crosses the bounds of the image, it
	  is adjusted to fit the image size.

	  The maximum size for a texture depends on the graphics
	  driver and can be retrieved with the getMaximumSize function.

	  If this function fails, the texture is left unchanged.

	  \param data Pointer to the file data in memory
	  \param size Size of the data to load, in bytes
	  \param area Area of the image to load

	  \return True if loading was successful

	  \see loadFromFile, loadFromStream, loadFromImage)**")

    .def("load-from-stream/texture", &sf::Texture::loadFromStream,
	 policies<>(), "", "",
	 R"**(\brief Load the texture from a custom stream

	  This function is a shortcut for the following code:
	  \code
	  sf::Image image;
	  image.loadFromStream(stream);
	  texture.loadFromImage(image, area);
	  \endcode

	  The \a area argument can be used to load only a sub-rectangle
	  of the whole image. If you want the entire image then leave
	  the default value (which is an empty IntRect).
	  If the \a area rectangle crosses the bounds of the image, it
	  is adjusted to fit the image size.

	  The maximum size for a texture depends on the graphics
	  driver and can be retrieved with the getMaximumSize function.

	  If this function fails, the texture is left unchanged.

	  \param stream Source stream to read from
	  \param area   Area of the image to load

	  \return True if loading was successful

	  \see loadFromFile, loadFromMemory, loadFromImage)**")

    .def("load-from-image", &sf::Texture::loadFromImage,
	 policies<>(), "", "",
	 R"**(\brief Load the texture from an image

	  The \a area argument can be used to load only a sub-rectangle
	  of the whole image. If you want the entire image then leave
	  the default value (which is an empty IntRect).
	  If the \a area rectangle crosses the bounds of the image, it
	  is adjusted to fit the image size.

	  The maximum size for a texture depends on the graphics
	  driver and can be retrieved with the getMaximumSize function.

	  If this function fails, the texture is left unchanged.

	  \param image Image to load into the texture
	  \param area  Area of the image to load

	  \return True if loading was successful

	  \see loadFromFile, loadFromMemory)**")

    .def("get-size/texture", &sf::Texture::getSize,
	 policies<>(), "", "",
	 R"**(\brief Return the size of the texture

	  \return Size in pixels)**")

    .def("copy-to-image", &sf::Texture::copyToImage,
	 policies<>(), "", "",
	 R"**(\brief Copy the texture pixels to an image

	  This function performs a slow operation that downloads
	  the texture's pixels from the graphics card and copies
	  them to a new image, potentially applying transformations
	  to pixels if necessary (texture may be padded or flipped).

	  \return Image containing the texture's pixels

	  \see loadFromImage)**")

    .def("update-from-pa", (void (sf::Texture::*)(const Uint8*))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update the whole texture from an array of pixels

	 The \a pixel array is assumed to have the same size as
	 the \a area rectangle, and to contain 32-bits RGBA pixels.

	 No additional check is performed on the size of the pixel
	 array, passing invalid arguments will lead to an undefined
	 behavior.

	 This function does nothing if \a pixels is null or if the
	 texture was not previously created.

	 \param pixels Array of pixels to copy to the texture)**")

    .def("update-part-from-pa", (void (sf::Texture::*)(const Uint8*, unsigned int, unsigned int, unsigned int, unsigned int))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update a part of the texture from an array of pixels

	 The size of the \a pixel array must match the \a width and
	 \a height arguments, and it must contain 32-bits RGBA pixels.

	 No additional check is performed on the size of the pixel
	 array or the bounds of the area to update, passing invalid
	 arguments will lead to an undefined behavior.

	 This function does nothing if \a pixels is null or if the
	 texture was not previously created.

	 \param pixels Array of pixels to copy to the texture
	 \param width  Width of the pixel region contained in \a pixels
	 \param height Height of the pixel region contained in \a pixels
	 \param x      X offset in the texture where to copy the source pixels
	 \param y      Y offset in the texture where to copy the source pixels)**")

    .def("update-from-image", (void (sf::Texture::*)(const Image&))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update the texture from an image

	 Although the source image can be smaller than the texture,
	 this function is usually used for updating the whole texture.
	 The other overload, which has (x, y) additional arguments,
	 is more convenient for updating a sub-area of the texture.

	 No additional check is performed on the size of the image,
	 passing an image bigger than the texture will lead to an
	 undefined behavior.

	 This function does nothing if the texture was not
	 previously created.

	 \param image Image to copy to the texture)**")

    .def("update-part-from-image", (void (sf::Texture::*)(const Image&, unsigned int, unsigned int))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update a part of the texture from an image

	 No additional check is performed on the size of the image,
	 passing an invalid combination of image size and offset
	 will lead to an undefined behavior.

	 This function does nothing if the texture was not
	 previously created.

	 \param image Image to copy to the texture
	 \param x     X offset in the texture where to copy the source image
	 \param y     Y offset in the texture where to copy the source image)**")

    .def("update-from-window", (void (sf::Texture::*)(const Window&))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update the texture from the contents of a window

	 Although the source window can be smaller than the texture,
	 this function is usually used for updating the whole texture.
	 The other overload, which has (x, y) additional arguments,
	 is more convenient for updating a sub-area of the texture.

	 No additional check is performed on the size of the window,
	 passing a window bigger than the texture will lead to an
	 undefined behavior.

	 This function does nothing if either the texture or the window
	 was not previously created.

	 \param window Window to copy to the texture)**")

    .def("update-part-from-window", (void (sf::Texture::*)(const Window&, unsigned int, unsigned int))&sf::Texture::update,
	 policies<>(), "", "",
	 R"**(\brief Update a part of the texture from the contents of a window

	 No additional check is performed on the size of the window,
	 passing an invalid combination of window size and offset
	 will lead to an undefined behavior.

	 This function does nothing if either the texture or the window
	 was not previously created.

	 \param window Window to copy to the texture
	 \param x      X offset in the texture where to copy the source window
	 \param y      Y offset in the texture where to copy the source window)**")
    
    .def("set-smooth", &sf::Texture::setSmooth,
	 policies<>(), "", "",
	 R"**(\brief Enable or disable the smooth filter

	  When the filter is activated, the texture appears smoother
	  so that pixels are less noticeable. However if you want
	  the texture to look exactly the same as its source file,
	  you should leave it disabled.
	  The smooth filter is disabled by default.

	  \param smooth True to enable smoothing, false to disable it

	  \see isSmooth)**")

    .def("is-smooth", &sf::Texture::isSmooth,
	 policies<>(), "", "",
	 R"**(\brief Tell whether the smooth filter is enabled or not

	  \return True if smoothing is enabled, false if it is disabled

	  \see setSmooth)**")

    .def("set-repeated", &sf::Texture::setRepeated,
	 policies<>(), "", "",
	 R"**(\brief Enable or disable repeating

	  Repeating is involved when using texture coordinates
	  outside the texture rectangle [0, 0, width, height].
	  In this case, if repeat mode is enabled, the whole texture
	  will be repeated as many times as needed to reach the
	  coordinate (for example, if the X texture coordinate is
	  3 * width, the texture will be repeated 3 times).
	  If repeat mode is disabled, the "extra space" will instead
	  be filled with border pixels.
	  Warning: on very old graphics cards, white pixels may appear
	  when the texture is repeated. With such cards, repeat mode
	  can be used reliably only if the texture has power-of-two
	  dimensions (such as 256x128).
	  Repeating is disabled by default.

	  \param repeated True to repeat the texture, false to disable repeating

	  \see isRepeated)**")

    .def("is-repeated", &sf::Texture::isRepeated,
	 policies<>(), "", "",
	 R"**(\brief Tell whether the texture is repeated or not

	  \return True if repeat mode is enabled, false if it is disabled

	  \see setRepeated)**")

    .def("get-native-handle", &sf::Texture::getNativeHandle,
	 policies<>(), "", "",
	 R"**(\brief Get the underlying OpenGL handle of the texture.

	  You shouldn't need to use this function, unless you have
	  very specific stuff to implement that SFML doesn't support,
	  or implement a temporary workaround until a bug is fixed.

	  \return OpenGL handle of the texture or 0 if not yet created)**");
}

  
inline scope registerTextureBind()
{
  return
    def("texture/bind", &sf::Texture::bind,
	policies<>(), "", "",
	R"**(\brief Bind a texture for rendering

     This function is not part of the graphics API, it mustn't be
     used when drawing SFML entities. It must be used only if you
     mix sf::Texture with OpenGL code.

     \code
     sf::Texture t1, t2;
     ...
     sf::Texture::bind(&t1);
     draw OpenGL stuff that use t1...
     sf::Texture::bind(&t2);
     draw OpenGL stuff that use t2...
     sf::Texture::bind(NULL);
     draw OpenGL stuff that use no texture...
     \endcode

     The \a coordinateType argument controls how texture
     coordinates will be interpreted. If Normalized (the default), they
     must be in range [0 .. 1], which is the default way of handling
     texture coordinates with OpenGL. If Pixels, they must be given
     in pixels (range [0 .. size]). This mode is used internally by
     the graphics classes of SFML, it makes the definition of texture
     coordinates more intuitive for the high-level API, users don't need
     to compute normalized values.

     \param texture Pointer to the texture to bind, can be null to use no texture
     \param coordinateType Type of texture coordinates to use)**");
}

inline scope registerTextureGetMaximumSize()
{
  return
    def("texture/get-maximum-size", &sf::Texture::getMaximumSize,
	policies<>(), "", "",
	R"**(\brief Get the maximum texture size allowed

       This maximum size is defined by the graphics driver.
       You can expect a value of 512 pixels for low-end graphics
       card, and up to 8192 pixels or more for newer hardware.

       \return Maximum size allowed for textures, in pixels)**");
}



#endif //CLASP_SFML_TEXTURE_HPP

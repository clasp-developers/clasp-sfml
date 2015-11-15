#ifndef CLASP_SFML_IMAGE_HPP
#define CLASP_SFML_IMAGE_HPP

#include <SFML/Graphics/Image.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Image> registerImage()
{
  return
    class_<sf::Image>("image", no_default_constructor)
    .def_constructor("make-image", constructor<>())

    .def("image/create", (void (sf::Image::*)(unsigned int, unsigned int, const sf::Color&))&sf::Image::create,
	 policies<>(), "", "",
	 R"**(\brief Create the image and fill it with a unique color

		\param width  Width of the image
		\param height Height of the image
		\param color  Fill color)**")

    // .def("create-from-array", (void (sf::Image::*)(unsigned int, unsigned int, const sf::Uint8*))&sf::Image::create,
    // 	policies<>(), "", "",
    // 	R"**(\brief Create the image from an array of pixels

    // 	The \a pixel array is assumed to contain 32-bits RGBA pixels,
    // 	and have the given \a width and \a height. If not, this is
    // 	an undefined behavior.
    // 	If \a pixels is null, an empty image is created.

    // 	\param width  Width of the image
    // 	\param height Height of the image
    // 	\param pixels Array of pixels to copy to the image)**")

    .def("load-from-memory", &sf::Image::loadFromMemory,
	 policies<>(), "", "",
	 R"**(\brief Load the image from a file in memory

		The supported image formats are bmp, png, tga, jpg, gif,
		psd, hdr and pic. Some format options are not supported,
		like progressive jpeg.
		If this function fails, the image is left unchanged.

		\param data Pointer to the file data in memory
		\param size Size of the data to load, in bytes

		\return True if loading was successful

		\see loadFromFile, loadFromStream)**")

    // .def("load-from-stream", &sf::Image::loadFromStream,
    // 	policies<>(), "", "",
    // 	R"**(\brief Load the image from a custom stream

    // 	The supported image formats are bmp, png, tga, jpg, gif,
    // 	psd, hdr and pic. Some format options are not supported,
    // 	like progressive jpeg.
    // 	If this function fails, the image is left unchanged.

    // 	\param stream Source stream to read from

    // 	\return True if loading was successful

    // 	\see loadFromFile, loadFromMemory)**")

    .def("save-to-file", &sf::Image::saveToFile,
	 policies<>(), "", "",
	 R"**(\brief Save the image to a file on disk

		The format of the image is automatically deduced from
		the extension. The supported image formats are bmp, png,
		tga and jpg. The destination file is overwritten
		if it already exists. This function fails if the image is empty.

		\param filename Path of the file to save

		\return True if saving was successful

		\see create, loadFromFile, loadFromMemory)**")

    .def("get-size", &sf::Image::getSize,
	 policies<>(), "", "",
	 R"**(\brief Return the size (width and height) of the image

		\return Size of the image, in pixels)**")

    .def("create-mask-from-color", &sf::Image::createMaskFromColor,
	 policies<>(), "", "",
	 R"**(\brief Create a transparency mask from a specified color-key

		This function sets the alpha value of every pixel matching
		the given color to \a alpha (0 by default), so that they
		become transparent.

		\param color Color to make transparent
		\param alpha Alpha value to assign to transparent pixels)**")

    .def("copy", &sf::Image::copy,
	 policies<>(), "", "",
	 R"**(\brief Copy pixels from another image onto this one

		This function does a slow pixel copy and should not be
		used intensively. It can be used to prepare a complex
		static image from several others, but if you need this
		kind of feature in real-time you'd better use sf::RenderTexture.

		If \a sourceRect is empty, the whole image is copied.
		If \a applyAlpha is set to true, the transparency of
		source pixels is applied. If it is false, the pixels are
		copied unchanged with their alpha value.

		\param source     Source image to copy
		\param destX      X coordinate of the destination position
		\param destY      Y coordinate of the destination position
		\param sourceRect Sub-rectangle of the source image to copy
		\param applyAlpha Should the copy take in account the source transparency?)**")

    .def("set-pixel", &sf::Image::setPixel,
	 policies<>(), "", "",
	 R"**(\brief Change the color of a pixel

		This function doesn't check the validity of the pixel
		coordinates, using out-of-range values will result in
		an undefined behavior.

		\param x     X coordinate of pixel to change
		\param y     Y coordinate of pixel to change
		\param color New color of the pixel

		\see getPixel)**")

    .def("get-pixel", &sf::Image::getPixel,
	 policies<>(), "", "",
	 R"**(\brief Get the color of a pixel

		This function doesn't check the validity of the pixel
		coordinates, using out-of-range values will result in
		an undefined behavior.

		\param x X coordinate of pixel to get
		\param y Y coordinate of pixel to get

		\return Color of the pixel at coordinates (x, y)

		\see setPixel)**")

    .def("get-pixels-ptr", &sf::Image::getPixelsPtr,
	 policies<>(), "", "",
	 R"**(\brief Get a read-only pointer to the array of pixels

		The returned value points to an array of RGBA pixels made of
		8 bits integers components. The size of the array is
		width * height * 4 (getSize().x * getSize().y * 4).
		Warning: the returned pointer may become invalid if you
		modify the image, so you should never store it for too long.
		If the image is empty, a null pointer is returned.

		\return Read-only pointer to the array of pixels)**")

    .def("flip-horizontally", &sf::Image::flipHorizontally,
	 policies<>(), "", "",
	 R"**(\brief Flip the image horizontally (left <-> right))**")

    .def("flip-vertically", &sf::Image::flipVertically,
	 policies<>(), "", "",
	 R"**(\brief Flip the image vertically (top <-> bottom))**");
}

#endif //CLASP_SFML_IMAGE_HPP

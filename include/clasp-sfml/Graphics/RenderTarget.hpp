#ifndef CLASP_SFML_RENDERTARGET_HPP
#define CLASP_SFML_RENDERTARGET_HPP

#include <SFML/Graphics/RenderTarget.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::RenderTarget> registerRenderTarget()
{
  return
    class_<sf::RenderTarget>("render-target", no_default_constructor)

    .def("clear", &sf::RenderTarget::clear,
	 policies<>(), "", "",
	 R"**(\brief Clear the entire target with a single color

		This function is usually called once every frame,
		to clear the previous contents of the target.

		\param color Fill color to use to clear the render target)**")

    .def("set-view", &sf::RenderTarget::setView,
	 policies<>(), "", "",
	 R"**(\brief Change the current active view

		The view is like a 2D camera, it controls which part of
		the 2D scene is visible, and how it is viewed in the
		render target.
		The new view will affect everything that is drawn, until
		another view is set.
		The render target keeps its own copy of the view object,
		so it is not necessary to keep the original one alive
		after calling this function.
		To restore the original view of the target, you can pass
		the result of getDefaultView() to this function.

		\param view New view to use

		\see getView, getDefaultView)**")

    .def("get-view", &sf::RenderTarget::getView,
	 policies<>(), "", "",
	 R"**(\brief Get the view currently in use in the render target

		\return The view object that is currently used

		\see setView, getDefaultView)**")

    .def("get-default-view", &sf::RenderTarget::getDefaultView,
	 policies<>(), "", "",
	 R"**(\brief Get the default view of the render target

		The default view has the initial size of the render target,
		and never changes after the target has been created.

		\return The default view of the render target

		\see setView, getView)**")

    .def("get-viewport", &sf::RenderTarget::getViewport,
	 policies<>(), "", "",
	 R"**(\brief Get the viewport of a view, applied to this render target

		The viewport is defined in the view as a ratio, this function
		simply applies this ratio to the current dimensions of the
		render target to calculate the pixels rectangle that the viewport
		actually covers in the target.

		\param view The view for which we want to compute the viewport

		\return Viewport rectangle, expressed in pixels)**")

    // .def("map-pixel-to-coords", (Vector2f (sf::RenderTarget::*)(const Vector2i&))&sf::RenderTarget::mapPixelToCoords,
    // 	policies<>(), "", "",
    // 	R"**(\brief Convert a point from target coordinates to world
    // 	coordinates, using the current view

    // 	This function is an overload of the mapPixelToCoords
    // 	function that implicitly uses the current view.
    // 	It is equivalent to:
    // 	\code
    // 	target.mapPixelToCoords(point, target.getView());
    // 	\endcode

    // 	\param point Pixel to convert

    // 	\return The converted point, in "world" coordinates

    // 	\see mapCoordsToPixel)**")

	   
    .def("map-pixel-to-coords", (sf::Vector2f (sf::RenderTarget::*)(const sf::Vector2i&, const sf::View&) const)&sf::RenderTarget::mapPixelToCoords,
	 policies<>(), "(self point &optional (view (get-view self)))", "", //FIXME works?
	 R"**(\brief Convert a point from target coordinates to world coordinates

		This function finds the 2D position that matches the
		given pixel of the render target. In other words, it does
		the inverse of what the graphics card does, to find the
		initial position of a rendered pixel.

		Initially, both coordinate systems (world units and target pixels)
		match perfectly. But if you define a custom view or resize your
		render target, this assertion is not true anymore, i.e. a point
		located at (10, 50) in your render target may map to the point
		(150, 75) in your 2D world -- if the view is translated by (140, 25).

		For render-windows, this function is typically used to find
		which point (or object) is located below the mouse cursor.

		This version uses a custom view for calculations, see the other
		overload of the function if you want to use the current view of the
		render target.

		\param point Pixel to convert
		\param view The view to use for converting the point

		\return The converted point, in "world" units

		\see mapCoordsToPixel)**")

    // .def("map-coords-to-pixel", (Vector2i (sf::RenderTarget::*)(const Vector2f&))&sf::RenderTarget::mapCoordsToPixel,
    // 	policies<>(), "", "",
    // 	R"**(\brief Convert a point from world coordinates to target
    // 	coordinates, using the current view

    // 	This function is an overload of the mapCoordsToPixel
    // 	function that implicitly uses the current view.
    // 	It is equivalent to:
    // 	\code
    // 	target.mapCoordsToPixel(point, target.getView());
    // 	\endcode

    // 	\param point Point to convert

    // 	\return The converted point, in target coordinates (pixels)

    // 	\see mapPixelToCoords)**")

    .def("map-coords-to-pixel", (sf::Vector2i (sf::RenderTarget::*)(const sf::Vector2f&, const sf::View&) const)&sf::RenderTarget::mapCoordsToPixel,
	 policies<>(), "(self point &optional (view (get-view self)))", "", //FIXME: I don't think this will work...
	 R"**(\brief Convert a point from world coordinates to target coordinates

		This function finds the pixel of the render target that matches
		the given 2D point. In other words, it goes through the same process
		as the graphics card, to compute the final position of a rendered point.

		Initially, both coordinate systems (world units and target pixels)
		match perfectly. But if you define a custom view or resize your
		render target, this assertion is not true anymore, i.e. a point
		located at (150, 75) in your 2D world may map to the pixel
		(10, 50) of your render target -- if the view is translated by (140, 25).

		This version uses a custom view for calculations, see the other
		overload of the function if you want to use the current view of the
		render target.

		\param point Point to convert
		\param view The view to use for converting the point

		\return The converted point, in target coordinates (pixels)

		\see mapPixelToCoords)**")

    .def("draw", (void (sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&))&sf::RenderTarget::draw,
	 policies<>(), "(self drawable &optional (states nil))", "",
	 R"**(\brief Draw a drawable object to the render target

		\param drawable Object to draw
		\param states   Render states to use for drawing)**")

    // .def("draw-vertices", (void (sf::RenderTarget::*)(const sf::Vertex*, unsigned int, sf::PrimitiveType, const sf::RenderStates&))&sf::RenderTarget::draw,
    // 	policies<>(), "", "",
    // 	R"**(\brief Draw primitives defined by an array of vertices

    // 	\param vertices    Pointer to the vertices
    // 	\param vertexCount Number of vertices in the array
    // 	\param type        Type of primitives to draw
    // 	\param states      Render states to use for drawing)**")

    .def("get-size", &sf::RenderTarget::getSize,
	 policies<>(), "", "",
	 R"**(\brief Return the size of the rendering region of the target

		\return Size in pixels)**")

    .def("push-gl-states", &sf::RenderTarget::pushGLStates,
	 policies<>(), "", "",
	 R"**(\brief Save the current OpenGL render states and matrices

		This function can be used when you mix SFML drawing
		and direct OpenGL rendering. Combined with popGLStates,
		it ensures that:
		\li SFML's internal states are not messed up by your OpenGL code
		\li your OpenGL states are not modified by a call to a SFML function

		More specifically, it must be used around code that
		calls Draw functions. Example:
		\code
		OpenGL code here...
		window.pushGLStates();
		window.draw(...);
		window.draw(...);
		window.popGLStates();
		OpenGL code here...
		\endcode

		Note that this function is quite expensive: it saves all the
		possible OpenGL states and matrices, even the ones you
		don't care about. Therefore it should be used wisely.
		It is provided for convenience, but the best results will
		be achieved if you handle OpenGL states yourself (because
		you know which states have really changed, and need to be
		saved and restored). Take a look at the resetGLStates
		function if you do so.

		\see popGLStates)**")

    .def("pop-gl-states", &sf::RenderTarget::popGLStates,
	 policies<>(), "", "",
	 R"**(\brief Restore the previously saved OpenGL render states and matrices

		See the description of pushGLStates to get a detailed
		description of these functions.

		\see pushGLStates)**")

    .def("reset-gl-states", &sf::RenderTarget::resetGLStates,
	 policies<>(), "", "",
	 R"**(\brief Reset the internal OpenGL states so that the target is ready for drawing

		This function can be used when you mix SFML drawing
		and direct OpenGL rendering, if you choose not to use
		pushGLStates/popGLStates. It makes sure that all OpenGL
		states needed by SFML are set, so that subsequent draw()
		calls will work as expected.

		Example:
		\code
		OpenGL code here...
		glPushAttrib(...);
		window.resetGLStates();
		window.draw(...);
		window.draw(...);
		glPopAttrib(...);
		OpenGL code here...
		\endcode)**");
}

#endif //CLASP_SFML_RENDERTARGET_HPP

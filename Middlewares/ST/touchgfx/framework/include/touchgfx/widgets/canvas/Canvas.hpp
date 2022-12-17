/******************************************************************************
* Copyright (c) 2018(-2022) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.20.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file touchgfx/widgets/canvas/Canvas.hpp
 *
 * Declares the touchgfx::Canvas class.
 */
#ifndef TOUCHGFX_CANVAS_HPP
#define TOUCHGFX_CANVAS_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/widgets/canvas/CWRUtil.hpp>
#include <touchgfx/widgets/canvas/CanvasWidget.hpp>

namespace touchgfx
{
/**
 * Class for easy rendering using CanvasWidgetRenderer.
 *
 * The Canvas class will make implementation of a new CanvasWidget very easy. The few simple
 * primitives allows moving a "pen" and drawing the outline of a shape which can then be
 * rendered.
 *
 * The Canvas class has been optimized to eliminate drawing unnecessary lines outside the
 * currently invalidated rectangle.
 */
class Canvas
{
public:
    /**
     * Canvas Constructor. Locks the framebuffer and prepares for drawing only in the allowed area
     * which has been invalidated. The color depth of the LCD is taken into account.
     *
     * @param  _widget         a pointer to the CanvasWidget using this Canvas. Used for getting the
     *                         canvas dimensions.
     * @param  invalidatedArea the are which should be updated.
     *
     * @note Locks the framebuffer.
     */
    Canvas(const CanvasWidget* _widget, const Rect& invalidatedArea);

    /**
     * Finalizes an instance of the Canvas class.
     *
     * @note Unlocks the framebuffer.
     */
    virtual ~Canvas()
    {
    }

    /**
     * Move the current pen position to (x, y). If the pen is outside the drawing area, nothing is
     * done, but the coordinates are saved in case the next operation is lineTo a coordinate which
     * is inside (or on the opposite side of) the drawing area.
     *
     * @param  x The x coordinate for the pen position in CWRUtil::Q5 format.
     * @param  y The y coordinate for the pen position in CWRUtil::Q5 format.
     */
    void moveTo(CWRUtil::Q5 x, CWRUtil::Q5 y);

    /**
     * Draw line from the current (x, y) to the new (x, y) as part of the shape being drawn. As for
     * moveTo, lineTo commands completely outside the drawing are are discarded.
     *
     * @param  x The x coordinate for the pen position in CWRUtil::Q5 format.
     * @param  y The y coordinate for the pen position in CWRUtil::Q5 format.
     *
     * @see CWRUtil::Q5, moveTo
     */
    void lineTo(CWRUtil::Q5 x, CWRUtil::Q5 y);

    /**
     * Move the current pen position to (x, y). If the pen is outside (above or below)
     * the drawing area, nothing is done, but the coordinates are saved in case the next operation
     * is lineTo a coordinate which is inside (or on the opposite side of) the drawing area.
     *
     * @tparam T Either int or float.
     * @param  x The x coordinate for the pen position.
     * @param  y The y coordinate for the pen position.
     */
    template <typename T>
    void moveTo(T x, T y)
    {
        moveTo(CWRUtil::toQ5<T>(x), CWRUtil::toQ5<T>(y));
    }

    /**
     * Draw line from the current (x, y) to the new (x, y) as part of the shape being drawn. As for
     * moveTo, lineTo commands completely outside the drawing are are discarded.
     *
     * @tparam T either int or float.
     * @param  x The x coordinate for the pen position.
     * @param  y The y coordinate for the pen position.
     */
    template <typename T>
    void lineTo(T x, T y)
    {
        lineTo(CWRUtil::toQ5<T>(x), CWRUtil::toQ5<T>(y));
    }

    /**
     * Render the graphical shape drawn using moveTo() and lineTo() with the given Painter. The
     * shape is automatically closed, i.e. a lineTo() is automatically inserted connecting the
     * current pen position with the initial pen position given in the first moveTo() command.
     *
     * @param  customAlpha (Optional) Alpha to apply to the entire canvas. Useful if the canvas is
     *                     part of a more complex container setup that needs to be faded. Default is
     *                     solid.
     *
     * @return true if the widget was rendered, false if insufficient memory was available to render
     *         the widget.
     */
    bool render(uint8_t customAlpha = 255);

    /**
     * Determines if we the outline was too complex to draw completely.
     *
     * @return True if it was too complex, false if not.
     */
    FORCE_INLINE_FUNCTION bool wasOutlineTooComplex()
    {
        return rasterizer.wasOutlineTooComplex();
    }

private:
    // Pointer to the widget using the Canvas
    const CanvasWidget* widget;

    // Invalidate area in Q5 coordinates
    CWRUtil::Q5 invalidatedAreaX;
    CWRUtil::Q5 invalidatedAreaY;
    CWRUtil::Q5 invalidatedAreaWidth;
    CWRUtil::Q5 invalidatedAreaHeight;

    // For drawing
    Rect dirtyAreaAbsolute;
    Rasterizer rasterizer;

    // Used for optimization of drawing algorithm
    bool penUp, penHasBeenDown;
    CWRUtil::Q5 previousX, previousY;
    uint8_t previousOutside;
    uint8_t penDownOutside;
    CWRUtil::Q5 initialX, initialY;

    enum
    {
        POINT_IS_ABOVE = 1 << 0,
        POINT_IS_BELOW = 1 << 1,
        POINT_IS_LEFT = 1 << 2,
        POINT_IS_RIGHT = 1 << 3
    };

    FORCE_INLINE_FUNCTION uint8_t isOutside(const CWRUtil::Q5& x, const CWRUtil::Q5& y, const CWRUtil::Q5& width, const CWRUtil::Q5& height) const
    {
        return ((y < 0) ? (POINT_IS_ABOVE) : (y >= height ? POINT_IS_BELOW : 0)) |
               ((x < 0) ? (POINT_IS_LEFT) : (x >= width ? POINT_IS_RIGHT : 0));
    }

    void transformFrameBufferToDisplay(CWRUtil::Q5& x, CWRUtil::Q5& y) const;

    bool close();
};

} // namespace touchgfx

#endif // TOUCHGFX_CANVAS_HPP

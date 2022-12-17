/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/graph/GraphScroll.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/containers/Slider.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void slider_sinus_changed(int value)
    {
        // Override and implement this function in Screen1
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage background;
    touchgfx::TextAreaWithOneWildcard hour;
    touchgfx::GraphScroll<100> graph_temp;
    touchgfx::GraphElementLine graph_tempLine1;
    touchgfx::PainterRGB888 graph_tempLine1Painter;
    touchgfx::GraphElementGridX graph_tempMajorXAxisGrid;
    touchgfx::GraphElementGridY graph_tempMajorYAxisGrid;
    touchgfx::GraphLabelsX graph_tempMajorXAxisLabel;
    touchgfx::GraphLabelsY graph_tempMajorYAxisLabel;
    touchgfx::Slider slider_sinus_count;
    touchgfx::TextAreaWithOneWildcard text_sinus_count;

    /*
     * Wildcard Buffers
     */
    static const uint16_t HOUR_SIZE = 16;
    touchgfx::Unicode::UnicodeChar hourBuffer[HOUR_SIZE];
    static const uint16_t TEXT_SINUS_COUNT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar text_sinus_countBuffer[TEXT_SINUS_COUNT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen1ViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREEN1VIEWBASE_HPP
/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


Screen1ViewBase::Screen1ViewBase() :
    sliderValueChangedCallback(this, &Screen1ViewBase::sliderValueChangedCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setBitmap(touchgfx::Bitmap(BITMAP_DARK_BACKGROUNDS_MAIN_BG_480X272PX_ID));
    background.setPosition(0, 0, 480, 272);
    background.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    hour.setXY(21, -12);
    hour.setColor(touchgfx::Color::getColorFromRGB(0, 255, 238));
    hour.setLinespacing(0);
    Unicode::snprintf(hourBuffer, HOUR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_7Z8V).getText());
    hour.setWildcard(hourBuffer);
    hour.resizeToCurrentText();
    hour.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GBRP));

    graph_temp.setScale(1);
    graph_temp.setPosition(0, 66, 480, 206);
    graph_temp.setGraphAreaMargin(0, 20, 0, 20);
    graph_temp.setGraphAreaPadding(6, 5, 0, 3);
    graph_temp.setGraphRangeY(0, 100);

    graph_tempMajorXAxisGrid.setScale(1);
    graph_tempMajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(82, 89, 92));
    graph_tempMajorXAxisGrid.setInterval(10);
    graph_tempMajorXAxisGrid.setLineWidth(1);
    graph_temp.addGraphElement(graph_tempMajorXAxisGrid);

    graph_tempMajorYAxisGrid.setScale(1);
    graph_tempMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(82, 89, 92));
    graph_tempMajorYAxisGrid.setInterval(10);
    graph_tempMajorYAxisGrid.setLineWidth(1);
    graph_temp.addGraphElement(graph_tempMajorYAxisGrid);

    graph_tempMajorXAxisLabel.setScale(1);
    graph_tempMajorXAxisLabel.setInterval(10);
    graph_tempMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_72RM));
    graph_tempMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    graph_temp.addBottomElement(graph_tempMajorXAxisLabel);

    graph_tempMajorYAxisLabel.setScale(1);
    graph_tempMajorYAxisLabel.setInterval(10);
    graph_tempMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_NYNM));
    graph_tempMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    graph_temp.addLeftElement(graph_tempMajorYAxisLabel);

    graph_tempLine1Painter.setColor(touchgfx::Color::getColorFromRGB(37, 219, 74));
    graph_tempLine1.setPainter(graph_tempLine1Painter);
    graph_tempLine1.setLineWidth(2);
    graph_temp.addGraphElement(graph_tempLine1);

    graph_temp.addDataPoint(39.67016f);
    graph_temp.addDataPoint(38.41368f);
    graph_temp.addDataPoint(42.60038f);
    graph_temp.addDataPoint(52.02974f);
    graph_temp.addDataPoint(65.08088f);
    graph_temp.addDataPoint(79.08196f);
    graph_temp.addDataPoint(90.94352f);
    graph_temp.addDataPoint(97.90134f);
    graph_temp.addDataPoint(98.18766f);
    graph_temp.addDataPoint(91.46657f);
    graph_temp.addDataPoint(78.92682f);
    graph_temp.addDataPoint(63.00899f);
    graph_temp.addDataPoint(46.83308f);
    graph_temp.addDataPoint(33.46555f);
    graph_temp.addDataPoint(25.20426f);
    graph_temp.addDataPoint(23.05468f);
    graph_temp.addDataPoint(26.52431f);
    graph_temp.addDataPoint(33.78383f);
    graph_temp.addDataPoint(42.1541f);
    graph_temp.addDataPoint(48.79802f);
    graph_temp.addDataPoint(51.44657f);
    graph_temp.addDataPoint(48.97995f);
    graph_temp.addDataPoint(41.72053f);
    graph_temp.addDataPoint(31.36517f);
    graph_temp.addDataPoint(20.57296f);
    graph_temp.addDataPoint(12.30923f);
    graph_temp.addDataPoint(9.10672f);
    graph_temp.addDataPoint(12.42508f);
    graph_temp.addDataPoint(22.26664f);
    graph_temp.addDataPoint(37.14332f);
    graph_temp.addDataPoint(54.40421f);
    graph_temp.addDataPoint(70.84513f);
    graph_temp.addDataPoint(83.45235f);
    graph_temp.addDataPoint(90.10012f);
    graph_temp.addDataPoint(90.03285f);
    graph_temp.addDataPoint(84.01534f);
    graph_temp.addDataPoint(74.11564f);
    graph_temp.addDataPoint(63.17508f);
    graph_temp.addDataPoint(54.09593f);
    graph_temp.addDataPoint(49.12192f);
    graph_temp.addDataPoint(49.28804f);
    graph_temp.addDataPoint(54.17447f);
    graph_temp.addDataPoint(62.02444f);
    graph_temp.addDataPoint(70.19673f);
    graph_temp.addDataPoint(75.84097f);
    graph_temp.addDataPoint(76.62939f);
    graph_temp.addDataPoint(71.36447f);
    graph_temp.addDataPoint(60.31216f);
    graph_temp.addDataPoint(45.17753f);
    graph_temp.addDataPoint(28.72727f);
    graph_temp.addDataPoint(14.14969f);
    graph_temp.addDataPoint(4.30759f);
    graph_temp.addDataPoint(1.06547f);
    graph_temp.addDataPoint(4.85485f);
    graph_temp.addDataPoint(14.58296f);
    graph_temp.addDataPoint(27.90695f);
    graph_temp.addDataPoint(41.80589f);
    graph_temp.addDataPoint(53.31082f);
    graph_temp.addDataPoint(60.21435f);
    graph_temp.addDataPoint(61.58678f);
    graph_temp.addDataPoint(57.97343f);
    graph_temp.addDataPoint(51.22598f);
    graph_temp.addDataPoint(44.01059f);
    graph_temp.addDataPoint(39.11465f);
    graph_temp.addDataPoint(38.72366f);
    graph_temp.addDataPoint(43.84683f);
    graph_temp.addDataPoint(54.03351f);
    graph_temp.addDataPoint(67.45155f);
    graph_temp.addDataPoint(81.30943f);
    graph_temp.addDataPoint(92.52009f);
    graph_temp.addDataPoint(98.44452f);
    graph_temp.addDataPoint(97.53368f);
    graph_temp.addDataPoint(89.71168f);
    graph_temp.addDataPoint(76.4063f);
    graph_temp.addDataPoint(60.21881f);
    graph_temp.addDataPoint(44.31329f);
    graph_temp.addDataPoint(31.6738f);
    graph_temp.addDataPoint(24.41005f);
    graph_temp.addDataPoint(23.28015f);
    graph_temp.addDataPoint(27.54568f);
    graph_temp.addDataPoint(35.19292f);
    graph_temp.addDataPoint(43.46457f);
    graph_temp.addDataPoint(49.57006f);
    graph_temp.addDataPoint(51.39935f);
    graph_temp.addDataPoint(48.064f);
    graph_temp.addDataPoint(40.13233f);
    graph_temp.addDataPoint(29.50012f);
    graph_temp.addDataPoint(18.92831f);
    graph_temp.addDataPoint(11.36076f);
    graph_temp.addDataPoint(9.18926f);
    graph_temp.addDataPoint(13.64653f);
    graph_temp.addDataPoint(24.47638f);
    graph_temp.addDataPoint(39.96318f);
    graph_temp.addDataPoint(57.3146f);
    graph_temp.addDataPoint(73.30541f);
    graph_temp.addDataPoint(85.02635f);
    graph_temp.addDataPoint(90.55632f);
    graph_temp.addDataPoint(89.39492f);
    graph_temp.addDataPoint(82.55093f);
    graph_temp.addDataPoint(72.26645f);

    slider_sinus_count.setXY(229, 18);
    slider_sinus_count.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_EDGE_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_EDGE_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_EDGE_KNOB_ID));
    slider_sinus_count.setupHorizontalSlider(3, 7, 0, 0, 125);
    slider_sinus_count.setValueRange(1, 21);
    slider_sinus_count.setValue(1);
    slider_sinus_count.setNewValueCallback(sliderValueChangedCallback);

    text_sinus_count.setXY(415, 20);
    text_sinus_count.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    text_sinus_count.setLinespacing(0);
    Unicode::snprintf(text_sinus_countBuffer, TEXT_SINUS_COUNT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_DM31).getText());
    text_sinus_count.setWildcard(text_sinus_countBuffer);
    text_sinus_count.resizeToCurrentText();
    text_sinus_count.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FBQO));

    add(__background);
    add(background);
    add(hour);
    add(graph_temp);
    add(slider_sinus_count);
    add(text_sinus_count);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_sinus_count)
    {
        //Interaction1
        //When slider_sinus_count value changed call virtual function
        //Call slider_sinus_changed
        slider_sinus_changed(value);
    }
}
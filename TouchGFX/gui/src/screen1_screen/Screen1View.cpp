#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View() {}

void
Screen1View::setupScreen() {
    Screen1ViewBase::setupScreen();

    setSinusCountText(slider_sinus_count.getValue());
    setDateTime(presenter->getCurrentDateTime());
}

void
Screen1View::tearDownScreen() {
    Screen1ViewBase::tearDownScreen();
}

/**
 * \brief           Sets the view to current date and time
 *
 * \param           dt: Current date and time to set
 */
void
Screen1View::setDateTime(const struct tm* dt) {
    hour.invalidate();
    Unicode::snprintf(hourBuffer, HOUR_SIZE, "%02u:%02u:%02u", (unsigned)dt->tm_hour, (unsigned)dt->tm_min,
                      (unsigned)dt->tm_sec);
    hour.setWidth(hour.getTextWidth());
    hour.invalidate();
}

/**
 * \brief           Adds new temperature to the graph
 *
 * \param           temp: New temperature
 */
void
Screen1View::setTemp(float temp) {
    graph_temp.addDataPoint((int)temp);
}

/**
 * \brief           Called when slider value changed
 *
 * \param           value: New value
 */
void
Screen1View::slider_sinus_changed(int value) {
    presenter->setSinusCount(value);
    setSinusCountText(value);
}
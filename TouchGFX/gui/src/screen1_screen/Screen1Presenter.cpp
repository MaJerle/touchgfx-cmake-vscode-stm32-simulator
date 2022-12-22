#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/screen1_screen/Screen1View.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v) : view(v) {}

void
Screen1Presenter::activate() {}

void
Screen1Presenter::deactivate() {}

void
Screen1Presenter::notifyNewDateTime(const struct tm* dt) {
    view.setDateTime(dt);
}

void
Screen1Presenter::notifyNewTemp(float temp) {
    view.setTemp(temp);
}

void
Screen1Presenter::setSinusCount(int value) {
    model->setSinusCount(value < 0 ? 1 : value);
}
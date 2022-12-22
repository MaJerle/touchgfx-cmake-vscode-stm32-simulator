#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <ctime>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>

class Screen1View : public Screen1ViewBase {
  public:
    Screen1View();

    virtual ~Screen1View() {}

    virtual void setupScreen();
    virtual void tearDownScreen();

    /* Called from presenter */
    void setDateTime(const struct tm* dt);
    void setTemp(float temp);

    /* View functions */
    void slider_sinus_changed(int value);

  protected:
  private:
    /**
     * \brief       Update sinus counter text
     * 
     */
    void
    setSinusCountText(int value) {
        text_sinus_count.invalidate();
        Unicode::snprintf(text_sinus_countBuffer, TEXT_SINUS_COUNT_SIZE, "%d", value);
        text_sinus_count.setWidth(text_sinus_count.getTextWidth());
        text_sinus_count.invalidate();
    }
};

#endif // SCREEN1VIEW_HPP

#ifndef MODEL_HPP
#define MODEL_HPP

#include <ctime>

class ModelListener;

class Model {
  public:
    Model();

    void
    bind(ModelListener* listener) {
        modelListener = listener;
    }

    void tick();
    void setSinusCount(size_t sinus_count);

    /**
     * \brief           Get the Current Date Time object
     * 
     * \return          const struct tm* 
     */
    const struct tm*
    getCurrentDateTime(void) {
        return &current_dt;
    }

  protected:
    ModelListener* modelListener;

  private:
    size_t sinus_count;
    time_t last_time;
    struct tm current_dt;
};

#endif // MODEL_HPP

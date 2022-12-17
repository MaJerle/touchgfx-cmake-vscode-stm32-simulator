#ifndef MODEL_HPP
#define MODEL_HPP

#include <ctime>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener *listener)
    {
        modelListener = listener;
    }

    void tick();
    void setSinusCount(size_t sinus_count);

protected:
    ModelListener *modelListener;

private:
    time_t last_time;
    size_t sinus_count;
};

#endif // MODEL_HPP

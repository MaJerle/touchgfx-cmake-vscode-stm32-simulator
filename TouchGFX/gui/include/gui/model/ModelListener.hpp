#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <ctime>

class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    void bind(Model *m)
    {
        model = m;
    }

    /* Empty implementation - fallback option */
    virtual void notifyNewDateTime(const tm *dt) {}
    virtual void notifyNewTemp(float temp) {}

protected:
    Model *model;
};

#endif // MODELLISTENER_HPP

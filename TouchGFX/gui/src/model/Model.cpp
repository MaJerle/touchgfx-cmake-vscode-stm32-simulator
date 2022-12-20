#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#include <cmath>

Model::Model() : modelListener(0), sinus_count(1)
{
}

void Model::tick()
{
    static uint32_t cnt = 0;
    static time_t raw_time = 1671459593;
    struct tm dt;

    ++cnt;

    /* Get current time */
#if defined(SIMULATOR)
    time(&raw_time);        /* Windows time */
#else  /* SIMULATOR */
    if (cnt % 60 == 0) {    /* Simple counter increase */
        ++raw_time;
    }
#endif /* !SIMULATOR */

    if (raw_time != last_time)
    {
        last_time = raw_time;
        dt = *gmtime(&raw_time);        /* Simple gmtime calculation */

        /* Notify active presenter */
        modelListener->notifyNewDateTime(&dt);
    }

    /* Temperature data from sensor */
#if defined(SIMULATOR) || 1
    {
        double temp;

        if (cnt % 4 == 0)
        {
            /* Calculate temperature manually */
            temp = 0;
            for (size_t i = 1; i <= this->sinus_count; i += 2)
            {
                temp += sin(2.0 * 3.1415 * (20 * i) * cnt * 20) * (48 / i) + (i == 1 ? 50 : 0);
            }
            modelListener->notifyNewTemp((float)temp);
        }
    }
#else  /* SIMULATOR */
    /* Get sensor data on real device */
#endif /* !SIMULATOR */
}

/**
 * \brief           Sets the number of sinus frequencies.
 *
 * Value is set from the view to model
 *
 * \param           sinus_count
 */
void Model::setSinusCount(size_t sinus_count)
{
    this->sinus_count = sinus_count;
}

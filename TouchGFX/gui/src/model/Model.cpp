#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#include <cmath>

Model::Model() : modelListener(0), sinus_count(1)
{
}

void Model::tick()
{
    time_t raw_time;
    struct tm dt;

    /* Get current time */
#if defined(SIMULATOR)
    time(&raw_time);
    if (raw_time != last_time)
    {
        last_time = raw_time;
        localtime_s(&dt, &raw_time);

        /* Notify active presenter */
        modelListener->notifyNewDateTime(&dt);
    }
#else  /* SIMULATOR */
    /* Get current RTC from the MCU RTC block */
#endif /* !SIMULATOR */

    /* Temperature data from sensor */
#if defined(SIMULATOR)
    {
        static uint32_t cnt = 0;
        double temp;

        if (++cnt % 2 == 0)
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
    /* Get current RTC from the MCU RTC block */
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


#include "TimerSettingsInterface.h"


class SettingsAdapter : public TimerSettingsInterface
{
public:
    // Empty virtual destructor for proper cleanup
    virtual ~SettingsAdapter() {}

    SettingsAdapter();

    int32_t getPT(const char* key) const;
    void setPT(const char* key, int32_t PT);


};



#include "settingsNVSinternal.h"
#include "TimerSettingsInterface.h"


class SettingsAdapter : public TimerSettingsInterface, public Settings
{
public:

	SettingsAdapter() = default;

    // Empty virtual destructor for proper cleanup
    virtual ~SettingsAdapter() {}


    int32_t getPT(const char* key) const;
    void setPT(const char* key, int32_t PT);


};

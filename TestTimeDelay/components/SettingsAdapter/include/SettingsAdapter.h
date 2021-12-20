

#include "settingsNVSinternal.h"
#include "TimerSettingsInterface.h"
#include "TimerSettings2Interface.h"
#include "TimerSettings3Interface.h"


class SettingsAdapter
		: public TimerSettingsInterface,
		  public TimerSettings2Interface,
		  public TimerSettings3Interface,
		  public Settings
{
public:

	SettingsAdapter() = default;

    // Empty virtual destructor for proper cleanup
    virtual ~SettingsAdapter() {}

    int32_t getPT(const char* key) const;
    int32_t getPT_up(const char* key) const;
    int32_t getPT_down(const char* key) const;
    int32_t getPT_float(const char* key) const;
    void setPT(const char* key, int32_t PT);
    void setPT_up(const char* key, int32_t PT_up);
    void setPT_down(const char* key, int32_t PT_down);
    void setPT_float(const char* key, int32_t PT_float);

};

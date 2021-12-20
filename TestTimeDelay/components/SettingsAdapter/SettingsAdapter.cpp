#include <stdio.h>






#include "SettingsAdapter.h"
#include "settingsNVS.h"

SettingsAdapter::SettingsAdapter() {

}

int32_t SettingsAdapter::getPT(const char *key) const {
	return (getS32("CF-A", key, 0));
}

void SettingsAdapter::setPT(const char *key, int32_t PT) {
	setU32("CF-A", key, PT);
}

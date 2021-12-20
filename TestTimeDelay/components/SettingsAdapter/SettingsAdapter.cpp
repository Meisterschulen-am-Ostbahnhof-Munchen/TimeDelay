#include <stdio.h>






#include "SettingsAdapter.h"


int32_t SettingsAdapter::getPT(const char *key) const {
	return (SettingsAdapter::getS32("CF-A", key, 0));
}

void SettingsAdapter::setPT(const char *key, int32_t PT) {
	SettingsAdapter::setS32("CF-A", key, PT);
}

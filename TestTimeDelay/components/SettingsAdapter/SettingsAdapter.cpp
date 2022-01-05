#include <stdio.h>






#include "SettingsAdapter.h"


int32_t SettingsAdapter::getPT(const char *key) const {
	return (SettingsAdapter::getS32("CF-A", key, 0));
}

int32_t SettingsAdapter::getPT_up(const char *key) const {
	return (SettingsAdapter::getS32("CF-A", key, 0));
}

int32_t SettingsAdapter::getPT_down(const char *key) const {
	return (SettingsAdapter::getS32("CF-A", key, 0));
}

int32_t SettingsAdapter::getPT_float(const char *key) const {
	return (SettingsAdapter::getS32("CF-A", key, 0));
}

void SettingsAdapter::setPT(const char *key, int32_t PT) {
	SettingsAdapter::setS32("CF-A", key, PT);
}

void SettingsAdapter::setPT_up(const char *key, int32_t PT_up) {
	SettingsAdapter::setS32("CF-A", key, PT_up);
}

void SettingsAdapter::setPT_down(const char *key, int32_t PT_down) {
	SettingsAdapter::setS32("CF-A", key, PT_down);
}

void SettingsAdapter::setPT_float(const char *key, int32_t PT_float) {
	SettingsAdapter::setS32("CF-A", key, PT_float);
}

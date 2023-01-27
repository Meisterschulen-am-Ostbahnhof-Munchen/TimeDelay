/* ************************************************************************ */
/*!
   \file
   \brief       Helper functions for reading and writing settings to a file.

*/
/* ************************************************************************ */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>

#include "settingsNVSinternal.h"
#include "settingsNVS.h"
#include "esp_err.h"
#include "esp_log.h"
#include "nvs.h"
#include "nvs_flash.h"



/* ************************************************************************ */

static const char * const TAG = "settings";






struct Settings::Impl
{
	static nvs_handle_t my_handle;
};

nvs_handle_t Settings::Impl::my_handle;


void Settings::init(void)
{
	// Initialize NVS
	esp_err_t err = nvs_flash_init();
	if (err == ESP_ERR_NVS_NO_FREE_PAGES or err == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		// NVS partition was truncated and needs to be erased
		// Retry nvs_flash_init
		ESP_ERROR_CHECK (nvs_flash_erase());
		err = nvs_flash_init();
	}
	ESP_ERROR_CHECK(err);
	// Open
	ESP_LOGD(TAG, "\n");
	ESP_LOGD(TAG, "Opening Non-Volatile Storage (NVS) handle... ");
	esp_err_t result = nvs_open("storage", NVS_READWRITE, &Impl::my_handle);
	if (result not_eq ESP_OK) {
		ESP_LOGD(TAG, "Error (%s) opening NVS handle!\n", esp_err_to_name(result));
	} else {
		ESP_LOGD(TAG, "Done\n");
	}
	return;
}




int8_t Settings::getS8(const char section[], const char key[], const int8_t defaultValue)
{
	int8_t value;
	esp_err_t error = nvs_get_i8(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setS8(section, key, value);
	}
	ESP_LOGI(TAG, "setS8, section = %s, key = %s, value = %" PRIi8 "", section, key, value);
	return (value);
}

int16_t Settings::getS16(const char section[], const char key[], const int16_t defaultValue)
{
	int16_t value;
	esp_err_t error = nvs_get_i16(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setS16(section, key, value);
	}
	ESP_LOGI(TAG, "getS16, section = %s, key = %s, value = %" PRIi16 "", section, key, value);
	return (value);
}

int32_t Settings::getS32(const char section[], const char key[], const int32_t defaultValue)
{
	int32_t value;
	esp_err_t error = nvs_get_i32(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setS32(section, key, value);
	}
	ESP_LOGI(TAG, "getS32, section = %s, key = %s, value = %" PRIi32 "", section, key, value);
	return (value);
}

int64_t Settings::getS64(const char section[], const char key[], const int64_t defaultValue)
{
	int64_t value;
	esp_err_t error = nvs_get_i64(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setS64(section, key, value);
	}
	ESP_LOGI(TAG, "getS64, section = %s, key = %s, value = %" PRIi64 "", section, key, value);
	return (value);
}

uint8_t Settings::getU8(const char section[], const char key[], const uint8_t defaultValue)
{
	uint8_t value;
	esp_err_t error = nvs_get_u8(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setU8(section, key, value);
	}
	ESP_LOGI(TAG, "getU8, section = %s, key = %s, value = %" PRIu8 "", section, key, value);
	return (value);
}

uint16_t Settings::getU16(const char section[], const char key[], const uint16_t defaultValue)
{
	uint16_t value;
	esp_err_t error = nvs_get_u16(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setU16(section, key, value);
	}
	ESP_LOGI(TAG, "getU16, section = %s, key = %s, value = %" PRIu16 "", section, key, value);
	return (value);
}

uint32_t Settings::getU32(const char section[], const char key[], const uint32_t defaultValue)
{
	uint32_t value;
	esp_err_t error = nvs_get_u32(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setU32(section, key, value);
	}
	ESP_LOGI(TAG, "getU32, section = %s, key = %s, value = %" PRIu32 "", section, key, value);
	return (value);
}

uint64_t Settings::getU64(const char section[], const char key[], const uint64_t defaultValue)
{
	uint64_t value;
	esp_err_t error = nvs_get_u64(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setU64(section, key, value);
	}
	ESP_LOGI(TAG, "getU64, section = %s, key = %s, value = %" PRIu64 "", section, key, value);
	return (value);
}

uint64_t Settings::getX64(const char section[], const char key[], const uint64_t defaultValue)
{
	uint64_t value;
	esp_err_t error = nvs_get_u64(Impl::my_handle, key, &value);
	if (error not_eq ESP_OK)
	{
		value = defaultValue;
		Settings::setX64(section, key, value);
	}
	ESP_LOGI(TAG, "getX64, section = %s, key = %s, value = %" PRIx64 "", section, key, value);
	return (value);
}

size_t Settings::getString(const char section[], const char key[], const char defaultValue[], char captionOut[], size_t size)
{

	esp_err_t error = nvs_get_str(Impl::my_handle, key, captionOut, &size);
	if (error not_eq ESP_OK)
	{
		if (defaultValue == nullptr)
		{
			return (size_t)0U;
		}
		Settings::setString(section, key, defaultValue);
	}
	ESP_LOGI(TAG, "getString, section = %s, key = %s, value = %s", section, key, captionOut);
	return (strlen(captionOut));
}


void Settings::setS8(const char section[], const char key[], const int8_t value)
{
	ESP_LOGI(TAG, "setS8, section = %s, key = %s, value = %" PRIi8 "", section, key, value);
	nvs_set_i8(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setS16(const char section[], const char key[], const int16_t value)
{
	ESP_LOGI(TAG, "setS16, section = %s, key = %s, value = %" PRIi16 "", section, key, value);
	nvs_set_i16(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setS32(const char section[], const char key[], const int32_t value)
{
	ESP_LOGI(TAG, "setS32, section = %s, key = %s, value = %" PRIi32 "", section, key, value);
	nvs_set_i32(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setS64(const char section[], const char key[], const int64_t value)
{
	ESP_LOGI(TAG, "setS64, section = %s, key = %s, value = %" PRIi64 "", section, key, value);
	nvs_set_i64(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setU8(const char section[], const char key[], const uint8_t value)
{
	ESP_LOGI(TAG, "setU8, section = %s, key = %s, value = %" PRIu8 "", section, key, value);
	nvs_set_u8(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setU16(const char section[], const char key[], const uint16_t value)
{
	ESP_LOGI(TAG, "setU16, section = %s, key = %s, value = %" PRIu16 "", section, key, value);
	nvs_set_u16(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setU32(const char section[], const char key[], const uint32_t value)
{
	ESP_LOGI(TAG, "setU32, section = %s, key = %s, value = %" PRIu32 "", section, key, value);
	nvs_set_u32(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setU64(const char section[], const char key[], const uint64_t value)
{
	ESP_LOGI(TAG, "setU64, section = %s, key = %s, value = %" PRIu64 "", section, key, value);
	nvs_set_u64(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setX64(const char section[], const char key[], const uint64_t value)
{
	ESP_LOGI(TAG, "setX64, section = %s, key = %s, value = %" PRIx64 "", section, key, value);
	nvs_set_u64(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::setString(const char section[], const char key[], const char value[])
{
	ESP_LOGI(TAG, "setString, section = %s, key = %s, value = %s", section, key, value);
	nvs_set_str(Impl::my_handle, key, value);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}

void Settings::eraseString(const char section[], const char key[])
{
	ESP_LOGI(TAG, "erase_item, section = %s, key = %s", section, key);
	nvs_erase_key(Impl::my_handle, key);
	ESP_LOGD(TAG, "Committing updates in NVS ... ");
	esp_err_t err = nvs_commit(Impl::my_handle);
	ESP_LOGI(TAG, "Result: %s, %i, %s ", (err not_eq ESP_OK) ? "Failed!" : "Done", err, esp_err_to_name(err));
}







/* ************************************************************************ */

int8_t getS8(const char section[], const char key[], const int8_t defaultValue)
{
	return (Settings::getS8(section, key, defaultValue));
}

int16_t getS16(const char section[], const char key[], const int16_t defaultValue)
{
	return (Settings::getS16(section, key, defaultValue));
}

int32_t getS32(const char section[], const char key[], const int32_t defaultValue)
{
	return (Settings::getS32(section, key, defaultValue));
}

int64_t getS64(const char section[], const char key[], const int64_t defaultValue)
{
    return (Settings::getS64(section, key, defaultValue));
}

/* ************************************************************************ */

uint8_t getU8(const char section[], const char key[], const uint8_t defaultValue)
{
	return (Settings::getU8(section, key, defaultValue));
}

uint16_t getU16(const char section[], const char key[], const uint16_t defaultValue)
{
	return (Settings::getU16(section, key, defaultValue));
}

uint32_t getU32(const char section[], const char key[], const uint32_t defaultValue)
{
	return (Settings::getU32(section, key, defaultValue));
}

uint64_t getU64(const char section[], const char key[], const uint64_t defaultValue)
{
	return (Settings::getU64(section, key, defaultValue));
}

/* ************************************************************************ */

uint64_t getX64(const char section[], const char key[], const uint64_t defaultValue)
{
	return (Settings::getX64(section, key, defaultValue));
}

size_t getString(const char section[], const char key[], const char defaultValue[], char caption[], size_t size)
{
	return (Settings::getString(section, key, defaultValue, caption, size));
}

/* ************************************************************************ */

void setS8(const char section[], const char key[], const int8_t value)
{
	return (Settings::setS8(section, key, value));
}

void setS16(const char section[], const char key[], const int16_t value)
{
	return (Settings::setS16(section, key, value));
}

void setS32(const char section[], const char key[], const int32_t value)
{
	return (Settings::setS32(section, key, value));
}

void setS64(const char section[], const char key[], const int64_t value)
{
	return (Settings::setS64(section, key, value));
}

/* ************************************************************************ */

void setU8(const char section[], const char key[], const uint8_t value)
{
	Settings::setU8(section, key, value);
}

void setU16(const char section[], const char key[], const uint16_t value)
{
	Settings::setU16(section, key, value);
}

void setU32(const char section[], const char key[], const uint32_t value)
{
	Settings::setU32(section, key, value);
}

void setU64(const char section[], const char key[], const uint64_t value)
{
	Settings::setU64(section, key, value);
}

/* ************************************************************************ */

void setX64(const char section[], const char key[], const uint64_t value)
{
	Settings::setX64(section, key, value);
}

void setString(const char section[], const char key[], const char value[])
{
	Settings::setString(section, key, value);
}

/* ************************************************************************ */

void eraseString(const char section[], const char key[])
{
	Settings::eraseString(section, key);
}
/* ************************************************************************ */
void initSettings(void)
{
	Settings::init();
}
/* ************************************************************************ */

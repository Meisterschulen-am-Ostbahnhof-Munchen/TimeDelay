/*
 * settingsNVSinternal.h
 *
 *  Created on: 20.12.2021
 *      Author: franz
 */

#ifndef COMPONENTS_SETTINGS_SETTINGSNVSINTERNAL_H_
#define COMPONENTS_SETTINGS_SETTINGSNVSINTERNAL_H_


class Settings
{
private:
    // Internal implementation class
	struct Impl;
	Settings() = default;
public :

    static void init(void);
    static int8_t getS8(const char section[], const char key[], const int8_t defaultValue);
    static int16_t getS16(const char section[], const char key[], const int16_t defaultValue);
    static int32_t getS32(const char section[], const char key[], const int32_t defaultValue);
    static int64_t getS64(const char section[], const char key[], const int64_t defaultValue);
    static uint8_t getU8(const char section[], const char key[], const uint8_t defaultValue);
    static uint16_t getU16(const char section[], const char key[], const uint16_t defaultValue);
    static uint32_t getU32(const char section[], const char key[], const uint32_t defaultValue);
    static uint64_t getU64(const char section[], const char key[], const uint64_t defaultValue);
    static uint64_t getX64(const char section[], const char key[], const uint64_t defaultValue);
    static size_t getString(const char section[], const char key[], const char defaultValue[], char captionOut[], size_t size);
    static void setS8(const char section[], const char key[], const int8_t value);
    static void setS16(const char section[], const char key[], const int16_t value);
    static void setS32(const char section[], const char key[], const int32_t value);
    static void setS64(const char section[], const char key[], const int64_t value);
    static void setU8(const char section[], const char key[], const uint8_t value);
    static void setU16(const char section[], const char key[], const uint16_t value);
    static void setU32(const char section[], const char key[], const uint32_t value);
    static void setU64(const char section[], const char key[], const uint64_t value);
    static void setX64(const char section[], const char key[], const uint64_t value);
    static void setString(const char section[], const char key[], const char value[]);
    static void eraseString(const char section[], const char key[]);


};


#endif /* COMPONENTS_SETTINGS_SETTINGSNVSINTERNAL_H_ */

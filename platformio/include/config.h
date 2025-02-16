/* Configuration option declarations for esp32-weather-epd.
 * Copyright (C) 2022-2023  Luke Marzen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <cstdint>
#include <vector>
#include <Arduino.h>

// E-PAPER PANEL
// This project currently supports the following E-Paper panels:
//   DISP_BW - WaveShare 800x480, 7.5inch E-Ink display, Black/White
//             https://www.waveshare.com/product/7.5inch-e-paper-hat.htm
//   DISP_3C - Waveshare 800x480, 7.5inch E-Ink display, Red/Black/White
//             https://www.waveshare.com/product/7.5inch-e-paper-hat-b.htm
//   Note: Although this 3-color panel is supported, this program only draws
//         black/white to the screen. (i.e. no red icons/text)
// Uncomment the macro that identifies your panel. (exactly 1 must be defined)
#define DISP_BW
// #define DISP_3C

// LOCALE
// If your locale is not here, you can add it by copying and modifying one of
// the files in src/locales. Please feel free to create a pull request to add
// official support for your locale.
// Uncomment your preferred locale. (exactly 1 must be defined)
// #define LOCALE_EN_GB
#define LOCALE_EN_US

// UNITS
// Define exactly one macro for each unit below.

// UNITS - TEMPERATURE
//   Metric   : Celsius
//   Imperial : Fahrenheit
// #define UNITS_TEMP_KELVIN
// #define UNITS_TEMP_CELSIUS
#define UNITS_TEMP_FAHRENHEIT

// UNITS - WIND SPEED
//   Metric   : Kilometers per Hour
//   Imperial : Miles per Hour
// #define UNITS_SPEED_METERSPERSECOND
// #define UNITS_SPEED_FEETPERSECOND
// #define UNITS_SPEED_KILOMETERSPERHOUR
#define UNITS_SPEED_MILESPERHOUR
// #define UNITS_SPEED_KNOTS
// #define UNITS_SPEED_BEAUFORT

// UNITS - PRESSURE
//   Metric   : Millibars
//   Imperial : Inches of Mercury
// #define UNITS_PRES_HECTOPASCALS
// #define UNITS_PRES_PASCALS
// #define UNITS_PRES_MILLIMETERSOFMERCURY
#define UNITS_PRES_INCHESOFMERCURY
// #define UNITS_PRES_MILLIBARS
// #define UNITS_PRES_ATMOSPHERES
// #define UNITS_PRES_GRAMSPERSQUARECENTIMETER
// #define UNITS_PRES_POUNDSPERSQUAREINCH

// UNITS - VISIBILITY DISTANCE
//   Metric   : Kilometers
//   Imperial : Miles
// #define UNITS_DIST_KILOMETERS
#define UNITS_DIST_MILES

// AIR QUALITY INDEX
// Seemingly every country uses a different scale for Air Quality Index (AQI).
// I have written a library to calculate many of the most popular AQI scales.
// Feel free to request the addition of a new AQI scale by opening an Issue.
// https://github.com/lmarzen/pollutant-concentration-to-aqi
// Uncomment your preferred AQI scale. (exactly 1 must be defined)
// #define AUSTRALIA_AQI
// #define CANADA_AQHI
// #define EUROPE_CAQI
// #define HONG_KONG_AQHI
// #define INDIA_AQI
// #define MAINLAND_CHINA_AQI
// #define SINGAPORE_PSI
// #define SOUTH_KOREA_CAI
// #define UNITED_KINGDOM_DAQI
#define UNITED_STATES_AQI

// WIND ICON PRECISION
// The wind direction icon shown to the left of the wind speed can indicate wind
// direction with a minimum error of ±0.5°. This uses more flash storage because
// 360 24x24 wind direction icons must be stored, totaling ~25kB. For either
// preference or incase flash space becomes a concern there are a handful of
// selectable options listed below. 360 points seems excessive, but the option
// is there.
//
// DIRECTIONS                 #     ERROR  STORAGE  
// Cardinal                   4  ±45.000°     288B  E
// Ordinal                    8  ±22.500°     576B  NE
// Secondary Intercardinal   16  ±11.250°   1,152B  NNE
// Tertiary Intercardinal    32   ±5.625°   2,304B  NbE
// (360)                    360   ±0.500°  25,920B  1°
// Uncomment your preferred wind level direction precision.
// (exactly 1 must be defined)
// #define WIND_DIRECTIONS_CARDINAL
// #define WIND_DIRECTIONS_ORDINAL
#define WIND_DIRECTIONS_SECONDARY_INTERCARDINAL
// #define WIND_DIRECTIONS_TERTIARY_INTERCARDINAL
// #define WIND_DIRECTIONS_360

/* DISABLE ALERTS
 * The handling of alerts is complex. Each country has a unique national alert
 * system that recieves alerts from many different government agencies. This 
 * results is huge variance in the formatting of alerts. OpenWeatherMap provides
 * alerts in English only. Any combination of these factors may make it
 * undesirable to display alerts in some regions.
 * Disable alerts by uncommenting the ALERTS_DISABLED macro.
 */
// define ALERTS_DISABLED

// Set the below constants in "config.cpp"
extern const uint8_t PIN_BAT_ADC;
extern const uint8_t PIN_EPD_BUSY;
extern const uint8_t PIN_EPD_CS;
extern const uint8_t PIN_EPD_RST;
extern const uint8_t PIN_EPD_DC;
extern const uint8_t PIN_EPD_SCK;
extern const uint8_t PIN_EPD_MISO;
extern const uint8_t PIN_EPD_MOSI;
extern const uint8_t PIN_BME_SDA;
extern const uint8_t PIN_BME_SCL;
extern const uint8_t BME_ADDRESS;
extern const char *WIFI_SSID;
extern const char *WIFI_PASSWORD;
extern const String OWM_APIKEY;
extern const String OWM_ENDPOINT;
extern const String OWM_ONECALL_VERSION;
extern const String LAT;
extern const String LON;
extern const String CITY_STRING;
extern const char *TIMEZONE;
extern const char *TIME_FORMAT;
extern const char *HOUR_FORMAT;
extern const char *DATE_FORMAT;
extern const char *REFRESH_TIME_FORMAT;
extern const char *NTP_SERVER_1;
extern const char *NTP_SERVER_2;
extern const long SLEEP_DURATION;
extern const int BED_TIME;
extern const int WAKE_TIME;
extern const char UNITS;
extern const int HOURLY_GRAPH_MAX;
extern const float LOW_BATTERY_VOLTAGE;
extern const float VERY_LOW_BATTERY_VOLTAGE;
extern const float CRIT_LOW_BATTERY_VOLTAGE;
extern const unsigned long LOW_BATTERY_SLEEP_INTERVAL;
extern const unsigned long VERY_LOW_BATTERY_SLEEP_INTERVAL;

#endif

#ifndef SETTINGS_H
#define SETTINGS_H


// PROGRAM STATES
#define NORMAL 0
#define CHARGING 1
#define STANDBY 2
#define SAFETY 3

// VOLTAGE STATES
#define V_GOOD 0
#define V_TOO_LOW 1
#define V_TOO_HIG 2

// PUMP STATES
#define P_OFF 0
#define P_LOW 1
#define P_HIG 2




// THRESHOLDS
#define V_MIN 0.5
#define V_MAX 4.5
#define T_MIN 0.5
#define T_MID 3.0
#define T_MAX 4.5
#define C_MAX 4.0




// PINS (TBD)
#define PIN_READ_SENSOR_MUX 0
#define PIN_WRITE_PUMP_POWER_MUX 1
#define PIN_SELECT_SENSOR_MUX 0
#define PIN_SELECT_PUMP_POWER_MUX 1
#define PIN_VOLTAGE_00 0
#define PIN_VOLTAGE_01 1
#define PIN_VOLTAGE_02 2
#define PIN_VOLTAGE_03 3
#define PIN_VOLTAGE_04 4
#define PIN_VOLTAGE_05 5
#define PIN_VOLTAGE_06 6
#define PIN_VOLTAGE_07 7
#define PIN_VOLTAGE_08 8
#define PIN_VOLTAGE_09 9
#define PIN_VOLTAGE_10 10
#define PIN_VOLTAGE_11 11
#define PIN_VOLTAGE_12 12
#define PIN_VOLTAGE_13 13



// MUX CHANNELS: Pump and Power (TBD)
#define MUXCHAN_P_OFF 0
#define MUXCHAN_P_LOW 1
#define MUXCHAN_P_HIG 2
#define MUXCHAN_POWER 3

// MUX CHANNELS: SENSORS (TBD)
#define MUXCHAN_TEMP_00 0
#define MUXCHAN_TEMP_01 1
#define MUXCHAN_TEMP_02 2
#define MUXCHAN_TEMP_03 3
#define MUXCHAN_TEMP_04 4
#define MUXCHAN_TEMP_05 5
#define MUXCHAN_TEMP_06 6
#define MUXCHAN_TEMP_07 7
#define MUXCHAN_TEMP_08 8
#define MUXCHAN_TEMP_09 9
#define MUXCHAN_TEMP_10 10
#define MUXCHAN_TEMP_11 11
#define MUXCHAN_TEMP_12 12
#define MUXCHAN_TEMP_13 13
#define MUXCHAN_CURR_00 14



// OTHER
#define DIG_HIG 1
#define DIG_LOW 0
#define HISTORY_LEN 10
#define NO_MUX 255


#endif
/*

AllWize - Simple Example

Simple slave that sends faked data using CayenneLPP frame format.

Copyright (C) 2018-2021 by AllWize <github@allwize.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "AllWize.h"
#include "CayenneLPP.h"

// -----------------------------------------------------------------------------
// Board configuration
// -----------------------------------------------------------------------------

// Check http://wiki.allwize.io/index.php?title=Allwize_K2#Arduino_IDE
// to add support to Allwize K2 board in Arduino IDE
#if not defined(ARDUINO_ALLWIZE_K2)
    #error "This example is meant to run on an AllWize K2 board!"
#endif

#define MODULE_SERIAL           SerialWize
#define DEBUG_SERIAL            SerialUSB
#define RESET_PIN               PIN_WIZE_RESET

// -----------------------------------------------------------------------------
// Configuration
// -----------------------------------------------------------------------------

#define WIZE_CHANNEL            CHANNEL_04
#define WIZE_POWER              POWER_14dBm
#define WIZE_DATARATE           DATARATE_2400bps
#define WIZE_MID                0x06FA
#define WIZE_UID                0x20212223
#define WIZE_APP_ID		          0xFE
#define WIZE_NETWORK_ID		      0x01

#define BATTERY_MONITOR_PIN     A3
#define BATTERY_MONITOR_ENABLE  4
#define BATTERY_RATIO           (3300.0 * 2.0 / 1024.0)

// -----------------------------------------------------------------------------
// Globals
// -----------------------------------------------------------------------------

AllWize allwize(&MODULE_SERIAL, RESET_PIN);
CayenneLPP payload(32);

// -----------------------------------------------------------------------------
// AllWize
// -----------------------------------------------------------------------------

void wizeSetup() {

    DEBUG_SERIAL.println("[WIZE] Initializing radio module");

    // Init AllWize object
    allwize.begin();
    if (!allwize.waitForReady()) {
        DEBUG_SERIAL.println("[WIZE] Error connecting to the module, check your wiring!");
        while (true);
    }

    allwize.slave();
    allwize.setChannel(WIZE_CHANNEL, true);
    allwize.setPower(WIZE_POWER);
    allwize.setDataRate(WIZE_DATARATE);
    allwize.setMID(WIZE_MID);
    allwize.setUID(WIZE_UID);
    allwize.setWizeApplication(WIZE_APP_ID);
    allwize.setWizeNetworkId(WIZE_NETWORK_ID);

    DEBUG_SERIAL.println("[WIZE] Ready...");

}

void wizeSend(uint8_t * payload, size_t len) {

    char buffer[64];
    DEBUG_SERIAL.print("[WIZE] Sending: ");
    for (uint8_t i = 0; i<len; i++) {
        snprintf(buffer, sizeof(buffer), "%02X", payload[i]);
        DEBUG_SERIAL.print(buffer);
    }
    DEBUG_SERIAL.print("\n");

    if (!allwize.send(payload, len)) {
        DEBUG_SERIAL.println("[WIZE] Error sending message");
    }

}

// -----------------------------------------------------------------------------
// Sensors
// -----------------------------------------------------------------------------

void sensorSetup() {
    pinMode(BATTERY_MONITOR_ENABLE, OUTPUT);
    pinMode(BATTERY_MONITOR_PIN, INPUT);
    digitalWrite(BATTERY_MONITOR_ENABLE, HIGH);
    analogReadResolution(10);
}

// Returns the temperature in C (with 1 decimal)
float getTemperature() {
    float t = random(100, 300) / 10.0;
    DEBUG_SERIAL.print("[SENSOR] Temperature (C): ");
    DEBUG_SERIAL.println(t);
    return t;
}

// Returns humidity in %
int getHumidity() {
    unsigned char h = random(20, 70);
    DEBUG_SERIAL.print("[SENSOR] Humidity (%): ");
    DEBUG_SERIAL.println(h);
    return h;
}

// Returns pressure in hPa
float getPressure() {
    float p = random(99000, 120000) / 100.0;
    DEBUG_SERIAL.print("[SENSOR] Pressure (hPa): ");
    DEBUG_SERIAL.println(p);
    return p;
}

// Returns battery level in mV
float getBattery() {
    digitalWrite(BATTERY_MONITOR_ENABLE, LOW);
    delay(40);
    float battery = BATTERY_RATIO * analogRead(BATTERY_MONITOR_PIN);
    digitalWrite(BATTERY_MONITOR_ENABLE, HIGH);
    DEBUG_SERIAL.print("[SENSOR] Battery (mV): ");
    DEBUG_SERIAL.println(battery);
    return battery;
}


// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

void setup() {

    // Init serial DEBUG_SERIAL
    DEBUG_SERIAL.begin(115200);
    while (!DEBUG_SERIAL && millis() < 5000);
    DEBUG_SERIAL.println();
    DEBUG_SERIAL.println("[MAIN] Basic slave example");

    // Init radio
    wizeSetup();

    // Sensor setup
    sensorSetup();

}

void loop() {

    // Build payload
    payload.reset();
    payload.addAnalogInput(1, getBattery());
    payload.addTemperature(2, getTemperature());
    payload.addRelativeHumidity(3, getHumidity());
    payload.addBarometricPressure(4, getPressure());

    // Send the string as payload
    wizeSend(payload.getBuffer(), payload.getSize());

    // Delay responses for 20 seconds
    delay(20000);

}

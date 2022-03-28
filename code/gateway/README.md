# AllWize - WIZE 2 MQTT Bridge

Listens to messages on the same channel and data rate,
decodes them using LPP or MBUS and forwards them to an MQTT broker.
This example is meant to run on a Wemos D1 board (ESP8266).

Configuration: copy the `configuration.sample.h` file to `configuration.h` and
edit it to configure your WiFi network credentials and the MQTT broker data.

**NOTICE: Use Arduino for ESP8266 2.4.X!!**

Required libraries:

* AllWize @ 1.1.6
* CayenneLPP @ 1.1.0
* ArduinoJson @ 6.17.3
* MBUSPayload @ 1.0.0
* AsyncMqttClient @ 0.8.2 (ZIP in `libraries` folder)
* ESPAsyncTCP @ 1.2.0 (ZIP in `libraries` folder)
* AsyncTCP @ 1.1.1 (ZIP in `libraries` folder)

Always remember to connect the antenna before powering the board!

## License

Copyright (C) 2018-2021 by AllWize ([http://allwize.io](http://allwize.io))

AllWize library is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AllWize library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with AllWize library.  If not, see <http://www.gnu.org/licenses/>.

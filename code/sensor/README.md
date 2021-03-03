# AllWize - BME280 Slave Example

Shows how to use a BME280 sensor (temperature, humidity & pressure) to send environmental data using CayenneLPP format.

Required libraries:

* AllWize @ 1.1.6
* CayenneLPP @ 1.1.0
* ArduinoJson @ 6.17.3
* Adafruit Unified Sensor @ 1.1.4
* Adafruit BME280 Library @ 2.1.2

The BME280 is a I2C sensor that must be powered with 3V3.
Remember that Grove I2C sensor use the following color convention:

* Black - Negative / Ground
* Red - Positive / Power / 3V3 / 5V
* White - SDA / DA
* Yellow - SCL / CL

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

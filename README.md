# AllWize Training Environment

This repository contains a training environment for workshops using two different approaches:

* A vagrant definition file for a VirtualBox machine
* A docker-compose file to run a docker stack

The Vagrant machine will be reacheble at 192.168.42.10, the docker container will expose the ports directly to the host machine.
None of the services have any security defined. 

**This environment is not meant for production or machines exposed to the Internet!!!**

|Service|port|
|---|---|
|Mosquitto|1883|
|NodeRED|1880|
|InfluxDB|8086|
|Grafana|3000|

## License

Copyright (C) 2020 by AllWize ([http://allwize.io](http://allwize.io))

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

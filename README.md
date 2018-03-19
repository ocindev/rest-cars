
![RestCars Logo](/images/header.png)
 
# The Project
The Rest Cars project provides Project Cars 2 Shared Memory Data via JSON over HTTP. The native windows command prompt application will act as a local webserver that provides the data over HTTP. Any HTTP client or web browser is able to access data provided by the API.

The application is mainly written in C++ and uses a embedded web server called mongoose (https://github.com/cesanta/mongoose).

For future implementation of functions you can take a look at the waffle board:


[![Waffle.io - Columns and their card count](https://badge.waffle.io/i12bokay/rest-cars.svg?columns=all)](https://waffle.io/i12bokay/rest-cars)

# Planned functions

HTML Stream overlays for stream applications such as OBS or XSplit:
* track map with current participiant positions
* participiant listing with standings and relative positions
* clutch and brake overlay
* steering overlay with exchangable wheel images

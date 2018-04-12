
![RestCars Logo](/images/header.png)
 
# The Project
The Rest Cars project provides Project Cars 2 Shared Memory Data via JSON over HTTP. The native windows command prompt application will act as a local webserver that provides the data over HTTP. Any HTTP client or web browser is able to access data provided by the API.

The application is mainly written in C++ and uses mongoose for networking (https://github.com/cesanta/mongoose).

It is heavily inspired and based on the CREST Project made by Lars Rosenquist (https://github.com/NLxAROSA/CREST).
__Thanks for your work !__

# Usage

* Download the [latest release](https://github.com/nweiser94/rest-cars/releases/latest)
* Make sure that Project Cars 2 is running and SharedMemory (Project Cars2) is enabled
* Open the rest-cars.exe
* Open the url http://localhost:8000/restcars/api to access the REST-API
* [Sample json](https://raw.githubusercontent.com/nweiser94/rest-cars/master/rest-cars_example.json)

# Planned features

* Easy to use GUI



# Stream overlays

Aside from the REST API i work on a bunch of useful stream overlays for stream applications such as OBS and XSplit: 
* track map with current participiant positions
* participiant listing with standings and relative positions
* clutch and brake overlay
* steering overlay with exchangable wheel images

They are managed in an seperated repository: [Rest Cars Overlays](https://github.com/i12bokay/rest-cars-overlays)



# hvac-controller
ECE 561 project for a home HVAC controller using Arduino Opla platform.

This will have several interconnected components, each one communicating with a different sensor or peripheral.
The HVAC controller will sense and control several metrics related to HVAC.  For each metric, the overarching system (controller) will have multiple functions:

* Sensing: Sensors will be attached to the Opla carrier.
* Control: 
* Communication: sensor data will be displayed on the Arduino Opla display and more data regarding sensing, control, and current preferences will be available on Arduino Cloud
* Customization: Users will be able to customize desired controller behavior using decision thresholds, with common presets available
* Simulation: Future activity will be projected based on static models and input thresholds
* Diagnostics: Performance data such as compute usage, power, and battery will be made available [^note]


### Temperature, Humidity, Barometric Pressure



[^note]: This functionality may require significant overhead that poses compatibility challenges with our platforms in use.

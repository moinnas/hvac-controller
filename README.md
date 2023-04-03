# hvac-controller
ECE 561 project for a home HVAC controller using Arduino Opla platform.

This will have several interconnected components, each one communicating with a different sensor or peripheral.
The HVAC controller will sense and control several metrics related to HVAC.  For each metric, the overarching system (controller) will have multiple functions:

* Sensing: Sensors will be attached to the Opla carrier.
* Control: Operate fans, heating, hummidification, etc appliances based on on sensor data and desired behavior
* Communication: sensor data will be displayed on the Arduino Opla display and more data regarding sensing, control, and current preferences will be available on Arduino Cloud
* Customization: Users will be able to customize desired controller behavior using decision thresholds, timing, and room measurments, with common presets available
* Simulation: Future activity will be projected based on static models and input thresholds
* Diagnostics: Performance data such as compute usage, power, and battery will be made available [^note].  Will also include heuristics for determining component failure.


### Metrics
Each of the following metrics will be used to inform control measures on the appliances available:

* Temperature: sensor is built into the Opla platform
    * Control measures will be a fan for cooling and a heating plate for warming
* Air quality: sensor will be a MQ 135 air particle detector
    *  Controlled by a HEPA filter attached fan
*  Humidity: sensor is native to the Opla platform
    *  Controlled by an ultrasonic mist maker attached to a fan
*  Barommetric pressure: sensor is native to Opla platform
    * Cannot be controlled on the desired scale; may be used to inform other thresholding decisions



[^note]: This functionality may require significant overhead that poses compatibility challenges with our platforms in use.

main trick - 1st values from sensor after reset is always 0 - need to drop them.


test with WiringPi for amd8833, based on adafruit python code

https://learn.adafruit.com/adafruit-amg8833-8x8-thermal-camera-sensor/python-circuitpython


```
void QAMG8833::update()
void QAMG8833::dumpData()
reading 0x0F/0x0E regs: sensor temp 26.9375
results: 64
22.75 	 23.5 	 23.5 	 23.75 	 23.75 	 23.25 	 24.25 	 24.25
23.25 	 22.75 	 23 	 23 	 23 	 23.25 	 23.5 	 23
23.25 	 22.5 	 23.75 	 24 	 24 	 23.5 	 23.75 	 24
23 	 21.75 	 24.25 	 23.25 	 24.75 	 23.75 	 24.25 	 23.5
22.75 	 22.75 	 24 	 24.5 	 24.5 	 25.5 	 23.25 	 23.75
23 	 22.75 	 23.75 	 24 	 23.75 	 24 	 23.75 	 23.5
23.25 	 22.75 	 23.5 	 22.75 	 23 	 23.75 	 23.75 	 23.5
22.25 	 23 	 22.75 	 22.75 	 22.75 	 22.75 	 23 	 23
```

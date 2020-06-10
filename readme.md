<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Getting Started with the OPA module on the PIC18F16Q41
The Operational Amplifier (OPA) module on the PIC18F16Q41 is an embedded operational amplifier with an internal resistor ladder. This code example demonstrates the OPA module switching between the 4 different configurations - Unity Gain, Non-Inverting, Inverting, and External.

## Related Documentation
TBxxxx, "Using Operational Amplifiers in PIC16 and PIC18"<br>
TBxxxx, "Optimizing Internal Operational Amplifiers for Analog Signal Conditioning"<br>
ANxxxx, "Analog Sensor Measurement and Acquisition"

The above documents will be published soon. They will cover software setup for the OPA module and recommendations for analog signal sensor interfacing.
## Software Used

* <a href="http://www.microchip.com/mplab/mplab-x-ide">MPLAB® IDE 5.40 or newer</a>
* <a href="https://www.microchip.com/mplab/compilers">Microchip XC8 Compiler 2.20 or newer</a>
* <a href="https://www.microchip.com/mplab/mplab-code-configurator">MPLAB® Code Configurator (MCC) 3.95.0 or newer</a>

## Hardware Used

* <a href="https://www.microchip.com/wwwproducts/en/PIC18F16Q41">PIC18F16Q41 Product Information</a><br>
* <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137"> Microchip Curiosity Development Board (DM164137) </a>
* Variable Power Supply (0 - 5V) or Potentiometer
  * To use the built-in potentiometer on the Curiosity board, use a wire to move it from RC0 to the desired input.
* Parts for an external operational amplifier configuration (resistors, capacitors, etc...)

## Setup
#### External Pins

| Pin | Function
| --- | --------
| RA2 | Input for Unity Gain, Inverting, and Non-Inverting Configurations
| RB5 | Non-Inverting Input for External Configuration
| RB4 | Inverting Input for External Configuration
| RC2 | OPA Module Output

#### Parts on the Curiosity

| Pin | Function
| --- | --------
| RA5 | LED D4 - Configuration Indicator Bit 0
| RA1 | LED D5 - Configuration Indicator Bit 1
| RA2 | LED D6 - Not used, see note below
| RC5 | LED D7 - 2 Hz blinking light
| RC4 | S1 - Pushbutton Switch
| RC0 | *(if used)* Potentiometer on the Curiosity board

Note: LED D6 (RA2) changes intensity with the input. The potentiometer is not adversely affected by the LED on the pin in this case.

#### Internal Configurations Wiring
For the 3 internal configurations (unity gain, non-inverting, and inverting), RA2 is the input signal. Connect the variable power supply to this pin, or use a wire to move the output of the potentiometer from RC0 to RA2.

#### External Configuration Wiring

For the external configuration, the internal components are disabled. The exact components for this setup depend on the desired operational amplifier configuration. A list of a few standard configurations is shown below.

* Non-Inverting Amplifier
* Inverting Amplifier
* Unity Gain Buffer

## Operation
This code example demonstrates the 4 configurations possible with the OPA module - Unity Gain, Non-Inverting, Inverting, and External.

S1 on the Curiosity board triggers a move to the next configuration.

The current configuration is displayed on LEDs D4 and D5. The table below shows the order of switching, and the output function (using the default settings).

| Configuration                       | LEDs (D5, D4) | Output function
| ----------------------------------- | ------------- | -----
| Unity Gain                          | 00            | Vout = Vin
| Non-Inverting Amplifier             | 01            | Vout = 2 x Vin
| Inverting Amplifier<sup>1</sup>     | 10            | Vout = Vdd - Vin
| External                            | 11            | Dependent on Configuration

1 - The impedance of the input source may change the transfer function.

## Summary
This code example demonstrates the 4 basic modes of operation possible with the OPA module on the PIC18F16Q41.

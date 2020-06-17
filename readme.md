<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Getting Started with the OPA module on the PIC18F16Q41
On the PIC18F-Q family, the operational amplifier (OPA) module is a powerful analog peripheral. The OPA module comes with an internal resistor ladder, which can be used to create a non-inverting or inverting amplifier with no external components required. An internal switch can set the OPA module into unity gain without an external jumper wire. The OPA module also has the option for an external configuration, where the user can use externally placed components to build a custom amplifier configuration. This code example is designed to switch between and demonstrate the 4 configurations listed above -  Unity Gain, Non-Inverting Amplifier, Inverting Amplifier, and External.

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
* Potentiometer or Signal Source
  * To use the built-in potentiometer on the Curiosity board, use a wire to move it from RC0 to the desired input.
* Parts for an external operational amplifier configuration (resistors, capacitors, etc...)

## Setup
#### Pin Table

| Pin | Name          | Function
| --- | ------------- | ---
| RC5 | LED D7        | 2 Hz blinking light
| RC4 | S1            | Pushbutton Switch
| RC2 | OPA1OUT       | OPA Module Output
| RC0 | Potentiometer | Potentiometer on the Curiosity board
| RB5 | OPA1IN0+      | Non-Inverting Input for External Configuration
| RB4 | OPA1IN0-      | Inverting Input for External Configuration
| RA5 | LED D4        | Configuration Indicator Bit 0
| RA2 | OPA1IN        | Input for Unity Gain, Inverting, and Non-Inverting Configurations.<sup>1</sup>
| RA1 | LED D5        | Configuration Indicator Bit 1


Note:
1. LED D6 (RA2) changes intensity with the input. The voltage range of the potentiometer is reduced slightly due to the LED.

#### Internal Configurations Wiring<br>
<img src="images/InternalWiring.JPG" width="500px" alt="Internal Wiring"><br>
*Wiring the internal configurations using the potentiometer*

| Wire   | Name   | Function
| ------ | ------ | --------
| Yellow | OPA1IN | Input to the Operational Amplifier. Connect to a signal source such as RC0 (potentiometer (shown)).
| White  | OPA1OUT | Output of the Operational Amplifier

These modes of operation (unity gain, non-inverting, and inverting) utilize the internal resistor ladder or unity gain override of the OPA module. No external parts are needed for these modes. The internal pin-selection multiplexer is used with each configuration to set RA2 to be the signal input. The potentiometer on RC0 can be connected to RA2 in order to avoid the need for an external signal source.

#### External Configuration Wiring
For the external configuration, the internal feedback network is disabled, and all of the inputs to the operational amplifier are connected to I/O pins. In this mode, the OPA module on the device acts like a discrete single-supply operational amplifier.

This type of configuration is recommended when the internal ladder is not precise enough  or the circuit desired is not possible using the internal ladder (ex: Summing Amplifier).

## I/O Cautions
**The device will be permanently damaged by voltages above Vdd and below Vss. Do not apply these levels to any I/O on the device. Please consult the device datasheet for more information.**

## Operation
This code example demonstrates 4 basic configurations of the OPA module - Unity Gain, Non-Inverting, Inverting, and External.

S1 on the Curiosity board switches to the next configuration.

The current configuration is displayed on LEDs D4 and D5. The table below shows the order of switching and the output function.

| Configuration                       | LEDs (D5, D4) | Output function
| ----------------------------------- | ------------- | -----
| Unity Gain                          | 00            | Vout = Vin
| Non-Inverting Amplifier             | 01            | Vout = 2 x Vin
| Inverting Amplifier<sup>1</sup>     | 10            | Vout = Vdd - Vin
| External                            | 11            | Dependent on Configuration

Note:<br>
1 - The impedance of the input source affects the transfer function. For best results, the impedance of the source should be very low.

#### Unity Gain <br>
<img src="images/UnityGainSchematic.png" width="500px" alt="Unity Gain Schematic"><br>
*Unity Gain Schematic*<br>

In unity gain, the OPA module acts as a voltage buffer, tracking the input signal with the output for a gain of 1. This is most useful for sensitive signals that have a full-scale range, such as resistive voltage dividers.

<img src="images/unityGain.PNG" width="500px" alt="Unity Gain Output"><br>
*Unity Gain Output*<br>

The code snippet below is a (human readable) example of configuring the OPA module in unity gain.<br>

```
void UnityGainSetup(void)
{
    OPA1CON0 = 0x00;
    OPA1CON0bits.UG = 1;

    OPA1CON1 = 0x00;
    OPA1CON2 = 0x00;

    //Connect the Non-inverting input to OPA1IN0+
    OPA1CON2bits.PCH = 0b010;

    OPA1CON3 = 0x00;

    //Enable the Module
    OPA1CON0bits.EN = 1;
}
```

#### Non-Inverting Amplifier<br>
<img src="images/nonInvertingSchematic.png" width="500px" alt="Non-Inverting Schematic"><br>
*Non-Inverting Amplifier Schematic*<br>

The non-inverting amplifier produces an output greater than the input signal, with the gain in this configuration being **R2/R1 + 1**. In this code example, the internal resistor ladder is used to generate a gain of 2, however other gain options are available on the internal ladder.

<img src="images/nonInverting.PNG" width="500px" alt="Non-Inverting Amplifier Output"><br>
*Non-Inverting Amplifier (Gain of 2) Output* <br>

The code snippet below is a (human readable) example of configuring the OPA module as a non-inverting amplifier.<br>

```
void NonInvertingSetup(void)
{
    OPA1CON0 = 0x00;
    OPA1CON1 = 0x00;
    OPA1CON1bits.RESON = 1;
    OPA1CON1bits.GSEL = 0b011;  //Gain of 2

    //Ground the resistor ladder
    OPA1CON1bits.NSS = 0b111;

    OPA1CON2 = 0x00;

    //Connect the inverting input to the resistor ladder
    OPA1CON2bits.NCH = 0b001;

    //Connect the Non-inverting input to OPA1IN+
    OPA1CON2bits.PCH = 0b010;

    OPA1CON3 = 0x00;

    //Select OPA1IN0+ as the input
    OPA1CON3bits.PSS = 0b00;

    //Use internal feedback
    OPA1CON3bits.FMS = 0b10;

    //Enable the Module
    OPA1CON0bits.EN = 1;
}
```

#### Inverting Amplifier<br>
<img src="images/invertingSchematic.png" width="500px" alt="Inverting Amplifier Schematic"><br>
*Inverting Amplifier Schematic*<br>

The inverting amplifier produces an output that is inverted from the input. Since the OPA module is a single-supply device, the output must be level-shifted for correct operation. Vbias is used to level-shift the output of the operational amplifier in this configuration, with the level set to **(1 + R2/R1) * Vbias**. The level-shifted gain of this setup is equal to **-R2/R1**.<br>

<img src="images/inverting.PNG" width="500px" alt="Inverting Amplifier Output"><br>
*Inverting Amplifier Output*<br>
Note: The scale for output (yellow) has been increased to 1V/div from 500mV/div.<br>

The code snippet below is a (human readable) example of configuring the OPA module as an inverting amplifier.<br>

```
void InvertingSetup(void)
{
    OPA1CON0 = 0x00;
    OPA1CON1 = 0x00;

    OPA1CON1bits.RESON = 1;
    OPA1CON1bits.GSEL = 0b101;  //Gain of 3

    //Select OPA1IN0- as the input
    OPA1CON1bits.NSS = 0b000;   

    OPA1CON2 = 0x00;

    //Connect the inverting input to the resistor ladder
    OPA1CON2bits.NCH = 0b001;   

    //Connect the non-inverting input to Vdd/2
    OPA1CON2bits.PCH = 0b011;

    OPA1CON3 = 0x00;

    //Enable internal feedback
    OPA1CON3bits.FMS = 0b10;

    //Enable the Module
    OPA1CON0bits.EN = 1;
}
```

## Summary
The OPA module in the PIC18-Q family is a flexible analog peripheral that can be used in a number of ways. Each configuration has a specific use case that can aid in signal acquisition applications through an internal connection with the ADC. Other analog peripherals can also utilize the OPA module to unlock new use cases, for instance, the DAC output can be mirrored or tracked in output level through the module. The 4 configurations shown in this code example are the tip of the iceberg - most op-amp circuit can be modified to function on the OPA module.

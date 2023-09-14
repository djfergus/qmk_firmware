# Macropad Pico

This is a pico port of my [macropad](https://github.com/ArtiomSu/qmk_firmware/tree/macropad_artiomsu/keyboards/macropad_artiomsu) with additional features

[RP 2040 Pinout](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md)

OLED Setup stolen from [here](https://learn.adafruit.com/using-qmk-on-rp2040-microcontrollers/kb2040-one-key-keyboard-with-oled-display) 

## Rotary Encoder Info
[qmk docs](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md)

So when you are buying one, make sure it says EC11 somewhere in the shop listing.

When hooking up the encoder you will see there is one side with 3 pins and another side with 2 pins.

The 2 pin side is just the regular switch.

The 3 pin side, has the ground pin in the middle. And the two pins on the side would plug into any GPIO pins you want

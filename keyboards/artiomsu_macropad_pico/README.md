# Macropad Pico

This is a pico port of my [macropad](https://github.com/ArtiomSu/qmk_firmware/tree/macropad_artiomsu/keyboards/macropad_artiomsu) with additional features aswell as using the raspberry pi pico instead of the arduino pro micro

# Sections
[Pico Vs Pro Micro](#why-the-raspberry-pi-pico-rp-2040-instead-of-the-usual-pro-micro)

[Parts List](#parts-list)

[Build Guide](#build-guide)

[Build Videos](#build-video)

[QMK Tips](#qmk-tips)

[Photos](#photos)

# Why the raspberry pi pico (RP 2040) instead of the usual pro micro?

I used the pro micro for my 30 key keyboard and macro pad before. This was before QMK supported the RP 2040. And on both ocassions I had to trim down the firmware/make compromises as I ran out of ram or flash storage.

This won't be a problem with the RP 2040, due to the massive spec gap. Also weirdly enough the RP 2040 can be found for cheaper.

RP 2040 vs pro micro specs
| Controller | CPU Speed | RAM    | FLASH |
| -----------|-----------|--------|-------|
| RP 2040    | 133 MHz   | 264 KB | 2 MB  |
| Pro Micro  | 16 Mhz    | 2.5 KB | 32 KB |

So as you can see the pico is over 100x more powerful in some aspects so running out of ram or flash storage is a thing of the past. As well as having two cpu cores, but I'm not sure if qmk utilises them, I don't think so.

The pico also has two hardware state machines that can be used for the LEDs and serial communication between the two halves, leaving more reasources available for your custom functions.

So overall the pico will be the go to controller for qmk from now on.

# Parts List
| Quantity | Item | Price | Shop | Optional |
|----------|------|-------|------|----------|
|1| raspberry pi pico | €5 | Pimoroni (€10 shipping) if in EU, Adafruit if in US | No |
|21| 1N4148 diodes | €8 for 500 | Amazon UK | No |
|27| switches (I reused my Box Navies from my ergodox)| - | - | No |
|27| keycaps (I reused keycaps from my ergodox again)| - | - | No |
|4| EC11 rotaty encoder | €2 for 5 | ebay | No |
|1| 128x32 OLED AVR display | €3 | ebay | No |
|1| case. I 3d printed mine. You will need about 150 grams of fillament for these | €35 | Amazon for 1KG fillament | No |
|1| 10 Pin rainbow ribbon cable | €7 | Amazon | Yes |
|1| WS2812B 60/m led strip (1m) | €5 | Ebay | Yes |
|100| Wires, (try get the breadboard jumper Arduino kind so we can easily connect it to the controller) | €11 | Amazon | No |
|1| Soldering Iron, Solder Wire | - | - | No |
|1| Hotglue Gun and sticks | - | - | No |

# Build Guide

For the volume knobs I got them from [here](https://www.thingiverse.com/thing:4206617) make sure to use the 20mm one. 

# Build Videos

# QMK Tips

[RP 2040 Pinout](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md)

OLED Setup stolen from [here](https://learn.adafruit.com/using-qmk-on-rp2040-microcontrollers/kb2040-one-key-keyboard-with-oled-display) 

build test firmware

`make clean && qmk flash -kb artiomsu_macropad_pico -km test`

## Rotary Encoder Info
[qmk docs](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md)

So when you are buying one, make sure it says EC11 somewhere in the shop listing.

When hooking up the encoder you will see there is one side with 3 pins and another side with 2 pins.

The 2 pin side is just the regular switch.

The 3 pin side, has the ground pin in the middle. And the two pins on the side would plug into any GPIO pins you want

# Photos

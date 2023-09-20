# Macropad Pico

![header](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/header.jpg)

This is a remake of my first [macropad](https://github.com/ArtiomSu/qmk_firmware/tree/macropad_artiomsu/keyboards/macropad_artiomsu) with additional features aswell as using the raspberry pi pico instead of the arduino pro micro

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

#### Step 1
Connect up the 3 pins to each rotary encoder and test them to make sure they work using the simple qmk firmware.
![step_1](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_1.jpg)

#### Step 2
Plug in all the switches, make sure they are in the same direction
![step_2](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_2.jpg)

#### Step 3
Secure the Switches with hotglue
![step_3](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_3.jpg)

#### Step 4
Add the diodes. Make sure they are all facing down and don't forget to include the rotaty encoders.
![step_4](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_4.jpg)

#### Step 5
Wire up the rows.
![step_5](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_5.jpg)

#### Step 6
Wire up the columns
![step_6](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_6.jpg)

#### Step 7
Extend the rows. Now you can test to see if the switches function ok with qmk. Wire then up using the pin layout inside info.json
![step_7](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_7.jpg)

#### Step 8
Glue in the OLED display. Connect it to the 3v output on the pico, can use 5v if you want but I'm using that for the leds and didn't want to splice wires together.
![step_8](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_8.jpg)

#### Step 9
Prepare the led strip. There is 6 sections with 5 leds each.
![step_9](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_9.jpg)

#### Step 10
Glue in the led strip grid. Connect it to 5v output on the pico.
![step_10](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/step_10.jpg)


# Build Video

coming soon.

# QMK Tips

[RP 2040 Pinout](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md)

[OLED docs](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md)

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

![photo1](https://github.com/ArtiomSu/qmk_firmware/raw/artiomsu_macropad_pico/keyboards/artiomsu_macropad_pico/public/images/photo_1.jpg)



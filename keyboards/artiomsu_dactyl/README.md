# RP 2040 Handwired Dactyl Manuform 5x7 by ArtiomSu

# README WIP

![header1](/public/images/header.jpg)

This is using the raspberry pi pico micro controller on both halves of the keyboard. 

The dactyl keyboard present in the qmk repo is configured with the pro micro in mind, hence I split this out into its own keyboard directory. Also so I can include the build guide. 


# Wiring Diagram
I didn't find any decent wiring diagram for the 5x7 form factor and it took me some time to figure it out. So here is a diagram I created.  

![wiring_diagram](/public/images/wiring.png)

Make sure to take note of the differences on the wiring of the ttrs jack and columns between the two sides.

The numbers and letters in the diagram correspond to the pin labels you see on the physical micro controller. These won't be the same pins used in qmk but it helps with the wiring. 

For the actual pins to use in qmk, they need to be the GPIO equivelent. See the [pinout here](https://learn.adafruit.com/adafruit-kb2040/pinouts)

# Parts List
| Quantity | Item | Price | Shop | Optional |
|----------|------|-------|------|----------|
|2| adafruit KB 2040 (same chip as the official raspberry pi pico but slightly smaller and has USB C) micro controllers | €25 | Pimoroni (€10 shipping) if in EU, Adafruit if in US | No |
|2| JST-SH Cable (Qwicc, STEMMA QT, QW/ST) | €3 | Pimoroni (€10 shipping) if in EU, Adafruit if in US | Yes (you can use any spare pin on the controller for hooking up the led strip) |
|74| 1N4148 diodes | €8 for 500 | Amazon UK | No |
|2| TTRS Jack breakout board | €6 for 10 | Amazon UK | No |
|74| switches (I reused my ZealPc Clickiez from my ergodox)| - | - | No |
|74| keycaps (I reused keycaps from my ergodox again)| - | - | No |
|2| dactyl cases. I 3d printed mine. You will need almost a full 1KG fillament spool for these | €35 | Amazon for fillament | No |
|2| wrist wrests. I 3d printed these too | - | - | Yes but recommended |
|1| 10 Pin rainbow ribbon cable | €7 | Amazon | Yes |
|1| WS2812B 144/m led strip (1m) | €12 | Amazon | Yes |
|1| WS2812B 60/m led strip (3m) | €12 | Ebay | Yes |
|100| Wires, (try get the breadboard jumper Arduino kind so we can easily connect it to the controller) | €11 | Amazon | No |
|1| Soldering Iron, Solder Wire | - | - | No |
|1| Hotglue Gun and sticks | - | - | Yes but recommended |

So the build is actually quite affordable, provided that you are reusing the switches and keycaps from a different keyboard. If you don't have a 3d printer, there are 3d printing services that do it for you. It shouldn't cost more than €50 to get the two halves printed and shipped. 

# Build Guide
### Build video
coming soon
#### Step 1
Wire up the diodes. Take note of the direction, make sure it is the same as the diagram.
![step_1](/public/images/step_1.jpg)

#### Step 2
Wire up the columns as per the diagram.
![step_2](/public/images/step_2.jpg)

#### Step 3
Wire up the rows as per the diagram.
![step_3](/public/images/step_3.jpg)

#### Step 4
Extend the connectors so that we can easily plug into the controller.
![step_4](/public/images/step_4.jpg)

#### Step 5
This step assumes you have soldered on the connectors to both the micro controller and the ttrs breakout board.

Now just wire them up as in the diagram.
![step_5](/public/images/step_5.jpg)

#### Step 6
Prepare the first led strip. This will be powered by the Stemma QT port at the bottom of the kb 2040 micro controller. 

Also add connectors for the second led strip.
![step_6](/public/images/step_6.jpg)

#### Step 7
Secure the connections with hotglue
![step_7](/public/images/step_7.jpg)

#### Step 8
Hook up the columns and rows to the controller as per the diagram.
![step_8](/public/images/step_8.jpg)

#### Step 9
The led strip can be left hanging loose for now.

Now you can try flashing the qmk firmware onto the board. And check if all of the buttons and led strip work.

You can compile the test firmware. See the QMK tips section down bellow for testing tips.

![step_9](/public/images/step_9.jpg)
Loosely hook up the led strip for testing

#### Step 10
![step_10](/public/images/step_10.jpg)
Hot glue the first led strip and row wires

#### Step 11
![step_11](/public/images/step_11.jpg)
Using 30 LEDs from the 60/m LED strip. Wire then up around the bottom of the case. 

#### Step 12
![step_12](/public/images/step_12.jpg)
Using 43 LEDs from the 60/m LED strip. Wire up a grid like so.

#### Step 13
![step_13](/public/images/step_13.jpg)

#### Step 14
![step_14](/public/images/step_14.jpg)

#### Step 15
![step_15](/public/images/step_15.jpg)

#### Step 16
![step_16](/public/images/step_16.jpg)


# QMK tips
## Setup
Make sure you clone my fork and switch to my dactyl branch.
```sh
git clone https://github.com/ArtiomSu/qmk_firmware.git

git checkout artiom_dactyl
```

You will also need to have the [qmk cli tool](https://github.com/qmk/qmk_cli) installed. It is required for building the firmware now.

## Testing
To build the test firmware you can do.
```sh
make clean && make artiomsu_dactyl:test
```

Then put the controller into bootloader mode and copy the `.uf2` firmware file onto the controller

Inside `config.h` make sure to `#define MASTER_LEFT` or `#define MASTER_RIGHT` depending on which side you built.

Yes you can test the sides independantly before testing them both at the same time.



## Sections you should take a look at after you are done

Make sure to checkout the [rp2040 sections](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md) as they are a bit different to the pro micros.

Make sure to checkout the [split keyboard](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md) specific information.


https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#lighting-layers



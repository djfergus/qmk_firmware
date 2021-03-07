# Hardware Calculator Macropad

```
                    +------------------------------+
                    |        Default layer         |
                    | N = Numlock                  |
                    | E = Enter                    |
                    | L = Shortcuts Layer          |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | N |  | / |  | + |  | - |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 7 |  | 8 |  | 9 |  | + |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 4 |  | 5 |  | 6 |  | E |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 1 |  | 2 |  | 3 |  | , |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 0 |  | . |  | = |  | L |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```


This is a 20 button macropad custom made by myself ArtiomSu. Checkout the Photos of the build down at the bottom.

This macropad acts like a hardware calculator that types out the result of an equation entered directly into the numpad with the help of a modified TinyExpr library. 

### Default layout
The default layout includes the full version of the library with a few changes to make it work with pro micro. 

It must be compiled with an earlier avr-binutils package as with the latest the firmware size is too big.

### Minified Layout
The minified layout solves the issue of the default layout by removing every unneccessary functions from the library that are not used by my layout such as the sin, cos, tan, ..etc functions. 

This allows the firmware to be compiled with the latest avr-binutils and therefore the firwmare can fit on the pro micro.

This layout also allows you to send mouse keys within a layer.

This layout also enables auto clicking to the left mouse key, there are two modes 
1. The firmware sends left mouse clicks while the left mouse key is pressed down.
2. The firmware sends left mouse clicks all the time until auto clicking is disabled regradless if the mouse key is pressed.

# Compile and flash
You will need to short pins 2 and 3 on the pro micro to enter flashing mode. 

You will also need to know the location of the pro micro in terms of where is it in /dev.

The easiest way to do this is to plug in the pro micro and run 

`sudo dmesg | grep tty`

For me this outputs `/dev/ttyACM0` for you it could be different but we will need this in the following command to flash the firmware.

### To compile the default layout
Compile with this make sure you are in the root of the qmk_firmware directory.

`make clean && make macropad_artiomsu:default`

To flash the firmware

`sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:macropad_artiomsu_default.hex`

### To compile the minimised layout

`make clean && make macropad_artiomsu:minimised`

To flash the firmware

`sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:macropad_artiomsu_minimised.hex`

# Minimised Layout Layers
```
                    +------------------------------+
                    |        Default layer         |
                    | N = Numlock                  |
                    | E = Enter                    |
                    | L = Shortcuts Layer          |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | N |  | / |  | * |  | - |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 7 |  | 8 |  | 9 |  | + |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 4 |  | 5 |  | 6 |  | E |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 1 |  | 2 |  | 3 |  | , |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 0 |  | . |  | = |  | L |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```

```
                    +------------------------------+
                    |        Shortcuts Layer       |
                    | A = AutoClicker hold         |
                    | B = AutoClicker Auto         |
                    | + = increase precission      |
                    | - = decrease precission      |
                    | R = RESET macropad           |
                    | 3 = Mouse Layer              |
                    | 4 = Gaming Layer             |
                    | 2 = Calc Layer               |
                    | L = Default Layer            |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | A |  |   |  |   |  | - |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | B |  |   |  |   |  | + |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  |   |  |   |  |   |  |   |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  |   |  |   |  |   |  | R |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 3 |  | 4 |  | 2 |  | L |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```

```
                    +------------------------------+
                    |        Default layer         |
                    | P = Type out equation        |
                    | = = Type out Result          |
                    | L = Default Layer            |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | P |  | / |  | + |  | - |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 7 |  | 8 |  | 9 |  | + |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 4 |  | 5 |  | 6 |  | ^ |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 1 |  | 2 |  | 3 |  | % |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | 0 |  | . |  | = |  | L |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```

```
                    +------------------------------+
                    |        Mouse Layer           |
                    | 0 = Mouse Speed 0            |
                    | 1 = Mouse Speed 1            |
                    | 2 = Mouse Speed 2            |
                    | U = Mouse Wheel Up           |
                    | D = Mouse Wheel Down         |
                    | A = Cursor UP                |
                    | B = Cursor Left              |
                    | C = Cursor Down              |
                    | E = Cursor Right             |
                    | 4 = Mouse Back Button        |
                    | 5 = Mouse Forward Button     |
                    | L = Left Click               |
                    | M = Middle Click             |
                    | R = Right Click              |
                    | Z = Default Layer            |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | 0 |  | 1 |  | 2 |  | U |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  |   |  | A |  |   |  | D |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | B |  | C |  | E |  | 4 |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  |   |  |   |  |   |  | 5 |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | L |  | M |  | R |  | Z |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```

```
                    +------------------------------+
                    |        Gaming Layer          |
                    | T = Tab                      |
                    | $ = Shift                    |
                    | Z = Default Layer            |
                    | ^ = Control                  |
                    | _ = Space                    |
                    +------------------------------+
                    |  +---+  +---+  +---+  +---+  |
                    |  | 1 |  | 2 |  | 3 |  | 4 |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | R |  | Q |  | W |  | E |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | T |  | A |  | S |  | D |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | $ |  | X |  | C |  | V |  |
                    |  +---+  +---+  +---+  +---+  |
                    |                              |
                    |  +---+  +---+  +---+  +---+  |
                    |  | Z |  | F |  | ^ |  | _ |  |
                    |  +---+  +---+  +---+  +---+  |
                    +------------------------------+
```

# Photos

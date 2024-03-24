# Civic Radio Modernizer 3000

![board rendering](https://github.com/userexec/civicradiomodernizer3000/blob/main/board.png?raw=true)

This package of KiCad files and an Arduino sketch produces a circuit board you don't want. It hijacks the amplifier inputs, source switching functions, and radio preset buttons/LEDs of a Honda 39100-SEO-A300-M1 radio connected to it via a parallel cable. Note that this radio does not have a parallel port (of course it doesn't). You have to chop the cable in half and solder the open end into specific points around the radio, then connect the other end to this board. Power comes over the parallel cable so it's the only required connection--just print a case for it and tuck it behind the dash anywhere it fits.

## What it adds

Attaching this board over parallel to the appropriate Honda radio with correct points soldered adds:
- Bluetooth
- Radio/Cassette/Bluetooth switching on radio preset buttons 1, 2, 3
- Bluetooth audio controls on radio preset buttons 4, 5, 6
- Funky animations of the faceplate LEDs when you press those buttons
- All audio adjustments like volume, balance, fade, bass, treble etc. retain function across all modes
- Steering wheel controls over optional DB-9 serial cable
- 3.5mm output of anything currently playing, regardless of source
- RCA output of anything currently playing, regardless of source
- Attachment via DB-9 serial cable to a controller hub for the rest of the car's modules

## What you should build instead of this

Seriously don't build this. By the time this board is printed and you've ordered components it comes up to like $150. It requires hours of soldering and a significant possibility of breaking your radio. How are you even going to use the CAT-BUS port? It uses some random undocumented protocol some weird guy on the internet put together for a project car. Why do you even have a Honda 39100-SEO-A300-M1?

A bluetooth cassette tape will work just as well. Does the cassette belt on your 39100-SEO-A300-M1 not work? A PRB SCX 16.0 square cut belt will fit perfectly.

Better yet, buy an aftermarket amplifier with bluetooth.

If you're just looking for a way to attach an amp to your vintage radio, yes this will provide the correct outputs, but there are so many options that are million times easier.

## Pin mapping

The whole magic is in where you solder the parallel cable's wires into the radio. Here's what goes to what:

| Wire color | Pin | Function | Solder point |
| ------- | ------- | ------- | ------- |
| **brown** | **1** | GND | Radio case |
| **red** | **2** | 12V | any 12V accessory point behind main radio connector |
| **orange** | **3** | SPK_L | Bottom of main board at output of pre-amp board |
| **bad girl pink** | **4** | SPK_R | Bottom of main board at output of pre-amp board |
| **bubblegum pink** | **5** | B+ | Gray wire from main board to cassette module (disconnect wire, cut plug) |
| **princess pink** | **6** | B+RADIO | Blue wire from main board to cassette module (from same plug) |
| **yellow** | **7** | B+TAPE | Purple wire from main board to cassette module (from same plug) |
| **ninja turtle** | **8** | BTN1 | Cut traces on radio preset button board |
| **grass** | **9** | BTN2 | Solder GND to one side of switches |
| **normal blue** | **10** | BTN3 | Solder BTN inputs to other sides |
| **light blue** | **11** | BTN4 |  |
| **ugly blue (brown)** | **12** | BTN5 |  |
| **turqoise** | **13** | BTN6 |  |
| purple | 14 | GND |  |
| **normal gray** | **15** | LED6 | Cut traces on radio preset board |
| **white** | **16** | LED5 | Link all LED GNDs, solder to GND |
| **dirty white** | **17** | LED4 | Solder LED outputs to other sides |
| ***brown (white)*** | **18** | LED3 | of corresponding LEDs |
| ***orange (black)*** | **19** | LED2 |  |
| *red (black)* | 19 | LED2 |  |
| ***bubblegum pink (blue)*** | **20** | LED1 |  |
| *bad girl pink (black)* | 20 | LED1 |  |
| *princess pink (white)* | 21 |  |  |
| *yellow (black)* | 21 |  |  |
| *ninja turtle (black)* | 22 |  |  |
| *grass (brown)* | 22 |  |  |
| *light blue (black)* | 23 |  |  |
| *normal gray (black)* | 23 |  |  |
| *normal blue (white) *| 24 |  |  |
| ugly blue | 24 |  |  |
| *turqoise (green)* | 24 |  |  |
| *dirty white (green)* | 25 |  |  |
| *purple (white)* | 25 |  |  |
| white (black)* | 25 |  |  |
| disgusting gray | nc |  |  |
| *disgusting gray (green)* | nc |  |  |
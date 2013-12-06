Sensor_Library
==============

##Welcome!

This is the repository for my robot sensor program.

This program uses analog to digital conversion to convert distances to voltage levels picked up by the sensors.

- Lower voltages correspond to further distances.
- Higher voltages correspond to closer distances.

When the left sensor picks up a voltage level higher than the threshold (programmed by user) LED1 lights up.
When the right sensor picks up a voltage level higher than the threshold (programmed by user) LED2 lights up.

###Navigate to the header file to change how sensitive you want the robot to be.

- Larger numbers relate to closer distances.
- Smaller numbers relate to further distances.

Here are some reference values to help you out:

- 0x230~~ 3.5 inches
- 0x200~~ 4.0 inches
- 0x175~~ 4.5 inches
- 0x150~~ 7.0 inches
- 0x125~~ 10  inches
- 0x100~~ 15  inches
- 0x075~~ 17  inches

The sample code provided is preprogrammed to pick up 3.5 inches with the left sensor and 15 inches on the right sensor to highlight this difference.

Any distance greater than becomes unreliable due to lighting interference and noise and would not be recommended.

Refer to comments if you have questions.

###Have Fun!

  

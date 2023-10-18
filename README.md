# Robotic_Dog
This repository displays my robotic dog project, including the STL, Gerber, and Ino files. It also offers a glimpse into my thoughts and ideas throughout the design process, including previous iterations of various design aspects.

## General Overview
Each leg of the dog is 30cm long and contains three MG996R servo motors: two for shoulder actuation on two axes and one for knee actuation. The dog contains five custom PCBs. Each leg has one PCB that distributes power and signal to the three servos. The central PCB is controlled by an ATMega328 microcontroller and distributes power and signal to each of the four leg PCBs. The code is written in Arduino C++ and calculates servo angles based on X (horizontal distance from shoulder) and Z (vertical distance from shoulder) coordinates of the foot. This system allows for smooth linear motion and easier programming.

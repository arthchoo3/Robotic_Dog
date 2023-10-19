# Robotic_Dog
This repository displays my robotic dog project, including the STL, Gerber, and Ino files. It also offers a glimpse into my thoughts and ideas throughout the design process, including previous iterations of various design aspects.

## General Overview
 The dog is made of 143 3D-printed pieces, 5 custom PCBs, and 12 servo motors. Each leg of the dog is 30cm long and contains three MG996R servo motors: two for shoulder actuation on two axes and one for knee actuation. Each leg has one PCB that distributes power and signal to the three servos. The central PCB is controlled by an ATMega328 microcontroller and distributes power and signal to each of the four leg PCBs. The code is written in Arduino C++ and calculates servo angles based on X (horizontal distance from shoulder) and Z (vertical distance from shoulder) coordinates of the foot. This system allows for smooth linear motion and easier programming.
![Dog 2 Leg](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/3cca1a64-80d2-4610-9812-5a4194ab8efb)
![Dog Standing Up](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/9a2b34aa-a8fb-4a82-b717-2ca8a31ef286)
![Dog Standing Up 2](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/ddeacf45-d78a-49c4-9054-25f4c0445189)
![Dog Parts](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/08c969cd-acbc-4623-bc0c-e1c24e558340)


## Joint Design
In my first attempt at building a robotic dog, I attempted to mount the structural components of the legs directly to the servo horns. This design did not work because the servo horns were not designed to withstand forces perpendicular to their plane of rotation. So, for this dog, I went for a design approach in which the bending forces act not on the servo horn itself but on a rotary guide and hub system. This makes it so the servos must only resist the torsion forces for which they were designed.

The servo motor (blue) rotates the cylinder (green) which rotates the leg strut (gray) and the hub (yellow). Any bending forces that the leg strut would have previously placed on the servo horn are now supported by the rotary guide (red), making the servo only responsible for rotating the system.
![Dog 2 Joint](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/d6daaeb5-4d5b-46df-a669-bc10ba195efe)

## PCBs
For the microcontroller, I chose to use the ATMega328 from an Arduino Uno because I am very familiar with C++ and the Arduino IDE. The central PCB has four sets of three-prong plugs, one plug for each leg and one prong for each servo. It also has four sets of positive and negative outputs to power each leg. Each leg also has its own PCB into which the three servos plug to connect to the central PCB.
The PCBs are also decorated with symbols of the vibrant programming community at my school.  
![Dog Main PCB](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/65dabec6-20ab-4b3c-a956-38c645a6b7d3)
![Dog knee PCB](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/9696339b-598c-4e50-865b-fc28dd12991e)

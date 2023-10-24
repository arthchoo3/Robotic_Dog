# Robotic_Dog
This repository displays my robotic dog project, including the STL, Gerber, and Ino files. It also offers a glimpse into my thoughts and ideas throughout the design process, including previous iterations of various design aspects.

## General Overview
 The dog is made of 143 3D-printed pieces, 5 custom PCBs, and 12 servo motors. Each leg of the dog is 30cm long and contains three MG996R servo motors: two for shoulder actuation on two axes and one for knee actuation. Each leg has one PCB that distributes power and signal to the three servos. The central PCB is controlled by an ATMega328 microcontroller and distributes power and signal to each of the four leg PCBs. The code is written in Arduino C++.
![IMG_9329](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/273ebf46-8734-4387-b771-131e685d39fe)
![IMG_9317](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/ab07ba57-b3a0-4a9b-984a-dc1d20e91b98)
![Dog Parts](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/d76e9858-e44e-4b20-81f2-83991191965a)


https://github.com/arthchoo3/Robotic_Dog/assets/140445967/36175da8-d79e-43d7-8e23-6a641d8918cc

## Joint Design
In my first attempt at building a robotic dog, I attempted to mount the structural components of the legs directly to the servo horns. This design did not work because the servo horns were not designed to withstand forces perpendicular to their plane of rotation. So, for this dog, I went for a design approach in which the bending forces act not on the servo horn itself but on a rotary guide and hub system. This makes it so the servos must only resist the torsion forces for which they were designed.

The servo motor (blue) rotates the cylinder (green) which rotates the leg strut (gray) and the hub (yellow). Any bending forces that the leg strut would have previously placed on the servo horn are now supported by the rotary guide (red), making the servo only responsible for rotating the system.
![Dog 2 Joint](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/d6daaeb5-4d5b-46df-a669-bc10ba195efe)

## PCBs
For the microcontroller, I chose to use the ATMega328 from an Arduino Uno because I am very familiar with C++ and the Arduino IDE. The central PCB has four sets of three-prong plugs, one plug for each leg and one prong for each servo. It also has four sets of positive and negative outputs to power each leg. Each leg also has its own PCB into which the three servos plug to connect to the central PCB.
The PCBs are also decorated with symbols of the vibrant programming community at my school.  
![Dog Main PCB](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/65dabec6-20ab-4b3c-a956-38c645a6b7d3)
![Dog knee PCB](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/9696339b-598c-4e50-865b-fc28dd12991e)

## Code and Calculations
The code is written in Arduino C++ and uses the following math to calculate servo angles based on X (horizontal distance from shoulder) and Z (vertical distance from shoulder) coordinates of the foot. This system allows for smooth linear motion and easier programming.
![Dog Math](https://github.com/arthchoo3/Robotic_Dog/assets/140445967/e37cdb4a-5254-4ac0-afb9-9cb8ab86184f)

## Setbacks and Limitations
The MG996R Servos that the dog currently uses do not have enough torque to properly carry the dog's weight. This is why the dog leans forward as it walks because if the weight isn’t shifted more to the front legs, the rear motors will give out under the dog's weight. This is also the reason the dog must be plugged into a power supply because the servos cannot support the weight of a battery pack. I am currently saving money from my weekend job to buy higher torque servos so this won’t be an issue in the future. 

## Future Plans
Right now, the very basic PCB that controls the dog only allows for pre-programmed motion. I am currently learning to work with CH340C USB to Serial converters so I can add USB ports to make the dog remote-controlled. I also plan to buy higher torque servos once I have saved enough money so the dog can move more fluidly.


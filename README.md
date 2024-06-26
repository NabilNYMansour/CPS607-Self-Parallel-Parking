﻿# CPS607-Self-Parallel-Parking
- This is the repository for the final assignment project in Ryerson University's CPS607 course given by Professor Jimmy Tran.
- The assignment presents the following:
	1. There exists an environment where an empty space exists between two parked objects and two black lines. The size of the parking slot is 35cm by 20cm like the diagram below.
  ![Diagram of enviroment](https://github.com/NabilNYMansour/CPS607-Self-Parallel-Parking/blob/main/FinalPic.PNG)
  This diagram was provided by the Professor in the assignment pdf file.
	2. The robot car (https://www.amazon.ca/dp/B08LCZ2XYN/ref=twister_B08NB77BB5?_encoding=UTF8&psc=1) can be placed anywhere in the environment except the empty slot between the two parked objects.
  3. After activating the robot, the robot must execute an operation that allows it to autonomously drive itself between the two slots and park itself parallelly to the two objects.
  4. At all times, the robot must not collide with the objects.
  5. The wheels of the car must never touch the black line labelled "Curb".
  ---
  ## Code explanation
  - The logic of the code assumes that the robot will start from the right side like the diagram below:
  1. Rotate the sonar to the right and move forward as the sonar reads a value less than 20.
  2. Move forward as the sonar reads a value more than 20.
  3. Move backward as the sonar reads a value less than 20.
  4. Rotate the sonar to the left. 
  5. Rotate the entire robot clockwise as the sonar reads a value more than 20.
  6. Move forward until the line reader sensors return a value of 0 (until the car touches the first black line) and then a value of 1 (indicating that the car has passed the black line.
  7. Rotate the entire car counter-clockwise as the line reader sensor return a value of 1 (until the car touches the first black line again).
  8. Wiggle the car to the left or to the right to make the car perfectly in parallel with the objects it is facing by making two readings and seeing if they are not equal. The diagram below shows how this step is done.
  ![Diagram of Proper Orientation logic](https://github.com/NabilNYMansour/CPS607-Self-Parallel-Parking/blob/main/D2.PNG)
  9. Stop the car.
  - A step by step diagram is shown below.
  ![Diagram of logic](https://github.com/NabilNYMansour/CPS607-Self-Parallel-Parking/blob/main/D1.jpg)
  ---
  - The following shows a recording of me demoing the robot as it executes the parallel parking operation.

  ![Recording of Assignment](https://github.com/NabilNYMansour/CPS607-Self-Parallel-Parking/assets/56453977/d40d113b-af50-438c-a922-b0414cecae29)

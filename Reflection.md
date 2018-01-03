# **Udacity Self-Driving Car Nanodegree - PID Control Project**

## Introduction

The purpose of this project was to control the steering angle of a virtual car in a simulator program via a PID controller to race around a track as fast as possible. The simulator allows to monitor the actual position and the ground truth and streams the cross-track error (cte) to the c++ program. The task was to build a simple PID controller to use the CTE in order to output a steering value and send it back to the simulator. On top of that the throttle had to be optimized in order to race as fast as possible without crashing the car.

## Reflection

### Describe the effect each of the P, I, D components had in your implementation.

- The proportional portion or "p gain" of the controller counteracts the CTE. This means the further the car is away from the lane center the harder it steers back towards the middle. The higher this value is the more aggressive the counter steering towards the middle is. The value becomes zero once the car crosses the lane center and therefore it has to overshoot and oscillate around the target value if no other gain is present.

- The integral component or "i gain" integrates the CTE over time and therefore eliminates a bias in the system that the controller would otheriwse follow (offset to the side of the lane middle). In the case of this simulator there was no bias present. Therefore the I component was left out and the controller can be considered a PD controller.

- The differential portion or "d gain" can help to avoid overshooting as it differentiates the CTE (d_cte/d_t) which leads to a smoother approach of the target position. When properly tuned a PD or PID controller can settle in after a bit of overshooting or without overshooting at all (slower).

### Adjusting the speed

It was required to finish a lap as quickly as possible and therefore the throttle (and speed) had to be adjusted. As the course has a lot of straight sections but also a few tight curves the speed has to be adjusted dynamically in order to achieve the best results. As no other sensors or inputs were given I decided to adjust the speed based on the steering command. This is not ideal as the car can only react (reduce speed) and cannot "look ahead" and brake like a human driver would do, but it did the job for this simplified project.

### Describe how the final hyperparameters were chosen.

The parameters were chosen manually by try and error.

First I added enough proportional gain to correct offsets quickly and steer aggressively enough in the curves which led to a large amount of overshooting. I then added differential gain to reduce the overshooting. Once it was stable I increased the speed and increased the proportional gain slightly to make sure the car can follow the tight turns at higher speeds which introduced a little overshooting. As the goal was to go as fast as possible and not as comfortable as possible (I would not like to sit in a car that is driving like this) - this flaw was accepted.
The final parameters where [P: 0.11, I: 0.0, D: 3.8].

## Simulation

### The vehicle must successfully drive a lap around the track.

Here is a video showing the result: [./videos/pid_vid.mp4](./videos/pid_vid.mp4).

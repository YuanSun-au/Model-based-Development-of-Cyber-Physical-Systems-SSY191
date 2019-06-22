# Model-based-Development-of-Cyber-Physcial-Systems-SSY191 (Embedded Systems)
Repository for the course "Model-based Development of Cyber Physcial Systems" - SSY191 at Chalmers University


In this project, a full design of control systems for the Bitcraze quadrocopter have been done (we have a mix of Crazyflie 2.0 and 2.1). The purpose was to apply knowledge from the previous courses in Modelling and Simulation, Discrete Events Systems, and Linear Control Systems Design and the knowledge from this course to apply a model-based approach to design a control system for a quadrocopter.

## Group Project:  

- **Modelling**: derivation of the dynamics equations of a Quadcopter using Matlab, Simulink and Simscape
- **Discretization**: system discretization based on nonlinear equations
- **Sensor fusion**: design of a complementary filter to estiimate orientation of the quadcopter using gyroscope and accelerometer measurements
- **Control Design**: implementation of LQR with integral action and pre-filter controllers for controlling roll, pitch and yaw rate of the Quadrotor.
- **Control Evaluation**: Evaluation of the control design system against the simulated and physical model
- **Embedded implementation**: implementation of the control system in C with multiple threads and synchronisation on the FreeRTOS, in order to operate in the Crazyflie board.

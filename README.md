# CPU-Scheduling-Algorithms
## Description

The CPU Scheduling Algorithms Simulation project is a console-based C++ application that simulates various CPU scheduling algorithms. It supports the following scheduling algorithms: First-Come, First-Served (FCFS), Round Robin (RR), Shortest Remaining Time Next (SRTN), and Shortest Job First (SJF). The application takes the arrival time and burst time of each process as input and generates a Gantt chart, as well as calculates the turnaround time, waiting time, and completion time for each process based on the selected algorithm.


## Installation

To run the CPU Scheduling Algorithms Simulation project, follow these steps:
1) Download the project source code or clone the repository to your local machine.

2) Ensure that you have a C++ compiler installed on your system, such as GCC or Clang.

3) Compile the project using the appropriate compiler command. For example, with GCC:

   `g++ -o cpu_scheduler first_come_first_served.cpp round_robin.cpp shortest_job_first.cpp shortest_remaining_time_next.cpp scheduling_process.cpp main.cpp`
4) Once the compilation is successful, run the executable file to start the application:

   `./cpu_scheduler`

## Usage
1) Upon running the CPU Scheduling Algorithms Simulation application, you will be prompted to enter the number of processes, the arrival time and the burst time for each process.

2) Enter the required information as requested by the application.

3) After providing the input, you will be presented with a menu to select the scheduling algorithm to simulate.

4) Choose the desired algorithm by entering the corresponding option number.

5) The application will then display the Gantt chart representing the execution order of the processes, along with the turnaround time, waiting time, and completion time for each process based on the selected algorithm.

6) To exit the application, follow the prompts or press a specific key as instructed.

## File Structure
The CPU Scheduling Algorithms Simulation project consists of the following files:
 * first_come_first_served.cpp: Module containing the implementation of the First-Come, First-Served (FCFS) algorithm.
 * round_robin.cpp: Module containing the implementation of the Round Robin (RR) algorithm.
 * shortest_remaining_time_next.cpp: Module containing the implementation of the Shortest Remaining Time Next (SRTN) algorithm.
 * shortest_job_first.cpp: Module containing the implementation of the Shortest Job First (SJF) algorithm.
 * scheduling_process.cpp: Module containing the implementation of the input and output related operations for Process related data.
 * main.cpp: The main module that drives the console-based application, handles user input, and invokes the selected scheduling algorithm.

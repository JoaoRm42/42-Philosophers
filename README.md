# 42 Philosophers Project

Welcome to the 42 Philosophers Project repository! This project is part of the 42 curriculum and is inspired by the classic "Dining Philosophers" problem. The goal is to solve this problem using multithreading in C, managing concurrency, and avoiding deadlocks and race conditions.

## Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)
- [Grade](#grade)

## Introduction

The Philosophers project aims to teach students about concurrency, multithreading, and synchronization in C by implementing a solution to the "Dining Philosophers" problem. The challenge is to ensure that philosophers can eat without causing deadlocks or race conditions.

## Project Objectives

- Implement a solution to the "Dining Philosophers" problem.
- Use multithreading to manage philosopher actions concurrently.
- Avoid deadlocks and race conditions.
- Gain a deeper understanding of concurrency and synchronization primitives.

## Requirements

- A Unix-based operating system (Linux or macOS).
- GCC compiler.
- Basic understanding of C programming and multithreading concepts.

## Project Structure

Here's a brief overview of the project structure:

```
.
├── includes
│ └── philo.h
├── src
│ ├── checker.c
│ ├── dinner.c
│ ├── init.c
│ ├── main.c
│ ├── messages.c
│ ├── philo.c
│ ├── philo2.c
│ ├── routine.c
| └── utils.c
├── Makefile
└── README.md
```


## Installation

1. **Clone the Repository**:
    ```bash
    git clone git@github.com:joaoped2-42PORTO/42-Philosophers.git
    cd 42-Philosophers
    ```

2. **Compile the Project**:
    ```bash
    make
    ```

    This will create the necessary executable file (e.g., `philo`).

## Usage

To run the `philo` program, use the following command:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- number_of_philosophers: The number of philosophers and forks.
- time_to_die: Time (in milliseconds) before a philosopher dies without eating.
- time_to_eat: Time (in milliseconds) it takes for a philosopher to eat.
- time_to_sleep: Time (in milliseconds) a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat (optional): If all philosophers have eaten this many times, the simulation ends. If not specified, the simulation runs indefinitely.

```bash
./philo 5 800 200 200
```

## Contributing
Contributions are welcome! If you have any suggestions or improvements, feel free to create an issue or submit a pull request. Please ensure that your contributions adhere to the coding standards and guidelines of the project.

## Acknowledgments
The 42 Network for providing the inspiration and resources for this project.
The C programming community for their excellent documentation and support.
All contributors who have helped improve this project.

## Grade

- Norminette: Ok!
- Grade: 100/100

---

Happy coding!

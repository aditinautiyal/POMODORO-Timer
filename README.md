# Pomodoro Timer
### By Aditi Nautiyal
### May still need some testing

A simple C program implementing the Pomodoro Technique for time management.

## Overview

This program creates a Pomodoro timer that alternates between work periods (25 minutes) and break periods (5 minutes). The user can specify the number of work intervals and customize break activities.

## Features

- Set custom number of work intervals
- Define personalized break activities
- Real-time countdown display
- Break activity selection before each break
- Clear notifications when timers complete

## Requirements

- C compiler (GCC recommended)
- Standard C libraries

## Installation

1. Clone this repository or download the source files
2. Compile using the included Makefile:

```
make
```

## Usage

Run the program:

```
./pomodoro
```

Follow the prompts to:
1. Enter the number of work intervals
2. Input your preferred break activities
3. Start the timer

## How It Works

The program will cycle through:
- 25-minute work sessions with countdown display
- Break activity selection
- 5-minute break sessions with countdown display
- "Time to get back to work!" notifications

When all intervals are complete, the program will exit.

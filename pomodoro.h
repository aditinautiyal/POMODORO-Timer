// Aditi Nautiyal

#ifndef POMODORO_H
#define POMODORO_H

// Function declarations
void clearScreen();
void displayCountdown(int minutes, int seconds);
void runTimer(int minutes, const char *message);
void runWorkSession();
void runBreakSession(char activities[][100], int numActivities);

#endif /* POMODORO_H */

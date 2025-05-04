// Aditi Nautiyal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "pomodoro.h"

#define WORK_TIME 25    // Work time in minutes
#define BREAK_TIME 5    // Break time in minutes
#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_LENGTH 100

// Function to clear the screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display a countdown timer
void displayCountdown(int minutes, int seconds) {
    printf("\r%02d:%02d", minutes, seconds);
    fflush(stdout);
}

// Function to run a timer for a specified number of minutes
void runTimer(int minutes, const char *message) {
    time_t startTime, currentTime;
    int remainingSeconds, displayMinutes, displaySeconds;
    int totalSeconds = minutes * 60;
    
    time(&startTime);
    
    while (1) {
        time(&currentTime);
        remainingSeconds = totalSeconds - (int)difftime(currentTime, startTime);
        
        if (remainingSeconds <= 0) {
            break;
        }
        
        displayMinutes = remainingSeconds / 60;
        displaySeconds = remainingSeconds % 60;
        
        clearScreen();
        printf("%s\n", message);
        displayCountdown(displayMinutes, displaySeconds);
        
        sleep(1);
    }
    
    clearScreen();
    printf("%s completed!\n", message);
}

// Function to run a work session
void runWorkSession() {
    printf("\nStarting a %d-minute work session...\n", WORK_TIME);
    sleep(2);
    runTimer(WORK_TIME, "Work Session");
}

// Function to run a break session with a chosen activity
void runBreakSession(char activities[][MAX_ACTIVITY_LENGTH], int numActivities) {
    int choice;
    
    printf("\nTime for a %d-minute break! Choose an activity:\n", BREAK_TIME);
    
    for (int i = 0; i < numActivities; i++) {
        printf("%d. %s\n", i + 1, activities[i]);
    }
    
    printf("Your choice (1-%d): ", numActivities);
    scanf("%d", &choice);
    
    // Validate input
    while (choice < 1 || choice > numActivities) {
        printf("Invalid choice. Please select between 1 and %d: ", numActivities);
        scanf("%d", &choice);
    }
    
    printf("\nGood idea! Taking a break with: %s\n", activities[choice - 1]);
    sleep(2);
    
    runTimer(BREAK_TIME, "Break Time");
    
    printf("Time to get back to work!\n");
    printf("Time to get back to work!\n");
    printf("Time to get back to work!\n");
    
    sleep(3);
}

int main() {
    int intervals;
    int numActivities = 0;
    char activities[MAX_ACTIVITIES][MAX_ACTIVITY_LENGTH];
    char buffer[MAX_ACTIVITY_LENGTH];
    
    printf("=== Pomodoro Timer ===\n\n");
    
    // Get number of intervals
    printf("Enter the number of intervals (An interval is one 25-minute work session): ");
    scanf("%d", &intervals);
    
    // Clear the input buffer
    while (getchar() != '\n');
    
    // Get break activities
    printf("\nEnter break activities (up to %d, one per line, enter an empty line to finish):\n", MAX_ACTIVITIES);
    
    while (numActivities < MAX_ACTIVITIES) {
        printf("Activity %d: ", numActivities + 1);
        fgets(buffer, MAX_ACTIVITY_LENGTH, stdin);
        
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (strlen(buffer) == 0) {
            break;  // Empty line, stop asking for activities
        }
        
        strcpy(activities[numActivities], buffer);
        numActivities++;
    }
    
    // Ensure at least one activity is entered
    if (numActivities == 0) {
        strcpy(activities[0], "Take a short walk");
        numActivities = 1;
        printf("\nNo activities entered. Added default activity: 'Take a short walk'\n");
    }
    
    printf("\nStarting Pomodoro timer with %d intervals and %d break activities.\n", intervals, numActivities);
    printf("Press Enter to begin...");
    getchar();
    
    // Run the Pomodoro cycles
    for (int i = 0; i < intervals; i++) {
        clearScreen();
        printf("=== Interval %d of %d ===\n", i + 1, intervals);
        
        runWorkSession();
        
        if (i < intervals - 1) {  // No break after the last work session
            runBreakSession(activities, numActivities);
        }
    }
    
    printf("\nCongratulations! You've completed all %d Pomodoro intervals.\n", intervals);
    
    return 0;
}

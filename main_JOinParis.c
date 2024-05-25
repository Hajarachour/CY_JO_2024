#include "functions_JOinParis.h"
#include "imports_and_variables_JOinParis.h"
#include "structures_JOinParis.h"

/**
 * main - The main function of the program.
 *
 * This function initializes the data directory and initial athletes.
 * It then enters a loop where it allows the user to add performances,
 * display performance history, display performance statistics, analyze performance trends,
 * find the top athletes for an event, or quit the program.
 */
int main() {
    char athlete_name[50];
    char date[11];
    char event[50];
    char time[10];
    int position;
    Athlete athlete; // Structure to hold the athlete's performance data
    int status; // Variable to hold the status of operations

    // Create the data directory if it does not exist
    create_data_dir();
    // Create initial athletes and their performance files
    create_initial_athletes();

    // Main loop to handle user input and operations
    while (1) {
        // Prompt for the athlete's name
        printf("Enter athlete's name: ");
        if (scanf("%49s", athlete_name) != 1) {
            fprintf(stderr, "Error reading athlete's name.\n");
            continue;
        }

        // Construct the file path for the athlete's data file
        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

        // Check if the file exists, if not, create a new file for the athlete
        FILE *file = fopen(file_path, "r");
        if (file == NULL) {
            create_athlete_file(athlete_name);
        } else {
            fclose(file);
        }

        // Read the athlete's performances from the file
        read_performances(athlete_name, &athlete);

        // Prompt for an operation choice
        int choice;
        printf("Choose an option:\n");
        printf("1. Add a new performance\n");
        printf("2. Display performance history\n");
        printf("3. Display performance statistics\n");
        printf("4. Display athlete's performance trend\n");
        printf("5. Find top 3 athletes for an event\n");
        printf("6. Quit\n");
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Error reading choice.\n");
            continue;
        }

        // Handle the chosen operation
        switch (choice) {
            case 1:
                // Add a new performance
                prompt_date(date);
                prompt_sport(event);
                if (strcmp(event, "4x400m") == 0) {
                    status = check_exiting_relais_for_date(athlete_name, date);
                    if (status == 1) {
                        fprintf(stderr, "Existing relay for %s.\n", date);
                        continue;
                    }
                }
                printf("Enter time: ");
                if (scanf("%9s", time) != 1) {
                    fprintf(stderr, "Error reading time.\n");
                    continue;
                }
                if (strcmp(event, "4x400m") == 0) {
                    prompt_position(&position);
                } else {
                    position = 0;
                }
                add_performance(athlete_name, date, event, time, position);
                break;

            case 2:
                // Display performance history
                display_history(&athlete);
                break;

            case 3:
                // Display performance statistics
                prompt_sport(event);
                athlete_statistics(&athlete, event);
                break;

            case 4:
                // Display athlete's performance trend
                prompt_sport(event);
                printf("Choose an option:\n");
                printf("1. Display progress between two dates\n");
                printf("2. Display linear regression\n");
                printf("Your choice: ");
                int sub_choice;
                if (scanf("%d", &sub_choice) != 1) {
                    fprintf(stderr, "Error reading choice.\n");
                    continue;
                }
                switch (sub_choice) {
                    case 1: {
                        char date1[11], date2[11];
                        prompt_date(date1);
                        prompt_date(date2);
                        athlete_progress_dates(&athlete, event, date1, date2);
                        break;
                    }
                    case 2:
                        athlete_progress_linear(&athlete, event);
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                        break;
                }
                break;

            case 5:
                // Find top 3 athletes for an event
                prompt_sport(event);
                find_top_athletes(event);
                break;

            case 6:
                // Quit the program
                printf("Exiting program.\n");
                free(athlete.performances);
                return 0;

            default:
                // Handle invalid choices
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // Free the allocated memory for performances before exiting
    free(athlete.performances);
    return 0;
}

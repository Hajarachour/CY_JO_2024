#include "functions_JOinParis.h"
#include "imports_and_variables_JOinParis.h"
#include "structures_JOinParis.h"

int main() {
    char athlete_name[50];
    char date[11];
    char event[50];
    char time[10];
    int position;
    Athlete athlete;
    int status;


    create_data_dir();
    create_initial_athletes();

    while (1) {
        printf("Enter athlete's name: ");
        if (scanf("%49s", athlete_name) != 1) {
            fprintf(stderr, "Error reading athlete's name.\n");
            continue;
        }

        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);
        FILE *file = fopen(file_path, "r");
        if (file == NULL) {
            create_athlete_file(athlete_name);
        } else {
            fclose(file);
        }

        read_performances(athlete_name, &athlete);

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

        switch (choice) {
            case 1:
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
                display_history(&athlete);
                break;

            case 3:
                prompt_sport(event);
                athlete_statistics(&athlete, event);
                break;

            case 4:
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
                prompt_sport(event);
                find_top_athletes(event);
                break;

            case 6:
                printf("Exiting program.\n");
                free(athlete.performances);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    free(athlete.performances);
    return 0;
}

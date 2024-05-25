#include "functions_JOinParis.h"
#include "imports_and_variables_JOinParis.h"

void create_data_dir() {
    struct stat st = {0};
    if (stat(DATA_DIR, &st) == -1) {
        if (mkdir(DATA_DIR, 0700) != 0) {
            fprintf(stderr, "Error creating directory %s\n", DATA_DIR);
            exit(1);
        }
    }
}

void create_athlete_file(const char* athlete_name) {
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "Error creating file %s\n", file_path);
        return;
    }

    fclose(file);
    printf("File created for athlete %s\n", athlete_name);
}

void add_performance(const char* athlete_name, const char* date, const char* event, const char* time, int position) {
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", file_path);
        return;
    }

    if (strcmp(event, "4x400m") == 0) {
        fprintf(file, "%s;%s;%s;%d\n", date, event, time, position);
    } else {
        fprintf(file, "%s;%s;%s\n", date, event, time);
    }

    fclose(file);
}

void create_initial_athletes() {
    create_data_dir();

    create_athlete_file("Sanem");
    add_performance("Sanem", "2024-03-23", "100m", "13.2", 0);
    add_performance("Sanem", "2024-05-23", "100m", "13.0", 0);
    add_performance("Sanem", "2024-07-23", "100m", "12.9", 0);
    add_performance("Sanem", "2024-09-23", "100m", "12.6", 0);

    create_athlete_file("Dimittri");
    add_performance("Dimittri", "2024-04-13", "400m", "234", 0);

    create_athlete_file("Hajar");
    add_performance("Hajar", "2024-01-28", "marathon", "7800", 0);

    create_athlete_file("Hamed");
    add_performance("Hamed", "2024-04-18", "5000m", "780", 0);

    create_athlete_file("Hamza");
    add_performance("Hamza", "2024-01-28", "marathon", "5400", 0);

    create_athlete_file("Haarise");
    add_performance("Haarise", "2024-01-28", "marathon", "5100", 0);

    printf("Initial athletes created and performances added.\n");
}

void read_performances(const char* athlete_name, Athlete *athlete) { // Lire les performances
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "No file found for athlete %s\n", athlete_name);
        return;
    }

    char line[MAX_LINE_LENGTH];
    athlete->count = 0;
    athlete->capacity = INITIAL_PERFORMANCES;
    athlete->performances = (Performance *)malloc(athlete->capacity * sizeof(Performance));

    while (fgets(line, sizeof(line), file)) {
        if (athlete->count >= athlete->capacity) {
            athlete->capacity *= 2;
            athlete->performances = (Performance *)realloc(athlete->performances, athlete->capacity * sizeof(Performance));
        }

        char *date = strtok(line, ";");
        char *event = strtok(NULL, ";");
        char *time = strtok(NULL, ";");
        char *position = strtok(NULL, "\n");

        if (date && event && time) {
            strcpy(athlete->performances[athlete->count].date, date);
            strcpy(athlete->performances[athlete->count].event, event);
            strcpy(athlete->performances[athlete->count].time, time);
            athlete->performances[athlete->count].position = position ? atoi(position) : 0;
            athlete->count++;
        }
    }

    fclose(file);
    strcpy(athlete->name, athlete_name); // Set the athlete's name
}

void display_history(const Athlete *athlete) {
    for (int i = 0; i < athlete->count; i++) {
        printf("Date: %s, Event: %s, Time: %s", athlete->performances[i].date, athlete->performances[i].event, athlete->performances[i].time);
        if (strcmp(athlete->performances[i].event, "4x400m") == 0) {
            printf(", Position: %d", athlete->performances[i].position);
        }
        printf("\n");
    }
}

void athlete_statistics(const Athlete *athlete, const char *event) {
    float best_time = 9999.0;
    float worst_time = 0.0;
    float total_time = 0.0;
    int count = 0;

    for (int i = 0; i < athlete->count; i++) {
        if (strcmp(athlete->performances[i].event, event) == 0) {
            float time = atof(athlete->performances[i].time);
            if (time < best_time) best_time = time;
            if (time > worst_time) worst_time = time;
            total_time += time;
            count++;
        }
    }

    if (count > 0) {
        printf("Event: %s\n", event);
        printf("Best time: %.2f\n", best_time);
        printf("Worst time: %.2f\n", worst_time);
        printf("Average time: %.2f\n", total_time / count);
    } else {
        printf("No performances found for event %s\n", event);
    }
}

void athlete_progress_linear(const Athlete *athlete, const char *event) {
    int n = 0;
    float sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0;
    float *times = NULL;
    char **dates = NULL;

    for (int i = 0; i < athlete->count; i++) {
        if (strcmp(athlete->performances[i].event, event) == 0) {
            float time = atof(athlete->performances[i].time);
            times = realloc(times, (n + 1) * sizeof(float));
            dates = realloc(dates, (n + 1) * sizeof(char *));
            times[n] = time;
            dates[n] = strdup(athlete->performances[i].date);
            sum_x += n;
            sum_y += time;
            sum_xx += n * n;
            sum_xy += n * time;
            n++;
        }
    }

    if (n > 0) {
        float slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
        float intercept = (sum_y - slope * sum_x) / n;

        printf("Event: %s\n", event);
        printf("Number of performances: %d\n", n);
        printf("Regression Line: y = %.2f * x + %.2f\n", slope, intercept);

        char output_file[256];
        snprintf(output_file, sizeof(output_file), "%s_%s_performance.png", athlete->name, event);

        // Plot using gnuplot
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
        if (gnuplotPipe) {
            fprintf(gnuplotPipe, "set terminal png size 800,600\n");
            fprintf(gnuplotPipe, "set output '%s'\n", output_file);
            fprintf(gnuplotPipe, "set title 'Athlete Performance Over Time'\n");
            fprintf(gnuplotPipe, "set xlabel 'Date'\n");
            fprintf(gnuplotPipe, "set ylabel 'Time (seconds)'\n");
            fprintf(gnuplotPipe, "set xdata time\n");
            fprintf(gnuplotPipe, "set timefmt '%%Y-%%m-%%d'\n");
            fprintf(gnuplotPipe, "set format x '%%Y-%%m-%%d'\n");
            fprintf(gnuplotPipe, "set xtics rotate by -45\n");
            fprintf(gnuplotPipe, "set pointsize 2\n"); // Set point size
            fprintf(gnuplotPipe, "set style line 1 lw 2\n"); // Set line width
            fprintf(gnuplotPipe, "plot '-' using 1:2 with points title 'Performance' pointtype 7, '-' using 1:2 with lines title 'Trend' linestyle 1\n");

            for (int i = 0; i < n; i++) {
                fprintf(gnuplotPipe, "%s %f\n", dates[i], times[i]);
            }
            fprintf(gnuplotPipe, "e\n");

            for (int i = 0; i < n; i++) {
                float predicted = slope * i + intercept;
                fprintf(gnuplotPipe, "%s %f\n", dates[i], predicted);
            }
            fprintf(gnuplotPipe, "e\n");
            pclose(gnuplotPipe);
            printf("Plot saved as '%s'.\n", output_file);
        }

        for (int i = 0; i < n; i++) {
            free(dates[i]);
        }
    } else {
        printf("No performances found for event %s\n", event);
    }

    free(times);
    free(dates);
}

void athlete_progress_dates(const Athlete *athlete, const char *event, const char *date1, const char *date2) {
    float time1 = -1.0;
    float time2 = -1.0;

    for (int i = 0; i < athlete->count; i++) {
        if (strcmp(athlete->performances[i].event, event) == 0) {
            if (strcmp(athlete->performances[i].date, date1) == 0) {
                time1 = atof(athlete->performances[i].time);
            }
            if (strcmp(athlete->performances[i].date, date2) == 0) {
                time2 = atof(athlete->performances[i].time);
            }
        }
    }

    if (time1 >= 0 && time2 >= 0) {
        printf("Athlete's progress for event %s between %s and %s: %.2f\n", event, date1, date2, time2 - time1);
    } else {
        printf("Times not found for one of the specified dates.\n");
    }
}

int is_valid_date(const char *date) {
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return 0;
    }

    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    if (month < 1 || month > 12) return 0;

    int max_days_in_month = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_days_in_month = 30;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            max_days_in_month = 29; // Leap year
        } else {
            max_days_in_month = 28;
        }
    }

    if (day < 1 || day > max_days_in_month) return 0;

    return 1;
}

void prompt_date(char *date) {
    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        if (scanf("%10s", date) == 1 && is_valid_date(date)) {
            break;
        } else {
            printf("Invalid date format. Please try again.\n");
        }
    }
}

int check_exiting_relais_for_date(const char *athlete_name, char *date_event) {
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "No file found for athlete %s\n", athlete_name);
        return 0;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {

        char *date = strtok(line, ";");
        char *event = strtok(NULL, ";");
        if (event && date ) {
             if ((strcmp(event, "4x400m")== 0) && (strcmp(date, date_event) == 0 ))
              {  fclose(file);
                  return 1;

              }
           }
        else {
              fclose(file);
              return 0; 
             }     
    }

    fclose(file);
    return 0;
}

int is_valid_sport(const char *sport) {
    for (int i = 0; i < numValidSports; i++) {
        if (strcmp(sport, validSports[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void prompt_sport(char *sport) {
    while (1) {
        printf("Enter event (valid options: 100m, 400m, 5000m, marathon, 4x400m): ");
        if (scanf("%49s", sport) == 1 && is_valid_sport(sport)) {
            break;
        } else {
            printf("Invalid event. Please try again.\n");
        }
    }
}

int is_valid_position(int position) {
    return position >= 1 && position <= 4;
}

void prompt_position(int *position) {
    while (1) {
        printf("Enter position (1, 2, 3, 4): ");
        if (scanf("%d", position) == 1 && is_valid_position(*position)) {
            break;
        } else {
            printf("Invalid position. Please try again.\n");
        }
    }
}

typedef struct {
    char name[50];
    float time;
} AthletePerformance;

int compare_performance(const void *a, const void *b) {
    AthletePerformance *ap1 = (AthletePerformance *)a;
    AthletePerformance *ap2 = (AthletePerformance *)b;
    if (ap1->time < ap2->time) return -1;
    if (ap1->time > ap2->time) return 1;
    return 0;
}

void find_top_athletes(const char *event) {
    DIR *dir;
    struct dirent *entry;
    AthletePerformance *all_performances = NULL;
    int total_performances = 0;

    if ((dir = opendir(DATA_DIR)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            Athlete athlete;
            char athlete_name[50];
            strncpy(athlete_name, entry->d_name, sizeof(athlete_name));
            athlete_name[strcspn(athlete_name, ".")] = '\0'; // Remove the file extension
            read_performances(athlete_name, &athlete);

            for (int i = 0; i < athlete.count; i++) {
                if (strcmp(athlete.performances[i].event, event) == 0) {
                    total_performances++;
                    all_performances = realloc(all_performances, total_performances * sizeof(AthletePerformance));
                    strncpy(all_performances[total_performances - 1].name, athlete.name, sizeof(all_performances[total_performances - 1].name));
                    all_performances[total_performances - 1].time = atof(athlete.performances[i].time);
                }
            }

            // Free allocated memory for the athlete's performances
            free(athlete.performances);
        }
    }
    closedir(dir);

    if (total_performances > 0) {
        qsort(all_performances, total_performances, sizeof(AthletePerformance), compare_performance);

        int num_athletes = total_performances < 3 ? total_performances : 3;
        printf("Top %d athletes for event %s:\n", num_athletes, event);
        for (int i = 0; i < num_athletes; i++) {
            printf("%d. %s - Time: %.2f\n", i + 1, all_performances[i].name, all_performances[i].time);
        }

        if (num_athletes == 3) {
            printf("Congratulations to %s, %s, and %s! You are going to the Olympics!\n",
                all_performances[0].name, all_performances[1].name, all_performances[2].name);
        } else if (num_athletes == 2) {
            printf("Congratulations to %s and %s! You are going to the Olympics!\n",
                all_performances[0].name, all_performances[1].name);
        } else if (num_athletes == 1) {
            printf("Congratulations to %s! You are going to the Olympics!\n",
                all_performances[0].name);
        }

        // Free allocated memory for the performances
        free(all_performances);
    } else {
        printf("No athletes found for event %s\n", event);
    }
}
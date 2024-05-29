#include "functions_JOinParis.h"
#include "imports_and_variables_JOinParis.h"
#include <float.h>


/**
 * create_data_dir - Creates a directory named DATA_DIR if it does not exist.
 *
 * This function checks if a directory defined by the macro DATA_DIR exists.
 * If the directory does not exist, it attempts to create it with permissions set to 0700.
 * If the directory creation fails, an error message is printed and the program exits with status 1.
 */
void create_data_dir() {
    struct stat st = {0}; // Declare a stat structure to store information about the directory

    // Check if the directory exists using stat() function
    if (stat(DATA_DIR, &st) == -1) {
        // If the directory does not exist, create it with permissions 0700
        if (mkdir(DATA_DIR, 0700) != 0) {
            // If the directory creation fails, print an error message and exit
            fprintf(stderr, "Error creating directory %s\n", DATA_DIR);
            exit(1);
        }
    }
}


/**
 * create_athlete_file - Creates a file for a specific athlete.
 *
 * This function creates a file in the DATA_DIR directory for the given athlete.
 * The file will have the name format: athlete_name.txt.
 * If the file cannot be created, an error message is printed.
 * If the file is successfully created, a confirmation message is printed.
 */
void create_athlete_file(const char* athlete_name) {
    char file_path[256]; // Buffer to hold the file path

    // Create the file path in the format "DATA_DIR/athlete_name.txt"
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    // Open the file for writing (create it if it does not exist)
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "Error creating file %s\n", file_path);
        return;
    }

    fclose(file);
    printf("File created for athlete %s\n", athlete_name);
}


/**
 * add_performance - Adds performance data for a specific athlete.
 *
 * This function appends performance data to the athlete's file located in the DATA_DIR directory.
 * The performance data includes the date, event, time, and position (if applicable).
 * If the event is "4x400m", the position is also included in the data.
 * If the file cannot be opened, an error message is printed.
 */
void add_performance(const char* athlete_name, const char* date, const char* event, const char* time, int position) {
    char file_path[256]; // Buffer to hold the file path

    // Create the file path in the format "DATA_DIR/athlete_name.txt"
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    // Open the file for appending (add data to the end of the file)
    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", file_path);
        return;
    }

    // Write performance data to the file
    if (strcmp(event, "4x400m") == 0) {
        // If the event is "4x400m", include the position in the data
        fprintf(file, "%s;%s;%s;%d\n", date, event, time, position);
    } else {
        // For other events, write the date, event, and time only
        fprintf(file, "%s;%s;%s\n", date, event, time);
    }

    fclose(file);
}


void create_initial_athletes() { // Create initial data for a set of athletes
    create_data_dir();

    create_athlete_file("Robin");
    add_performance("Robin", "2023-01-10", "100m", "13.5", 0);
    add_performance("Robin", "2023-03-10", "100m", "13.2", 0);
    add_performance("Robin", "2023-05-10", "100m", "13.0", 0);
    add_performance("Robin", "2023-07-10", "100m", "12.8", 0);
    add_performance("Robin", "2023-09-10", "100m", "12.5", 0);
    add_performance("Robin", "2023-11-10", "400m", "53.5", 0);
    add_performance("Robin", "2024-01-10", "400m", "52.5", 0);
    add_performance("Robin", "2024-03-10", "400m", "51.0", 0);
    add_performance("Robin", "2024-05-10", "400m", "50.0", 0);
    add_performance("Robin", "2024-05-24", "400m", "49.0", 0);
    add_performance("Robin", "2023-02-10", "marathon", "8200", 0);
    add_performance("Robin", "2023-04-10", "marathon", "8100", 0);
    add_performance("Robin", "2023-06-10", "marathon", "8000", 0);
    add_performance("Robin", "2023-08-10", "marathon", "7900", 0);
    add_performance("Robin", "2023-10-10", "marathon", "7800", 0);

    create_athlete_file("Dimittri");
    add_performance("Dimittri", "2023-01-15", "100m", "12.5", 0);
    add_performance("Dimittri", "2023-03-15", "100m", "12.3", 0);
    add_performance("Dimittri", "2023-05-15", "100m", "12.1", 0);
    add_performance("Dimittri", "2023-07-15", "100m", "11.9", 0);
    add_performance("Dimittri", "2023-09-15", "100m", "11.7", 0);
    add_performance("Dimittri", "2023-02-15", "400m", "51.0", 0);
    add_performance("Dimittri", "2023-04-15", "400m", "50.0", 0);
    add_performance("Dimittri", "2023-06-15", "400m", "49.2", 0);
    add_performance("Dimittri", "2023-08-15", "400m", "49.1", 0);
    add_performance("Dimittri", "2023-10-15", "400m", "48.0", 0);
    add_performance("Dimittri", "2023-11-15", "5000m", "780", 0);
    add_performance("Dimittri", "2024-01-15", "5000m", "760", 0);
    add_performance("Dimittri", "2024-03-15", "5000m", "740", 0);
    add_performance("Dimittri", "2024-05-15", "5000m", "720", 0);
    add_performance("Dimittri", "2024-05-24", "5000m", "700", 0);

    create_athlete_file("Raphael");
    add_performance("Raphael", "2023-01-20", "400m", "54.0", 0);
    add_performance("Raphael", "2023-03-20", "400m", "53.0", 0);
    add_performance("Raphael", "2023-05-20", "400m", "52.0", 0);
    add_performance("Raphael", "2023-07-20", "400m", "51.0", 0);
    add_performance("Raphael", "2023-09-20", "400m", "46.0", 0);
    add_performance("Raphael", "2023-02-20", "marathon", "8800", 0);
    add_performance("Raphael", "2023-04-20", "marathon", "8700", 0);
    add_performance("Raphael", "2023-06-20", "marathon", "8600", 0);
    add_performance("Raphael", "2023-08-20", "marathon", "7900", 0);
    add_performance("Raphael", "2023-10-20", "marathon", "7400", 0);
    add_performance("Raphael", "2023-11-20", "4x400m", "185", 1);
    add_performance("Raphael", "2024-01-20", "4x400m", "180", 1);
    add_performance("Raphael", "2024-03-20", "4x400m", "175", 1);
    add_performance("Raphael", "2024-05-20", "4x400m", "170", 1);
    add_performance("Raphael", "2024-05-24", "4x400m", "165", 1);

    create_athlete_file("Hamed");
    add_performance("Hamed", "2023-01-25", "100m", "13.7", 0);
    add_performance("Hamed", "2023-03-25", "100m", "13.5", 0);
    add_performance("Hamed", "2023-05-25", "100m", "13.3", 0);
    add_performance("Hamed", "2023-07-25", "100m", "13.0", 0);
    add_performance("Hamed", "2023-09-25", "100m", "12.8", 0);
    add_performance("Hamed", "2023-02-25", "400m", "52.0", 0);
    add_performance("Hamed", "2023-04-25", "400m", "51.0", 0);
    add_performance("Hamed", "2023-06-25", "400m", "50.0", 0);
    add_performance("Hamed", "2023-08-25", "400m", "49.0", 0);
    add_performance("Hamed", "2023-10-25", "400m", "48.0", 0);
    add_performance("Hamed", "2023-11-25", "5000m", "800", 0);
    add_performance("Hamed", "2024-01-25", "5000m", "780", 0);
    add_performance("Hamed", "2024-03-25", "5000m", "760", 0);
    add_performance("Hamed", "2024-05-25", "5000m", "740", 0);
    add_performance("Hamed", "2024-05-25", "5000m", "718", 0);
    add_performance("Hamed", "2024-05-25", "4x400m", "160", 4);
    add_performance("Hamed", "2024-05-25", "marathon", "7000", 0);
    

    create_athlete_file("Hamza");
    add_performance("Hamza", "2023-01-30", "100m", "12.9", 0);
    add_performance("Hamza", "2023-03-30", "100m", "12.7", 0);
    add_performance("Hamza", "2023-05-30", "100m", "12.5", 0);
    add_performance("Hamza", "2023-07-30", "100m", "12.3", 0);
    add_performance("Hamza", "2023-09-30", "100m", "12.1", 0);
    add_performance("Hamza", "2023-02-30", "400m", "50.0", 0);
    add_performance("Hamza", "2023-04-30", "400m", "49.0", 0);
    add_performance("Hamza", "2023-06-30", "400m", "48.0", 0);
    add_performance("Hamza", "2023-08-30", "400m", "47.0", 0);
    add_performance("Hamza", "2023-10-30", "400m", "46.0", 0);
    add_performance("Hamza", "2023-11-30", "marathon", "7500", 0);
    add_performance("Hamza", "2024-01-30", "marathon", "7400", 0);
    add_performance("Hamza", "2024-03-30", "marathon", "7300", 0);
    add_performance("Hamza", "2024-05-30", "marathon", "7200", 0);
    add_performance("Hamza", "2024-05-25", "marathon", "7100", 0);

    create_athlete_file("Haarise");
    add_performance("Haarise", "2023-01-05", "100m", "13.8", 0);
    add_performance("Haarise", "2023-03-05", "100m", "13.6", 0);
    add_performance("Haarise", "2023-05-05", "100m", "13.4", 0);
    add_performance("Haarise", "2023-07-05", "100m", "13.2", 0);
    add_performance("Haarise", "2023-09-05", "100m", "13.0", 0);
    add_performance("Haarise", "2023-02-05", "400m", "51.5", 0);
    add_performance("Haarise", "2023-04-05", "400m", "50.5", 0);
    add_performance("Haarise", "2023-06-05", "400m", "49.5", 0);
    add_performance("Haarise", "2023-08-05", "400m", "48.5", 0);
    add_performance("Haarise", "2023-10-05", "400m", "47.5", 0);
    add_performance("Haarise", "2023-11-05", "5000m", "780", 0);
    add_performance("Haarise", "2024-01-05", "5000m", "760", 0);
    add_performance("Haarise", "2024-03-05", "5000m", "740", 0);
    add_performance("Haarise", "2024-05-05", "5000m", "715", 0);

    create_athlete_file("Simon");
    add_performance("Simon", "2023-01-10", "400m", "53.5", 0);
    add_performance("Simon", "2023-03-10", "400m", "52.5", 0);
    add_performance("Simon", "2023-05-10", "400m", "51.5", 0);
    add_performance("Simon", "2023-07-10", "400m", "50.5", 0);
    add_performance("Simon", "2023-09-10", "400m", "49.5", 0);
    add_performance("Simon", "2023-02-10", "marathon", "7900", 0);
    add_performance("Simon", "2023-04-10", "marathon", "7800", 0);
    add_performance("Simon", "2023-06-10", "marathon", "7700", 0);
    add_performance("Simon", "2023-08-10", "marathon", "7600", 0);
    add_performance("Simon", "2023-10-10", "marathon", "7400", 0);
    add_performance("Simon", "2023-11-10", "100m", "13.2", 0);
    add_performance("Simon", "2024-01-10", "100m", "13.0", 0);
    add_performance("Simon", "2024-03-10", "100m", "12.8", 0);
    add_performance("Simon", "2024-05-10", "100m", "12.6", 0);
    add_performance("Simon", "2024-05-25", "100m", "12.4", 0);

    create_athlete_file("Alain");
    add_performance("Simon", "2023-01-10", "100m", "10.5", 0);
    add_performance("Simon", "2023-01-10", "400m", "42.5", 0);
    add_performance("Simon", "2023-01-10", "4x400m", "165", 2);
    add_performance("Simon", "2023-01-10", "marathon", "7300", 0);

    printf("Initial athletes created and performances added.\n");
}

int compare_dates(const void *a, const void *b) { // Compare two Performance structures based on their dates for the sort later
    Performance *pa = (Performance *)a;
    Performance *pb = (Performance *)b;
    return strcmp(pa->date, pb->date);
}

/**
 * read_performances - Reads performance data for a specific athlete from a file.
 *
 * This function reads the performance data from the athlete's file located in the DATA_DIR directory.
 * It stores the performance data in the provided Athlete structure.
 * If the file cannot be found, an error message is printed.
 * The performances are sorted by date after reading.
 */
void read_performances(const char* athlete_name, Athlete *athlete) {
    char file_path[256]; // Buffer to hold the file path

    // Create the file path in the format "DATA_DIR/athlete_name.txt"
    snprintf(file_path, sizeof(file_path), "%s/%s.txt", DATA_DIR, athlete_name);

    // Open the file for reading
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "No file found for athlete %s\n", athlete_name);
        return;
    }

    char line[MAX_LINE_LENGTH]; // Buffer to hold each line read from the file
    athlete->count = 0;
    athlete->capacity = INITIAL_PERFORMANCES;
    athlete->performances = (Performance *)malloc(athlete->capacity * sizeof(Performance)); // Allocate memory for the performances array

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // If the performances array is full, double its capacity
        if (athlete->count >= athlete->capacity) {
            athlete->capacity *= 2;
            athlete->performances = (Performance *)realloc(athlete->performances, athlete->capacity * sizeof(Performance));
        }

        // Parse the line to extract date, event, time, and position
        char *date = strtok(line, ";");
        char *event = strtok(NULL, ";");
        char *time = strtok(NULL, ";");
        char *position = strtok(NULL, "\n");

        // If the required fields are present, store them in the performances array
        if (date && event && time) {
            strcpy(athlete->performances[athlete->count].date, date);
            strcpy(athlete->performances[athlete->count].event, event);
            strcpy(athlete->performances[athlete->count].time, time);
            athlete->performances[athlete->count].position = position ? atoi(position) : 0;
            athlete->count++; // Increment the count of performances
        }
    }

    // Close the file after reading
    fclose(file);
    // Set the athlete's name
    strcpy(athlete->name, athlete_name);

    // Sort the performances by date
    qsort(athlete->performances, athlete->count, sizeof(Performance), compare_dates);
}


void display_history(const Athlete *athlete) { // Display the performance history of a specific athlete
    for (int i = 0; i < athlete->count; i++) {
        printf("Date: %s, Event: %s, Time: %s", athlete->performances[i].date, athlete->performances[i].event, athlete->performances[i].time);
        if (strcmp(athlete->performances[i].event, "4x400m") == 0) {
            printf(", Position: %d", athlete->performances[i].position);
        }
        printf("\n");
    }
}

void athlete_statistics(const Athlete *athlete, const char *event) { // Calculate and display statistics for a specific event of an athlete
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
    // Initialize variables for linear regression calculation
    int n = 0;
    float sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0;
    float *times = NULL;
    char **dates = NULL;

    // Initialize variables to find min and max times
    float min_time = FLT_MAX, max_time = FLT_MIN;

    // Loop through athlete's performances to collect data
    for (int i = 0; i < athlete->count; i++) {
        if (strcmp(athlete->performances[i].event, event) == 0) {
            float time = atof(athlete->performances[i].time);
            times = realloc(times, (n + 1) * sizeof(float));
            dates = realloc(dates, (n + 1) * sizeof(char *));
            times[n] = time;
            dates[n] = strdup(athlete->performances[i].date);
            sum_x += n;            // x is the index (0, 1, 2, ...)
            sum_y += time;         // y is the performance time
            sum_xx += n * n;       // x^2
            sum_xy += n * time;    // x*y
            if (time < min_time) min_time = time;
            if (time > max_time) max_time = time;
            n++;
        }
    }

    // Calculate regression line only if there are enough data points
    if (n > 0) {
        // Calculate slope (m) and intercept (b)
        float slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
        float intercept = (sum_y - slope * sum_x) / n;

        printf("Event: %s\n", event);
        printf("Number of performances: %d\n", n);
        printf("Regression Line: y = %.2f * x + %.2f\n", slope, intercept);

        // Generate the output file name for the plot
        char output_file[256];
        snprintf(output_file, sizeof(output_file), "%s_%s_performance.png", athlete->name, event);

        // Calculate the y-axis range for the plot
        float y_min = min_time * 0.9;
        float y_max = max_time * 1.1;

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
            fprintf(gnuplotPipe, "set yrange [%f:%f]\n", y_min, y_max);  // Set y-axis range
            fprintf(gnuplotPipe, "set pointsize 2\n"); // Set point size
            fprintf(gnuplotPipe, "set style line 1 lw 2\n"); // Set line width
            fprintf(gnuplotPipe, "plot '-' using 1:2 with points title 'Performance' pointtype 7, '-' using 1:2 with lines title 'Trend' linestyle 1\n");

            // Plot actual performance data points
            for (int i = 0; i < n; i++) {
                fprintf(gnuplotPipe, "%s %f\n", dates[i], times[i]);
            }
            fprintf(gnuplotPipe, "e\n");

            // Plot the regression line
            for (int i = 0; i < n; i++) {
                float predicted = slope * i + intercept;
                fprintf(gnuplotPipe, "%s %f\n", dates[i], predicted);
            }
            fprintf(gnuplotPipe, "e\n");
            pclose(gnuplotPipe);
            printf("Plot saved as '%s'.\n", output_file);
        }

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(dates[i]);
        }
    } else {
        printf("No performances found for event %s\n", event);
    }

    free(times);
    free(dates);
}


int is_valid_date(const char *date) { // check date has the right format
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

void prompt_date(char *date) { // Prompts the user to enter a date and validates it
    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        if (scanf("%10s", date) == 1 && is_valid_date(date)) {
            break;
        } else {
            printf("Invalid date format. Please try again.\n");
        }
    }
}

int check_exiting_relais_for_date(const char *athlete_name, char *date_event) { // Checks if a relay event exists for the given athlete on the specified date
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

int is_valid_sport(const char *sport) { // Checks if the given sport event is valid
    for (int i = 0; i < numValidSports; i++) {
        if (strcmp(sport, validSports[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void prompt_sport(char *sport) { // Prompts the user to enter a sport event and validates it
    while (1) {
        printf("Enter event (valid options: 100m, 400m, 5000m, marathon, 4x400m): ");
        if (scanf("%49s", sport) == 1 && is_valid_sport(sport)) {
            break;
        } else {
            printf("Invalid event. Please try again.\n");
        }
    }
}

int is_valid_position(int position) { // Checks if the given position is valid (1-4)
    return position >= 1 && position <= 4;
}

void prompt_position(int *position) { // Prompts the user to enter a position and validates it
    while (1) {
        printf("Enter position (1, 2, 3, 4): ");
        if (scanf("%d", position) == 1 && is_valid_position(*position)) {
            break;
        } else {
            printf("Invalid position. Please try again.\n");
        }
    }
}

int compare_performance(const void *a, const void *b) { // Comparison function for sorting performances by time
    AthletePerformance *ap1 = (AthletePerformance *)a;
    AthletePerformance *ap2 = (AthletePerformance *)b;
    if (ap1->time < ap2->time) return -1;
    if (ap1->time > ap2->time) return 1;
    return 0;
}

/**
 * athlete_progress_dates - Calculates the progress of an athlete between two dates for a specific event.
 *
 * This function finds the performance times of an athlete for a specified event on two given dates.
 * It then calculates and prints the difference in performance times between the two dates.
 * If the times for one or both dates are not found, an appropriate message is printed.
 */
void athlete_progress_dates(const Athlete *athlete, const char *event, const char *date1, const char *date2) {
    float time1 = -1.0; // Initialize time1 to -1.0 to indicate not found
    float time2 = -1.0; // Initialize time2 to -1.0 to indicate not found

    // Ensure date1 is earlier than date2
    char date_earlier[11], date_later[11];
    if (strcmp(date1, date2) <= 0) {
        strcpy(date_earlier, date1);
        strcpy(date_later, date2);
    } else {
        strcpy(date_earlier, date2);
        strcpy(date_later, date1);
    }

    // Loop through performances to find the times for the given dates
    for (int i = 0; i < athlete->count; i++) {
        if (strcmp(athlete->performances[i].event, event) == 0) {
            if (strcmp(athlete->performances[i].date, date_earlier) == 0) {
                time1 = atof(athlete->performances[i].time); // Convert time string to float
            }
            if (strcmp(athlete->performances[i].date, date_later) == 0) {
                time2 = atof(athlete->performances[i].time); // Convert time string to float
            }
        }
    }

    // Print the progress if both times are found
    if (time1 >= 0 && time2 >= 0) {
        printf("Athlete's progress for event %s between %s and %s: %.2f\n", event, date_earlier, date_later, time2 - time1);
    } else {
        printf("Times not found for one of the specified dates.\n");
    }
}

/**
 * find_top_athletes - Finds and displays the top 3 athletes for a specific event.
 *
 * This function searches through all athlete files in the DATA_DIR directory,
 * reads their performances for a specified event, and determines the top 3 performances.
 * If less than 3 performances are found, it displays the available top performances.
 * If no performances are found for the event, it prints an appropriate message.
 */
void find_top_athletes(const char *event) {
    DIR *dir; // Pointer for the directory
    struct dirent *entry; // Structure to hold directory entries
    AthletePerformance *all_performances = NULL; // Array to hold all performances for the event
    int total_performances = 0; // Counter for the total number of performances

    // Open the data directory
    if ((dir = opendir(DATA_DIR)) == NULL) {
        perror("opendir"); // Print an error message if the directory cannot be opened
        return;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if the entry is a regular file
            Athlete athlete;
            char athlete_name[50];
            strncpy(athlete_name, entry->d_name, sizeof(athlete_name)); // Copy the file name
            athlete_name[strcspn(athlete_name, ".")] = '\0'; // Remove the file extension
            read_performances(athlete_name, &athlete); // Read the athlete's performances

            // Check each performance for the specified event
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
    closedir(dir); // Close the directory

    // If there are performances, sort and display the top 3
    if (total_performances > 0) {
        qsort(all_performances, total_performances, sizeof(AthletePerformance), compare_performance);

        int num_athletes = total_performances < 3 ? total_performances : 3; // Determine the number of top athletes to display
        printf("Top %d athletes for event %s:\n", num_athletes, event);
        for (int i = 0; i < num_athletes; i++) {
            printf("%d. %s - Time: %.2f\n", i + 1, all_performances[i].name, all_performances[i].time);
        }

        // Congratulate the top athletes
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

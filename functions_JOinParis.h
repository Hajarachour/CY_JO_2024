#ifndef FUNCTIONS_JOINPARIS_H
#define FUNCTIONS_JOINPARIS_H

#include "structures_JOinParis.h"

// Function declarations
void create_data_dir();
void create_athlete_file(const char* athlete_name);
void add_performance(const char* athlete_name, const char* date, const char* event, const char* time, int position);
void create_initial_athletes();
int compare_dates(const void *a, const void *b);
void read_performances(const char* athlete_name, Athlete *athlete);
void display_history(const Athlete *athlete);
void athlete_statistics(const Athlete *athlete, const char *event);
void athlete_progress_linear(const Athlete *athlete, const char *event);
void athlete_progress_dates(const Athlete *athlete, const char *event, const char *date1, const char *date2);
void prompt_date(char *date);
void prompt_sport(char *sport);
void prompt_position(int *position);
int is_valid_date(const char *date);
int is_valid_sport(const char *sport);
int is_valid_position(int position);
int check_exiting_relais_for_date(const char *athlete_name, char *date_event);
void find_top_athletes(const char *event);
int compare_performance(const void *a, const void *b);

#endif

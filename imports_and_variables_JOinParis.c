#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define DATA_DIR "data_athletes"
#define MAX_LINE_LENGTH 256
#define INITIAL_PERFORMANCES 10

const char *validSports[] = {"100m", "400m", "5000m", "marathon", "4x400m"}; // List of available sports
const int numValidSports = sizeof(validSports) / sizeof(validSports[0]);

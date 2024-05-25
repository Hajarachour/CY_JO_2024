typedef struct {
    char date[11];
    char event[50];
    char time[10];
    int position; // Position for relay races
} Performance;

typedef struct {
    char name[50];
    Performance *performances;
    int count;
    int capacity;
} Athlete;

typedef struct { // Structure to hold athlete performance data
    char name[50];
    float time;
} AthletePerformance;

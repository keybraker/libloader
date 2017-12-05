#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <ctime>

using namespace std;

struct progressData{
    int     FINAL,
            time;
    string  name;
};

void loadingDots (progressData* progressValues, int numOfValues);
void progressBar (progressData* progressValues, int numOfValues);
void pingpong (progressData* progressValues, int numOfValues);

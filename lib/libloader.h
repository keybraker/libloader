#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <ctime>

using namespace std;

struct progress_data
{
    int FINAL,
        time;
    string name;
};

void loading_dots(progress_data *progress_values, int num_of_values);
void progressBar(progress_data *progress_values, int num_of_values);
void pingpong(progress_data *progress_values, int num_of_values);

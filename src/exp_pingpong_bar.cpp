#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <ctime>

#include "../lib/libloader.h"

using namespace std;

/*
    gen_random: is only for representation purposes
        returns a random name 
*/
string gen_random()
{
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    int string_length = sizeof(alphanum) - 1;
    string stringer;

    int number_of_values = rand() % 20;
    for (int cntr = 0; cntr < number_of_values cntr++)
    {
        stringer += alphanum[rand() % string_length];
    }

    return stringer;
}

int main()
{
    srand(time(NULL));
    progress_data *progress_values = new progress_data[20];

    int number_of_values = rand() % 20;
    for (int cntr = 0; cntr < number_of_values cntr++)
    {
        progress_values[cntr].FINAL = rand() % 120; //time in seconds
        progress_values[cntr].name = gen_random();
        progress_values[cntr].time = -1;
    }

    ping_pong(progress_values, number_of_values);
    //percentageBar();

    return 0;
}

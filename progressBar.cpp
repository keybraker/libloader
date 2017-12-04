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

void percentageBar (progressData* progressValues, int numOfValues){

    int k = 0;
    time_t start,end;
    time (&start);
    time (&end);
    
    system("clear");
    while ( difftime (end,start) < progressValues[0].FINAL ||
            difftime (end,start) < progressValues[1].FINAL ||
            difftime (end,start) < progressValues[2].FINAL ){
        
        int length = 0;
        while(length < numOfValues){
            
            string inliner = "\033["+to_string(length+1)+";0f";
            if(progressValues[length].time !=  -1){ 
                int pos = (progressValues[length].time*50)/progressValues[length].FINAL;
                cout    << inliner
                        << setw(3) << (2*pos) << " % [";
                        for (int i = 0; i < 50 ; i++) {
                            if (i < pos) cout << "=";
                            else if (i == pos) cout << ">";
                            else cout << " ";
                        }
                cout    << "] " << progressValues[length].name;

            }else{

                if(difftime (end,start) >= progressValues[length].FINAL){
                    int pos = (difftime(end, start)*50)/progressValues[length].FINAL;
                    cout    << inliner
                            << setw(3) << (2*pos) << " % [";
                            for (int i = 0; i < 50 ; i++) {
                                if (i < pos) cout << "=";
                                else if (i == pos) cout << ">";
                                else cout << " ";
                            }
                    cout    << "] " << progressValues[length].name;

                    progressValues[length].time = difftime(end, start);

                }else{
                    int pos = (difftime(end, start)*50)/progressValues[length].FINAL;
                    cout    << inliner
                            << setw(3) << (2*pos) << " % [";
                            for (int i = 0; i < 50 ; i++) {
                                if (i < pos) cout << "=";
                                else if (i == pos) cout << ">";
                                else cout << " ";
                            }
                    cout    << "] " << progressValues[length].name;
                }

            }
            length++;
        }
        cout.flush();
        usleep(250000);
        time (&end);
    }


    int length = 0;
    while(length < numOfValues){
        
        string inliner = "\033["+to_string(length+1)+";0f";
        if(progressValues[length].time == -1){
            progressValues[length].time = difftime (end,start);
        } 
        int pos = (progressValues[length].time*50)/progressValues[length].FINAL;
        cout    << inliner
                << setw(3) << (2*pos) << " % [";
                for (int i = 0; i < 50 ; i++) {
                    if (i < pos) cout << "=";
                    else if (i == pos) cout << ">";
                    else cout << " ";
                }
        cout    << "] " << progressValues[length].name;

        cout.flush();
        length++;
    }
}

/*
    genRandom:  is only for representation purposes
                returns a random name 
*/
string genRandom(){

    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    string stringer;

    int cntr = 0, numberOfValues = rand() % 20;
    while(cntr < numberOfValues){
        stringer += alphanum[rand() % stringLength];
        cntr++;
    }

    return stringer;
}

int main() {

    srand (time(NULL));
    progressData* progressValues = new progressData[20];

    int cntr = 0, numberOfValues = rand() % 20;
    while(cntr < numberOfValues){

        progressValues[cntr].FINAL = rand() % 120; //time in seconds
        progressValues[cntr].name =  genRandom();;
        progressValues[cntr].time = -1;

        cntr++;
    }

    percentageBar(progressValues, numberOfValues);

    return 0;
}

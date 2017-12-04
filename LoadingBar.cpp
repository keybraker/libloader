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

void loadingDots (progressData* progressValues, int numOfValues){

    int k = 0;
    time_t start,end;
    time (&start);
    time (&end);
    
    system("clear");
    while ( difftime (end,start) < progressValues[0].FINAL ||
            difftime (end,start) < progressValues[1].FINAL ||
            difftime (end,start) < progressValues[2].FINAL ){

        string progress;
        if(k == 0){ k++; progress = string(1, '.') + string(5, ' ');}
        else if (k == 1){ k++; progress = string(2, '.') + string(4, ' ');}
        else{ k=0; progress = string(3, '.') + string(3, ' ');}
        
        int length = 0;
        while(length < numOfValues){
            
            string inliner = "\033["+to_string(length+1)+";0f";
            if(progressValues[length].time !=  -1){ 

                if(progressValues[length].time >= 60){
                    cout    << inliner
                            << "[ " << setw(4) 
                            << " 100% / " << setw(4) 
                            << setprecision(2) 
                            << progressValues[length].time/60 
                            << " min ] loading " 
                            << progressValues[length].name
                            << " ✔  " << endl;
                }else{
                    cout    << inliner
                            << "[ " << setw(4) 
                            << " 100% / " << setw(4) 
                            << setprecision(2) 
                            << progressValues[length].time 
                            << " sec ] loading " 
                            << progressValues[length].name
                            << " ✔  " << endl;
                }

            }else{

                if(difftime (end,start) >= 60){

                    if(difftime (end,start) >= progressValues[length].FINAL){
                        cout    << inliner
                                << "[ " << setw(4) 
                                << " 100% / " << setw(4) 
                                << setprecision(2) << difftime (end,start)/60 
                                << " min ] loading " 
                                << progressValues[length].name
                                << " ✔  " << endl;

                        progressValues[length].time = difftime(end, start);

                    }else{

                        cout    << inliner
                                << "[ " << setw(4) 
                                << setprecision(2) << difftime (end,start)/progressValues[length].FINAL*100 
                                << "% / " << setw(4) 
                                << setprecision(2) << difftime (end,start)/60 
                                << " min ] loading " 
                                << progressValues[length].name
                                << " " << progress;

                    }

                }else{

                    if(difftime (end,start) >= progressValues[length].FINAL){
                        cout    << inliner
                                << "[ " << setw(4) 
                                << " 100% / " << setw(4) 
                                << setprecision(2) << difftime (end,start) 
                                << " sec ] loading " 
                                << progressValues[length].name
                                << " ✔  " << endl;

                        progressValues[length].time = difftime(end, start);

                    }else{

                        cout    << inliner
                                << "[ " << setw(4) 
                                << setprecision(2) << difftime (end,start)/progressValues[length].FINAL*100 
                                << "% / " << setw(4) 
                                << setprecision(2) << difftime (end,start) 
                                << " sec ] loading " 
                                << progressValues[length].name
                                << " " << progress;

                    }

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

        if(progressValues[length].time >= 60){
            cout    << inliner
                    << "[ " << setw(4) 
                    << " 100% / " << setw(4) 
                    << setprecision(2) 
                    << progressValues[length].time/60 
                    << " min ] loading " 
                    << progressValues[length].name
                    << " ✔  " << endl;
        }else{
            cout    << inliner
                    << "[ " << setw(4) 
                    << " 100% / " << setw(4) 
                    << setprecision(2) 
                    << progressValues[length].time 
                    << " sec ] loading " 
                    << progressValues[length].name
                    << " ✔  " << endl;
        }
        cout.flush();
        length++;
    }
}

void percentageBar (){

    float progress = 0.0;
    while (progress < 1.0) {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        sleep(1);
        std::cout.flush();

        progress += 0.16; // for demonstration only
    }
    std::cout << std::endl;

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

        progressValues[cntr].FINAL = rand() % 120;//time in seconds
        progressValues[cntr].name =  genRandom();;
        progressValues[cntr].time = -1;

        cntr++;
    }

    loadingDots(progressValues, numberOfValues);
    //percentageBar();

    return 0;
}

//sudo tcpdump -ni h1-eth0 not ether proto 0x88cc and not ether proto 0x8942 and not arp

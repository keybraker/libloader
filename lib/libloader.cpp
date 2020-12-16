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

void loading_dots(progress_data *progress_values, int num_of_values)
{
    int k = 0;
    time_t start, end;
    time(&start);
    time(&end);

    system("clear");
    while (difftime(end, start) < progress_values[0].FINAL ||
           difftime(end, start) < progress_values[1].FINAL ||
           difftime(end, start) < progress_values[2].FINAL)
    {
        string progress;
        if (k == 0)
        {
            k++;
            progress = string(1, '.') + string(5, ' ');
        }
        else if (k == 1)
        {
            k++;
            progress = string(2, '.') + string(4, ' ');
        }
        else
        {
            k = 0;
            progress = string(3, '.') + string(3, ' ');
        }

        int length = 0;
        while (length < num_of_values)
        {
            string inliner = "\033[" + to_string(length + 1) + ";0f";
            if (progress_values[length].time != -1)
            {
                if (progress_values[length].time >= 60)
                {
                    cout << inliner
                         << "[ " << setw(4)
                         << " 100% / " << setw(4)
                         << setprecision(2)
                         << progress_values[length].time / 60
                         << " min ] loading "
                         << progress_values[length].name
                         << " ✔  " << endl;
                }
                else
                {
                    cout << inliner
                         << "[ " << setw(4)
                         << " 100% / " << setw(4)
                         << setprecision(2)
                         << progress_values[length].time
                         << " sec ] loading "
                         << progress_values[length].name
                         << " ✔  " << endl;
                }
            }
            else
            {
                if (difftime(end, start) >= 60)
                {
                    if (difftime(end, start) >= progress_values[length].FINAL)
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << " 100% / " << setw(4)
                             << setprecision(2) << difftime(end, start) / 60
                             << " min ] loading "
                             << progress_values[length].name
                             << " ✔  " << endl;

                        progress_values[length].time = difftime(end, start);
                    }
                    else
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << setprecision(2) << difftime(end, start) / progress_values[length].FINAL * 100
                             << "% / " << setw(4)
                             << setprecision(2) << difftime(end, start) / 60
                             << " min ] loading "
                             << progress_values[length].name
                             << " " << progress;
                    }
                }
                else
                {
                    if (difftime(end, start) >= progress_values[length].FINAL)
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << " 100% / " << setw(4)
                             << setprecision(2) << difftime(end, start)
                             << " sec ] loading "
                             << progress_values[length].name
                             << " ✔  " << endl;

                        progress_values[length].time = difftime(end, start);
                    }
                    else
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << setprecision(2) << difftime(end, start) / progress_values[length].FINAL * 100
                             << "% / " << setw(4)
                             << setprecision(2) << difftime(end, start)
                             << " sec ] loading "
                             << progress_values[length].name
                             << " " << progress;
                    }
                }
            }
            length++;
        }
        cout.flush();
        usleep(250000);
        time(&end);
    }

    int length = 0;
    while (length < num_of_values)
    {
        string inliner = "\033[" + to_string(length + 1) + ";0f";

        if (progress_values[length].time == -1)
        {
            progress_values[length].time = difftime(end, start);
        }

        if (progress_values[length].time >= 60)
        {
            cout << inliner
                 << "[ " << setw(4)
                 << " 100% / " << setw(4)
                 << setprecision(2)
                 << progress_values[length].time / 60
                 << " min ] loading "
                 << progress_values[length].name
                 << " ✔  " << endl;
        }
        else
        {
            cout << inliner
                 << "[ " << setw(4)
                 << " 100% / " << setw(4)
                 << setprecision(2)
                 << progress_values[length].time
                 << " sec ] loading "
                 << progress_values[length].name
                 << " ✔  " << endl;
        }
        cout.flush();
        length++;
    }
}

void progress_bar(progress_data *progress_values, int num_of_values)
{
    time_t start, end;
    time(&start);
    time(&end);

    system("clear");
    while (difftime(end, start) < progress_values[0].FINAL ||
           difftime(end, start) < progress_values[1].FINAL ||
           difftime(end, start) < progress_values[2].FINAL)
    {
        int length = 0;
        while (length < num_of_values)
        {
            string inliner = "\033[" + to_string(length + 1) + ";0f";
            if (progress_values[length].time != -1)
            {
                int pos = (progress_values[length].time * 50) / progress_values[length].FINAL;
                cout << inliner
                     << setw(3) << (2 * pos) << " % [";
                for (int i = 0; i < 50; i++)
                {
                    if (i < pos)
                        cout << "=";
                    else if (i == pos)
                        cout << ">";
                    else
                        cout << " ";
                }
                cout << "] " << progress_values[length].name;
            }
            else
            {
                if (difftime(end, start) >= progress_values[length].FINAL)
                {
                    int pos = (difftime(end, start) * 50) / progress_values[length].FINAL;
                    cout << inliner
                         << setw(3) << (2 * pos) << " % [";
                    for (int i = 0; i < 50; i++)
                    {
                        if (i < pos)
                            cout << "=";
                        else if (i == pos)
                            cout << ">";
                        else
                            cout << " ";
                    }
                    cout << "] " << progress_values[length].name;

                    progress_values[length].time = difftime(end, start);
                }
                else
                {
                    int pos = (difftime(end, start) * 50) / progress_values[length].FINAL;
                    cout << inliner
                         << setw(3) << (2 * pos) << " % [";
                    for (int i = 0; i < 50; i++)
                    {
                        if (i < pos)
                            cout << "=";
                        else if (i == pos)
                            cout << ">";
                        else
                            cout << " ";
                    }
                    cout << "] " << progress_values[length].name;
                }
            }
            length++;
        }
        cout.flush();
        usleep(250000);
        time(&end);
    }

    int length = 0;
    while (length < num_of_values)
    {
        string inliner = "\033[" + to_string(length + 1) + ";0f";
        if (progress_values[length].time == -1)
        {
            progress_values[length].time = difftime(end, start);
        }
        int pos = (progress_values[length].time * 50) / progress_values[length].FINAL;
        cout << inliner
             << setw(3) << (2 * pos) << " % [";
        for (int i = 0; i < 50; i++)
        {
            if (i < pos)
                cout << "=";
            else if (i == pos)
                cout << ">";
            else
                cout << " ";
        }
        cout << "] " << progress_values[length].name;

        cout.flush();
        length++;
    }
}

void ping_pong(progress_data *progress_values, int num_of_values)
{
    int k = 0;
    time_t start, end;
    time(&start);
    time(&end);

    system("clear");
    while (difftime(end, start) < progress_values[0].FINAL ||
           difftime(end, start) < progress_values[1].FINAL ||
           difftime(end, start) < progress_values[2].FINAL)
    {
        string progress;
        if (k == 0)
        {
            k++;
            progress = string(1, '[') + string(1, '=') + string(3, ' ') + string(1, ']') + string(1, ' ');
        }
        else if (k == 1)
        {
            k++;
            progress = string(1, '[') + string(1, ' ') + string(1, '=') + string(2, ' ') + string(1, ']') + string(1, ' ');
        }
        else if (k == 2)
        {
            k++;
            progress = string(1, '[') + string(2, ' ') + string(1, '=') + string(1, ' ') + string(1, ']') + string(1, ' ');
        }
        else
        {
            k = 0;
            progress = string(1, '[') + string(3, ' ') + string(1, '=') + string(1, ']') + string(1, ' ');
        }

        int length = 0;
        while (length < num_of_values)
        {
            string inliner = "\033[" + to_string(length + 1) + ";0f";
            if (progress_values[length].time != -1)
            {
                if (progress_values[length].time >= 60)
                {
                    cout << inliner
                         << "[ " << setw(4)
                         << " 100% / " << setw(4)
                         << setprecision(2)
                         << progress_values[length].time / 60
                         << " min ] loading "
                         << progress_values[length].name
                         << " ✔               " << endl;
                }
                else
                {
                    cout << inliner
                         << "[ " << setw(4)
                         << " 100% / " << setw(4)
                         << setprecision(2)
                         << progress_values[length].time
                         << " sec ] loading "
                         << progress_values[length].name
                         << " ✔               " << endl;
                }
            }
            else
            {
                if (difftime(end, start) >= 60)
                {
                    if (difftime(end, start) >= progress_values[length].FINAL)
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << " 100% / " << setw(4)
                             << setprecision(2) << difftime(end, start) / 60
                             << " min ] loading "
                             << progress_values[length].name
                             << " ✔               " << endl;

                        progress_values[length].time = difftime(end, start);
                    }
                    else
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << setprecision(2) << difftime(end, start) / progress_values[length].FINAL * 100
                             << "% / " << setw(4)
                             << setprecision(2) << difftime(end, start) / 60
                             << " min ] loading "
                             << progress_values[length].name
                             << " " << progress;
                    }
                }
                else
                {
                    if (difftime(end, start) >= progress_values[length].FINAL)
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << " 100% / " << setw(4)
                             << setprecision(2) << difftime(end, start)
                             << " sec ] loading "
                             << progress_values[length].name
                             << " ✔               " << endl;

                        progress_values[length].time = difftime(end, start);
                    }
                    else
                    {
                        cout << inliner
                             << "[ " << setw(4)
                             << setprecision(2) << difftime(end, start) / progress_values[length].FINAL * 100
                             << "% / " << setw(4)
                             << setprecision(2) << difftime(end, start)
                             << " sec ] loading "
                             << progress_values[length].name
                             << " " << progress;
                    }
                }
            }
            length++;
        }
        cout.flush();
        usleep(333333);
        time(&end);
    }

    int length = 0;
    while (length < num_of_values)
    {
        string inliner = "\033[" + to_string(length + 1) + ";0f";

        if (progress_values[length].time == -1)
        {
            progress_values[length].time = difftime(end, start);
        }

        if (progress_values[length].time >= 60)
        {
            cout << inliner
                 << "[ " << setw(4)
                 << " 100% / " << setw(4)
                 << setprecision(2)
                 << progress_values[length].time / 60
                 << " min ] loading "
                 << progress_values[length].name
                 << " ✔               " << endl;
        }
        else
        {
            cout << inliner
                 << "[ " << setw(4)
                 << " 100% / " << setw(4)
                 << setprecision(2)
                 << progress_values[length].time
                 << " sec ] loading "
                 << progress_values[length].name
                 << " ✔               " << endl;
        }
        cout.flush();
        length++;
    }
}
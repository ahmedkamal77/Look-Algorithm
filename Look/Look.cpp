// Look.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set <int> higherTracks;
    set <int>::iterator higherIt = higherTracks.begin();
    set <int> lowerTracks;
    set <int>::iterator lowerIt = lowerTracks.begin();
    int direction = 1, n = 0, x = 0;  //1 means away cylinder center, 0 means twards cylinder center
    int track = 0, totalTracks = 0;
    cout << "Enter number of tracks and Initial Position and Direction e.g 70 50 1:";
    cin >> n >> track >> direction;
    cout << endl;
    cout << "Enter the number of element:";
    cin >> x;
    cout << endl;
    cout << "Enter the sequence of tracks:";
    for (int i = 0; i < x; i++)
    {
        int y = 0;
        cin >> y;
        if (y >= track)
            higherTracks.insert(y);
        else
            lowerTracks.insert(y);
    }
    cout << endl;
    higherIt = higherTracks.begin();
    lowerIt = lowerTracks.end();
    lowerIt--;

    if (direction == 1)
    {
        for (int i = 0; i < higherTracks.size(); i++)
        {
            totalTracks += *higherIt - track;
            track = *higherIt;
            higherIt++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //totalTracks += (n-track); track = n;   //in case the elevator will complete until the end of the cylinder (in case of SCAN strategy)

        for (int i = 0; i < lowerTracks.size(); i++)
        {
            totalTracks += track - *lowerIt;
            track = *lowerIt;
            lowerIt--;
        }
    }
    else
    {
        for (int i = 0; i < lowerTracks.size(); i++)
        {
            totalTracks += track - *lowerIt;
            track = *lowerIt;
            lowerIt--;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //totalTracks += track - 0;  track = 0;   //in case the elevator will complete until the start of the cylinder (in case of SCAN strategy)

        for (int i = 0; i < higherTracks.size(); i++)
        {
            totalTracks += *higherIt - track;
            track = *higherIt;
            higherIt++;
        }
    }

    cout << "Total tracks = " << totalTracks << endl;  //assumig that seek time = 1 ms for each track 

}



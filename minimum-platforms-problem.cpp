#include <bits/stdc++.h>
using namespace std;

// O(nlogn) time, O(1) space
int minStations(vector<double> arrival, vector<double> depart) {
    sort(arrival.begin(), arrival.end());
    sort(depart.begin(), depart.end());

    int i = 0, j = 0, cnt = 0, stations = 0;
    while(i < arrival.size() && j < depart.size()) {
        if(arrival[i] <= depart[j]) {
            cnt++; i++;
        }
        else {
            cnt--; j++;
        }
        stations = max(stations, cnt);
    }
    return stations;
}

int main() {
    vector<double> arrival {2.00, 2.10, 3.00, 3.20, 3.50, 5.00}, depart {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};
    cout << minStations(arrival, depart) << endl;

    return 0;
}

/*

After sorting both arrival and departure times, 

arrival:    2.00, 2.10, 3.00, 3.20, 3.50, 5.00
depart:     2.30, 3.20, 3.40, 4.00, 4.30, 5.20

Check at any point what are the max number of trains on platform:

Time        Arrival/Depart          Total platforms needed at this time

2.00           Arrival                              1
2.10           Arrival                              2
2.30           Depart                               1
3.00           Arrival                              2
3.20           Depart                               1
3.20           Arrival                              2
3.40           Depart                               1
3.50           Arrival                              2
4.00           Depart                               1
4.30           Depart                               0
5.00           Arrival                              1
5.20           Depart                               0

So, max trains on platforms at any time did not exceed 2. So, min platforms needed: 2

*/

#include <bits/stdc++.h>
using namespace std;

// O(1) time, O(1) space
double angleClock(string t) {
    string h, m;
    istringstream ss(t);
    getline(ss, h, ':'), getline(ss, m);

    int hrs = stoi(h) % 12, min = stoi(m);

    double degHrs = (hrs + (double)min/60) * 30;
    double degMin = (min * 6);

    double diff = abs(degHrs - degMin);
    if(diff > 180)  diff = 360 - diff;
    return diff;
}

int main() {
    string t = "1:45";
    cout << angleClock(t) << endl;

    return 0;
}

/*

Angle covered by hour hand in 1 hr = 360 / 12 = 30
Angle covered by min hand in 1 min = 360 / 60 = 6
Angle between hour and min hand is the absolute difference between the two.

Ex: time = 1:45, distance travelled by hour hand = 1 + (45/60) hrs = 1.75 hrs and distance travelled by min hand = 45 mins
Angle covered by hour hand = 1.75 * 30 = 52.5
Angle covered by min hand = 45 * 6 = 270

So, difference between the two angles, diff = 217.5
Shorter angle between them is min(360 - diff, diff) = min(142.5, 217.5) = 142.5

*/

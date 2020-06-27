#include <bits/stdc++.h>
using namespace std;

/*

heights:    7 0 4 2 5 0 6 4 0 5
lmax:       0 7 7 7 7 7 7 7 7 7     -> tallest bar on left of current bar
rmax:       6 6 6 6 6 6 5 5 5 0     -> tallest bar on right of current bar

rain:         6 2 4 1 6 0 1 5       -> 25
We don't care about trapping rain water on edge bars because it'll flow over the edges

*/

// Two passes. O(n) time, O(n) space
int trappingRainWater(vector<int> heights) {
    int n = heights.size();
    vector<int> lmax(n), rmax(n);

    // tallest bar to the left of current bar
    for(int i = 1; i < n; i++)  lmax[i] = max(lmax[i-1], heights[i-1]);
    
    int rain = 0;
    for(int i = n-2; i >= 0; i--) {
        rmax[i] = max(rmax[i+1], heights[i+1]);     // tallest bar to the right of current bar

        // find amount of rain that can deposit over current bar
        int diff = min(lmax[i], rmax[i]) - heights[i];
        rain += (diff < 0) ? 0 : diff;
    }
    return rain;
}



/*

l                   r        lmax = 0, rmax = 2, rain = 0
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] <= lmax, so rain += 0-0, and l++

  l                 r        lmax = 0, rmax = 2, rain = 0
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] > lmax, so lmax = 1 and l++

    l               r        lmax = 1, rmax = 2, rain = 0
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] <= lmax, so rain += 1-0, and l++

      l             r        lmax = 1, rmax = 2, rain = 1
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] > lmax, so lmax = 2, and l++

        l           r        lmax = 2, rmax = 2, rain = 1
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] <= lmax, so rain += 2-1 and l++

          l         r        lmax = 2, rmax = 2, rain = 2
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] <= lmax, so rain += 2-0 and l++

            l       r        lmax = 2, rmax = 2, rain = 4
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] <= lmax, so rains += 2-1 and l++

              l     r        lmax = 2, rmax = 2, rain = 5
0 1 0 2 1 0 1 3 2 1 2     -> lmax <= rmax and heights[l] > lmax, so lmax = 3 and l++

                l   r        lmax = 3, rmax = 2, rain = 5
0 1 0 2 1 0 1 3 2 1 2     -> rmax < lmax and heights[r] <= rmax, so rain += 2-2 and r--

                l r          lmax = 3, rmax = 2, rain = 5
0 1 0 2 1 0 1 3 2 1 2     -> rmax < lmax and heights[r] <= rmax, so rain += 2-1 and r--

                  l
0 1 0 2 1 0 1 3 2 1 2        lmax = 3, rmax = 2, rain = 6
                  r

*/

// Single Pass. O(n) time, O(1) space
int trappingRainWater(vector<int> heights) {
    int n = heights.size(), l = 0, r = n-1;

    int lmax = heights[0], rmax = heights[n-1], rain = 0;
    while(l < r) {
        if(lmax <= rmax) {
            if(heights[l] > lmax)   lmax = heights[l];
            else    rain += lmax - heights[l];
            l++;
        }
        else {
            if(heights[r] > rmax)    rmax = heights[r];
            else    rain += rmax - heights[r];
            r--;
        }
    }
    return rain;
}

int main() {
    vector<int> heights {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2};
    cout << trappingRainWater(heights) << endl;

    return 0;
}

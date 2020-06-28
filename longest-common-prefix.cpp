#include <bits/stdc++.h>
using namespace std;

// O(s) time, where s is sum of all characters in words, O(1) space
string longestCommonPrefix(vector<string> words) {
    int n = words.size();
    string lcp;
    bool mismatch = false;

    // for each character upto mismatch in first word
    for(int i = 0, j; i < words[0].size() && !mismatch; i++) {
        // check character at same index for remaining words
        for(j = 1; j < n; j++) {
            if(words[j][i] != words[0][i]) {
                mismatch = true; break;     // is mismatch break out of loops
            }
        }
        if(j == n)  lcp += words[0][i];     // if character is present in all words, add it to lcp
    }
    return lcp;
}

int main() {
    vector<string> words {"flower", "flow", "flight"};
    cout << longestCommonPrefix(words) << endl;

    return 0;
}

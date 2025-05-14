Ques - Find the duplicate in an array

#include <bits/stdc++.h>
using namespace std;

int duplicate(const vector<int>& array) {
    int n = array.size();
    vector<int> sorted = array;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i + 1 < n; i++) {
        if (sorted[i] == sorted[i + 1]) {
            return sorted[i];       
        }
    }
    return -1;
}
int main() {
    vector<int> array = {98, 77, 56, 44, 54, 223, 33, 56, 56};
    cout << duplicate(array);
    return 0;
}

Ques - Print all the elements of an array.

# include <bits/stdc++.h>
using namespace std;
void Print(vector <int> array) {
  int n = array.size();
  for (int i = 0; i < n; i++){
    cout << array[i];
  }
}
int main(){
  int array = {2,3,4,5};
  Print(array);
  return 0;
}

// sizeof/sizeof only works on old‐style C arrays you declare right there. 
// It divides total bytes by one element’s bytes — all done at compile time.
// .size() is a built-in counter for C++ containers (like vector) that always knows how many elements it holds, 
// even if you add or remove items at runtime.
// In short: use sizeof/sizeof for plain fixed arrays; use .size() for any modern C++ container that tracks its own length.


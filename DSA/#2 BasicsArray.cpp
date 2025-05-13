Ques - Print the array

# include <bits/stdc++.h>
using namespace std;

void Print (vector<int> array){
  cout << "{";
  int n = array.size();
  for (int i = 0; i < n; i++) {
    cout << array[i];
    if( i < n - 1){
      cout << ",";
    }
  }
  cout << "}";
}
int main(){
  vector<int> array = {2,3,4,5};
  Print(array);
  return 0;
}

Ques - Find the Sum of an Array

#include <bits/stdc++.h>
using namespace std;

int Sum (vector<int> array) {
  int n = array.size();
  int result = 0;
  for (int i = 0; i < n; i++){
    result = result + array[i];
  }
  cout << result;
  return result;
}
int main () {
  vector <int> array = {2,3,4,5};
  Sum(array);
  return 0;
}

//we can also write -
int Sum (const vector<int>& array){
  int result = 0;
  for(int x : array) result += x;
  return result;
}
int main () {
  vector<int> array = {2,3,4,5};
  cout << Sum(array) << endl;
  return 0;
}

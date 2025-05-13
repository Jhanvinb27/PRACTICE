Ques - Tell if a value exists in an array

# include <bits/stdc++.h>
using namespace std;

bool ifExists (const vector <int>& array, int x) {
  int n = array.size();
  for (int i = 0; i < n; i++){
    if ( x == array[i]){
      return true;
    }
  }
  return false;
}
int main () {
  vector <int> array = {7,5,8,5,3,4};
  int x = 99;
  if( ifExists(array,x)){
      cout << "true";
  } else {
      cout << "false";
  }
  return 0;
}

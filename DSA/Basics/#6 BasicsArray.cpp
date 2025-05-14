Ques - Find the smallest element of the array and return it's index

# include <bits/stdc++.h>
using namespace std;

int Smallest(const vector<int>& array){
  int n = array.size();
  int small = INT_MAX;
  int idx = -1;
  for (int i = 0; i < n; i++){
    if(array[i] < small){
      small = array[i];
      idx = i;
    }
  }
  return idx;
}
int main(){
  vector<int> array = {43893484,85,23895,483488,958};
  cout << Smallest(array);
  return 0;
}

O/P : 1

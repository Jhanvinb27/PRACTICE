Ques - Find the max element of an array

# include<bits/stdc++.h>
using namespace std;

int Max (const vector<int>& array){
  int n = array.size();
  int maxi = 0;
  for(int i = 0; i < n; i++){
    maxi = array[0];
    if(array[i] > maxi){
      maxi = array[i];
    }
  }
  return maxi;
}
int main() {
  vector<int> array = {2,3,4,5,6};
  cout << Max(array) << endl;
  return 0;
}

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

# include <bits/stdc++.h>
using namespace std;

int Max2(const vector<int>& array) {
    int n = array.size();
    int max1 = max(array[0], array[1]);
    int max2 = min(array[0], array[1]);
    for (int i = 2; i < n; i++) {
        int x = array[i];
        if (x > max1) {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2) {
            max2 = x;
        }
    }
    return max2;
}

int main (){
  vector<int> array = {2,3,4,5,6};
  cout << Max2(array) << endl;
  return 0;
}

Ques - In an array with all duplicates, return the single element

# include<bits/stdc++.h>
using namespace std;

int Single(const vector<int>& array){
  int n = array.size();
  vector<int> sorted = array;
  sort(sorted.begin(),sorted.end());
  for(int i = 0; i + 1 < n; i+=2){
    if(sorted[i] != sorted[i+1]){
      return sorted[i];
    }
  }
  return sorted[n-1];
}

int main(){
  vector<int> array = {2,2,3,3,4,4,8,1,1};
  cout << Single(array);
  return 0;
}

//Beautiful solution
class Solution {
public:
  int Singleton(vector<int> array){
    int n = array.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
      ans = ans^nums[x]; // ans^=nums[x]
    }
    return ans;
  }
};


/*
Ques - There are n cars going to the same destination along a one-lane road.
     - The destination is target miles away.
     - You are given two arrays:
            - position[i]: starting position of ith car
            - speed[i]: speed of ith car
     - A car cannot overtake another car
     - If a faster car catches a slower car, they form a fleet
     - A fleet moves at the speed of the slowest car
     - Return the number of car fleets reaching the destination
*/

/*
Example 1 - Input: target = 12
                    position = [10,8,0,5,3]
                    speed = [2,4,1,1,3]
          - Output: 3

Example 2 - Input: target = 10
                    position = [3]
                    speed = [3]
          - Output: 1
*/

/*
Observation -
- Cars cannot overtake → order matters
- Faster cars behind may catch slower cars ahead
- Fleet forms when a car catches up before target
- Instead of simulating movement → think in terms of time
- Time to reach target = (target - position) / speed :contentReference[oaicite:0]{index=0}
*/

/*
Approach - Greedy + Sorting
         - Calculate time each car takes to reach target
         - Sort cars by position (closest to target first)
         - Traverse from closest to farthest
         - Track maximum time (slowest fleet ahead)

Intuition -
- If a car behind takes LESS time → it catches up → same fleet
- If a car takes MORE time → cannot catch → new fleet
- So we only compare times, not simulate movement
*/

/*
Algorithm -
          - create vector of pair(position, time)
          - sort in descending order of position
          - initialize fleets = 0
          - initialize maxTime = 0
          - for each car:
                - if current time > maxTime:
                        - fleets++
                        - update maxTime
          - return fleets
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), greater<>());

        int fleets = 0;
        double maxTime = 0;

        for(auto &car : cars){
            if(car.second > maxTime){
                fleets++;
                maxTime = car.second;
            }
        }

        return fleets;
    }
};

// Time : O(n log n)   (sorting)
// Space : O(n)

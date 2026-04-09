/*
Ques - You are given an 2-D array points where points[i] = [xi, yi] 
represents the coordinates of a point on an X-Y axis plane. 
You are also given an integer k.

Return the k closest points to the origin (0, 0).

The distance between two points is defined as the 
Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).

You may return the answer in any order.
*/
/*
Approach - we'll find distance of every point on the plane w.r.t origin
         - sort it  // no need to sort just push in heap because heaps have the property to store the max only
         - and will maintain a heap of size k of closest points.
         - first we will push all in k.
         - then pop the top with the max elements.
         - return the heap elements in an array.
*/
# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;

        for(auto p : points){
            int dist = p[0]*p[0] + p[1]*p[1];
            pq.push({dist, p});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Time: O(n log k)
//Space: O(k)

/*
Ques - Design a data structure that efficiently maintains 
       the median of a dynamically growing stream of integers.
     - You must implement the following operations:
           - MedianFinder() → Initializes the data structure
           - void addNum(int num) → Adds an integer num to the stream
           - double findMedian() → Returns the median of all elements so far
*/
/*
Example - Input
          ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
          [[], [1], [2], [], [3], []]
        - Output
          [null, null, null, 1.5, null, 2.0]
        - Explanation
          MedianFinder mf = new MedianFinder();
          mf.addNum(1);       // Stream = [1]
          mf.addNum(2);       // Stream = [1, 2]
          mf.findMedian();    // (1 + 2) / 2 = 1.5
          mf.addNum(3);       // Stream = [1, 2, 3]
          mf.findMedian();    // 2
*/
/*
Observation - The input numbers can be positive, negative, or zero
            - The number of elements in the stream can grow over time
            - The median should be updated after every insertion
*/
/*
Approach - sorting (too slow)
         - every time a number comes → sort everything again 😭
*/
/*
Approach - split into two heaps: left max, right min — median sits at the boundary
         - split nums into two groups:
         - we will maintain two heaps:
                - max heap : L.H.S to store the set of smallest num.
                             top will be max(largest) of all small nums
                - min heap : R.H.S to store the set of the largest num.
                             top will be min(smallest) of all large nums
        - we maintain size diff <= 1
        - left elements <= right elements
        - decide where to put the incoming stream elements
                - if x is small → goes to LEFT (max heap)
                - if x is big → goes to RIGHT (min heap)
        - simply compare with maxHeap.top()
*/

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.size() > right.size() ? left.top() : right.top();
    }
};

/* Time : addNum()     → O(log n)
          findMedian() → O(1)
   Space : O(n)
*/

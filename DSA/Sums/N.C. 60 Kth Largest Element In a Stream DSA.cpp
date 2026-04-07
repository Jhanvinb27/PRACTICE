/*
Design a class to find the kth largest integer in a stream of values, including duplicates. 
E.g. the 2nd largest from [1, 2, 3, 3] is 3. 
The stream is not necessarily sorted.

Implement the following methods:
      -  constructor(int k, int[] nums) Initializes the object given an integer k and the stream of integers nums.
      -  int add(int val) Adds the integer val to the stream and returns the kth largest integer in the stream.

*/

/*
Example - 
Input:
["KthLargest", [3, [1, 2, 3, 3]], "add", [3], "add", [5], "add", [6], "add", [7], "add", [8]]

Output:
[null, 3, 3, 3, 5, 6]

Explanation:
KthLargest kthLargest = new KthLargest(3, [1, 2, 3, 3]);
kthLargest.add(3);   // return 3
kthLargest.add(5);   // return 3
kthLargest.add(6);   // return 3
kthLargest.add(7);   // return 5
kthLargest.add(8);   // return 6
*/

/*
Constraints:
1 <= k <= 1000
0 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-1000 <= val <= 1000
There will always be at least k integers in the stream when you search for the kth integer.
*/

/*
Approach 1 - we will look at the array 
           - then we will create an output array and will insert the 1st value as "null"
           - then we will insert the given number from the input array to original sorted array
           - then will sort the array  
           - and add the kth element by finding it using n-k to the output array
*/
/*
ex - this array is given nums[4,5,3,2,7,8,4,3,1,6,7,7,6,8,0]
      n=15 k=3
   - first we will sort this array // O(nlog n)
      # include <bits/stdc++.h>
      using namespace std;
      int main(){
        vector <int> nums = {4,5,3,2,7,8,4,3,1,6,7,7,6,8,0};
        sort (nums.begin(),nums.end());
        for(int x : nums) cout << x << " ";
        return 0;
      }
   - this will output [0 1 2 3 3 4 4 5 6 6 7 7 7 8 8 ]
   - then using the sorted array, we will find the kth largest element // O(1)
   - then with [n-k], we can find the kth largest element(since duplicates are not needed to be handeled)
   - this will give us kth largest element i.e 15-3=12th element of the array i.e 7
   - then add this in output array
   - T.C = O(nlog n)
   - S.C = O(log n) // sort() uses recursion stack
*/
// Let's code this approach
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4,5,3,2,7,8,4,3,1,6,7,7,6,8,0};
    int k = 3;

    // step 1: sort the array
    sort(nums.begin(), nums.end());

    // step 2: create output array and insert "null" (using -1 as placeholder)
    vector<int> output;
    output.push_back(-1);

    // step 3: insert all elements from sorted array
    for(int x : nums) {
        output.push_back(x);
    }

    // step 4: find kth largest using n-k
    int n = nums.size();
    int kthLargest = nums[n - k];

    // step 5: add kth largest to output array
    output.push_back(kthLargest);

    // print output
    for(int x : output) {
        cout << x << " ";
    }

    return 0;
}
//REDUNDANT AND DOESN"T MAKE SENSE
/*
Approach 2 : Maintain Sorted List
Intuition   -  In this problem, we need to be able to repeatedly fetch the k-th largest element 
            -  from a growing stream of numbers. Suppose we assume that the stream of numbers is 
            -  always sorted in ascending order. In that case, returning the k-th largest element becomes a 
            - straightforward operation of fetching the k-th element from the end of the stream.

            - Thus, one approach is to maintain a list that stores the entire stream of 
            - numbers seen so far, and ensure the list remains sorted each time we add a new element. 
            - This allows us to fetch the k-th largest element with no extra work.

            - For our constructor, we can initialize our list stream with the initial 
            - set of numbers nums provided, and then sort stream in ascending order.

            - For every new val added to the stream by the add(int val) call, 
            - we ensure val is inserted at the correct position so that stream remains sorted. 
            - Because stream is sorted beforehand, we can efficiently find the correct position 
            - for val by using binary search.

            For this binary search insertion: 
                  - We start with the entirety of stream as our search space
                  - We check the middle element stream[mid]
                  - If stream[mid] == val then we know that we can add val at index mid
                  - If stream[mid] < val, then val needs to be added to the right of stream[mid], 
                    so we limit the search space to the right half of stream.
                  - If stream[mid] is greater than val,val needs to be added to the left of stream[mid], 
                    so we limit the search space to the left half of stream.
                  - We can repeat this procedure until we narrow down our search space to 
                    the correct index to add val.
                  - After inserting val in the correct position, we can return 
                    stream[stream.length - k], which is the k-th largest element in the stream.
*/
/*
Algorithm
    1. In the constructor:
          - Initialize class variable k
          - Initialize class variable list stream
          - Add all of nums to stream, used to keep track of the total stream.
          - Sort stream in ascending order
    2. In the add(int val) function:
          - Call helper function getIndex(int val) to find the index i to add val
          - Insert val in stream at index i
          - Return the k-th largest element in stream, at index stream.size() - k
    3. In the getIndex(int val):
          - Define starting search space: Initialize left to 0 and right to stream.size() - 1
          - While left <= right:
                  - Calculate index for middle element: Initialize mid to (left + right) / 2
                  - Get middle element: Initialize midElement to stream.get(mid)
                  - If midElement == val return mid
                  - If midElement > val:
                  - Go to left half of search space: Reassign right to mid - 1
                  - If midElement < val:
                  - Go to right half of search space: Reassign left to mid + 1
*/
class KthLargest {
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            stream.push_back(num);
        }
        sort(stream.begin(), stream.end());
    }

    int add(int val) {
        int index = getIndex(val);
        // Add val to correct position
        stream.insert(stream.begin() + index, val);
        return stream[stream.size() - k];
    }

private:
    int getIndex(int val) {
        int left = 0;
        int right = stream.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = stream[mid];
            if (midValue == val) return mid;
            if (midValue > val) {
                // Go to left half
                right = mid - 1;
            } else {
                // Go to right half
                left = mid + 1;
            }
        }
        return left;
    }
};
/*
Complexity Analysis: 
          Let M be the size of the initial stream nums given in the constructor. 
          Let N be the number of calls of add.
Time Complexity: O(N^2 + N.M)
          The constructor involves creating a list stream from nums, which takes O(M) time. 
          Then, sorting this list takes O(M⋅logM) time. 
          Thus, the time complexity of the constructor is O(M⋅logM) time.

          The add function involves running a binary search on stream. 
          Because the total size of stream at the end would be O(M+N), 
          each binary search is bounded by a time complexity of O(log(M+N)). 
          Moreover, adding a number in stream can take worst-case O(M+N) time, 
          as adding an element in the middle of a list can offset all the elements to its right. 
          Then, the time complexity of a single add call would be O(M+N+log(M+N)). 
          Because add is called N times, the time complexity of all the 
          add calls would be O(N⋅(M+N+log(M+N))).

          We see that after expanding the time complexity for the add function, the N⋅M and N^2
          terms dominate all the other log terms in our calculations, so the total 
          time complexity is O(N^2+N⋅M)

Space Complexity: O(M+N)
          The maximum size for stream is M+N, so the total space complexity is O(M+N).
*/

/*
Approach 3: Heap
Intuition - In Approach 2, sorting the entire stream of numbers seems unnecessary because 
          - we only need the k-th largest element. Maintaining a sorted list becomes costly 
          - as its size increases. To optimize, we can focus on only the necessary elements for 
          - retrieving and updating the k-th largest element.

          - Consider a stream of numbers [0, 4, 6, 9] where k = 3 and incoming val = 2. 
          - Before adding 2, the k-th largest element is 4. Adding 2 does not affect 4's position 
          - since 2 is smaller. Now, if the incoming value is 7, which is greater than both 4 and 6, 7 
          - would become the 2nd largest number, pushing 6 to be the new k-th largest element, 
          - and 4 is no longer in the top k.

          - From this example, we see that keeping track of just the k largest elements allows us 
            to efficiently maintain the k-th largest element:
          - If an incoming element val is smaller than or equal to the existing k-th largest element: 
            The k largest elements remain unchanged, and we can return the current k-th largest element.
          - If val is larger than the current k-th largest element: It replaces the current k-th largest 
            element. After adding val, the new k-th largest element is the next largest element.
          - To efficiently maintain the k largest elements, we use a min-heap. 
            In a min-heap, elements are organized such that the smallest element is 
            always at the top (root node), providing O(1) access time. 
            Adding elements and removing the top element from the min-heap can be done in O(logn) time.

          - For our problem, the min-heap will contain the k largest elements, 
            with the k-th largest element at the top. If a new val is greater than the k-th largest element, 
            we add val to the heap and remove the top element, keeping the heap size at k and updating 
            the k-th largest element.

          - In our optimized approach, we initialize the min-heap with the initial stream nums 
            in the constructor and ensure it contains only the k largest elements. 
            In the add(int val) function, if val is smaller than the current k-th largest element 
            and the heap already contains k elements, we return the top element. Otherwise, we add val, 
            remove the top element if the heap size exceeds k, and return the updated top element.

          - This approach is more efficient in both time and space complexity compared to maintaining 
            a fully sorted list, as the relaxed ordering of a heap allows quick access and updates to 
            the k largest elements without the overhead of sorting the entire stream.

Algorithm - In the constructor:
          - Initialize class variable k to the input value k
          - Initialize a class PriorityQueue minHeap to hold the k largest elements
          - Iterate through each element num in the initial stream nums:
          - Call add(num)
          - In the add(int val) function:
          - If val is greater than the smallest element in minHeap or 
            the size of minHeap is less than k elements:
          - Add val to minHeap
          - If the size of minHeap is greater than k, then remove the top element
          - Return the top element as the k-th largest element in the stream
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        // Add to our minHeap if we haven't processed k elements yet
        // or if val is greater than the top element (the k-th largest)
        if (minHeap.size() < k || minHeap.top() < val) {
            minHeap.push(val);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
/*
Complexity Analysis: Let M be the size of the initial stream nums given in the constructor, 
                     and let N be the number of calls to add.
Time Complexity: O((M+N)⋅logk)
                    - The add function involves adding and removing an element from a heap of size k, 
                    - which is an O(logk) operation. Since the add function is called N times, 
                    - the total time complexity for all add calls is O(N⋅logk).
                    - The constructor also calls add M times to initialize the heap, 
                    - leading to a time complexity of O(M⋅logk).
                    - Therefore, the overall time complexity is O((M+N)⋅logk).
Space Complexity: O(k)
                 - The minHeap maintains at most k elements, so the space complexity is O(k).
*/

//Another one just to look at - it uses the min wala min heap
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  
    // Min-heap to store the k largest elements
};

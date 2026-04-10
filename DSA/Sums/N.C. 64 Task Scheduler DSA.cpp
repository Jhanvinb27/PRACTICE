/*
Ques - You are given an array of CPU tasks, each labeled with a letter from 
     - A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. 
     - Tasks can be completed in any order, but there's a constraint: 
     - there has to be a gap of at least n intervals between two tasks with the same label.
     - Return the minimum number of CPU intervals required to complete all tasks.
*/

/*
Example : Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
             After completing task A, you must wait two intervals before doing A again. 
             The same applies to task B. In the 3rd interval, neither A nor B can be done, 
             so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
*/

/*
Approach - check st element , put it in an output array
         - if same element exists in the array the check n's length
         - insert othrt element or put the place blank until n's length is acheived
         - repeat it again for next set
         - until all elements form original array gets exhausted
         - count the number of elements in the output array, count blank space as an element
         - return the number of elements
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> remaining = tasks;
        vector<char> output;

        while (!remaining.empty()) {
            unordered_set<char> used;
            int cycle = n + 1;
            vector<char> nextRemaining;

            for (int i = 0; i < remaining.size() && cycle > 0; i++) {
                if (used.find(remaining[i]) == used.end()) {
                    output.push_back(remaining[i]);
                    used.insert(remaining[i]);
                    cycle--;
                } else {
                    nextRemaining.push_back(remaining[i]);
                }
            }

            for (int i = 0; i < nextRemaining.size(); i++) {
                remaining.push_back(nextRemaining[i]);
            }

            remaining.erase(remaining.begin(), remaining.begin() + min((int)remaining.size(), (int)used.size()));

            while (cycle > 0 && !remaining.empty()) {
                output.push_back('_');
                cycle--;
            }
        }

        return output.size();
    }
};

// Time Linit exceeded

/*
Approach - count the letter that appears the most
         - put it first with gaps
         - fill gaps with other jobs
         - if gaps remain → add idle time
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Create 26 boxes (for A to Z) to count how many times each job appears
        vector<int> freq(26, 0);

        // Step 2: Go through each job and increase its count
        // Example: if we see 'A', we increase count of A
        for (char t : tasks)
            freq[t - 'A']++;

        // Step 3: Find the job that appears the most times
        // This job will control how we arrange everything
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Step 4: Count how many jobs have this maximum frequency
        // Example: if A=3 and B=3 → countMax = 2
        int countMax = count(freq.begin(), freq.end(), maxFreq);

        // Step 5: Imagine placing the most frequent job in groups
        // If maxFreq = 3 → we create 2 gaps between them
        int partCount = maxFreq - 1;

        // Step 6: Each gap must have at least 'n' distance
        // So each part size becomes (n + 1)
        int partLength = n + 1;

        // Step 7: Total minimum slots needed using this structure
        // We also add countMax at the end for last group
        int result = partCount * partLength + countMax;

        // Step 8: Sometimes we already have enough jobs to fill all gaps
        // So we take max of:
        // (1) total jobs
        // (2) calculated structure
        return max((int)tasks.size(), result);
    }
};
// Time Complexity : O(n) or O(|tasks|)
// Space Complexity : O(1) or O(26)

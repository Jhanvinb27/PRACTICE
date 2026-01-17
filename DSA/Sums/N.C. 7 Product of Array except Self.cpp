/*
Ques - Given an <int> array nums
     - return an array -> "output"   
     - where output[i] -> is product of elements of nums except nums[i]

Constraints - product is guaranteed to fit in 32 bit integer
              (a signed 32-bit integer ranges from -2,147,483,648 to 2,147,483,647, 
              while an unsigned 32-bit integer goes from 0 to 4,294,967,295)
            - 2 <= nums.length <= 1000
            - -20 <= nums[i] <= 20

Example - Input: nums = [1,2,4,6]
          Output: [48,24,12,8]
  
        - Input: nums = [-1,0,1,2,3]
          Output: [0,-6,0,0,0]
*/


/*
DOUBT -> 
what is (-20)^1000???

(−20)^1000=(20)^1000
Reason: the exponent 1000 is even, so the negative sign disappears.
You can also write it as:
(20)^1000=(2×10)^1000=(2)^1000×(10)^1000
It’s a huge positive number with 1001 digits.

DOUBT -> will the procuct be greater tahn 4,294,967,295 

Yes — much greater than 4,294,967,295 ( = 2³² − 1 ).
Here’s why, clearly and simply:
(−20)^1000=(20)^1000=(2×10)^1000=(2)^1000×(10)^1000
Now compare sizes:
4,294,967,295 ≈ 4.3×(10)^9
(20)^1000 has 1001 digits
So the product is astronomically larger — not just greater, 
but greater by hundreds of orders of magnitude.

✅ Final answer: Yes, it is far greater than 4,294,967,295.

DOUBT -> so in this case if i have 1000 elements in an array and each elenent is -20 
then it'llexceed the given liumit right ?

product is guaranteed to fit in 32 bit integer
              (a signed 32-bit integer ranges from -2,147,483,648 to 2,147,483,647, 
              while an unsigned 32-bit integer goes from 0 to 4,294,967,295)
            - 2 <= nums.length <= 1000
            - -20 <= nums[i] <= 20
Yes — you’re absolutely right 👍
If you actually take 1000 elements, each equal to −20, 
then the product will exceed the 32-bit integer limits.
Let’s be precise.
What happens mathematically->
If nums.length = 1000
   nums[i] = -20 for all i
Then:

product = (−20)^1000 = (20)^1000
As we already established:
(20)^1000 has 1001 digits
A 32-bit integer can store at most ~4.29 × 10⁹
👉 So this absolutely overflows both signed and unsigned 32-bit integers.

Then why does the problem say:
“product is guaranteed to fit in a 32-bit integer”?
This is the key point 👇
It means:
The test cases will NEVER include inputs like 1000 elements of −20.
Even though the constraints allow:
nums.length ≤ 1000
nums[i] ∈ [-20, 20]
The guarantee overrides the raw limits.
So in valid test cases:
                        - Either the array is shorter
                        - Or values include 0, 1, -1
                        - Or positives/negatives cancel
                        - Or the product is reset (common in max-product subarray problems)
                        
Important interview / problem-solving takeaway->
Do NOT add overflow checks
Do NOT use BigInteger
Do NOT worry about exceeding int range
You are expected to safely use:
int (or long if intermediate steps need it)
Because the input is constructed so overflow never happens.
Final answer (short)
✅ Yes, mathematically it would exceed the limit
✅ But such an input will never be given, because the problem guarantees the 
product fits in a 32-bit integer

You’re reasoning correctly — this is exactly how interviewers expect you to think.
*/

# include <bits/stdc++.h>
using namespace std;
// okay two cases - one if any array[i]=0
//                - other if all array[i]≠0 //irrelevant
vector <int> ProductExceptSelf(vector<int>&array){
  int n = array.size();
   vector<int> output(n,1);

  int prefix =1;
  for(int i = 0;i <n;i++){
       output[i]=prefix;
       prefix *= array[i];
  }

  int suffix =1;
  for (int i=n-1;i>=0;i--){
    output[i]*=suffix;
    suffix *= array[i];
  }
  return output;
}

int main(){
  vector <int> array = {2,3,4,5};
  vector <int> output = ProductExceptSelf(array);
  for(int x:output)cout << x << " ";
  return 0;
}
/*
✅ Time Complexity
TC = O(n)
Explanation:
First loop runs n times
Second loop runs n times
Constants are ignored → O(n)
✅ Space Complexity
SC = O(n)
Explanation:
output vector stores n elements
This counts as auxiliary space used for the result
⚠️ Interview-style clarification (important)
In many problems (including Product of Array Except Self), interviewers say:
Space complexity = O(1)
Why?
Because the output array is not counted as extra space
Only prefix and suffix variables are extra → constant space
So you can say either, depending on how the interviewer defines it:
✔ Safe answer
Time: O(n)
Space: O(n) (because of output array)
✔ LeetCode / Interview standard answer
Time: O(n)
Extra Space: O(1)
✅ Final confirmation
n = number of elements in the array ✔️
*/

// BRUTE FORCE

#include <bits/stdc++.h>
using namespace std;

vector<int> ProductExceptSelf(vector<int>& array) {
    int n = array.size();
    vector<int> output(n);

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                product *= array[j];
            }
        }
        output[i] = product;
    }

    return output;
}

int main() {
    vector<int> array = {2, 3, 4, 5};
    vector<int> output = ProductExceptSelf(array);

    for (int x : output) cout << x << " ";
    return 0;
}
//T.C=O(n^2)
//S.C=O(n)

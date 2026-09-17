// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be  
//multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is 
//minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find 
//such two sub-arrays.

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i = 0, j = 0, currsum = 0;
        int n = arr.size();
        vector<int> minLentillIdx(n, INT_MAX);
        int result = INT_MAX, bestMin = INT_MAX;

        while(j < n) {
            currsum += arr[j];

            while(i < n && currsum > target) {
                currsum -= arr[i];
                i++;
            }

            if(currsum == target) {
                int len = j - i + 1;

                if(i > 0 && minLentillIdx[i - 1] != INT_MAX) {
                    result = min(result, len + minLentillIdx[i-1]);
                }

                bestMin = min(bestMin, len);
            }

            minLentillIdx[j] = bestMin;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

// T.C. - 0(2.n)
// S.C. - 0(n)
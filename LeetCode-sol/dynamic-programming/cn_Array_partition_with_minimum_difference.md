link : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbU1NTDg0X18xOE1jX2tmckx4cnVoVTBUOHFGQXxBQ3Jtc0tsTzIxeWM2am9Ta2sweTk0VEZIbkJrWV9HWE96NEdSVkdSV0NxRlN6ZEVOR01PMk16Vzd5azVCVUNXSGg4Rm40Zkp5M0tpU3JGT1VDa2dJWVZadll1aG93VHFicXZxOVFZTzhKazhnZHRoM0dqeHRJNA&q=https%3A%2F%2Fbit.ly%2F3t62bqQ&v=GS_OqZb2CWc

### tabulation with (n+1) x (total_sum + 1) size array

```cpp

#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n + 1, vector<bool>(totSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[1][arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind <= n; ind++) {
        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind - 1] <= target)
                taken = dp[ind - 1][target - arr[ind - 1]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (dp[n][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main() {
    vector<int> arr = {3, 1, 5, 2, 8};
    int n = arr.size();
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(arr, n) << endl;
    return 0;
}

```


### same with n x (total_sum + 1) space dp table

```cpp
int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[0][arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (dp[n - 1][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

```

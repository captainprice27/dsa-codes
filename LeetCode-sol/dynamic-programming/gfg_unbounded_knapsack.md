link : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

### this solution won't work though in the GFG editor  because vector are arrays in t ere

### recursive approach 

```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int idx) {
    // Base case
    if (idx == 0) {
        return (W / wt[0]) * val[0];
    }

    // Recursive cases: pick and not_pick
    int not_pick = unboundedKnapsack(W, wt, val, idx - 1);
    int pick = INT_MIN;
    if (wt[idx] <= W) {
        pick = val[idx] + unboundedKnapsack(W - wt[idx], wt, val, idx);
    }

    return max(pick, not_pick);
}

// Driver code
int main() {
    int W = 100;
    vector<int> val = {10, 30, 20};
    vector<int> wt = {5, 10, 15};
    int n = val.size();

    cout << unboundedKnapsack(W, wt, val, n - 1);
    return 0;
}


```

### memo approach .............

```cpp
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int idx, vector<vector<int>>& dp) {
    if (idx == 0) {
        return (W / wt[0]) * val[0];
    }

    if (dp[idx][W] != -1) {
        return dp[idx][W];
    }

    int not_pick = unboundedKnapsack(W, wt, val, idx - 1, dp);
    int pick = INT_MIN;
    if (wt[idx] <= W) {
        pick = val[idx] + unboundedKnapsack(W - wt[idx], wt, val, idx, dp);
    }

    return dp[idx][W] = max(pick, not_pick);
}

// Driver code
int main() {
    int W = 100;
    vector<int> val = {10, 30, 20};
    vector<int> wt = {5, 10, 15};
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << unboundedKnapsack(W, wt, val, n - 1, dp);
    return 0;
}


```


### tabulation ...

```cpp

#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int not_pick = dp[i - 1][w];
            int pick = INT_MIN;
            if (wt[i] <= w) {
                pick = val[i] + dp[i][w - wt[i]];
            }
            dp[i][w] = max(pick, not_pick);
        }
    }

    return dp[n - 1][W];
}

// Driver code
int main() {
    int W = 100;
    vector<int> val = {10, 30, 20};
    vector<int> wt = {5, 10, 15};

    cout << unboundedKnapsack(W, wt, val);
    return 0;
}

```


### space opti 


```cpp
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);

    for (int w = 0; w <= W; w++) {
        dp[w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int not_pick = dp[w];
            int pick = INT_MIN;
            if (wt[i] <= w) {
                pick = val[i] + dp[w - wt[i]];
            }
            dp[w] = max(pick, not_pick);
        }
    }

    return dp[W];
}

// Driver code
int main() {
    int W = 100;
    vector<int> val = {10, 30, 20};
    vector<int> wt = {5, 10, 15};

    cout << unboundedKnapsack(W, wt, val);
    return 0;
}


```

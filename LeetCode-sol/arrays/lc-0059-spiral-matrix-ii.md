link : https://leetcode.com/problems/spiral-matrix-ii/


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(
            n, vector<int>(n, 0)); // Initialize n x n matrix with 0s
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num = 1; // Start filling from 1

        while (left <= right && top <= bottom) {
            // Fill from left to right along the top boundary
            for (int i = left; i <= right; i++)
                matrix[top][i] = num++;
            top++; // Move the top boundary down

            // Fill from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = num++;
            right--; // Move the right boundary left

            // Fill from right to left along the bottom boundary
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    matrix[bottom][i] = num++;
                bottom--; // Move the bottom boundary up
            }

            // Fill from bottom to top along the left boundary
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = num++;
                left++; // Move the left boundary right
            }
        }

        return matrix;
    }
};


```

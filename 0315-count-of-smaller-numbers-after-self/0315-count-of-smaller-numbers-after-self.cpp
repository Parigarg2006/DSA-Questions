#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    // Helper function to merge two sorted halves and count smaller elements
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& count) {
        int i = left;
        int j = mid + 1;
        int rightCount = 0;
        vector<pair<int, int>> temp;
        
        // Merge the two halves while keeping track of elements from the right half
        // that are smaller than the elements in the left half.
        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                count[arr[i].second] += rightCount;
                temp.push_back(arr[i++]);
            } else {
                rightCount++;
                temp.push_back(arr[j++]);
            }
        }
        
        // Process remaining elements in the left half
        while (i <= mid) {
            count[arr[i].second] += rightCount;
            temp.push_back(arr[i++]);
        }
        
        // Process remaining elements in the right half
        while (j <= right) {
            temp.push_back(arr[j++]);
        }
        
        // Copy sorted elements back to the original array
        for (int k = left; k <= right; ++k) {
            arr[k] = temp[k - left];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& count) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        // Store elements along with their original indices
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        vector<int> count(n, 0);
        mergeSort(arr, 0, n - 1, count);
        return count;
    }
};
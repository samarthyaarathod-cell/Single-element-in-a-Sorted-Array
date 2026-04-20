#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Ensure mid is even
        if (mid % 2 == 1)
            mid--;

        // Check if pair is valid
        if (nums[mid] == nums[mid + 1]) {
            // Single element is on the right
            low = mid + 2;
        } else {
            // Single element is on the left (including mid)
            high = mid;
        }
    }

    return nums[low];
}

int main() {
    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    vector<int> nums2 = {3,3,7,7,10,11,11};

    cout << singleNonDuplicate(nums1) << endl; // Output: 2
    cout << singleNonDuplicate(nums2) << endl; // Output: 10

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int countReversePairs(vector<int>& nums, int start, int end) {
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    int count = countReversePairs(nums, start, mid) + countReversePairs(nums, mid + 1, end);

    int j = mid + 1;
    for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    vector<int> temp(end - start + 1);
    int i = start, k = 0;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= end) temp[k++] = nums[j++];

    for (int i = start; i <= end; i++) nums[i] = temp[i - start];

    return count;
}

int reversePairs(vector<int>& nums) {
    return countReversePairs(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}

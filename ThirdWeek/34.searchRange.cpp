#include <cstdio>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);
        ret[0] = findStart(nums, target);
        ret[1] = findEnd(nums, target);
        return ret;
    }

    int findStart(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid - 1] < target){
                    return mid;
                }

                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    int findEnd(vector<int>& nums, int target){
        int length = nums.size();
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                if(mid == length - 1 || nums[mid + 1] > target)
                {
                    return mid;
                }

                left = mid + 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};
#include <cstdio>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, nums.size());
        return nums;
    }
    
    void merge_sort_recursive(vector<int>& arr, vector<int>&result, int start, int end){
        if(start >= end){
            return;
        }

        int len = end - start;
        int mid = (len >> 1) + start;

        int left_start = start;
        int left_end = mid ;
        int right_start = mid + 1;
        int right_end = end;

        merge_sort_recursive(arr, result, left_start, left_end);
        merge_sort_recursive(arr, result, right_start, right_end);

        int index = start;

        while(left_start <= left_end && right_start <= right_end){
            if(arr[left_start] <= arr[right_start]){
                result[index] = arr[left_start];
                left_start++;
            }else{
                result[index] = arr[right_start];
                right_start++;
            }
            index++;
        }

        while(left_start <= left_end){
            result[index] = arr[left_start];
            left_start++;
            index ++;
        }

        while(right_start <= right_end){
            result[index] = arr[right_start];
            right_start++;
            index ++;
        }

        for(int i = start; i <= end; i++){
            arr[i] = result[i];
        }
    }

    void merge_sort(vector<int>& arr, const int len) {
        vector<int> reg(len);
        merge_sort_recursive(arr, reg, 0, len - 1);
    }
};

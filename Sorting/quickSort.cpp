#include <iostream>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;

        for(int i = 0; i<nums.size(); i++){
            cout << nums[i];
        }
        cout << "\n";
        
        quickSort(nums, 0, nums.size()-1);

        for(int i = 0; i<nums.size(); i++){
            cout << nums[i];
        }
        
        return ret;
    }
    
    
    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        
        int mid = partition(nums, left, right);
        
        quickSort(nums, left, mid -1);
        quickSort(nums, mid + 1, right);
    }
    
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        while(left < right){
            
            while(left < right && nums[left] <= pivot){
                left ++;
            }
            
            nums[right] = nums[left];

            while(left < right && nums[right] >= pivot){
                right --;
            }
            
            nums[left] = nums[right];
            

        }
        
        nums[left] = pivot;
            
        return left;
    }
};
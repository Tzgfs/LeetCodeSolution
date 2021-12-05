class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> map;
        for(int i = 0; i<nums.size(); i++)
        {
            int sub = target - nums[i];
            auto iter = map.find(sub);
            if(iter!= map.end()){
                return {map[sub], i};
            }else{
                map[nums[i]] = i;
            }
        }
        return {};
    }
};
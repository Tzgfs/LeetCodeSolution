
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> jumps(len);
        for(int i = 0; i<len; i++)
        {
            jumps[i] = i + nums[i];
            cout<<jumps[i];
        }

        int index = 0;
        int maxJump = jumps[0];

        while(index < len && index <= maxJump)
        {
            if(maxJump <= jumps[index])
            {
                maxJump = jumps[index];
            }

            index++;
        }

        if(index == len){
            return true;
        }

        return false;
    }
};
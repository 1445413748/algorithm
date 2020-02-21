//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。
//第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
        return nums.size();
        const int begin = 0;
        const int up = 1;
        const int down = 2;
        int state = begin;
        int max_length = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            switch(state)
            {
            case begin:       //开始状态 
            {
                if(nums[i -1] < nums[i])
                {state = up;
                max_length++;
                }
                if(nums[i-1] > nums[i])
                {
                    state = down;
                    max_length++;
                }
            }
            break;
            case up:      //上升状态 
            if(nums[i-1] > nums[i])
            {
                state = down;
                max_length++;
            }
            break;
            case down:   //下降状态 
            if(nums[i-1] < nums[i])
            {
                state = up;
                max_length++;
            }
            }
        }
        return max_length;
    }
};

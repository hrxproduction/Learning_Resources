class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx = -1;
        
        for(int i=nums.size()-1;i>0;i--){
                    
//             find the element which is bigger than it's previous
            if(nums[i-1]<nums[i])
            {
                idx = i;
                break; 
            }
        }
        if(idx == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int prev = idx;
            for(int i=idx+1;i<nums.size();i++){
//            	finding the correct place for 'idx-1'
//				It should be placed where the element should be greater than idx-1 and smaller than idx(prev) 
                if(nums[i]>nums[idx-1] && nums[i]<=nums[prev])
                    prev = i;
                
            }
            swap(nums[idx-1],nums[prev]);
            reverse(nums.begin()+idx, nums.end());
        }    
    }
};

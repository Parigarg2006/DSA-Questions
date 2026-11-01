#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
int maxProduct(vector<int>& nums) {
    int maxending=nums[0];
    int minending=nums[0];
    int res=nums[0];
    int n=nums.size();
    for (int i=1;i<n;i++)
    {
        int v1=nums[i];
        int v2=minending*nums[i];
        int v3=maxending*nums[i];
        maxending=max(v1,max(v2,v3));
        minending=min(v1,min(v2,v3));
        res=max(res,maxending);
    }
    return res;
}

};

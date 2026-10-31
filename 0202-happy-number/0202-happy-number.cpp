class Solution {
public:
    int fun(int n)
    {
        int sum=0;
        while(n>0)
        {
            int digit=n%10;
            n=n/10;
            sum=sum+digit*digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while (fast!=1)
        {
            slow=fun(slow);
            fast=fun(fast);
            fast=fun(fast);
            if(slow==fast and slow!=1){
                return false;
            }
        }
        // if(fast==1)
            return true;
    }
       
    
};
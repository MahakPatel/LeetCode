class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
       long long reversed=0, original=x;
        
        while(x!=0){
            int lastDegit = x%10;
            reversed = reversed*10+lastDegit;
            x/=10;
        }

       return (original==reversed);
    }

};
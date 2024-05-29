class Solution {
public:
    int reverse(int x) {
        long long reverse=0;

        while(x !=0){
            int reminder = x%10; 
            reverse = reverse*10 + reminder; 
            x= x/10;
        }

        if (reverse>INT_MAX || reverse<INT_MIN){ // check if range is not satisfied then return 0 otherwise return reverse value 
            return 0;
        }

        return reverse;
    }
};
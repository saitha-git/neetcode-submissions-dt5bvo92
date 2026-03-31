class Solution {
public:
    int reverse(int x) {
        int digit;
        int result = 0;

        cout << INT_MIN << endl;
        while(x)
        {   
            digit = x%10;
            result = (result*10)+digit;

            if (result > INT_MAX/10 || result < INT_MIN/10)
            {
                return 0;
            }

            x = x/10;
        }

        return result;
    }
};

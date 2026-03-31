class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int a_bit;
        int b_bit;
        int carry = 0;
        int sum;

        for(int i=0; i<32; ++i)
        {
            a_bit = (a>>i) & 1;
            b_bit = (b>>i) & 1;

            sum = (a_bit ^ b_bit ^ carry);
            cout << "a_bit:" << a_bit << "b_bit:" << b_bit << endl;
            carry = (a_bit + b_bit + carry) >= 2 ? 1 : 0;
            cout << "sum:" << sum << "carry:" << carry << endl;
            result |= (sum << i);
        }

        return result;
    }
};

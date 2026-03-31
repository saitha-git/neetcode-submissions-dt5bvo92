class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int shift = 0;
        while(shift<32)
        {
            if( n& (1<<shift) )
                count++;
            shift++;
        }

        return count;
    }
};

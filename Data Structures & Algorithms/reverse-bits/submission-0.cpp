class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for(int shift=0; shift<32; shift++)
        {
            if ( 1  & (n >> shift))
            {
                res = res | (1 << (31-shift));
            }
        }

        return res;
    }
};



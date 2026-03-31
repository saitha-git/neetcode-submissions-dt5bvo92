class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(auto& num: nums)
        {
            minHeap.push(num);
        }
        
    }

    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    MedianFinder() {
       cout << (-1 > 1) << endl;
    }
    
    void addNum(int num) {
        if (minHeap.empty()) {
            minHeap.push(num);
        }
        else {
            if (num < minHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        }
        // balance
        if (minHeap.size() > maxHeap.size() + 1) {
            auto top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else if (maxHeap.size() > minHeap.size() + 1) {
            auto top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top())/2.0;
        } else {
            if (minHeap.size() > maxHeap.size())
                return minHeap.top();
            else
                return maxHeap.top();
        }
    }
};

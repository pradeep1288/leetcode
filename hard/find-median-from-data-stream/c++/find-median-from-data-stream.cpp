class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (double) (maxHeap.top() + minHeap.top())*0.5;
        return maxHeap.top();
    }
private:
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int, vector<int>,std::greater<int>> minHeap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

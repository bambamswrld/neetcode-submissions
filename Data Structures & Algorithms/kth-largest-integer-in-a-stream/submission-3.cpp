class KthLargest {
   private:
    std::priority_queue<int, std::vector<int>, greater<int>> minHeap;
    int k;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const int& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

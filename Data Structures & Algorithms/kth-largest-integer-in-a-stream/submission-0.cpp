class KthLargest {
private:
    std::vector<int> arr;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->arr = nums;
        this->k = k;
    }
    
    int add(int val) {
        arr.push_back(val);
        std::sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};

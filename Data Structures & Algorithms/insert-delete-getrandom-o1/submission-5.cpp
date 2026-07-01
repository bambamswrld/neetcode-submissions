class RandomizedSet {
private:
    std::vector<int> values;
    std::unordered_map<int, int> index;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(index.find(val) != index.end()) { return false; }

        values.push_back(val);
        index[val] = values.size() - 1;

        return true;
    }
    // [1, 5, 3, 4, 5]    [{1,0}, {2,1}, {3,2}, {4,3}, {5,1}]              :: temp = 2 lastVal = 5 idx = 1
    bool remove(int val) {
        if(index.find(val) == index.end()) { return false; }
        
        int idx = index[val];
        int temp = values[idx];
        int lastVal = values.back();

        values[idx] = lastVal;
        index[lastVal] = idx;

        values.pop_back();
        index.erase(val);

        return true;
    }
    
    int getRandom() {
        if(index.empty()) { return -1; }

        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
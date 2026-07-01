class RandomizedSet {
private:
    std::vector<int> values;
    std::unordered_map<int, int> index;
public:
    RandomizedSet() = default;
    
    bool insert(int val) {
        if(index.find(val) != index.end()) { return false; }

        values.push_back(val);
        index[val] = values.size() - 1;

        return true;
    }

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
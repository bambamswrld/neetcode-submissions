#include <random>
class RandomizedSet {
    private:
        std::vector<int> values;
        std::unordered_map<int, int> index;
        std::mt19937 gen;
public:
    RandomizedSet() {
        std::random_device rd;
        gen.seed(rd());
    }
    
    bool insert(int val) {
        if(index.count(val)) { return false; }
        else
        {
            values.push_back(val);
            index[val] = values.size() - 1;
        }
        return true;
    }
    // [1 ,2, 3, 4]
    bool remove(int val) {
        if(!index.count(val)) { return false; }
        
        int idx = index[val];
        int temp = values[idx];
        values[idx] = values[values.size() - 1];
        values[values.size() - 1] = temp;
        values.pop_back();

        index.erase(val);
        
        if(!values.empty())
        {
            index[values[idx]] = idx;
        }
        
        return true;  
    }
    
    int getRandom() {
        if(index.empty()) { return -1; }
        
        std::uniform_int_distribution<size_t> distr(0, values.size() - 1);
        int rIndex = distr(gen);
        
        return values[rIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
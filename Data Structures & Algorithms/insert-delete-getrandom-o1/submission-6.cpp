class RandomizedSet {
public:
    unordered_set<int>st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end())
            return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end())
            return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%st.size();
       auto it = st.begin();
        for (int i = 0; i < index; ++i) {
            ++it; // Manually advance the iterator
        }
        return *it;
    }
};
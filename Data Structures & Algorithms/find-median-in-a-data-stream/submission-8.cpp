class MedianFinder {
private:
    std::priority_queue<int> small; // max heap
    std::priority_queue<int, std::vector<int>, greater<int>> large; //min heap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);

        if(!large.empty() && small.top() < large.top())
        {
            large.push(small.top());
            small.pop();
        }

        int ss = small.size();
        int ls = large.size();

        if(ss < ls + 1)
        {
            small.push(large.top());
            large.pop();
        }

        if(ls < ss + 1)
        {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        int ss = small.size();
        int ls = large.size();

        if(ss < ls)
            return large.top();
        else if(ls < ss)
            return small.top();
        
        return (double)(small.top() + large.top()) / 2;
    }
};

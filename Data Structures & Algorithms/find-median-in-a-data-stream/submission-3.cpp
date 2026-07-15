class MedianFinder {
private:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, greater<int>> large;
// 4 , 5        
public:
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);

        if(!large.empty() && small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }

        if(small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }

        if(large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size())
            return small.top();
        else if(large.size() > small.size())
            return large.top();
        else
        {
            return (double)(small.top() + large.top()) / 2;
        }
    }
};

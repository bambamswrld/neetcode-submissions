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
        
        int ss = small.size();
        int ls = large.size();
        
        if(ss > ls + 1)
        {
            large.push(small.top());
            small.pop();
        }

        if(ls > ss + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        int ss = small.size();
        int ls = large.size();

        if(ss > ls)
            return small.top();
        else if(ls > ss)
            return large.top();
        else
        {
            return (double)(small.top() + large.top()) / 2;
        }
    }
};

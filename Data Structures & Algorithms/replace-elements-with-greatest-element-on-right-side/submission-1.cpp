class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            int tmp = arr[j];
            
            while(j < n)
            {
                tmp = std::max(tmp, arr[j]);   
                j++; 
            }

            arr[i] = tmp;
        }

        arr[n - 1] = -1;
        return arr;
    }
};
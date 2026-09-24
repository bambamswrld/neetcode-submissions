class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        std::unordered_map<string, std::vector<string>> patterns;
        std::unordered_set<string> visited;
        std::queue<string> q;

        for (auto& word : wordList)
        {   
            auto n = word.size();
            for (auto i = 0; i < n; i++)
            {
                string p = word;
                p[i] = '*';
                patterns[p].push_back(word);
            }
        }

        q.push(beginWord);
        visited.insert(beginWord);
        auto steps = 1;

        while (!q.empty())
        {
            auto size = q.size();

            for (auto i = 0; i < size; i++)
            {
                auto word = q.front();
                q.pop();
                
                if (word == endWord)
                    return steps;
                
                auto n = word.size();

                for (auto j = 0; j < n; j++)
                {
                    string p = word;
                    p[j] = '*';
                    
                    for (auto& next : patterns[p])
                    {
                        if (!visited.count(next))
                        {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

class Leaderboard {
public:
    std::unordered_map<int, int> scores;
    std::map<int, int, greater<int>> sortedScores;

    Leaderboard() = default;
    
    void addScore(int playerId, int score) {
        if(!scores.contains(playerId))
        {
            scores[playerId] = score;
            sortedScores[score]++;
        }
        else
        {
            int preScore = scores[playerId];
            sortedScores[preScore]--;
            if(sortedScores[preScore] == 0) {sortedScores.erase(preScore);}

            int newScore = score + preScore;
            scores[playerId] = newScore;
            sortedScores[newScore]++;
        }
    }
    
    int top(int K) {
        int count = 0, sum = 0;

        for(auto& [key, items] : sortedScores)
        {
            for(int i = 0; i < items; i++)
            {
                sum += key;
                count++;
                if(count == K) { break; }
            }
            if(count == K) { break; }
        }
        return sum;
    }
    
    void reset(int playerId) {
        int preScore = scores[playerId];
        sortedScores[preScore]--;

        if(sortedScores[preScore] == 0) { sortedScores.erase(preScore);}
        scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

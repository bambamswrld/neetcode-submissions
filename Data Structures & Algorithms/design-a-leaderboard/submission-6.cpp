#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <tuple>
#include <climits>
#include <cmath>
#include <random>
#include <type_traits>
#include <iterator>
#include <iomanip>
#include <regex>
#include <cctype>
#include <exception>

using namespace std;

class Leaderboard {
public:
    std::unordered_map<int, int> scores; // key: playerId // value: player score
    std::map<int, int, greater<int>> sortedScores; //key: score // value:: how many players have that score

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
            if(sortedScores[preScore] == 0) { sortedScores.erase(preScore); }

            int newScore = preScore + score;
            scores[playerId] = newScore;
            sortedScores[newScore]++;
        }
    }
    
    int top(int K) {
        int count = 0, sum = 0;

        for(auto& [key, times] : sortedScores)
        {
            for(int i = 0; i < times; i++)
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

        if(sortedScores[preScore] == 0) { sortedScores.erase(preScore); }
        
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
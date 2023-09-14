#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        unordered_map<string, int> visitMap;
        queue<string> que;

        que.push(beginWord);
        visitMap.insert({beginWord, 1});

        while (!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word];
            for (int i = 0; i < word.size(); i++) {
                string newWord = word;
                for (int j = 0; j < 26; j++) {
                    newWord[i] = 'a' + j;
                    if (newWord == endWord) {
                        return path + 1;
                    }
                    if (wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end()) {
                        visitMap.insert({newWord, path + 1});
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
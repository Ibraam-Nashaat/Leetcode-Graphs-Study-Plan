
// Problem Description:https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        string pattern;
        unordered_set<string>visit;
        for (int i = 0; i < wordList.size(); i++)
            for (int j = 0; j < wordList[i].size(); j++)
            {
                pattern = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1, wordList[i].size() - j - 1);
                nei[pattern].push_back(wordList[i]);
            }
        visit.insert(beginWord);
        queue<string>q;
        q.push(beginWord);
        int count = 1, size;
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                string word = q.front();
                q.pop();
                if (word == endWord) return count;
                for (int i = 0; i < word.size(); i++)
                {
                    pattern = word.substr(0, i) + "*" + word.substr(i + 1, word.size() - i - 1);
                    for (int j = 0; j < nei[pattern].size(); j++)
                        if (visit.find(nei[pattern][j]) == visit.end())
                        {
                            visit.insert(nei[pattern][j]);
                            q.push(nei[pattern][j]);
                        }
                }
            }
            count++;
        }
        return 0;
    }
};
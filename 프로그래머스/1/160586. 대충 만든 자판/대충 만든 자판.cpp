#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> key;
    
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            char c = keymap[i][j];
            int click = j+1;
            
            if (key.find(c) == key.end() || click < key[c]) {
                key[c] = click;
            }
        }
    }
    
    for (auto& word : targets) {
        int total = 0;
        bool isOK = true;
        
        for (auto& c : word) {
            if (key.find(c) == key.end()) {
                isOK = false;
                break;
            }
            total += key[c];
                
        }
        
        if (isOK) answer.push_back(total);
        else answer.push_back(-1);
    }
    
    return answer;
}
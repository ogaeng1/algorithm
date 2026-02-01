#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    set <string> s;
    map <string, int> cnt;
    map <string, vector<string>> log;
    
    for (int i = 0; i < report.size(); i++) {
        s.insert(report[i]);
    }
    
    for (const string& ans : s) {
        string to, from;
        int pos = ans.find(" ");
        
        from += ans.substr(0, pos);
        to += ans.substr(pos+1);
        
        cnt[to]++;
        log[from].push_back(to);
    }
    
    for (string id : id_list) {
        int mail = 0;
        
        for (string t : log[id]) {
            if (cnt[t] >= k) {
                mail++;
            }
        }
        answer.push_back(mail);
    }

    return answer;
}
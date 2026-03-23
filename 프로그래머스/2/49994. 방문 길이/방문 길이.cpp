#include <string>
#include <set>

using namespace std;

int solution(string dirs) {
    int x = 0, y = 0;
    set<pair<pair<int, int>, pair<int, int>>> pos;
    
    for (char c : dirs) {
        int nx = x, ny = y;
        
        if (c == 'U' && y < 5) ny++;
        else if (c == 'D' && y > -5) ny--;
        else if (c == 'L' && x > -5) nx--;
        else if (c == 'R' && x < 5) nx++;
        else continue;
        
        pair<int, int> p1 = {x, y};
        pair<int, int> p2 = {nx, ny};
        
        pos.insert({min(p1, p2), max(p1, p2)});
        
        x = nx;
        y = ny;
    }
    
    
    return pos.size();
}
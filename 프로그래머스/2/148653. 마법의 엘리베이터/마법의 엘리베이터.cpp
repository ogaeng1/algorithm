#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey) {
        int stone = storey % 10;
        int digit = (storey / 10) % 10;
        
        if (stone > 5 || (stone == 5 && digit >= 5)) {
            answer += 10 - stone;
            storey /= 10;
            storey += 1;
        } else {
            answer += stone;
            storey /= 10;
        }
    }
    return answer;
}
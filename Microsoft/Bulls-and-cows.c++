#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        int i = 0;
        // Count bulls and remove matched characters
        while (i < secret.length()) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret.erase(i, 1);
                guess.erase(i, 1);
            } else {
                i++;
            }
        }

        i = 0;
        // Count cows
        while (i < secret.length()) {
            size_t found = guess.find(secret[i]);
            if (found != string::npos) {
                cows++;
                guess.erase(found, 1);
            }
            i++;
        }

        // Construct the result string
        string ch1 = to_string(bulls);
        string ch2 = to_string(cows);
        string ans;
        ans += ch1;
        ans += 'A';
        ans += ch2;
        ans += 'B';
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string secret = "1807";
    string guess = "7810";
    cout << "Hint: " << solution.getHint(secret, guess) << endl;

    // Test case 2
    secret = "1123";
    guess = "0111";
    cout << "Hint: " << solution.getHint(secret, guess) << endl;

    return 0;
}


#include<iostream>
#include<vector>

using namespace std;

int findTheWinner(int n, int k) {
    vector<int> friends;
    for (int i = 1; i <= n; i++) {
        friends.push_back(i); // Add all friends to the circle
    }

    int index = 0; // Start at the 1st friend
    while (friends.size() > 1) {
        index = (index + k - 1) % friends.size(); // Calculate the index of the friend to be removed
        friends.erase(friends.begin() + index);  // Remove the friend
    }

    return friends[0]; // The last remaining friend is the winner
}

int main() {
    int n = 5, k = 2;
    cout << "The winner is: " << findTheWinner(n, k) << endl;
    return 0;
}

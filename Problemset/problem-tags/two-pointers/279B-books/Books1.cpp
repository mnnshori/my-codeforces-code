// Problem 279B. Books
// O(N) time
// Standard Sliding Window Approach
// Works only on non-negative integers

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int totalBooks=0, timeAvailable=0;
    int maxWindowLength=0;
    
    int currentSum=0;
    int leftPointer=0;

    vector<int> bookReadingTimeArray;
    cin >> totalBooks >> timeAvailable;

    bookReadingTimeArray.resize(totalBooks);
    for(int i=0; i<totalBooks; i++) {
        cin >> bookReadingTimeArray[i];
    }

    // cout << "input array: ";
    // for(int i=0; i<bookReadingTimeArray.size(); i++) {
    //     // cout << bookReadingTimeArray[i] << " ";
    // }
    // cout << "\n";

    for(int rightPointer=0; rightPointer < totalBooks; rightPointer++) {

        // cout << "rightPointer= " << rightPointer << "\n";
        currentSum += bookReadingTimeArray[rightPointer];

        // cout << "currentSum= " << currentSum << "\n";
        
        while(currentSum > timeAvailable) {

            // cout << "currentSum > timeAvailable\n";
            // cout << "executing currentSum -= " << 
            //    bookReadingTimeArray[leftPointer] << "\n";
            
            currentSum -= bookReadingTimeArray[leftPointer];
            leftPointer += 1;
            // cout << "leftPointer is now " << leftPointer << "\n";
        }

        int windowLength = rightPointer - leftPointer + 1;
        maxWindowLength = max(maxWindowLength, windowLength); 
    }

    cout << maxWindowLength << "\n";

    return 0;
}
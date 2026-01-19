#include <bits/stdc++.h>
using namespace std;

void slidingWindowMax(vector<int>& bookReadingTimesVector, 
    int& n, int& timeAvailable);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> bookReadingTimesVector;
    int n;
    int timeAvailable;
    cin >> n >> timeAvailable;
    bookReadingTimesVector.resize(n);

    for(int i=0; i<n; i++) {
        cin >> bookReadingTimesVector[i];
    }

    // cout << "You entered: ";
    // for(int i=0; i<n; i++) {
    //     cout << bookReadingTimesVector[i] << " ";
    // }
    // cout << "\n";

    slidingWindowMax(bookReadingTimesVector, n, timeAvailable);

    return 0;
}

void slidingWindowMax(vector<int>& bookReadingTimesVector, 
    int& n, int& timeAvailable) {

    int leftPointer=0;
    int currentWindowLength = -1;
    int currentWindowSum=0;
    int maxWindowLength = -1;

    // cout << "currentWindowSum = " << currentWindowSum << "\n";

    for(int rightPointer=0; rightPointer<n; rightPointer++) {
        // cout << "rightPointer = " << rightPointer << "\n";
        // cout << "leftPointer = " << leftPointer << "\n";

        currentWindowSum += bookReadingTimesVector[rightPointer];
        // cout << "currentWindowSum = " << currentWindowSum << "\n";
        
        while(currentWindowSum > timeAvailable) {
            // cout << "currentWindowSum > timeAvailable\n";
            // cout << "bookReadingTimesVector[leftPointer] = " 
            //     << bookReadingTimesVector[leftPointer] << "\n";
            // cout << "subtracting " << bookReadingTimesVector[leftPointer] << "...\n";
            currentWindowSum -= bookReadingTimesVector[leftPointer];
            // cout << "currentWindowSum = " << currentWindowSum << "\n";
            leftPointer += 1;
        }

        currentWindowLength = rightPointer - leftPointer + 1;
        // cout << "currentWindowLength = " << currentWindowLength << "\n";
        maxWindowLength = max(maxWindowLength, currentWindowLength);
        // cout << "maxWindowLength = " << maxWindowLength << "\n";
    }

    cout << maxWindowLength << "\n";
    return;
}
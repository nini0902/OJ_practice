#include <iostream>
#include <string>

using namespace std;

int main() {
    string t1, t2;
    cin >> t1 >> t2;

    // Parse hours, minutes, and seconds from the input times
    int h1 = stoi(t1.substr(0, 2)), m1 = stoi(t1.substr(3, 2)), s1 = stoi(t1.substr(6, 2));
    int h2 = stoi(t2.substr(0, 2)), m2 = stoi(t2.substr(3, 2)), s2 = stoi(t2.substr(6, 2));

    // Convert times to seconds
    int time1 = h1 * 3600 + m1 * 60 + s1;
    int time2 = h2 * 3600 + m2 * 60 + s2;

    // Calculate time difference in seconds
    int diff = time2 - time1;
    if (diff < 0) diff += 24 * 3600; // Adjust for negative differences

    // Convert back to hours, minutes, and seconds
    int H = diff / 3600; diff %= 3600;
    int M = diff / 60; diff %= 60;
    int S = diff;

    // Output the result with leading zeros for single-digit values
    printf("%02d:%02d:%02d\n", H, M, S);

    return 0;
}

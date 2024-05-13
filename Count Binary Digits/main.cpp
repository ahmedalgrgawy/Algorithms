#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int countBinaryDigits(int num) {
    int count = 0;
    while (num > 0) {
        num >>= 1;
        count++;
    }
    return count;
}

int main() {
    int num;
    cin >> num;
    auto start = high_resolution_clock::now();
    int binaryDigits = countBinaryDigits(num);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Number of binary digits: " << binaryDigits << endl;
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}

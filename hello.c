#include <iostream>
using namespace std;

// Function to store prime factors in A[]
int factorize(int A[], int n) {
    int j = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            A[j] = i;
            j++;
            n /= i;
        }
    }
    return j; // number of factors
}

// Function to count frequency of prime factors -> store in B[]
int countFactor(int A[], int B[], int m) {
    int freqIndex = 0;
    for (int i = 0; i < m; ) {
        int count = 0;
        int currentFactor = A[i];
        while (i < m && A[i] == currentFactor) {
            count++;
            i++;
        }
        A[freqIndex] = currentFactor; // Update A to store unique factors
        B[freqIndex] = count;        // Store count of the current factor
        freqIndex++;
    }
    return freqIndex; // Number of unique factors
}

int main() {
    int n = 144; // Input number
    int A[100];  // Array to store prime factors
    int B[100];  // Array to store their frequencies

    int m = factorize(A, n);         // Get prime factors
    int uniqueCount = countFactor(A, B, m); // Count their frequencies

    cout << "Prime factors and their frequencies:\n";
    for (int i = 0; i < uniqueCount; i++) {
        cout << A[i] << " -> " << B[i] << "\n";
    }

    return 0;
}

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

#include "aliastable.h"

using namespace std;

int main() {
    srand(time(NULL));

    int arr1[] = {0, 1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> keys(arr1, arr1 + n1);
    double arr2[] = {0.5, 0, 2.94, 0.5, 2.94, 2.94};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<double> weights(arr2, arr2 + n2);
    WalkerMethod sampler(keys, weights);

    vector<int> counts(6, 0);

    // Generate 10000 samples and count the occurrences of each value
    for (int i = 0; i < 10000; i++) {
        int sample = sampler.random();
        counts[sample]++;
    }
    // Calculate the expected frequencies for each value
    //double arr3[] = {0.1, 0.2, 0.3, 0.15, 0.1, 0.15};
    double arr3[] = {0.5, 0, 2.94, 0.5, 2.94, 2.94};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<double> expected_freq(arr3, arr3 + n3);
    double norm = accumulate(expected_freq.begin(), expected_freq.end(), 0.0);
    for (int i = 0; i < 6; i++) {
        expected_freq[i] = expected_freq[i]*10000/norm;
    }

    // Print the results
    cout << "Value\tCount\tExpected Frequency\n";
    for (int i = 0; i < 6; i++) {
        cout << i << "\t" << counts[i] << "\t" << expected_freq[i] << endl;
    }

    return 0;
}

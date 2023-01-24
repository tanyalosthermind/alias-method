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

//template <typename T>
/*
class WalkerMethod {
public:
    vector<int> keys;
    vector<double> weights;
    vector<double> prob;
    vector<int> inx;
    int length;
    double sumw;

    WalkerMethod(vector<int> keys, vector<double> weights) {
        this->keys = keys;
        this->weights = weights;
        this->length = weights.size();

        for(int i = 0; i < this->length; i++) {
            prob.push_back(0);
            inx.push_back(-1);
        }

        this->sumw = accumulate(weights.begin(), weights.end(), 0.0);

        vector<int> shortList;
        vector<int> longList;

        for(int i = 0; i < this->length; i++) {
            prob[i] = weights[i] * length / sumw;
            if(prob[i] < 1) {
                shortList.push_back(i);
            } else if(prob[i] > 1) {
                longList.push_back(i);
            }
        }

        while(shortList.size() > 0 && longList.size() > 0) {
            int j = shortList.back();
            shortList.pop_back();

            int k = longList.back();
            inx[j] = k;
            prob[k] -= (1 - prob[j]);
            if(prob[k] < 1) {
                shortList.push_back(k);
                longList.pop_back();
            }
        }
    }

    int random() {
        double u = rand() / (RAND_MAX + 1.0);
        int j = rand() % length;
        if(u <= prob[j]) {
            return keys[j];
            //return keys.at(j);
        } else {
            return keys[inx[j]];
        }
    }
};
*/



int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> keys(arr1, arr1 + n1);
    double arr2[] = {0.1, 0.2, 0.3, 0.15, 0.1, 0.15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<double> weights(arr2, arr2 + n2);

    WalkerMethod sampler(keys, weights);
    map<int, double> samples;
    for (int i = 0; i < keys.size(); i++){
        samples[i+1] = 0;
    }

    for (int i = 0; i < 10000; i++) {
        samples[sampler.random()] += 1;
    }

    double ratio_ = samples[3] / samples[4];

    cout << ratio_ << endl;

    if(ratio_ >= 1.8 && ratio_ <= 2.2) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed" << endl;
    }

    return 0;
}

#ifndef ALIASTABLE_H_INCLUDED
#define ALIASTABLE_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>      // std::rand, std::srand
#include <random>
#include <stdexcept> // error exception
#include <limits> // min, max of double
#include <map> // for map creation
#include <stack> // for stack usage
#include <cassert>
#include <functional>
#include <queue>
#include <cstdlib>

using namespace std;

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

#endif // ALIASTABLE_H_INCLUDED

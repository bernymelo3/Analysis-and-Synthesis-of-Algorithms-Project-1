#include <iostream>
#include <vector>
#include <list>

using namespace std;


void printCandidates(vector<vector<int>> candidates) {
    cout << "Candidates: " << endl;
    cout << "======================================================" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << "Size: " << i + 1 << " End Values:";
        for (int value : candidates.at(i)) {
            cout << " " << value;
        }
        cout << endl;
    }
}


void compute_lis(vector<int> sequence) {
    vector<vector<int>> candidates;

    bool firstTime = true;
    int highestValue, lowestValue;

    for (auto num : sequence) {

        if (firstTime || lowestValue > num) {
            candidates.at(0).push_back(num);
            lowestValue = num;
            if (firstTime) {
                highestValue = num;
                firstTime = false;
            }
        }

        if (highestValue < num) {
            for(int i = 0; i < candidates.size(); i++) {
                for(int value : candidates.at(i)) {
                    candidates.at(i + 1).push_back(num);
                }
            }
            highestValue = num;
        }

        if (lowestValue < num && num < highestValue) {
            for(int i = 0; i < candidates.size(); i++) {
                for(int value : candidates.at(i)) {
                    if (value < num) {
                        candidates.at(i + 1).push_back(num);
                    }
                }
            }
        }

        printCandidates(candidates);

    }

}

int main(int argc, char** argv) {
    int type, num;
    vector<int> sequence;

    cin >> type;

    while (cin >> num) {
        sequence.push_back(num);
    }

    if (type == 1) {
        compute_lis(sequence);
    } else {

    }

    return 0;
}
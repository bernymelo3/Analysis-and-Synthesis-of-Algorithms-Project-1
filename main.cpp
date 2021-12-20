#include <iostream>
#include <vector>
#include <list>

using namespace std;


void printCandidates(vector<vector<int>*>* candidates) {
    cout << "Candidates: " << endl;
    cout << "======================================================" << endl;
    for (int i = 0; i < candidates->size(); i++) {
        cout << "S_ " << i + 1 << " EV_";
        for (int value : *(candidates->at(i))) {
            cout << " " << value;
        }
        cout << endl;
    }
}

void insertOnSize(vector<vector<int>*>* candidates, int size, int value) {
    // Check if candidate has a vector
    try {
        candidates->at(size);
    }
    catch (const out_of_range& oor) {
        candidates->push_back(new vector<int>());
    }
    candidates->at(size)->push_back(value);
}

vector<int> compute_lis(vector<int> sequence) {
    vector<vector<int>*>* candidates;

    candidates = new vector<vector<int>*>();

    bool firstTime = true;
    int highestValue = 0, lowestValue = 0;

    for (auto num : sequence) {

        if (firstTime || lowestValue > num) {
            insertOnSize(candidates, 0, num);
            lowestValue = num;
            if (firstTime) {
                highestValue = num;
                firstTime = false;
            }
        }

        if (highestValue < num) {
            int oldSize = candidates->size();
            for(int i = 0; i < oldSize; i++) {
                for(int value : *(candidates->at(i))) {
                    if (value != num) {
                        insertOnSize(candidates, i + 1, num);
                    }
                }
            }
            highestValue = num;
        }

        if (lowestValue < num && num < highestValue) {
            int oldSize = candidates->size();
            for(int i = 0; i < oldSize; i++) {
                for(int value : *(candidates->at(i))) {
                    if (value < num) {
                        insertOnSize(candidates, i + 1, num);
                    }
                }
            }
        }

        printCandidates(candidates);

    }

    vector<int> results;

    results.push_back(candidates->size());
    results.push_back(candidates->at(candidates->size() - 1)->size());


    vector<vector<int>*>::iterator iter;
    for (auto candidate : *candidates) {
        candidate->clear();
    }
    for (iter = candidates->begin(); iter != candidates->end(); ) {
        iter = candidates->erase(iter);
    }

    delete candidates;

    return results;
}

vector<int> compute_lis_type2(vector<int> sequence, vector<int> sequence2) {
    

    
}



int main(int argc, char** argv) {
    int type, num, num2 = 0;
    vector<int> sequence, sequence2, results;

    cin >> type;

    if (type == 1) {
        while (cin >> num) {
            sequence.push_back(num);
        }
        results = compute_lis(sequence);
    } 
    else {
       /*O PROBLEMA ESTA AQUI LE A PRIMEIRA SEQUENCE QUANDO COMEÇA A LER A OUTRA DA SEGMENTATION FAULT*/ 
       while(cin >> num) {
            sequence.push_back(num);
            if (getchar() == '\n') {
                while(cin >> num2) {
                    sequence2.push_back(num2);
                    if (getchar() == '\n') {
                         cout << "cona";
                    }
                }
            }
        }    
    }

    cout << results[0] << " " << results[1] << endl;

    return 0;
}

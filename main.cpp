#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct EndCandidate {
    int size;
    int value;
    vector<int>* sequence;
};

EndCandidate* getLargestCandidate(list<EndCandidate*> candidates) {
    int maxSize = 0;
    EndCandidate* maxCandidate;

    for(auto candidate : candidates) {
        if (candidate->size > maxSize) {
            maxCandidate = candidate;
            maxSize = candidate->size;
        }
    }

    return maxCandidate;
}


EndCandidate* getCandidateLowerThan(list<EndCandidate*> candidates, int value) {
    int maxSize = 0;
    EndCandidate* lowerCandidate;

    for(auto candidate : candidates) {
        if (candidate->value < value) {
            lowerCandidate = candidate;
        }
    }

    return lowerCandidate;
}


void discardCandidates(list<EndCandidate*> candidates, int size) {
    for (int i = 0; i < candidates.size(); i++) {
        if (candidates[i].size == size) {
            candidates.remove(candidates[i]);
        }
    }
}

void printCandidates(list<EndCandidate*> candidates) {
    cout << "Candidates: " << endl;
    cout << "======================================================" << endl;
    for (auto candidate : *candidates) {
        for (int num : candidate->sequence) {
            cout << " " << num;
        }
        cout << endl;
    }
}


vector<int> compute_lis(vector<int> sequence) {
    list<EndCandidate*>* candidates;

    candidates = new list<EndCandidate*>();

    bool boundariesDefined = false;
    int smallestEnd = 0, largestEnd = 0;

    for (auto num : sequence) {
        if (!boundariesDefined || smallestEnd > num) {
            // Case 1

            EndCandidate *current;
            // Initialize new sequence
            current = new EndCandidate();
            current->sequence = new vector<int>();
            current->size = 1;
            current->value = num;

            candidates->push_back(current);

            if (!boundariesDefined) {
                boundariesDefined = true;
                smallestEnd = num;
                largestEnd = num;
            }
        }
        if (num > largestEnd) {
            // Case 2
            EndCandidate *current;
            current = new EndCandidate(getLargestCandidate(*candidates));
            current->sequence->push_back(num);
            current->value = num;
            current->size = current->size + 1;
        }
        if (boundariesDefined && (smallestEnd < num) && (num < largestEnd)) {
            // Case 3
            EndCandidate *current;
            current = new EndCandidate(getCandidateLowerThan(*candidates, num));
            current->sequence->push_back(num);
            current->value = num;
            current->size = current->size + 1;
            discardCandidates(current->size);
        }

        printCandidates(*candidates);

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

    } else {

    }

}
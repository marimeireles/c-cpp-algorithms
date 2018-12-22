#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int computeDynamicProgramming(int value, const vector<int>& sequence, int index,
    int topValue, int minimumValue, int **memoization) {

    if (value > topValue || value < 0) {
        return -1;
    }

    if (memoization[value][index] != -2) {
        return value;
    }

    if (index >= sequence.size()) {
        memoization[value][index] = value;
        return value;
    }

    int left, right;
    right = computeDynamicProgramming(value + sequence[index], sequence, index+1,
        topValue, minimumValue, memoization);
    left = computeDynamicProgramming(value - sequence[index], sequence, index+1,
        topValue, minimumValue, memoization);

    memoization[value][index] = max(left, right);
    return max(left, right);
}

int main(int argc, char const *argv[]) {

    FILE* inputFile = fopen(argv[1], "r");

    int numberInstances, sequenceSize, initialValue, topValue, minimumValue;
    fscanf(inputFile, "%d\n", &numberInstances);

    for (int i = 0; i < numberInstances; i++) {
        fscanf(inputFile, "%d %d %d %d\n", &sequenceSize, &initialValue, 
            &topValue, &minimumValue);
        int aux;
        vector<int> sequence;
        for (int j = 0; j < sequenceSize; ++j) {
            fscanf(inputFile, "%d", &aux);
            sequence.push_back(aux);
        }
        int index = 0;
        int** memoization = new int*[topValue+1];
        for (int i = 0; i < topValue+1; ++i) {
            memoization[i] = new int[sequenceSize+1];
            for (int j = 0; j < sequenceSize+1; ++j) {
                memoization[i][j] = -2;
            }
        }

        int answer = computeDynamicProgramming(initialValue, sequence, index, topValue,
            minimumValue, memoization);

        for (int i = 0; i < topValue+1; ++i) {
            delete[] memoization[i];
        }
        delete[] memoization;

        FILE* outputFile = fopen(argv[2], "w");
        answer >= minimumValue ? fprintf(outputFile, "S,%d\n", answer) :
            fprintf(outputFile, "N,%d\n", answer);
        fclose(outputFile);
    }

    fclose(inputFile);

    return 0;
}
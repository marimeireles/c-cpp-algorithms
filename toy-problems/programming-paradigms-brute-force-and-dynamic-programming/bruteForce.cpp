#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int computeBruteForce(int value, const vector<int>& sequence, int index,
    int topValue, int minimumValue) {

    if (value > topValue || value < 0) return -1;

    if (index >= sequence.size()) return value;

    int left, right;
    right = computeBruteForce(value + sequence[index], sequence, index+1,
        topValue, minimumValue);
    left = computeBruteForce(value - sequence[index], sequence, index+1,
        topValue, minimumValue);

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
        int answer = computeBruteForce(initialValue, sequence, index, topValue,
            minimumValue);

        FILE* outputFile = fopen(argv[2], "w");
        answer >= minimumValue ? fprintf(outputFile, "S,%d\n", answer) :
            fprintf(outputFile, "N,%d\n", answer);
        fclose(outputFile);
    }

    fclose(inputFile);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

string line;
vector<char> text;
int size = 0;


    while(getline(cin, line)) {
        if(line.empty())
            cout << endl;
        else {
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] != ' ')
                    text.push_back(line[i]);
            }
            sort(text.begin(), text.end());

            for (int i = 0; i < text.size(); ++i) {
                if (text[i + 1] == text[i] + 1 || text[i + 1] == text[i]) {
                    size++;
                }
                else {
                    if (text[i] != text.back()) {
                        printf("%c:%c, ", text[i-size], text[i]);
                        size = 0;
                    }
                    else {
                        printf("%c:%c\n", text[i-size], text[i]);
                        size = 0;
                    }
                }
            }
        }
        line = "";
        text.clear();
    }
}
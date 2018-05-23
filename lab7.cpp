#include <iostream>
#include <vector>

using namespace std;

void deleteWordAndPrint(char* str, int wordNumber) {
    vector<vector<char>> words;
    vector<char> currentWord;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord = vector<char>();
            }
        } else {
            currentWord.push_back(str[i]);
        }
    }
    
    for (int w = 0; w < words.size(); w++) {
        if (w == wordNumber) continue;
        
        for (int c = 0; c < words[w].size(); c++) {
            cout << words[w][c];
        }
        cout << " ";
    }
}

int main()
{
    char* src = "suka jopa gorit";
    deleteWordAndPrint(src, 0);
    return 0;
}

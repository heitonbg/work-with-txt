#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;
int main() {
    ifstream file("t.txt");
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    unordered_map<char, int> letterFrequency; 
    unordered_map<string, int> bigramFrequency; 

    string text;
    string line;
    while (getline(file, line)) {
        text += line + " "; 
    }
    file.close();

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (isalpha(c)) { 
            c = tolower(c); 
            letterFrequency[c]++;
            if (i < text.length() - 1 && isalpha(text[i + 1])) {
                string bigram = text.substr(i, 2);
                bigramFrequency[bigram]++;
            }
        }
    }

    cout << "Частота букв:\n";
    for (const auto& pair : letterFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nЧастота двухбуквенных сочетаний:\n";
    for (const auto& pair : bigramFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
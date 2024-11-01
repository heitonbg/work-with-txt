#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;
int main() {
    ifstream file("t.txt"); // Открываем файл
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    unordered_map<char, int> letterFrequency; // Для частоты букв
    unordered_map<string, int> bigramFrequency; // Для двухбуквенных сочетаний

    string text;
    string line;
    while (getline(file, line)) {
        text += line + " "; // Собираем текст из файла
    }
    file.close();

    // Подсчитываем частоту букв и двухбуквенных сочетаний
    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (isalpha(c)) { // Проверяем, является ли символ буквой
            c = tolower(c); // Приводим к нижнему регистру
            letterFrequency[c]++;
            if (i < text.length() - 1 && isalpha(text[i + 1])) {
                string bigram = text.substr(i, 2);
                bigramFrequency[bigram]++;
            }
        }
    }

    // Вывод частоты букв
    cout << "Частота букв:\n";
    for (const auto& pair : letterFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Вывод частоты двухбуквенных сочетаний
    cout << "\nЧастота двухбуквенных сочетаний:\n";
    for (const auto& pair : bigramFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

// practica6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <sstream>
#include <list>
using namespace std;


#pragma region Variant1
//char* getString() {
//    char* str = new char[100];
//    cout << "Input string: ";
//    cin.getline(str, 100);
//    return str;
//}
//
//void printString(char* str) {
//    cout << str << std::endl;
//}
//void sortString(char* str) {
//    char* word = strtok(str, " ");
//    int countWords = 0;
//    char* words[100];
//
//    while (word != NULL) {
//        words[countWords++] = word;
//        word = strtok(NULL, " ");
//    }
//
//    for (int i = 0; i < countWords - 1; i++)
//    {
//        for (int j = i + 1; j < countWords; j++)
//        {
//            if (strcmp(words[i], words[j]) > 0) {
//                char* temp = words[i];
//                words[i] = words[j];
//                words[j] = temp;
//            }
//        }
//    }
//    strcpy(str, "");
//    for (int i = 0; i < countWords; i++)
//    {
//        strcat(str, words[i]);
//        strcat(str, " ");
//    }
//}
//
#pragma endregion

char* getString() {
    string input;
    cout << "Input string: ";
    getline(cin, input);

    char* str = new char[input.length() + 1];
    strcpy(str, input.c_str());
    return str;
}
void printString(char* str) {
    cout << str << endl;
}

void sortString(char* str) {
    stringstream ss(str);
    string word;
    list<string> words;

    while (ss >> word) {
        bool check_letter = true;
        for (char c : word) {
            if (!isalpha(c)) {
                check_letter = false;
                break;
            }
        }
        if (check_letter) {
            words.push_back(word);
        }
    }


    words.sort();
    strcpy(str, "");
    for (const auto& w : words)
    {
        strcat(str, w.c_str());
        strcat(str, " ");
    }
}


int main()
{
    /*setlocale(LC_ALL, "ru");*/
    char* str = getString();
    sortString(str);
    cout << "Result: ";
    printString(str);
    //delete[] str;
    return 0;

}



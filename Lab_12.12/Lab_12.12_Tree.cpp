#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Note {
    string firstName;
    string lastName;
    string phoneNumber;
    Date birthDate;
};

struct TreeNode {
    Note data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(const Note& note) {
    TreeNode* newNode = new TreeNode;
    newNode->data = note;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(TreeNode*& root, const Note& note) {
    if (root == NULL) {
        root = createNode(note);
    }
    else {
        if (note.phoneNumber < root->data.phoneNumber) {
            addNode(root->left, note);
        }
        else {
            addNode(root->right, note);
        }
    }
}

void inputNotes(TreeNode*& root) {
    int numNotes;
    cout << "Введіть кількість записів: ";
    cin >> numNotes;

    for (int i = 0; i < numNotes; i++) {
        Note note;
        cout << "Запис " << (i + 1) << ":" << endl;
        cout << "Прізвище: ";
        cin >> note.lastName;
        cout << "Ім'я: ";
        cin >> note.firstName;
        cout << "Номер телефону: ";
        cin >> note.phoneNumber;
        cout << "Дата народження (дд мм рр): ";
        cin >> note.birthDate.day >> note.birthDate.month >> note.birthDate.year;
        addNode(root, note);
    }
}

void printPerson(const TreeNode* root, const string& lastName) {
    if (root == NULL) {
        cout << "Запис з прізвищем " << lastName << " не знайдений." << endl;
        return;
    }

    if (root->data.lastName == lastName) {
        cout << "Інформація про людину з прізвищем " << lastName << ":" << endl;
        cout << "Прізвище: " << root->data.lastName << endl;
        cout << "Ім'я: " << root->data.firstName << endl;
        cout << "Номер телефону: " << root->data.phoneNumber << endl;
        cout << "Дата народження: " << root->data.birthDate.day << "." << root->data.birthDate.month << "." << root->data.birthDate.year << endl;
    }
    else if (lastName < root->data.lastName) {
        printPerson(root->left, lastName);
    }
    else {
        printPerson(root->right, lastName);
    }
}

void sortNotes(TreeNode* root) {
    if (root != NULL) {
        sortNotes(root->left);
        cout << "Прізвище: " << root->data.lastName << ", Номер телефону: " << root->data.phoneNumber << endl;
        sortNotes(root->right);
    }
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    TreeNode* root = NULL;

    int menu;
    do {
        cout << "1. Додати запис: " << endl;
        cout << "2. Сортувати за номером телефону" << endl;
        cout << "Вибери(1-3): "; cin >> menu;
        string searchLastName;
        switch (menu)
        {
        case 1:
            inputNotes(root);
            break;
        case 2:
            cout << "Впорядковані записи за телефонними номерами:" << endl;
            sortNotes(root);
        case 3:
            cout << "Введіть прізвище для пошуку: ";
            cin >> searchLastName;
            printPerson(root, searchLastName);
        default:
            break;
        }
    } while (menu != 0);
}

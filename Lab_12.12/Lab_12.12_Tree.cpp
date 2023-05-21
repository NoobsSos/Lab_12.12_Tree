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
    cout << "������ ������� ������: ";
    cin >> numNotes;

    for (int i = 0; i < numNotes; i++) {
        Note note;
        cout << "����� " << (i + 1) << ":" << endl;
        cout << "�������: ";
        cin >> note.lastName;
        cout << "��'�: ";
        cin >> note.firstName;
        cout << "����� ��������: ";
        cin >> note.phoneNumber;
        cout << "���� ���������� (�� �� ��): ";
        cin >> note.birthDate.day >> note.birthDate.month >> note.birthDate.year;
        addNode(root, note);
    }
}

void printPerson(const TreeNode* root, const string& lastName) {
    if (root == NULL) {
        cout << "����� � �������� " << lastName << " �� ���������." << endl;
        return;
    }

    if (root->data.lastName == lastName) {
        cout << "���������� ��� ������ � �������� " << lastName << ":" << endl;
        cout << "�������: " << root->data.lastName << endl;
        cout << "��'�: " << root->data.firstName << endl;
        cout << "����� ��������: " << root->data.phoneNumber << endl;
        cout << "���� ����������: " << root->data.birthDate.day << "." << root->data.birthDate.month << "." << root->data.birthDate.year << endl;
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
        cout << "�������: " << root->data.lastName << ", ����� ��������: " << root->data.phoneNumber << endl;
        sortNotes(root->right);
    }
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    TreeNode* root = NULL;

    int menu;
    do {
        cout << "1. ������ �����: " << endl;
        cout << "2. ��������� �� ������� ��������" << endl;
        cout << "������(1-3): "; cin >> menu;
        string searchLastName;
        switch (menu)
        {
        case 1:
            inputNotes(root);
            break;
        case 2:
            cout << "����������� ������ �� ����������� ��������:" << endl;
            sortNotes(root);
        case 3:
            cout << "������ ������� ��� ������: ";
            cin >> searchLastName;
            printPerson(root, searchLastName);
        default:
            break;
        }
    } while (menu != 0);
}

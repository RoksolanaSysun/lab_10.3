#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h> // ��� ������������ ��������� ������

using namespace std;

// ��������� ��� ���������� ���������� ��� ������
struct Note {
    string surname;
    string first_name;
    string phone_number;
    int birth_date[3]; // {����, �����, ��}
};

// ������� ��� ��������� ������ ������
Note* resizeArray(Note* notes, int& size) {
    int newSize = size + 1;
    Note* newArray = new Note[newSize];
    for (int i = 0; i < size; ++i) {
        newArray[i] = notes[i];
    }
    delete[] notes;
    size = newSize;
    return newArray;
}

// ������� ��� �������� ����� ��� ������
void inputData(Note*& notes, int& count) {
    notes = resizeArray(notes, count);

    cout << "������ �������: ";
    cin >> notes[count - 1].surname;
    cout << "������ ��'�: ";
    cin >> notes[count - 1].first_name;
    cout << "������ ����� ��������: ";
    cin >> notes[count - 1].phone_number;
    cout << "������ ���� ���������� (���� ����� ��): ";
    cin >> notes[count - 1].birth_date[0] >> notes[count - 1].birth_date[1] >> notes[count - 1].birth_date[2];
}

// ������� ��� ���������� ������ �� �������� � ���������� �������
void sortNotes(Note* notes, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (notes[i].surname > notes[j].surname) {
                swap(notes[i], notes[j]);
            }
        }
    }
    cout << "������ ����������� �� ��������.\n";
}

// ������� ��� ����������� ���������� ��� �����, �� ���������� � ��������� �����
void displayByMonth(const Note* notes, int count, int month) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (notes[i].birth_date[1] == month) {
            cout << "�������: " << notes[i].surname << ", ��'�: " << notes[i].first_name
                << ", ����� ��������: " << notes[i].phone_number << ", ���� ����������: "
                << notes[i].birth_date[0] << "/" << notes[i].birth_date[1] << "/" << notes[i].birth_date[2] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "���� �����, �� ���������� � ����� �����.\n";
    }
}

int main() {
    SetConsoleCP(1251); // ������������ ��������� ��� ��������
    SetConsoleOutputCP(1251); // ������������ ��������� ��� ���������

    Note* notes = nullptr;
    int count = 0;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n����:\n";
        cout << "1. ������ ������\n";
        cout << "2. ��������� �� ��������\n";
        cout << "3. ³��������� �����, �� ���������� � ��������� �����\n";
        cout << "4. �����\n";
        cout << "������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputData(notes, count);
            break;
        case 2:
            sortNotes(notes, count);
            break;
        case 3: {
            int month;
            cout << "������ ����� ����� (1-12): ";
            cin >> month;
            displayByMonth(notes, count, month);
            break;
        }
        case 4:
            running = false;
            cout << "����� � ��������.\n";
            break;
        default:
            cout << "������������ ����. ��������� �� ���.\n";
            break;
        }
    }

    delete[] notes;
    return 0;
}

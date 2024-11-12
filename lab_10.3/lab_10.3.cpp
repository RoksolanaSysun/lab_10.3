#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h> // Для налаштування кодування виводу

using namespace std;

// Структура для збереження інформації про людину
struct Note {
    string surname;
    string first_name;
    string phone_number;
    int birth_date[3]; // {день, місяць, рік}
};

// Функція для збільшення розміру масиву
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

// Функція для введення даних про людину
void inputData(Note*& notes, int& count) {
    notes = resizeArray(notes, count);

    cout << "Введіть прізвище: ";
    cin >> notes[count - 1].surname;
    cout << "Введіть ім'я: ";
    cin >> notes[count - 1].first_name;
    cout << "Введіть номер телефону: ";
    cin >> notes[count - 1].phone_number;
    cout << "Введіть дату народження (день місяць рік): ";
    cin >> notes[count - 1].birth_date[0] >> notes[count - 1].birth_date[1] >> notes[count - 1].birth_date[2];
}

// Функція для сортування масиву за прізвищем у алфавітному порядку
void sortNotes(Note* notes, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (notes[i].surname > notes[j].surname) {
                swap(notes[i], notes[j]);
            }
        }
    }
    cout << "Список відсортовано за прізвищем.\n";
}

// Функція для відображення інформації про людей, які народилися у вказаному місяці
void displayByMonth(const Note* notes, int count, int month) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (notes[i].birth_date[1] == month) {
            cout << "Прізвище: " << notes[i].surname << ", Ім'я: " << notes[i].first_name
                << ", Номер телефону: " << notes[i].phone_number << ", Дата народження: "
                << notes[i].birth_date[0] << "/" << notes[i].birth_date[1] << "/" << notes[i].birth_date[2] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Немає людей, які народилися в цьому місяці.\n";
    }
}

int main() {
    SetConsoleCP(1251); // Встановлення кодування для введення
    SetConsoleOutputCP(1251); // Встановлення кодування для виведення

    Note* notes = nullptr;
    int count = 0;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nМеню:\n";
        cout << "1. Додати людину\n";
        cout << "2. Сортувати за прізвищем\n";
        cout << "3. Відобразити людей, які народилися у вказаному місяці\n";
        cout << "4. Вийти\n";
        cout << "Виберіть пункт: ";
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
            cout << "Введіть номер місяця (1-12): ";
            cin >> month;
            displayByMonth(notes, count, month);
            break;
        }
        case 4:
            running = false;
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
            break;
        }
    }

    delete[] notes;
    return 0;
}

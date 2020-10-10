#include <iostream>
#include <Windows.h>
using namespace std; 

struct Student {
    string name;
    string surname; 
    int score[3];
    int Sum = 0;
};

void showData(Student* st, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << "#" << i + 1 << "Имя:\t" << st[i].name << "Фамилия:\t" << st[i].surname << endl;
        for (int j = 0; j < 3; j++)
            cout << "Оценка # " << j + 1 << ": " << st[i].score[j] << endl;
    }
}
bool operator<(Student s1, Student s2) {
    return s1.Sum < s2.Sum;
}
void sort(Student*& student, const int size) // по убыванию
{
    cout << "sort:" << endl;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (student[i] < student[j]);
            {
                Student tempstudent = student[i];
                student[i] = student[j];
                student[j] = tempstudent;
            }
        }
    }
}

    int main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int amount;
        cout << "Введите количество студентов\n";
        cin >> amount;

        if (amount < 2) {
            cout << "Введите большее число" << endl;
            return 0;
        }
        Student* st = new Student[amount];
        for (int i = 0; i != amount; i++)
        {
            cout << "# " << i + 1 << " " << "Имя студента" << endl;
            cin >> st[i].name;
            cout << "#" << i + 1 << " " << "Фамилия студента" << endl;
            cin >> st[i].surname;
            cout << "Оценки студента" << endl;
            for (int j = 0; j < 3; j++) {
                cin >> st[i].score[j];
                st[i].Sum += st[i].score[j];
            }
            cin.get();
        }
        sort(st, amount);
        showData(st, amount);
        return 0;
    }



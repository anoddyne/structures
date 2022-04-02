#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    string fio;
    string yearob;
    int course;
    int group;
};
ostream& operator<<(ostream& out, const Student obj)
{
    out << obj.fio << " " << obj.yearob << " " << obj.group << " " << obj.course;
    return out;
}

int main()
{
    setlocale(LC_ALL, "");
    int search = 0;
    string fio_s, yearob_s;
    int course_s, group_s;
    int chek = 1;
    while (chek == 1)
    {
        cout << "Введите 1 для запуска, 0 для выхода > ";
        cin >> chek;
        switch (chek)
        {
        case(0):
            break;
        case(1):
        {
            int leng = 0;
            string s;
            ifstream fle("input.txt");
            while (getline(fle, s))
            {
                leng += 1;
            }
            Student* list = new Student[leng];
            int a = 0;

            fle.close();
            ifstream file("input.txt");

            string ss, buff;
            while (getline(file, s))
            {
                buff.assign(s);
                list[a].course = buff[0] - '0';
                buff.erase(0, 2);

                ss += buff[0];
                ss += buff[1];
                list[a].group = stoi(ss);
                ss.clear();
                buff.erase(0, 3);

                for (int i = 0; i < 4; i++)
                    list[a].yearob += buff[i];
                buff.erase(0, 5);

                list[a].fio.assign(buff);
                a += 1;
                buff.clear();
            }
            cout << "По какому параметру нужно найти студентов: 1 - по ФИО, 2 - по году рождения, 3 - по курсу, 4 - по номеру группы: ";

            cin >> search;
            switch (search) {
            case(1):
                getline(cin, fio_s);
                for (int i = 0; i <= leng; i++) {
                    if (list[i].fio.find(fio_s, 10)) {
                        cout << list[i].fio << ", " << list[i].course << " курс, " << list[i].group << " группа, " << list[i].yearob << " год рождения; " << endl;
                    }
                    else {
                        continue;
                    }

                }
            case(2):
                cin >> yearob_s;
                for (int i = 0; i <= leng; i++) {
                    if (list[i].yearob.find(yearob_s, 5)) {
                        cout << list[i].fio << ", " << list[i].course << " курс, " << list[i].group << " группа, " << list[i].yearob << " год рождения; " << endl;
                    }
                    else {
                        continue;
                    }
                }
            case(3): {
                cin >> course_s;
                for (int i = 0; i <= leng; i++) {
                    if (course_s == list[i].course) {
                        cout << list[i].fio << ", " << list[i].course << " курс, " << list[i].group << " группа, " << list[i].yearob << " год рождения; " << endl;
                    }
                    else {
                        continue;
                    }
                }
            }
            case(4):
                cin >> group_s;
                for (int i = 0; i <= leng; i++) {
                    if (group_s == list[i].group) {
                        cout << list[i].fio << ", " << list[i].course << " курс, " << list[i].group << " группа, " << list[i].yearob << " год рождения; " << endl;
                    }
                    else {
                        continue;
                    }
                }
            }


            file.close();
            continue;
        }
        default:
        {
            cout << "Ошибка ввода" << endl;
            continue;
        }
        }

    }
}


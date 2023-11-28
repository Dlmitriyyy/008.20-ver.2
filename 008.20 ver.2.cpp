#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;
    int daysToAdd;
public:
    Date() {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int operator- (const Date& opS) const
    {
        int difference;
        int differenceYears = year - opS.year;
        int count = 0;

        for (int y = 1; y < differenceYears; y += 2)
        {
            count++;
        }

        difference = (year - opS.year) * 365 + (month - opS.month) * 30 + (day - opS.day) + count;
        return difference;
    }

    Date operator+ (int opA) const {
        Date dateAfterAdd = *this;
        dateAfterAdd.day += opA;

        while (dateAfterAdd.day > 30) {
            dateAfterAdd.day -= 30;
            dateAfterAdd.month++;

            if (dateAfterAdd.month > 12) {
                dateAfterAdd.month = 1;
                dateAfterAdd.year++;
            }
        }
        return dateAfterAdd;
    }

    void displayDifference(const Date& opS, int daysToAdd) const
    {
        int difference = *this - opS;
        cout << "Різниця дат у днях: " << difference << " дн." << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        Date dateAfterAdd = *this + daysToAdd;
        cout << "Дата після додавання: " << dateAfterAdd.day << '.' << dateAfterAdd.month << '.' << dateAfterAdd.year << endl;
    }
};

int main()
{
    system("chcp 1251 > nul");
    int day, month, year;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Програма розраховує різницю в днях між двома датами з невеликою похибкою. Уважно вводьте дати: спочатку введіть кінцеву дату, а потім початкову. В іншому випадку можуть виникнути невірні значення, включаючи від'ємні результати." << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "Введіть кінцеву дату у форматі (DD MM YYYY) через пробіли: ";

    cin >> day >> month >> year;
    Date date1(day, month, year);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Введіть початкову дату у форматі (DD MM YYYY) через пробіли: ";
    cin >> day >> month >> year;
    Date date2(day, month, year);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    int daysToAdd;
    cout << "Введіть кількість днів яку бажаєте додати до кінцевої дати. Зверніть увагу на те що програма може не ідеально точно     видати данні так як рахує місяць за 30 днів: ";
    cin >> daysToAdd;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    date1.displayDifference(date2, daysToAdd);
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}

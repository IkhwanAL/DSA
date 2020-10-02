#include <iostream>

using namespace std;

/**
 * \return Int Number that represent Day
 * @param date Date in one month
 * @param month Month in one year(3 - 14), 13 = January, 14 = February
 * @param yearInCentury What year in those century
 * @param century Number Century
*/
int codeDay(int date, int month, int yearInCentury, int century){
    int day;
    day = (date + ( (13 *( month + 1)) / 5) + yearInCentury 
        + (yearInCentury / 4) + (century / 4) + (5*century)) % 7;

    return day;
}

/**
 * Finding The Year in century
*/
void Month(int &month, int &year){
    if(month == 1){
        month = 13;
        year = year - 1;
    }else if(month = 14){
        month = 14;
        year = year - 1;
    }
}
int findYearCentury(int year){
    return year % 100;
}
int findCentury(int year){
    return year / 100; 
}
main(){
    cout << "Find Your Day: " << endl;

    int date;
    cout << "Date 1 - 31: "; cin >> date;
    cout << endl;

    int month;
    cout << "Month 1 - 12: "; cin >> month;
    cout << endl;

    int year;
    cout << "Year: "; cin >> year;
    cout << endl;

    Month(month, year);
    int code = codeDay(date, month, findYearCentury(year), findCentury(year));

    switch (code)
    {
    case 0:
        cout << "Saturday" << endl;
        break;
    case 1:
        cout << "Sunday" << endl;
        break;
    case 2:
        cout << "Monday" << endl;
        break;
    case 3:
        cout << "Thuesday" << endl;
        break;
    case 4:
        cout << "Wednesday" << endl;
        break;
    case 5:
        cout << "Thursday" << endl;
        break;
    case 6:
        cout << "Friday" << endl;
        break;
    default:
        cout << "Check Input or Algorithm" << endl;
        break;
    }

}
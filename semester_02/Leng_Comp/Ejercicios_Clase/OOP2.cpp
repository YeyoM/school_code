#include <iostream>
using namespace std;

class Date {
  private: 
    int day, month, year;

  public:
    Date(int, int, int);
    Date(long);
    void showDate();
};

Date::Date(int _day, int _month, int _year) {
  day = _day;
  month = _month;
  year = _year;
}

Date::Date(long longDate) {
  year = int(longDate/10000);
  month = int((longDate - year * 10000)/100);
  day = int(longDate - year * 10000 - month * 100);
}

void Date::showDate(){ 
  cout <<"The date is: "<< month <<"/"<< day <<"/"<< year <<endl;
}

int main(){

  Date today(2, 3, 22);
  today.showDate();

  return 0;
}
#include <iostream>
using namespace std;

class Person {
  // Atributos
  private:
    int age;
    string name;
  // Metodos
  public:
    Person(int, string);
    void read();
    void run();
};

Person::Person(int _age, string _name){
  age = _age;
  name = _name;
}

void Person::read(){
  cout<<"My name is "<<name<<" Im "<<age<<" and Im reading a book"<<endl;
}

void Person::run(){
  cout<<"My name is "<<name<<" Im "<<age<<" and Im running"<<endl;
}

int main() {
  Person p1(18, "Diego");
  p1.read();
  p1.run();

  //system('pause')

  return 0;
}
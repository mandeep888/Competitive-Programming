#include <iostream>
using namespace std;

class Employee123{
private:
     string Name;
public:
    string Company;
    int Age;
    Employee (string name,string company,int age){
    Name= name;
    Company=company;
    Age=age;
    }
    // setter function
    void setname(string s){
        Name=s;
    }

    void getinfo(){
    cout<<"name--"<<Name<<endl;
    cout<<"company--"<<Company<<endl;
    cout<<"age--"<<Age<<endl;
    }
};

int main()
{
    Employee e1("mandeep","amazon",19);
    e1.setname("jassu");
    e1.getinfo();

    return 0;
}

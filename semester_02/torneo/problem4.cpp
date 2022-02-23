// Problem4
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    float salary,imp,tltim1,tltim2,res,r1,r2;
    cin >> salary;
    if (salary>=0&&salary<=2000) {
        cout<<"Exento de pago.";
    }else {
        if (salary > 2000 && salary <=3000)
        {
            tltim1 = salary * .08; 
            cout << "R$ "<<tltim1;
        }
        else
        {
            if (salary > 3000 && salary <= 4500)
            {
                res = salary - 2000;
                r1 = (res - 1000);
                r2 = (res - r1);
                tltim2 = (r1 * .18) + (r2 * .08); 
                cout << "tR$ " << tltim2;
            }
            else
            {
                if (salary > 4500) { 
                     int aux = salary;
                     salary -= 2000;
                     res = salary - 1000;
                     r1 = 1000; 
                     r2 =  aux - 4500;     
                    tltim1 = (res * .08) + (r1 * .18) + (r2 * .28); 
                    cout << "R$ " << tltim1;
                }
            }
        }
    }
}


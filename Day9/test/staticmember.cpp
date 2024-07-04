
#include <iostream>
using namespace std;

class Account{
    public:
    static int taccounts;
    
    Account(){
        ++taccounts;
    }
    ~Account(){
        --taccounts;
    }
    
    static void display(){
        cout<<"Total Accounts = "<<taccounts<<endl;
    }
};

int Account::taccounts=0;
int main()
{
    Account::display();
    
    Account a1;
    Account a2;
    Account::display();
    
    {
        Account a3;
        Account::display();
    }
    
    Account::display();

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accNo;
    string name;
    float balance;

public:
	
    // Function for creating Account;
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accNo;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Function Displaying Account;
    void displayAccount()
    {
        cout << "\n---------------------------";
        cout << "\nAccount Number : " << accNo;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance;
        cout << "\n---------------------------\n";
    }

    // Function for Deposit Money;
    void deposit()
    {
        float amount;

        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        balance += amount;

        cout << "Amount Deposited Successfully!";
    }

    // Function for Withdraw Money
    void withdraw()
    {
        float amount;

        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if(amount > balance)
        {
            cout << "Insufficient Balance!";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!";
        }
    }

    // Get Account Number
    int getAccNo()
    {
        return accNo;
    }

    // Get Balance
    float getBalance()
    {
        return balance;
    }

    // Save Data to File
    void writeToFile()
    {
        ofstream file("bank.txt", ios::app);

        file << accNo << endl;
        file << name << endl;
        file << balance << endl;

        file.close();
    }

    // Read Data from File
    void readFromFile()
    {
        ifstream file("bank.txt");

        int a;
        string n;
        float b;

        cout << "\n===== CUSTOMER RECORDS =====\n";

        while(file >> a)
        {
            file.ignore();

            getline(file, n);

            file >> b;

            cout << "\nAccount Number : " << a;
            cout << "\nCustomer Name  : " << n;
            cout << "\nBalance        : " << b;
            cout << "\n---------------------------";
        }

        file.close();
    }
};

int main()
{
    BankAccount customer;

    int choice;

    do
    {
        cout << "\n ========= BANK MANAGEMENT SYSTEM ==========";
        cout << "\n 1. Create Account";
        cout << "\n 2. Deposit Money";
        cout << "\n 3. Withdraw Money";
        cout << "\n 4. Display Account";
        cout << "\n 5. Show All Records";
        cout << "\n 6. Exit";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                customer.createAccount();
                customer.writeToFile();
                break;

            case 2:
                customer.deposit();
                break;

            case 3:
                customer.withdraw();
                break;

            case 4:
                customer.displayAccount();
                break;

            case 5:
                customer.readFromFile();
                break;

            case 6:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}

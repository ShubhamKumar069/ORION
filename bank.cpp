#include <iostream>
#include <string>

int option;
int loggedInIndex = -1;

int accNumber = 1000;
int totalAccounts = 0;
constexpr int MAX_ACCOUNTS = 100;

struct Account
{
    std::string name;
    int age;
    std::string accType;
    int pin;
    double balance;
    int accNumber;
};

Account accounts[MAX_ACCOUNTS];

bool checkFull()
{
    if (totalAccounts >= MAX_ACCOUNTS)
    {
        std::cout << "Bank storage full!" << std::endl;
        return true;
    }

    return false;
}

bool checkZero()
{
    if (totalAccounts == 0)
    {
        std::cout << "NO USER FOUND!" << std::endl;
        return true;
    }
    return false;
}

void createAcc()
{

    if (checkFull())
    {
        return;
    }

    std::string name;
    int age;
    std::string accType;
    int pin;
    double initialDepo;

    std::cout << "========== CREATE ACCOUNT ==========" << std::endl;
    std::cout << "\n";

    std::cout << "Enter name : ";
    std::cin.ignore(1000, '\n');
    getline(std::cin, name);
    std::cout << "Enter age : ";
    std::cin >> age;
    std::cout << "Enter Account Type (Savings/Current) : ";
    std::cin.ignore(1000, '\n');
    getline(std::cin, accType);
    std::cout << "Create PIN : ";
    std::cin >> pin;
    std::cout << "Enter initial deposit : $";
    std::cin >> initialDepo;

    accounts[totalAccounts].name = name;
    accounts[totalAccounts].age = age;
    accounts[totalAccounts].accType = accType;
    accounts[totalAccounts].pin = pin;
    accounts[totalAccounts].balance = initialDepo;
    accounts[totalAccounts].accNumber = accNumber++;

    std::cout << "Account Created Successfully!" << std::endl;
    std::cout << "Account Number : "
              << accounts[totalAccounts].accNumber
              << std::endl;
    std::cout << "Initial Deposit : $" << initialDepo << std::endl;

    totalAccounts++;
}

void withdraw(int acc)
{
    double amount;
    std::cout << "How Much Do You Wanna Withdraw : $";
    std::cin >> amount;
    if (amount <= 0)
    {
        std::cout << "Invalid Amount!" << std::endl;
        return;
    }
    if (amount > accounts[acc].balance)
    {
        std::cout << "Not Enough Money Available!" << std::endl;
        std::cout << "Balance : " << accounts[acc].balance << std::endl;
    }
    else
    {
        double leftAmount = accounts[acc].balance - amount;
        std::cout << "$" << amount << " Withdrawn From Your Account" << std::endl;
        accounts[acc].balance = leftAmount;
        std::cout << "Balance Left : " << accounts[acc].balance << std::endl;
    }
}

void deposit(int acc)
{
    double amount;
    std::cout << "How Much Do You Wanna Deposit : $";
    std::cin >> amount;

    if (amount <= 0)
    {
        std::cout << "Invalid Amount!" << std::endl;
        return;
    }

    accounts[acc].balance += amount;
    std::cout << "$" << amount << " Deposited To Your Account" << std::endl;
    std::cout << "New Balance : " << accounts[acc].balance << std::endl;
}

void checkBalance(int acc)
{
    std::cout << "Balance : " << accounts[acc].balance << std::endl;
}

void loggedInHome()
{

    int choice;

    do
    {
        std::cout << "================================================" << std::endl;
        std::cout << "                 ORION BANK" << std::endl;
        std::cout << "================================================" << std::endl;

        std::cout << "1. Withdraw" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Check Balance" << std::endl;
        std::cout << "4. Logout" << std::endl;
        std::cout << "Enter Choice:";
        std::cin >> choice;

        double currentBalance = accounts[loggedInIndex].balance;

        switch (choice)
        {
        case 1:
        {
            withdraw(loggedInIndex);
            break;
        }
        case 2:
        {
            deposit(loggedInIndex);
            break;
        }
        case 3:
        {
            checkBalance(loggedInIndex);
            break;
        }
        case 4:
        {
            std::cout << "Logged Out Successfully!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid Option!";
            break;
        }
        }

    } while (choice != 4);
}

void loginToAcc()
{
    if (checkZero())
    {
        return;
    }
    int accNo;
    int pin;
    std::cout << "=========== LOGIN ===========" << std::endl;
    std::cout << "Enter Account Number : ";
    std::cin >> accNo;
    std::cout << "Enter pin : ";
    std::cin >> pin;

    bool found = false;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accNumber == accNo && accounts[i].pin == pin)
        {
            found = true;
            loggedInIndex = i;
            std::cout << "Login Successful!" << std::endl;
            std::cout << "Welcome, " << accounts[i].name << std::endl;
            loggedInHome();
        }
    }

    if (!found)
    {
        std::cout << "Invalid Account Number or PIN!"
                  << std::endl;
    }
}

void thanks()
{
    std::cout << "THANKS FOR USING ORION BANK!" << std::endl;
}

void searchAccount()
{
    if (checkZero())
    {
        return;
    }

    std::cout << "=========== SEARCH ACCOUNT ===========" << std::endl;

    int pin;
    int accNo;

    std::cout << "Enter Your PIN : ";
    std::cin >> pin;
    std::cout << "Enter Account Number : ";
    std::cin >> accNo;

    bool found = false;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accNumber == accNo && accounts[i].pin == pin)
        {

            found = true;

            std::cout << "Account Name : " << accounts[i].name << std::endl;
            std::cout << "Account Age : " << accounts[i].age << std::endl;
            std::cout << "Account Type : " << accounts[i].accType << std::endl;
            std::cout << "Account Number : " << accounts[i].accNumber << std::endl;
        }
    }

    if (!found)
    {
        std::cout << "Invalid Account Number OR Account PIN!" << std::endl;
        return;
    }
}

void deleteAccount()
{
    if (checkZero())
    {
        return;
    }

    int pin;
    int accNo;
    char choice;

    std::cout << "Enter Your PIN : ";
    std::cin >> pin;
    std::cout << "Enter Account Number : ";
    std::cin >> accNo;

    bool found = false;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accNumber == accNo && accounts[i].pin == pin)
        {
            found = true;
            std::cout << "Confirm To Delete Account (Y/n) : ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                for (int j = i; j < totalAccounts - 1; j++)
                {
                    accounts[j] = accounts[j + 1];
                }

                totalAccounts--;
                std::cout << "Student Deleted Successfully!\n";
                break;
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "Deleting Account Rejected!\n";
                return;
            }
            else
            {
                std::cout << "Enter Valid Choices!!";
                return;
            }
        }
    }

    if (!found)
    {
        std::cout << "Invalid Account Number OR Account PIN!" << std::endl;
        return;
    }
}

void bankManagement()
{

    do
    {
        std::cout << "================================================" << std::endl;
        std::cout << "                 ORION BANK" << std::endl;
        std::cout << "================================================" << std::endl;

        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Login To Account" << std::endl;
        std::cout << "3. Search Account" << std::endl;
        std::cout << "4. Delete Account" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "\n";
        std::cout << "Enter Choice:";
        std::cin >> option;

        switch (option)
        {
        case 0:
            thanks();
            break;
        case 1:
            createAcc();
            break;
        case 2:
            loginToAcc();
            break;
        case 3:
            searchAccount();
            break;
        case 4:
            deleteAccount();
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            break;
        }

    } while (option != 0);
}
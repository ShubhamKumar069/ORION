#include <iostream>
#include <string>

int option;

int accNumber = 1000;
int totalAccounts = 0;
constexpr int MAX_ACCOUNTS = 100;

struct Account {
    std::string name;
    int age;
    std::string accType;
    int pin;
    double initialDepo;
    int accNumber;
};

Account accounts[MAX_ACCOUNTS];

bool checkFull() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        std::cout << "Bank storage full!" << std::endl;
        return true;
    }

    return false;
}

void createAcc() {

    if (checkFull()) {
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
    accounts[totalAccounts].initialDepo = initialDepo;
    accounts[totalAccounts].accNumber = accNumber++;

    std::cout << "Account Created Successfully!" << std::endl;
    std::cout << "Account Number : "
          << accounts[totalAccounts].accNumber
          << std::endl;
    std::cout << "Initial Deposit : $" << initialDepo << std::endl;

    totalAccounts++;


}

void loginToAcc() {
    int accNo;
    int pin;
    std::cout << "=========== LOGIN ===========" << std::endl;
    std::cout << "Enter Account Number : ";
    std::cin >> accNo;
    std::cout << "Enter pin : ";
    std::cin >> pin;

    bool found = false;

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNumber == accNo && accounts[i].pin == pin) {
            found = true;
            std::cout << "Login Successful!" << std::endl;
            std::cout << "Welcome, " << accounts[i].name <<std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid Account Number or PIN!"
                  << std::endl;
    }
}

void bankManagement() {

    do {
        std::cout << "================================================" << std::endl;
        std::cout << "                 ORION BANK" << std::endl;
        std::cout << "================================================" << std::endl;

        std::cout << "1. Create Account" <<std::endl;
        std::cout << "2. Login To Account" <<std::endl;
        std::cout << "3. View All Accounts" <<std::endl;
        std::cout << "4. Search Account" <<std::endl;
        std::cout << "5. Delete Account" <<std::endl;
        std::cout << "0. Back" <<std::endl;
        std::cout << "\n";
        std::cout << "Enter Choice:";
        std::cin >> option;

        switch (option) {
            case 1:
                createAcc();
                break;
            case 2:
                loginToAcc();
                break;
            default:
                std::cout << "Invalid Choice!" << std::endl;
                break;

        }

    }while(option != 0);

}

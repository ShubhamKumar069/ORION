#include <iostream>
#include "functions.h"

int main() {
    int option;

    do {

        std::cout << "=========================\n";
        std::cout << "          ORION\n";
        std::cout << "=========================\n";

        std::cout << "1. Student Management\n";
        std::cout << "2. Banking System\n";
        std::cout << "3. Calculator (COMING SOON!)\n";
        std::cout << "4. Games (COMING SOON!)\n";
        std::cout << "5. Utilities (COMING SOON!)\n";
        std::cout << "6. Admin Panel (COMING SOON!)\n";
        std::cout << "0. Exit\n";

        std::cout << "\nEnter Choice: ";
        std::cin >> option;

        switch(option) {

            case 1:
                studentManagement();
                break;

            case 2:
                bankManagement();
                break;

            case 3:
                calculator();
                break;

            // case 4:
            //     gameManagement();
            //     break;
            //
            // case 5:
            //     utilityManagement();
            //     break;
            //
            // case 6:
            //     adminPanel();
            //     break;

            case 0:
                std::cout << "Shutting Down...\n";
                break;

            default:
                std::cout << "Invalid choice!\n";
        }

    } while(option != 0);

    return 0;
}
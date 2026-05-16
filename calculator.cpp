#include <iostream>
#include <string>
#include <cmath>

bool checkZero(float num2)
{
    if (num2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void add(float num1, float num2)
{
    float sum = num1 + num2;
    std::cout << num1 << " + " << num2 << " = " << sum << std::endl;
}

void sub(float num1, float num2)
{
    float subValue = num1 - num2;
    std::cout << num1 << " - " << num2 << " = " << subValue << std::endl;
}

void mul(float num1, float num2)
{
    float product = num1 * num2;
    std::cout << num1 << " * " << num2 << " = " << product << std::endl;
}

void div(float num1, float num2)
{
    if (checkZero(num2))
    {
        std::cout << "Division Error!" << std::endl;
        return;
    }
    float q = num1 / num2;
    std::cout << num1 << " / " << num2 << " = " << q << std::endl;
}

void mod(float num1, float num2)
{
    if (checkZero(num2))
    {
        std::cout << "Division Error!" << std::endl;
        return;
    }
    float mod = fmod(num1, num2);
    std::cout << num1 << " % " << num2 << " = " << mod << std::endl;
}

void power(float num1, float num2)
{
    float result = std::pow(num1, num2);
    std::cout << num1 << "^" << num2 << " = " << result << std::endl;
}

void sqRoot(float num1)
{

    if (num1 < 0)
    {
        std::cout << "Invalid Input!" << std::endl;
        return;
    }

    double result = std::sqrt(num1);
    std::cout << "√" << num1 << " = " << result << std::endl;
}

void absValue(float num)
{
    std::cout << "ABSOLUTE VALUE : "
              << std::abs(num)
              << std::endl;
}

void cubeRoot(float num)
{
    double result = std::cbrt(num);
    std::cout << "CUBE ROOT : " << result << std::endl;
}

void percent(float nom, float den)
{
    float result = (nom / den) * 100;
    std::cout << "PERCENT : " << result << "%" << std::endl;
}

unsigned long long factorial(int n)
{

    if (n < 0)
    {
        std::cout << "Invalid Input!" << std::endl;
        return 0;
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void basicCalculations()
{
    int choice;
    float num1;
    float num2;

    do
    {

        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "              ORION CALCULATOR              \n";
        std::cout << "========================================\n";

        std::cout << " [1] ADD\n";
        std::cout << " [2] SUBTRACT\n";
        std::cout << " [3] MULTIPLY\n";
        std::cout << " [4] DIVIDE\n";
        std::cout << " [5] POWERS\n";
        std::cout << " [6] SQUARE ROOT\n";
        std::cout << " [7] MODULUS\n";
        std::cout << " [8] ABSOLUTE VALUE\n";
        std::cout << " [9] CUBE ROOT\n";
        std::cout << " [10] PERCENTAGE\n";
        std::cout << " [11] FACTORIAL\n";
        std::cout << " [0] Exit\n";

        std::cout << "----------------------------------------\n";
        std::cout << " Enter Choice -> ";
        std::cin >> choice;
        if (choice == 6 || choice == 8 || choice == 9 || choice == 11)
        {
            std::cout << "Enter Number : ";
            std::cin >> num1;
        }
        else if (
            choice == 1 ||
            choice == 2 ||
            choice == 3 ||
            choice == 4 ||
            choice == 5 ||
            choice == 7 ||
            choice == 10)
        {
            std::cout << "Enter First Number : ";
            std::cin >> num1;

            std::cout << "Enter Second Number : ";
            std::cin >> num2;
        }

        switch (choice)
        {
        case 0:
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        case 1:
        {
            add(num1, num2);
            break;
        }
        case 2:
        {
            sub(num1, num2);
            break;
        }
        case 3:
        {
            mul(num1, num2);
            break;
        }
        case 4:
        {
            div(num1, num2);
            break;
        }
        case 5:
        {
            power(num1, num2);
            break;
        }
        case 6:
        {
            sqRoot(num1);
            break;
        }
        case 7:
        {
            mod(num1, num2);
            break;
        }
        case 8:
        {
            absValue(num1);
            break;
        }
        case 9:
        {
            cubeRoot(num1);
            break;
        }
        case 10:
        {
            percent(num1, num2);
            break;
        }
        case 11:
        {
            factorial(num1);
            break;
        }
        default:
        {
            std::cout << "Invalid Input!" << std::endl;
            break;
        }
        }

    } while (choice != 0);
}

void scientificFeatures()
{
}

void homeMenu()
{

    int choice;

    do
    {

        std::cout << "\n";
        std::cout << "==================================================\n";
        std::cout << "                 ORION CALCULATOR                 \n";
        std::cout << "==================================================\n";

        std::cout << "                 MAIN MENU                        \n";
        std::cout << "--------------------------------------------------\n";

        std::cout << " [1]  Basic Calculations\n";
        std::cout << " [2]  Scientific Functions\n";
        std::cout << " [3]  Geometry & Mensuration\n";
        std::cout << " [4]  Unit Conversions\n";
        std::cout << " [5]  Programmer Tools\n";
        std::cout << " [6]  Equation Solver\n";
        std::cout << " [7]  Calculation History\n";
        std::cout << " [8]  Settings\n";

        std::cout << "--------------------------------------------------\n";
        std::cout << " [0]  Exit\n";
        std::cout << "==================================================\n";

        std::cout << "\n Enter Choice -> ";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        case 1:
        {
            basicCalculations();
            break;
        }
        default:
        {
            std::cout << "Invalid Input!" << std::endl;
            break;
        }
        }

    } while (choice != 0);
}

void calculator()
{
    homeMenu();
}
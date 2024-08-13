#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>

//Bank Account class with functions
class Bank_account{

    private:
        std::string username, password;
        double balance = 0, transaction_operand = 0;
        bool login_check;

    public:
        
        Bank_account(std::string user, std::string pass) : username(user), password(pass){

            balance = transaction_operand;

        }

        double deposit(double money_use){

            if (money_use < 0 )
                std::cerr << "Please enter a valid amount to deposit!" << "\n";
            else{
                std::cout << "Deposit Successful!" << "\n";
                return transaction_operand + money_use;
            }
        }
        
        double withdraw(double money_use){

            if (money_use < 0)
                std::cerr << "Please enter a valid amount to withdraw!" << "\n";
            else if (money_use > balance)
                std::cerr << "Insufficient balance to withdraw!" << "\n";
            else{
                std::cout << "Withdraw Successful!" << "\n";
                return transaction_operand - money_use;
            }
        }

        std::string NameGetter(){

            return username;
        }

        double BalanceGetter(){

            return balance;
        }
};

//Can only store up to 100 Accounts
Bank_account AccountUser[100];



void balance_view(int account_number){


    system("cls");
    std::cout << "=============================================" << "\n"
            <<   "#############################################" << "\n\n"

            <<   "Name: " << AccountUser->NameGetter() << "\n"
            <<   "Balance: " << AccountUser->BalanceGetter() << "\n"

            <<   "#############################################" << "\n\n"
            <<   "=============================================" << std::endl;
}



void Account_Menu(){

    int Option_Pick;

    system("cls");
    std::cout << "==========================================" << "\n"
            <<   "||          Welcome To Da Bank          ||" << "\n"
            <<   "==========================================" << "\n"
            <<   "******************************************" << "\n"
            <<   "##        Please select a number!       ##" << "\n"
            <<   "******************************************" << "\n"
            <<   "##[1] Create an Account                 ##" << "\n"
            <<   "##[2] Login                             ##" << "\n"
            <<   "##[3] Quit Program                      ##" << "\n"
            <<   "******************************************" << "\n"
            <<   "Selected Number: ";
    
    switch(Option_Pick){

        case 1:
            std::cout << "Use Function here" << std::endl;
            break;

        case 2:
            std::cout << "Use Function here" << std::endl;
            break;
        
        case 3:
            return;
        
        default:
            std::cerr << "Invalid Input! Please select a valid number!" << std::endl;
    }


}

void Login(){

    std::string name, pass;

    system("cls");
    std::cout << "==========================================" << "\n"
            <<   "||          Welcome to da Bank          ||" << "\n"
            <<   "==========================================" << "\n"
            <<   "******************************************" << "\n"
            <<   "##            Please login!             ##" << "\n"
            <<   "******************************************" << "\n";
    
    std::cout << "Username: ";
    std::getline(std::cin, name);

    std::cout << "Password: ";
    std::getline(std::cin, pass);

}






int main(){




    return 0;
}
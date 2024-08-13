#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	
	char username[50], correct_username[50] = "admin", password[50], correct_password[50] = "pass123", continue_input;
	int name_check, pass_check, selection_menu;
	double balance = 1000.00, balance_modify;
	
	cout << "=====================================================" << "\n"
		<< 	"||            Please login to continue             ||" << "\n"
		<<  "=====================================================" << "\n";
	
	do {
		
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		
		name_check = strcmp(username,correct_username);
		pass_check = strcmp(password,correct_password);
		
		if (name_check == 0 && pass_check == 0){
			system("cls");
			break;
		}
		if (name_check != 0 && pass_check == 0)
			cout << "Username is incorrect! Please try again!" << "\n\n";
		if (name_check == 0 && pass_check != 0)
			cout << "Password is incorrect! Please try again!" << "\n\n";
		if (name_check != 0 && pass_check != 0)
			cout << "Username and Password is incorrect! Please try again!" << "\n\n";
				
	}while (true);
	
	do {
		cout << "================================================" << "\n"
			<<  "||       Welcome to your Bank Account         ||" << "\n"
			<<  "================================================" << "\n"
			<<  "|| Kindly Choose an option (Enter the digit)  ||" << "\n"
			<<  "================================================" << "\n"
			<<  "||[1] Deposit Balance                         ||" << "\n"
			<<  "||[2] Withdraw Balance                        ||" << "\n"
			<<  "||[3] Check Balance                           ||" << "\n"
			<<  "||[4] Quit Program                            ||" << "\n"
			<<  "================================================" << "\n"
			<<  "Entered input: ";
		cin >> selection_menu;
		
		switch (selection_menu){
			
			case 1:
				system("cls");
				cout << "============================================" << "\n"
					<<  "||How much money are you going to deposit?||" << "\n"
					<<  "============================================" << "\n"
					<< 	"Entered Amount: ";
				cin >> balance_modify;
				balance += balance_modify;
				cout << "============================================" << "\n"
					<<  "||            Balance Updated!            ||" << "\n"
					<<  "============================================" << "\n"
					<< 	"Enter any key to continue: ";
				cin >> continue_input;
				continue_input = '\0';
				system("cls");
				break;
				
			case 2:	
				system("cls");
				do {
					cout << "=============================================" << "\n"
						<<  "||How much money are you going to withdraw?||" << "\n"
						<<  "=============================================" << "\n"
						<< 	"Entered Amount: ";
					cin >> balance_modify;
					balance -= balance_modify;
					
					if (balance < 0){
						cout << "\n\n" << "Insufficient balance to withdraw! Please enter the correct amount!" << "\n\n";
					}else {
					cout << "============================================" << "\n"
						<<  "||            Balance Updated!            ||" << "\n"
						<<  "============================================" << "\n"
						<< 	"Enter any key to continue: ";
					cin >> continue_input;
					continue_input = '\0';
					system("cls");
					break;
					}
					
					balance += balance_modify;
					
				}while (true);
				break;
			
			case 3:
				system("cls");
				cout << "=============================================" << "\n"
					<<  "||Name: " << correct_username << "                              ||"<< "\n"
					<<  "=============================================" << "\n"
					<<  "||Balance: P" << balance << "\n"
					<<  "=============================================" << "\n"
					<< 	"Enter any key to continue: ";
				cin >> continue_input;
				continue_input = '\0';
				system("cls");
				break;
				
			case 4:
				system("cls");
				cout << "Signing you off... Goodbye!" << endl;
				break;
				
			default:
				cout << "\n\n" << "Invalid Input! Please enter the correct number!" << "\n\n";
				break;
		}
		
	} while (selection_menu != 4);
	
	return 0;
}

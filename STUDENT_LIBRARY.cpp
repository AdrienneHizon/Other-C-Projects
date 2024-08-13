#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>


void clearconsole() {
    #ifdef _WIN32 
        std::system("cls"); 
    #else
        std::system("clear"); 
    #endif
}

struct student_information{

    std::string name;
    int student_id, grade, age;
    bool check_occupy = false;
};

student_information student[100];


void student_checker(){

    int j;

    for (j = 0; j < 100; j++){

        if (student[j].student_id > 0)
            student[j].check_occupy = true;

    }
}

void create_student(int student_count){

    int i, j, start_slot;

    clearconsole();

    for (i = 0; i < 100; i++){

        if (student[i].check_occupy == false){
            start_slot = i;
            student_count += start_slot;
            break;
        }
    }

    for (j = start_slot; j < student_count; j++){

        std::cout << "Enter the student's information: " << std::endl;

        do {
            std::cout << "\n" << "Student #" << j+1 << std::endl;
            std::cout << "Name: ";
            std::cin.ignore();
            getline(std::cin,student[j].name);
            std::cout << "Age: ";
            std::cin >> student[j].age;

            do {
                std::cout << "Grade: ";
                std::cin >> student[j].grade;

                if (student[j].grade < 0 || student[j].grade > 100)
                    std::cout << "Invalid student grade! Grade should not exceed within 100 and should not be lower than 0!" << "\n";

            } while (student[j].grade < 0 || student[j].grade > 100);


            std::cout << "Student ID: ";
            std::cin >> student[j].student_id;

            if (student[j].student_id == 0)
                std::cout << "\n" << "Student ID must not be zero! Please re-enter your information" << "\n";

        } while (student[j].student_id == 0);

            student[j].check_occupy = true;
    }

    clearconsole();
    std::cout << "Student records successfully created!" << "\n\n";

}


void student_display(){

    int i, student_empty = 0, student_counter, j;
    char student_grade_letter, letter_continue;

    for (i = 0; i < 100; i++){

        if (student[i].check_occupy == true)
            student_counter++;
        else if (student[i].check_occupy == false)
            student_empty++;
    }

    if (student_empty == 100){
        std::cout << "No student records found!" << "\n\n";
        return;
    }

    std::cout << "These are the following student records:" << std::endl;

    for (j = 0; j < student_counter; j++){

        if (student[j].grade >= 90 && student[j].grade <= 100)
            student_grade_letter = 'A';
        else if (student[j].grade >= 80 && student[j].grade <= 89)
            student_grade_letter = 'B';
        else if (student[j].grade >= 50 && student[j].grade <= 79)
            student_grade_letter = 'C';
        else if (student[j].grade < 50)
            student_grade_letter = 'F';


        std::cout << "\n" << "Student #" << j+1 << "\n"
            << "Name: " << student[j].name << "\n"
            << "Age: " << student[j].age << "\n"
            << "Grade: " << student[j].grade << "\n"
            << "Student ID: " << student[j].student_id << "\n"
            << "Status: " << student_grade_letter << std::endl;

    }

    std::cout << "\n" << "Enter any letter to continue: ";
    std::cin >> letter_continue;
    clearconsole();
    letter_continue = '\0';

}

void student_update(){

    int number, update;
    char letter_continue;
    
    do {
        std::cout << "Enter the Student # of the record you're going to update" << "\n"
                << "Student Number: ";
        std::cin >> number;
        number -= 1;

        if (student[number].check_occupy == false){
            clearconsole();
            std::cout << "Student record is not found!" << "\n\n";
            return;
        }
        else
            break;
    } while (true);

    
    do {
        std::cout << "\n" << "What do you want update in this record?" << "\n"
                << "[1] Modify the name of the student" << "\n"
                << "[2] Modify the age of the student" << "\n"
                << "[3] Modify the grade of the student" << "\n"
                << "[4] Modify the ID of the student" << "\n"
                << "[5] Cancel Operation" << "\n"
                << "Entered Option: ";
        std::cin >> update;

        if (update == 5){
            clearconsole();
            return;
        }
        if (update <= 0 || update > 5){
            clearconsole();
            std::cout << "Please enter a valid option!" << std::endl;
        }

    } while (update <= 0 || update > 5);

    switch (update){

        case 1:
            std::cout << "Enter the new name of the student: ";
            std::cin >> student[number].name;
            break;

        case 2:
            std::cout << "Enter the new age of the student: ";
            std::cin >> student[number].age;
            break;
        
        case 3:
            std::cout << "Enter the new grade of the student: ";
            std::cin >> student[number].grade;
            break;

        case 4:
            do {
                std::cout << "Enter the new ID of the student: ";
                std::cin >> student[number].student_id;

                if (student[number].student_id == 0)
                    std::cout << "Student Id cannot be zero! Please re-enter your information!";
            } while (student[number].student_id == 0);
            break;
    }
    

    std::cout << "\n" << "Update successful! Please type any letter to continue: ";
    std::cin >> letter_continue;

    letter_continue = '\0';
    clearconsole();

}

void student_arrange(){

    int i, j, k, slot_arrange;

    for (k = 0; k < 100; k++){

        if (student[k].check_occupy == false){
            slot_arrange = k;
            break;
        }
    }


    for (i = k; i < 100; i++){

        j = i + 1;

        student[i].name = student[j].name;
        student[i].age = student[j].age;
        student[i].grade = student[j].grade;
        student[i].student_id = student[j].student_id;
        student[i].check_occupy = student[j].check_occupy;

    }

}

void student_delete(){

    int number;
    char letter_continue, erase;
    
    do {
        std::cout << "Enter the Student # you're going to delete" << "\n"
                << "Student Number: ";
        std::cin >> number;
        number -= 1;

        if (student[number].check_occupy == false){
            clearconsole();
            std::cout << "Student record is not found!" << "\n\n";
            return;
        }
        else
            break;
    } while (true);

    do {
        std::cout << "Are you sure you want to delete Student #" << number + 1 << "?" << "\n"
                << "Input response (Type Y for yes and N for no): ";
        std::cin >> erase;
        erase = tolower(erase);

        if (erase == 'y' || erase == 'n'){
            if (erase == 'n'){
                clearconsole();
                std::cout << "Delete Cancelled!" << std::endl;
                return;
            }
            else if (erase == 'y')
                break;
        } else
            std::cout << "Invalid response! Please type either Y or N!" << "\n\n";
    } while (true);

        student[number].name = '\0';
        student[number].age = 0;
        student[number].grade = 0;
        student[number].student_id = 0;
        student[number].check_occupy = false;
        student_arrange();

        std::cout << "Student #" << number + 1 << " is successfully deleted! Press any letter to continue: ";
        std::cin >> letter_continue;

        letter_continue = '\0';
        clearconsole();


}


void main_menu(){

    std::cout << "=============================================================="
            <<   "=================Welcome to Student Library!==================" << "\n"
            <<   "NOTE: This program can only record up to 100 students!" << "\n"
            <<   "Please select the following (input the number corresponded):" << "\n"
            <<   "[1] Create a new student record" << "\n"
            <<   "[2] Display student records" << "\n"
            <<   "[3] Update student records" << "\n"
            <<   "[4] Delete student records" << "\n"
            <<   "[5] End program" << "\n"
            <<   "==============================================================" << "\n"
            <<   "Selected option: ";
}

void selection_menu(int input){

    int student_count;

    do{
        switch (input){
            case 1:
                student_checker();
                std::cout << "\n" << "Kindly enter the number of student records you want to create: ";
                std::cin >> student_count;
                create_student(student_count);
                break;

            case 2:
                clearconsole();
                student_checker();
                student_display();
                break;

            case 3:
                clearconsole();
                student_update();
                break;
            
            case 4:
                clearconsole();
                student_delete();
                break;

            case 5:
                clearconsole();
                std::cout << "Goodbye";
                exit(0);
                break;
            
            default:
                std::cout << "Error! Please pick a valid option!" << "\n"
                    << "Selected option: ";
                std::cin >> input;
                break;
        }
    }while (input <= 0 || input > 5);

}



int main(){
    
    int input;


    do{
        main_menu();
        std::cin >> input;
        selection_menu(input);
    } while (input !=5 );
  


    return 0;
}
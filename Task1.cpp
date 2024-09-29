#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

bool check_date(const std::string& date) {
    int start = 0;
    bool feb = false;
    bool month = true;
    bool day = true;
    bool year = true;    
    for (int i = 0; i < date.length() && year; ++i) {
        if (date[i] == '.' && month) {
            int temp_m = stoi(date.substr(start, i));           
            if (temp_m < 1 || temp_m > 12) {
                std::cout << "\nWrong month !";
                return true;
            }
            if (temp_m == 2) {
                feb = true;
            }
            start = i + 1;
            month = false;
        }
        else if (date[i] == '.' && day) {
            int temp_d = stoi(date.substr(start, i));          
            if (feb && (temp_d > 28 || temp_d < 1)) {
                std::cout << "\nWrong day !";
                return true;
            }
            else if (!feb && (temp_d < 1 || temp_d > 31)) {
                std::cout << "\nWrong day !";
                return true;
            }
            start = i + 1;
            day = false;
        }
        else if (!day && year) {
            int temp_y = stoi(date.substr(start,date.length()-1));            
            if (temp_y < 1900 || temp_y > 2024) {
                std::cout << "\nWrong Year!";
                return true;
            }
            year = false;
        }
    }
    if (!(day && month && year)) {
        return false;
    }
    else {
        return true;
    }
}

bool check_sum(const std::string& sum) {
    for (int i = 0; i < sum.length(); ++i) {
        if (sum[i] < '0' || sum[i] > '9') {
            std::cout << "\nWrong input! Enter number!";
            return true;
        }
    }
    return false;
}

bool check_name(const std::string&name) {
    for(int i = 0;i < name.length();++i) {
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <='Z')) {
            continue;
        }
        std::cout<<"\nIncorrect name";
        return true;
    }
    return false;
}

int main() {
    std::ofstream out_file_name("statements.txt",std::ios::app);
    char choice;
    do {
        std::cout << "\n(0) - exit\n(1) - add statemet\nEnter: ";
        std::cin >> choice;
        if (choice == '1') {
            std::string sum;
            std::string new_statements;
            std::string name;
            std::string date;
            do {
                std::cout << "\nEnter first name: ";
                std::cin >> name;
            }while(check_name(name));
            new_statements += name + " ";
            do {
                std::cout << "\nEnter last name: ";
                std::cin >> name;
            }while(check_name(name));
            new_statements += name + " ";
            do {
                std::cout << "\nEnter date (MM.DD.YYYY): ";
                std::cin >> date;
            } while (check_date(date));
            new_statements += date + " ";
            do {
                std::cout << "\nEnter sum: ";
                std::cin >> sum;
            } while (check_sum(sum));
            new_statements += sum;
            out_file_name << new_statements << std::endl;
        }
    } while (choice != '0');
    out_file_name.close();
}
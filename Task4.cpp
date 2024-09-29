#include<iostream>
#include<fstream>
#include<cstdlib>

bool withdraw(int& banknote_c, int& bankN_100, int& bankN_200, int& bankN_500, int& bankN_1000, int& bankN_2000, int& bankN_5000,int sum_d) {
    int bankN_100_copy = bankN_100;
    int bankN_200_copy = bankN_200;
    int bankN_500_copy = bankN_500;
    int bankN_1000_copy = bankN_1000;
    int bankN_2000_copy = bankN_2000;
    int bankN_5000_copy = bankN_5000;
    int sum_d_copy = sum_d;
    while (sum_d_copy != 0) {
        if (bankN_5000_copy != 0 && sum_d_copy >= 5000) {
            sum_d_copy -= 5000;
            --bankN_5000_copy;
        }
        else if (bankN_2000_copy != 0 && sum_d_copy >= 2000) {
            sum_d_copy -= 2000;
            --bankN_2000_copy;
        }
        else if (bankN_1000_copy != 0 && sum_d_copy >= 1000) {
            sum_d_copy -= 1000;
            --bankN_1000_copy;
        }
        else if (bankN_500_copy != 0 && sum_d_copy >= 500) {
            sum_d_copy -= 500;
            --bankN_500_copy;
        }
        else if (bankN_200_copy != 0 && sum_d_copy >= 200) {
            sum_d_copy -= 200;
            --bankN_200_copy;
        }
        else if (bankN_100_copy != 0 && sum_d_copy >= 100) {
            sum_d_copy -= 100;
            --bankN_100_copy;
        }
        else {
            return false;
        }
    }
    while (sum_d != 0) {
        if (bankN_5000 != 0 && sum_d >= 5000) {
            sum_d -= 5000;
            --bankN_5000;
            --banknote_c;
        }
        else if (bankN_2000 != 0 && sum_d >= 2000) {
            sum_d -= 2000;
            --bankN_2000;
            --banknote_c;
        }
        else if (bankN_1000 != 0 && sum_d >= 1000) {
            sum_d -= 1000;
            --bankN_1000;
            --banknote_c;
        }
        else if (bankN_500 != 0 && sum_d >= 500) {
            sum_d -= 500;
            --bankN_500;
            --banknote_c;
        }
        else if (bankN_200 != 0 && sum_d >= 200) {
            sum_d -= 200;
            --bankN_200;
            --banknote_c;
        }
        else if (bankN_100 != 0 && sum_d >= 100) {
            sum_d -= 100;
            --bankN_100;
            --banknote_c;
        }
    }        
    return true;
}

int read_atm(int& banknote_c, int& bankN_100, int& bankN_200, int& bankN_500, int& bankN_1000, int& bankN_2000, int& bankN_5000) {
    int sum = 0;
    std::ifstream in_file_name("atm.bin", std::ios::binary);
    if (!in_file_name.is_open()) {
        std::cout << "\nAtm is empty.";
    }
    else {
        in_file_name.read((char*)&banknote_c, sizeof(int));
        std::cout << "\nCount of banknotes is: " << banknote_c;
        in_file_name.read((char*)&bankN_100, sizeof(int));
        std::cout << "\nCount of banknote value 100 RUB: " << bankN_100;
        in_file_name.read((char*)&bankN_200, sizeof(int));
        std::cout << "\nCount of banknote value 200 RUB: " << bankN_200;
        in_file_name.read((char*)&bankN_500, sizeof(int));
        std::cout << "\nCount of banknote value 500 RUB: " << bankN_500;
        in_file_name.read((char*)&bankN_1000, sizeof(int));
        std::cout << "\nCount of banknote value 1 000 RUB: " << bankN_1000;
        in_file_name.read((char*)&bankN_2000, sizeof(int));
        std::cout << "\nCount of banknote value 2 000 RUB: " << bankN_2000;
        in_file_name.read((char*)&bankN_5000, sizeof(int));
        std::cout << "\nCount of banknote value 5 000 RUB: " << bankN_5000;
        sum = (5000 * bankN_5000) + (2000 * bankN_2000) + (1000 * bankN_1000) + (500 * bankN_500) + (200 * bankN_200) + (100 * bankN_100);
        std::cout << "\nTotal sum is: " << sum << std::endl;
    }
    in_file_name.close();
    return sum;
}

void write_atm(int& banknote_c, int& bankN_100, int& bankN_200, int& bankN_500, int& bankN_1000, int& bankN_2000, int& bankN_5000,char add_or_draw = '+') {   
    while (add_or_draw == '+' && banknote_c < 1000) {
        int temp = rand() % 5001;
        if (temp >= 4000) {
            banknote_c++;
            bankN_5000++;
        }
        else if (temp >= 2000) {
            banknote_c++;
            bankN_2000++;
        }
        else if (temp >= 1000) {
            banknote_c++;
            bankN_1000++;
        }
        else if (temp >= 500) {
            banknote_c++;
            bankN_500++;
        }
        else if (temp >= 200) {
            banknote_c++;
            bankN_200++;
        }
        else {
            banknote_c++;
            bankN_100++;
        }
    }   
    std::ofstream out_file_name("atm.bin", std::ios::binary);
    out_file_name.write((char*)&banknote_c, sizeof(int));
    out_file_name.write((char*)&bankN_100, sizeof(int));
    out_file_name.write((char*)&bankN_200, sizeof(int));
    out_file_name.write((char*)&bankN_500, sizeof(int));
    out_file_name.write((char*)&bankN_1000, sizeof(int));
    out_file_name.write((char*)&bankN_2000, sizeof(int));
    out_file_name.write((char*)&bankN_5000, sizeof(int));
    out_file_name.close();
}

int main() {
    int banknote_c = 0;
    int bankN_100 = 0;
    int bankN_200 = 0;
    int bankN_500 = 0;
    int bankN_1000 = 0;
    int bankN_2000 = 0;
    int bankN_5000 = 0;   
    int sum = 0;
    char choice;
    do {
        sum = read_atm(banknote_c, bankN_100, bankN_200, bankN_500, bankN_1000, bankN_2000, bankN_5000);
        std::cout << "\nChoice option.\n(0) - Exit\n(+) - add banknote\n(-) - withdraw banknote\nEnter: ";
        std::cin >> choice;
        if (choice == '+') {
            write_atm(banknote_c, bankN_100, bankN_200, bankN_500, bankN_1000, bankN_2000, bankN_5000);
        }
        else if (choice == '-') {                
            int sum_d;
            std::cout << "\nEnter that sum you want withdraw, now in atm: " << sum << "RUB";
            std::cout << "\nEnter: ";
            std::cin >> sum_d;
            if(!std::cin) {
                std::cerr<<"\nError!";
                return 1;
            }
            if (sum_d % 100 != 0 || sum_d < 100 || sum_d > sum) {
                std::cout << "\nThat sum cannot be withdraw.";
            }
            else {
                if (withdraw(banknote_c, bankN_100, bankN_200, bankN_500, bankN_1000, bankN_2000, bankN_5000, sum_d)) {
                    std::cout << "\nYou have successfully withdrawn " << sum_d << " RUB";
                    write_atm(banknote_c, bankN_100, bankN_200, bankN_500, bankN_1000, bankN_2000, bankN_5000, '-');
                }
                else {
                    std::cout << "\nYou cannot withdrawn that sum";
                }
            }            
        }        
    } while (choice != '0');   
}
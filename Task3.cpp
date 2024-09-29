#include<iostream>
#include<fstream>

int main () {
    std::ifstream in_file_name("river.txt");
    std::ofstream out_file_name("basket.txt");

    if(!in_file_name.is_open()) {
        std::cerr<<"\nFail to open file!";
        return 1;
    }
    std::string choice;
    int count = 0;
    do {
        std::cout<<"\nFinish catching (0)"<<std::endl;
        std::cout<<"What kind of fish do you want to catch ?\nEnter: ";
        std::cin >> choice;
        if(choice != "0") {
            in_file_name.seekg(0);
            int temp_int = 0;
            while(!in_file_name.eof() && temp_int == 0) {
                std::string temp_str;
                in_file_name >> temp_str;
                if(temp_str == choice) {
                    ++temp_int;
                    ++count;
                    out_file_name << choice << std::endl;                    
                }
            }            
            if(temp_int == 0) {
                std::cout<<"\nYou couldn't catch "<< choice <<" in river"<<std::endl;
            }
            else {
                std::cout<<"\nYot catch " << choice << "!" << std::endl;
            }      
        }
    }while(choice != "0");
    std::cout<<"\nTotal cathes fish count: "<<count;
    in_file_name.close();
    out_file_name.close();
}
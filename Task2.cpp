#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<vector>

int main () {
    int width = 0;
    int height = 0;
    std::vector<std::vector<int>> array;
    std::ofstream out_file_name("picture.txt");
    std::srand(std::time(nullptr));
    std::cout<<"Enter width: ";
    std::cin>>width;
    std::cout<<"\nEnter height: ";
    std::cin>>height;
    array.resize(height);
    for(int i = 0;i < height;i++) {     
        for(int j = 0;j < width;++j) {         
            array[i].push_back(rand()%2);           
        }        
    }
    for(int i = 0;i < height;++i) {
        for(int j = 0;j < width;++j) {
            out_file_name << array[i][j];   
        }        
        out_file_name<<std::endl;
    }
    out_file_name.close();
}
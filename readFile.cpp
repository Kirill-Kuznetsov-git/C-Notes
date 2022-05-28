#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream file("example.txt");
    fstream res("res.txt");
    int n, tmp; file >> n;
    while (!file.eof()){
        file >> tmp;
        res << tmp * 2;
        cout << tmp;
    }
    return 0;
}
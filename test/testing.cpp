#include <conio.h>

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    while (true)
        if (_kbhit()){
            char key = _getch();
            if (key == -32){
                key = _getch();
                cout << int(key) << endl;
            }
        }


    return 0;
}

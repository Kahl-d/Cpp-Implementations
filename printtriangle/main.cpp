#include <iostream>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int num){
    if(num == 1)
    {
        // add 9 spaces adn print *
        for(int i = 0; i < 9; i++)
        {
            cout << " ";
        }
        cout << " * " << endl;

    }
    else
    {
        DrawTriangle(num -2);
        // add 9 - num spaces and print *
        for(int i = 0; i < 9 - num ; i++)
        {
            cout << " ";
        }
        for(int i = 0; i < num; i++)
        {
            cout << " * ";
        }
        cout << endl;
    }

}


int main() {
    int baseLength;

    cin >> baseLength;
    DrawTriangle(baseLength);
    return 0;
}
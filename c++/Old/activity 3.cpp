#include <iostream>
#include <windows.h>

using namespace std;

int main() {
  cout << "Loading";
    for (int i = 0; i < 5; i++) {
        cout << "." << flush; // Flush the output buffer to display the dots immediately
        Sleep(1000); // Pause for 1000 milliseconds 

    }

    cout<<"done!"<<endl;
    return 0;


}

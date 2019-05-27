#include <iostream>
#include <windows.h>

using namespace std;

/*typedef struct _RECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT;*/

int main(int argc, char const *argv[]){
    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r);
    MoveWindow(console,r.left,r.top,700,500,TRUE);

    cout << "Teste" << endl;
    system("pause");
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "System_meneg.h"
#include <windows.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "Interf.h"
using namespace std;
bool workable;
bool offmenu;
int iItem;
int nLast;

system_meneg* meneg = new system_meneg();
void ShowMenu(int iItem) {
    system("cls");
    printf("\n\n\t\t%s1 - Create new profile\n", iItem == 1 ? "->" : " ");
    printf("\t\t%s2 - Entering to created profile\n", iItem == 2 ? "->" : " ");
    printf("\t\t%s3 - Exit\n", iItem == 3 ? "->" : " ");
}
void StartInterfaceMenu()
{
    do {
        ShowMenu(iItem);
        offmenu = false;
        while (offmenu == false)
        {
            if (GetAsyncKeyState(VK_UP))
            {
                keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
                if (0 < iItem - 1)
                    iItem = iItem - 1;
                else
                    iItem = nLast;
                ShowMenu(iItem);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
                if (iItem < nLast)
                    iItem = iItem + 1;
                else
                    iItem = 1;
                ShowMenu(iItem);
            }
            if (GetAsyncKeyState(VK_RETURN))
            {
                keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
                ShowMenu(iItem);
                switch (iItem)
                {
                case 1:
                    printf("Run \"Create new profile\"\n");
                    meneg->CreateAccount();
                    Sleep(2000);
                    offmenu = true;
                    break;
                case 2:
                    char c;
                    printf("Run \"Entering to created profile\"\n");
                    Sleep(2000);
                    cout << "\n\t\tYo are: " << endl;
                    cout << "\n\t1- custom;" << endl;
                    cout << "\n\t2- employee;" << endl;
                    cin >> c;
                    if (c == 1) {
                        meneg->SignINCustom();
                    }
                    else if (c == 2) {
                        meneg->SignINCustom();
                    }
                    else {
                        cout << "\nUncorrect menu" << endl;
                        offmenu = true;
                        break;
                    }
                    offmenu = true;
                    break;
                case 3:
                    printf("Exit...\n");
                    workable = false;
                    offmenu = true;
                    Sleep(1000);
                    break;
                }
            }
        }
    } while (workable == true);
    cout << "\n\tProgram ended!";
}

int main()
{
  
   StartInterfaceMenu();
    return 0;
}



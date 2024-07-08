#include "Directory.h"
#include "SeqList2.h"
using namespace std;


void Menu()
{
    Dir con;
    DirInit(con);
    int select = 0;
    while (true)
    {
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Find" << endl;
        cout << "4. Modify" << endl;
        cout << "5. Show" << endl;
        cout << "0. Exit" << endl;
        cout << "Please select: ";
        cin >> select;
        switch (select)
        {
        case 1:
            DirAdd(con);
            break;
        case 2:
            DirDel(con);
            break;
        case 3:
            DirFind(con);
            break;
        case 4:
            DirModify(con);
            break;
        case 5:
            DirShow(con);
            break;
        case 0:
            DirDestroy(con);
            return;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    }
    //! another way to imitate menu
    // int select = 1;
    // do
    // {
    //     /* code */
    //     case 0:
    //         DirDestroy(con);
    //         break;  //* only break out of switch
    // } while (select != 0)
}

int main()
{
    Menu();
    return 0;
}
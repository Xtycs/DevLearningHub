#include "Directory.h"
#include "SeqList2.h"
using namespace std;

void DirInit(Dir &con)
{
    SLInit(con);
}

void DirDestroy(Dir &con)
{
    SLDestroy(con);
}

void DirAdd(Dir &con)
{
    PerInfo temp;
    cout << "Please enter the name: ";
    cin >> temp.name;
    cout << "Please enter the gender: ";
    cin >> temp.gender;
    cout << "Please enter the age: ";
    cin >> temp.age;
    cout << "Please enter the telephone number: ";
    cin >> temp.tel;
    cout << "Please enter the address: ";
    cin >> temp.addr;

    SLPushback(con, temp);//reuse of the function in SeqList2.h
}

int FindByName(const Dir &con, char *name)
{
    for (int i = 0; i < con.size; i++)
    {
        if (strcmp(con.arr[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void DirDel(Dir &con)
{
    assert(con.size);

    char name[NAME_MAX];
    cout << "Please enter the name you want to delete: ";
    cin >> name;
    int result = FindByName(con, name);

    if (result == -1)
    {
        cout << "The name is not found." << endl;
    }
    else
    {
        SLErase(con, result);
        cout << "The name is deleted." << endl;
    }
}

void DirPrint(const Dir &con)
{
    for (int i = 0; i < con.size; i++)
    {
        cout << "Name: " << con.arr[i].name << endl;
        cout << "Gender: " << con.arr[i].gender << endl;
        cout << "Age: " << con.arr[i].age << endl;
        cout << "Telephone number: " << con.arr[i].tel << endl;
        cout << "Address: " << con.arr[i].addr << endl;
    }
}

void DirModify(Dir&con)
{
    assert(con.size);

    char name[NAME_MAX];
    cout << "Please enter the name you want to modify: ";
    cin >> name;
    int result = FindByName(con, name);

    if(result ==-1)
    {
        cout <<"The name is not found."<<endl;
    }
    else
    {
        PerInfo temp;
        cout << "Please enter the new name: ";
        cin >> temp.name;
        cout << "Please enter the new gender: ";
        cin >> temp.gender;
        cout << "Please enter the new age: ";
        cin >> temp.age;
        cout << "Please enter the new telephone number: ";
        cin >> temp.tel;
        cout << "Please enter the new address: ";
        cin >> temp.addr;
        SLInsert(con, result, temp);

        cout << "The name is modified." << endl;
    }
}

void DIrFind(const Dir &con)
{
    assert(con.size);

    char name[NAME_MAX];
    cout << "Please enter the name you want to find: ";
    cin >> name;
    int result = FindByName(con, name);
    if (result == -1)
    {
        cout << "The name is not found." << endl;
    }
    else
    {
        cout << "Name: " << con.arr[result].name << endl;
        cout << "Gender: " << con.arr[result].gender << endl;
        cout << "Age: " << con.arr[result].age << endl;
        cout << "Telephone number: " << con.arr[result].tel << endl;
        cout << "Address: " << con.arr[result].addr << endl;
    }
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *front = NULL;
        ListNode *temphead = NULL;
        ListNode *tail = NULL;
        ListNode *temp = head;
        while(temp)
        {
            if(temp->val != val)
            {
                if(temphead == tail)
                {
                    temphead=tail=temp;
                    front=temp;
                }
                else
                {
                    temphead=tail=temp;
                    temphead->next=tail;
                }
            }
            temp=temp->next;
        }
        return front;
    }
};
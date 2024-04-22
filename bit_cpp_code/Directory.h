//define the contact information
//#include "SeqList2.h" //never include each other, may result in endless loop
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

typedef struct PersonInfo
{
    char name[NAME_MAX];
    char gender[GENDER_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];
}PerInfo;

//todo The process is to put PerInfo into SeqList, then rename it as a Directory, use typedef two times.
typedef struct SeqList Dir;
//  typedef SL Dir; //this is wrong since SL is a typedefined name, not a variable name
//  #define SL Dir;
//  typedef SL Dir;

//need to use the method in sequence list.
void DirInit(Dir &con);
void DirDestroy(Dir &con);

void DirAdd(Dir &con);
void DirDel(Dir &con);

void DirFind(Dir &con);
void DirModify(Dir &con);

void DirShow(const Dir &con);

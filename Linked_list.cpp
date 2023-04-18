#include <iostream>
#include <iomanip>

#define NAME 50
#define ID 9
using namespace std;

struct Student {
    char id[ID];
    char name[NAME];
    float gpa;
};

struct Node {
    Student st;
    Node* link;
};

typedef struct Node* node;

node makenode();
void insert(node &head);
void print(node head);
void prthead();
void clear();
void prtline(int x);
void printST(Student st);
void sort(node head);
float findmax(node head);
float findmin(node head);
void max(node head);
void min(node head);

int main() {
    node head = NULL;
    int n = 0;
    char inpt;
    
    while(1) {
        prtline(66);
        cout << "*1. Import student list.                                         *\n";
        cout << "*2. Print all student lists.                                     *\n";
        cout << "*3. Find student has highest GPA.                                *\n";
        cout << "*4. Find student has lowest GPA.                                 *\n";
        cout << "*5. Sort the list of students in descending order of GPA.        *\n";
        cout << "*0. EXIT.                                                        *\n";
        prtline(66);

        cout << "\nEnter the number to execute the command: ";        
        cin >> inpt;  
        getchar();     
        
        switch(inpt) {
            case '1':
                insert(head);
                cout << "\nImport student list successful!\n";
                getchar();
                clear();
                break;
            case '2':
                if(head == NULL) cout << "\nList of student has not imported!\n";  
                else print(head);
                clear();
                break;
            case '3':
                if(head != NULL) {
                    cout << "\nStudent who has highest GPA is:\n\n";
                    max(head);
                }else cout << "\nList of student has not imported!\n";
                clear();
                break;
            case '4':
                if(head != NULL) {
                    cout << "\nStudent who has lowest GPA is:\n\n";
                    min(head);       
                }else cout << "\nList of student has not imported!\n";               
                clear();
                break;
            case '5':
                if(head != NULL) {
                    cout << "\nList of student after sort in increasing of GPA:\n\n";
                    sort(head);
                }else cout << "\nList of student has not imported!\n";
                print(head);
                clear();
                break;
            case '0':
                return 0;
            default:
                cout << "\nYou can only enter the number on the command table.\n";
                clear();
                break;
        }
    }
}

node makenode() {
    Student a;
    cout << "\nImport iformation for student:\n";
    cout << "\nID: ";    
    cin >> a.id;
    getchar();  
    cout << "Name: ";    
    cin.get(a.name, NAME);
    getchar();    
    cout << "GPA: "; cin >> a.gpa;
    
    node tmp = new Node;
    tmp->st = a;
    tmp->link = NULL;

    return tmp;
}

void insert(node &head) {
    node tmp = makenode();
    if(head == NULL) head = tmp;
    else {
        node p = head;
        while(p->link != NULL) {
            p = p->link;
        }
        p->link = tmp;
    }
}

void print(node head) {
    prthead();
    while(head != NULL) {
       printST(head->st);
       head = head->link;
    }
    prtline(48);
}

void clear() {
    cout << "\nPress ENTER to continue...";
    getchar();
    cout << "\x1b[2J";
    cout << "\033[0;0H";
}

void prthead() {
    prtline(48);
    cout << "|" << setw(12) << "ID   |" << setw(28) << "Name            |" << setw(7) << "GPA |" << endl;
    prtline(48);
}

void prtline(int x) {
    for(int i = 1; i <= x; i++)
        cout << "*";
    cout << endl;
}

void printST(Student st) {
    cout << "|" << setw(10) << st.id << " |" << setw(25 ) << st.name << "  |" << setw(5) << st.gpa << " |" << endl;   
}

void sort(node head) {
    for(node i = head; i != NULL; i = i->link) {
        node min = i;
        for(node j = i->link; j != NULL; j = j->link) {
            if(min->st.gpa > j->st.gpa) min = j;
        }
        Student tmp = min->st;
        min->st = i->st;
        i->st = tmp;
    }
}

float findmax(node head) {
    float max = head->st.gpa;
    while(head != NULL) {
        if(max < head->st.gpa) max = head->st.gpa;
        head = head->link;
    }

    return max;
}

float findmin(node head) {
    float min = head->st.gpa;
    while(head != NULL) {
        if(min > head->st.gpa) min = head->st.gpa;
        head = head->link;
    }

    return min;
}

void max(node head) {
    float max = findmax(head);
    prthead();
    for(node p = head; p != NULL; p = p->link)
        if(p->st.gpa == max) printST(p->st);
    prtline(48);
}

void min(node head) {
    float min = findmin(head);
    prthead();
    for(node p = head; p != NULL; p = p->link)
        if(p->st.gpa == min) printST(p->st);
    prtline(48);
    
}
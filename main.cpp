#include <iostream>
#include<fstream>
#include <iomanip>
#include<cstring>
#include<cctype>
#include<cstdlib>

using namespace std;


struct Nodetype;
typedef Nodetype* Nodeptr;

struct Nodetype
{
    int dognumber;
    char name[20];
    char breed[50];
    int position;
    Nodeptr Left, Right;
    int numnodes;
};



class Circular_Doubly_Linked_List{
private:
    Nodeptr Dogs;
public:

    Circular_Doubly_Linked_List();
    ~Circular_Doubly_Linked_List();
    void Addnewnode();
    void PrintList();
    void PrintFirst();
    void PrintLast();
    void Deletenode();
    void Replacenode();
    void Reposition();
    void Printanode();
    Nodeptr Search(int carnum);
    Nodeptr Search2(int pos);
    void Announce_Winner();
    bool Empty();
};

ofstream outs;

int main()
{
    char choice[3];
    char ch1,ch2;

    Circular_Doubly_Linked_List Dogs;

    outs.open("dogs.txt");


    void menu();

    void describeProgram();

    describeProgram();

    menu();
    cout<<endl;
    strcpy(choice,"");
    cout<<"Enter your choice."<<endl;
    cin.getline(choice,3);
    ch1 = choice[0];
    ch1 = toupper(ch1);
    ch2 = choice[1];
    ch2 = toupper(ch2);
    while (ch1 != 'Q')
    {
        switch(ch1)
        {
            case 'C':Dogs.Addnewnode();
                break;
            case 'P':Dogs.PrintList();
                break;
            case 'F': Dogs.PrintFirst();
                break;
            case 'L':Dogs.PrintLast();
                break;
            case 'D':switch(ch2)
                {
                    case 'R':Dogs.Replacenode();
                        break;
                    case '\0': Dogs.Deletenode();
                        break;
                }
                break;
            case 'R': Dogs.Reposition();
                break;
            case 'S': Dogs.Printanode();
                break;
            default : cout<<"Invalid choice. Try again!"<<endl;
        }
        cout<<endl;
        menu();
        for(int i= 0; i<3; i++)
        {
            choice[i]=' ';
        }
        cout<<"Please enter your choice."<<endl;
        cin.getline(choice,3);
        ch1 = choice[0];
        ch1 = toupper(ch1);
        ch2 = choice[1];
        ch2 = toupper(ch2);
    }
    Dogs.Announce_Winner();
    outs.close();
    system("PAUSE");
    return 0;
}
void describeProgram()
{
    cout<<"This program is a dog competition program"<< endl;
    cout<< "Create list of dogs competing in Best of Show."<<endl;
    cout<<"Print the list of dogs by position in line."<<endl;
    cout<<"Print the id, name, and breed of first place dog."<<endl;
    cout<<" Print the id, name, and breed of last place dog."<<endl;
    cout<<" Deletes a dog to be identified by id number."<<endl;
    cout<<"Replace a dog whose id number you specify."<<endl;
    cout<<"Allows to reposition a dog in the line."<<endl;
    cout<<"Show the position,id,name,breed of dog speicifed by id."<<endl;
    cout<<"Displays the winner"<<endl;
    cout<<endl;
}

void menu()
{
    cout<<"C or c    --- Create list of dogs competing in Best of Show."<<endl;
    cout<<"P or p    --- Print the list of dogs by position in line."<<endl;
    cout<<"F or f    --- Print the id, name, and breed of first place dog."<<endl;
    cout<<"L or l    --- Print the id, name, and breed of last place dog."<<endl;
    cout<<"D or d    --- Deletes a dog to be identified by id number."<<endl;
    cout<<"DR or dr  --- Replace a dog whose id number you specify."<<endl;
    cout<<"R or r    --- Allows the judge to reposition a dog in the line."<<endl;
    cout<<"S or s    --- Show the position,id,name,breed of dog speicifed by id."<<endl;
    cout<<"Q or q    --- Quit the program and announce the winner."<<endl;
    cout<<endl;
    return;
}

Circular_Doubly_Linked_List::Circular_Doubly_Linked_List()
{
    Dogs = new Nodetype;
    Dogs->Right = Dogs;
    Dogs->Left = Dogs;
    Dogs->numnodes = 0;
    Dogs->position = 0;

}

Circular_Doubly_Linked_List::~Circular_Doubly_Linked_List()
{
    Nodeptr p;

    while(Dogs->Right!= Dogs && Dogs->Left!= Dogs)
    {
        p = Dogs->Right;
        p->Left->Right = p->Right;
        p->Right->Left = p->Left;
        delete p;
    }
    cout<<"Circular Doubly-Linked List, Dogs, has been reallocated to the heap."
        <<endl;
    system("PAUSE");
}

void Circular_Doubly_Linked_List::Addnewnode()
{
    Nodeptr p,q;
    int dognum;
    int count;

    cout<<"Enter the dog number of the dog (-1 to stop):";
    cin>>dognum;
    count = 0;
    while(dognum != -1)
    {
        p = Search(dognum);
        if (p != NULL)
            cout<<"This dog is already in the line!"<<endl;
        else
        {
            count++;
            q = new Nodetype;
            q->dognumber = dognum;
            cin.ignore();
            cout<<"Enter the dog's name:";
            cin.getline(q->name,20);
            cout<<"Enter the breed of the dog:";
            cin.getline(q->breed,50);
            q->position = count;
            p = Dogs->Left;
            q->Right = Dogs;
            q->Left = p;
            p->Right = q;
            Dogs->Left = q;
            Dogs->numnodes++;
        }
        cout<<endl;
        cout<<"Enter dog number of the dog(-1 to stop):";
        cin>>dognum;
    }
    cin.ignore();
    return;
}

void Circular_Doubly_Linked_List::PrintList()
{
    Nodeptr p;

    p = Dogs;
    if (Empty())
        cout<<"Empty List!"<<endl;
    else
    {
        cout<<"Here is your current list of dogs :"<<endl<<endl;
        outs<<"Here is your current list of dogs:"<<endl<<endl;

        do
        {
            p = p->Right;
            cout<<right<<setw(4)<<p->position<<setw(16)<<p->dognumber
                <<setw(9)<<" "<<left<<setw(25)<<p->name<<setw(25)<<p->breed<<endl;
            outs<<right<<setw(4)<<p->position<<setw(16)<<p->dognumber
                <<setw(9)<<" "<<left<<setw(25)<<p->name<<setw(25)<<p->breed<<endl;
        }
        while (p->Right !=Dogs);
    }

    return;
}

void Circular_Doubly_Linked_List::PrintFirst()
{

    if(Empty())
        cout<<"Empty List!"<<endl;
    else
    {
        cout<<endl;
        cout<<"The client at the head of the list is:\n";
        cout<<"#"<<Dogs->Right->dognumber<<": "<<Dogs->Right->name<<endl;
        outs<<"The client at the head of the list is:\n";
        outs<<"#"<<Dogs->Right->dognumber<<": "<<Dogs->Right->name<<endl;
    }
    cout<<endl;
    outs<<endl;

    return;
}

void Circular_Doubly_Linked_List::PrintLast()
{

    if (Empty())
        cout<<"Empty List!"<<endl;
    else
    {
        cout<<endl;
        cout<<"The client at the end of the list is:\n";
        cout<<"#"<<Dogs->Left->dognumber<<": "<<Dogs->Left->name<<endl;
        outs<<"The client at the end of the list is:\n";
        outs<<"#"<<Dogs->Left->dognumber<<": "<<Dogs->Left->name<<endl;
    }
    cout<<endl;
    outs<<endl;

    return;
}
void Circular_Doubly_Linked_List::Deletenode()
{
    int dognum;
    int count;
    Nodeptr p;

    if (Empty())
        cout<<"Empty List!"<<endl;
    else
    {
        cout<<"Enter dog number of the dog you wish to delete."<<endl;
        cin>>dognum;
        cin.ignore();
        p = Search(dognum);
        if (p==NULL)
            cout<<"The dog is not in the line!"<<endl;
        else
        {
            p->Left->Right = p->Right;
            p->Right->Left = p->Left;
            delete p;
            Dogs->numnodes--;
            cout<<"Dog # "<<dognum<<" removed from the line!"<<endl<<endl;
            outs<<"Dog # "<<dognum<<" removed from the line!"<<endl<<endl;
            p = Dogs->Right;
            count = 0;
            while(p !=Dogs)
            {
                count++;
                p->position = count;
                p = p->Right;
            }
        }
    }
    return;
}

void Circular_Doubly_Linked_List::Printanode()
{
    int dognum;
    Nodeptr p;

    if (Empty())
        cout<<"Empty List!"<<endl;
    else
    {
        cout<<"Enter dog number of the dog."<<endl;
        cin>>dognum;
        cin.ignore();
        p = Search(dognum);
        if (p == NULL)
            cout<<"The dog is not in the line!"<<endl;
        else
        {

            cout<<endl;
            cout<<"Position #"<<p->position<<":"<<"Dog number "<<p->dognumber
                <<" "<<p->name<<" "<<p->breed<<"."
                <<endl<<endl;
            outs<<endl;
            outs<<"Position #"<<p->position<<":"<<"Dog number "<<p->dognumber
                <<" "<<p->name<<" "<<p->breed<<"."
                <<endl<<endl;
        }
    }
    return;
}

void Circular_Doubly_Linked_List::Replacenode() {
    Nodeptr p,q;
    int tracker;
    int dognum;


    if (Empty())
        cout<<"Empty List!"<<endl;
    else
    {

        cout<<"Enter Dog id to replace."<<endl;
        cin>>dognum;
        cin.ignore();
        p = Search(dognum);
        if (p==NULL)
            cout<<"NO DATA"<<endl;
        else
        {
            p->Left->Right = p->Right;
            p->Right->Left = p->Left;
            delete p;
            Dogs->numnodes--;
            cout<<"Dog: "<<dognum<<" removed "<<endl<<endl;
            p = Dogs->Right;
            tracker = 0;
            if(p != Dogs)
            {
                tracker++;
                p->position = tracker;
                p = p->Right;
                //here is where it now replaces the dog with a new one
                cout<<"Enter the new number of the dog (-1 to stop):";
                cin>>dognum;
                tracker = 0;
                while(dognum != -1)
                {
                    p = Search(dognum);
                    if (p != Dogs && p != NULL)
                        cout<<"This dog is already in the line!"<<endl;
                    else
                    {
                        tracker++;
                        q = new Nodetype;
                        q->dognumber = dognum;
                        cin.ignore();
                        cout<<"Enter the dog's name:";
                        cin.getline(q->name,20);
                        cout<<"Breed of the dog:";
                        cin.getline(q->breed,50);
                        q->position = tracker;
                        p = Dogs->Left;
                        q->Right = Dogs;
                        q->Left = p;
                        p->Right = q;
                        Dogs->Left = q;
                        Dogs->numnodes++;
                    }
                    break;
                }
                cout<<endl;
                cout<<"Enter dog number (-1 to stop):";
                cin>>dognum;
                cin.ignore();
            }
        }
    }
    return;
}
void Circular_Doubly_Linked_List::Reposition()
{
    int tracker;
    int currpos;
    int newpos;
    Nodeptr p,q;

    if (Empty())
        cout<<"Node is empty"<<endl;


    else {
        cout << "Enter the dog's position:" << endl;
        cin >> currpos;
        cin.ignore();
        //we want to use search 2 function for q
        q = Search2(currpos);
        if (q == NULL) {
            cout << "No Data in the position" << endl;
            outs << "No Data in the positon " << endl;
        }
        else {
            cout << "Enter reposition position" << endl;
            cin >> newpos;
            cin.ignore();
//we want to use search 2 function
            p = Search2(newpos);
            if (p == NULL) {
                cout << "No data in position" << endl;
                outs << "No data in position" << endl;
            }
            else {
                if(newpos > q->position) {

                    q->Left->Right = q->Right;
                    q->Right->Left = q->Left;
                    q->Left = p;
                    q->Right = p->Right;

                    p->Right->Left = q;
                    p->Right = q;
                    p = Dogs->Right;

                    tracker = 0;

                    while (p != Dogs) {
                        tracker= tracker + 1;
                        p->position = tracker;
                        p = p->Right;
                    }
                }
                else {

                    q->Left->Right = q->Right;
                    q->Right->Left = q->Left;

                    q->Right = p;
                    q->Left = p->Left;

                    p->Left->Right = q;
                    p->Left = q;

                    p = Dogs->Right;
                    tracker = 0;

                    while (p != Dogs) {
                        tracker= tracker +1;
                        p->position = tracker;
                        p = p->Right;
                    }
                }
            }
        }
    }
    return;
}

Nodeptr Circular_Doubly_Linked_List::Search(int dognum)
{
    bool found = false;
    Nodeptr p;

    if (Empty())
        return NULL;
    else
    {
        p = Dogs->Right;
        do
        {
            if (dognum == p->dognumber)
                found = true;
            else
                p = p->Right;

        }while (!found &&(p != Dogs));
        if (p != Dogs)
            return p;
        else
            return NULL;
    }
}


Nodeptr Circular_Doubly_Linked_List::Search2(int pos)
{
    bool found = false;
    Nodeptr p;

    if (Empty())
        return NULL;
    else
    {
        p = Dogs->Right;
        do
        {
            if (pos == p->position)
                found = true;
            else
                p = p->Right;

        }while (!found &&(p != Dogs));
        if (p != Dogs)
            return p;
        else
            return NULL;
    }
}


bool Circular_Doubly_Linked_List::Empty()
{
    if ((Dogs->Right == Dogs) && (Dogs->Left == Dogs))
        return true;
    else
        return false;
}
void Circular_Doubly_Linked_List::Announce_Winner()
{
    cout<<"The Dog that wins is: "<<Dogs->Right->dognumber<<": ";
    cout<<Dogs->Right->name<<endl;
    outs<<"The Dog that wins is: "<<Dogs->Right->dognumber<<": ";
    outs<<Dogs->Right->name<<endl;
    return;
}

/*Lets make a library for college or university plz like and subscribe*/
#include<iostream>
using namespace std;
class Book{
    private:
    string title;
    bool isissued;
    public:
    Book(){
        isissued=false;
    }
void addbook(){
    cout<<"Enter Your Book Title : ";
    cin>>title;
    isissued=false;
    cout<<"Book Added Successfully : ";
}
void issuebook(){
    if (isissued)
    {
        cout<<"Book Already Issued";
    }else
    {
        isissued=true;
        cout<<"Book Issued";
    }
}

void returnbook(){
    if (!isissued)
    {
        cout<<"Book Return";
    }
}
void display(){
    cout<<"------Book Details------"<<endl;
    cout<<"Title : "<<title<<endl;
    if (isissued)
    {
        cout<<"Status : Issued"<<endl;
    }else
    {
        cout<<"Status : Available"<<endl;
    }
    
    
}

};
int main(){
    Book a1;
    int choice;
    while (true)
    {
        cout<<"-----Menu-------\n";
        cout<<"1.Add Book\n";
        cout<<"2.Issue Book\n";
        cout<<"3.return Book\n";
        cout<<"4.show Book\n";
        cout<<"5.--Exit--\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
        if (choice==1)
        {
            a1.addbook();
        }else if (choice==2)
        {
            a1.issuebook();
        }else if (choice==3)
        {
            a1.returnbook();
        }else if (choice==4)
        {
            a1.display();
        }else if (choice==5)
        {
            break;
        }else
        
        {
            cout<<"invalid choice";
        }
        
        
        
        
        
    }
    
}
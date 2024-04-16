#include<iostream>
#include<iomanip>
using namespace std;

class literature {
    protected :
    int u_id;
    string title;
    public : 
    void getdata(){
        cout<<"Enter the unique id : ";
        cin>>u_id;
        cout<<"Enter the title : ";
        cin>>title;
    }
    void display(){
        cout<<"ID : "<<u_id<<endl;
        cout<<"Title : "<<title<<endl;
    }
};
// here we are going to inherit virtual because the data of base is inherited many time so to prevent copies of base class data more than one time we have used this virtual base class concept.

class e_literature : virtual protected literature{
    protected :
    string DOI;
    public : 
    void getdata(){
        
        cout<<"Enter the link : ";
        cin>>DOI;
    }
    void display(){
        cout<<"DOI : "<<DOI<<endl;
    }
};

class hard_bound : virtual protected literature {
    protected :
    int copies;
    public : 
    void getdata(){
        cout<<"ENter the no. of copies: ";
        cin>>copies;
    }
    void display(){
        cout<<"no. of copies are: "<<copies<<endl;
    }
};

class book : protected e_literature , protected hard_bound{
    protected :
    int ISBN;
    char choice;
    public : 
    void getdata(){
        cout<<"** Add book data ****"<<endl;
        literature ::getdata();
        cout<<"Enter ISBN number: ";
        cin>>ISBN;
        cout<<"(E) copy or (H)ard bound : ";
        cin>>choice;
        
        switch (choice)
        {
        case 'H': 
            hard_bound :: getdata();
            break;
        case 'E' : 
            e_literature ::getdata();
            break;
        default:
            cout<<"invalid choice!"<<endl;
            break;
        }
    }
    void display(){
        cout<<"-------------------------------------"<<endl;
        literature :: display();

        switch (choice)
        {
        case 'H': 
            hard_bound :: display();
            break;
        case 'E' : 
            e_literature :: display();
            break;
        default:
            cout<<"invalid choice!"<<endl;
            break;
        }
        cout<<"ISBN number: "<<ISBN<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    void display_list(){
        cout<<setw(10)<<left<<u_id;
        cout<<setw(30)<<left<<title;
        if(choice == 'H'){
        cout<<setw(10)<<left<<copies<<" copies"<<endl;
        }
        else if(choice == 'E'){
             cout<<setw(10)<<left<<DOI<<endl;
        }
    }
   
};
class magazine : protected e_literature , protected hard_bound{
    protected :
    int ISSN;
    char choice;
    public : 
    void getdata(){
        cout<<"** Add magazine data ****"<<endl;
        literature ::getdata(); 
        cout<<"Enter ISSN number: ";
        cin>>ISSN;
        cout<<"(E) copy or (H)ard bound : ";
        cin>>choice;
        switch (choice)
        {
        case 'H': 
            hard_bound :: getdata();
            break;
        case 'E' : 
            e_literature ::getdata();
            break;
        default:
            cout<<"invalid choice!"<<endl;
            break;
        }
    }
    void display(){
        cout<<"----------------------------------------"<<endl;
        literature ::display();
        switch (choice)
        {
        case 'H': 
            hard_bound :: display();
            break;
        case 'E' : 
            e_literature :: display();
            break;
        default:
            cout<<"invalid choice!"<<endl;
            break;
        }
        cout<<"ISSN number: "<<ISSN<<endl;
        cout<<"----------------------------------------"<<endl;

    }
    void display_list(){
        cout<<setw(10)<<left<<u_id;
        cout<<setw(30)<<left<<title;
         if(choice == 'H'){
        cout<<setw(10)<<left<<copies<<" copies"<<endl;
        }
        else if(choice == 'E'){
             cout<<setw(10)<<left<<DOI<<endl;
        }
    }
};

int main(){
    int choice; 
    char c;
    book b[10];
    magazine m[10];
    int btop=-1;
    int mtop=-1;
    do {
    cout<<"Enter 1 : add book data"<<endl;
    cout<<"Enter 2 : add magazine data"<<endl;
    cout<<"Enter 3 : list all books"<<endl;
    cout<<"Enter 4 : List all magazines"<<endl;
    cin>>choice;
    
    switch(choice)
    {
    case 1: 
            btop++;
            b[btop].getdata();
            break;
    case 2:
            mtop++;
            m[mtop].getdata();
            break;
     case 3:
        cout<<setw(10)<<left<<"ID NO.";
        cout<<setw(30)<<left<<"Title";
        cout<<setw(10)<<left<<"Status"<<endl;
        for (int i= 0 ;i <= btop ; i++)
        {
            b[i].display_list();
        }
        break;
    case 4:
        cout<<setw(10)<<left<<"ID NO.";
        cout<<setw(30)<<left<<"Title";
        cout<<setw(10)<<left<<"Status"<<endl;
        for(int i = 0 ; i <= mtop ; i++){
            m[i].display_list();
        }

    }
  
    cout<<"Enter M for main menu or enter any key to exit: ";
    cin>>c;
    }
    while( c == 'M');
return 0;
}

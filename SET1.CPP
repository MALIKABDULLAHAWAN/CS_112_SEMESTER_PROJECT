#include<iostream>
using namespace std;

class Host
{
    private:
      int ch;              //choice variable
      char c;

    public:
       void menu()
       {
        do{
        cout << "===== Host Menu =====" << endl;
        cout << "1. Remove a builder or user" << endl;
        cout << "2. Upgrade standard charges" << endl;
        cout << "3. Exit" << endl;
        cout<<"Choice: "<<endl;
        cin>> ch;
        switch(ch)
        {
            case 1:
                
                break;
            case 2:

                break;
            case 3:
                 
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
        cout<<"Do you want to perform another function (y/n): "<<endl;
        cin>> c;
        }while(c == 'y');
       }
       

    

};

class Builder : public Host
{
     private:
         char x;
         int y;
     public:
        void builder_menu()
        {
            do{
            cout << "===== Builder Menu =====" << endl;
            cout << "1. Upgrade your bio" << endl;
            cout << "2. See messages" << endl;
            cout << "3. Add your accounts" << endl;
            cout << "4. Exit" << endl;
            cout<<"Your choice:"<<endl;
            cin>> y;



            cout<<"Do you want to perform another function(y/n): "<<endl;
            cin>> x;
            }while(x == 'y'|| 'Y');
        }
       
};

class Client : public Host
{
    private:
        char z;
    public:
      void client_menu()
      {

      }
};

int main()
{
    int choice;
    cout<<"--------Welcome to the App--------";
    cout<<"choose your designation: "<<endl;
    cout<<"1: Host"<<endl;
    cout<<"2: Builder"<<endl;
    cout<<"3: Client "<<endl;
    cout<<"Enter Your choice: "<<endl;
    cin>> choice;
    switch(choice)
    {
        case 1: 
           
           break;
        case 2:
           
           break;
        case 3:
           
           break;
        default:
           cout<<"Invalid"<<endl;
    }


    return 0;
}
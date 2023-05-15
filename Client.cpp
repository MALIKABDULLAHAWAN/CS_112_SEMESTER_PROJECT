#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
class Host{};

class Client : public Host
{
private:
    char z;
    int s;
    string client_name, company_name;
    double length, width, height;


public:
    void createProfile()
    {
        cout << "Enter your name: ";
        cin >> client_name;

        ofstream profileFile("client_profile.txt");
        if (profileFile.is_open())
        {
            profileFile << "Client Name: " << client_name << endl;
            profileFile.close();
            cout << "Profile created and saved successfully!" << endl;
        }
        else
        {
            cout << "Error creating profile file." << endl;
        }
    }

    void textCompany()
    {
        cout << "Enter the name of the company you want to text: ";
        cin >> company_name;

        ofstream messageFile("company_messages.txt", ios::app);
        if (messageFile.is_open())
        {
            cout << "Enter your message: ";
            cin.ignore();
            string message;
            getline(cin, message);

            messageFile << "From: " << client_name << endl;
            messageFile << "To: " << company_name << endl;
            messageFile << "Message: " << message << endl;
            messageFile << "==============================" << endl;
            messageFile.close();

            cout << "Message sent successfully!" << endl;
        }
        else
        {
            cout << "Error opening message file." << endl;
        }
    }

    double calculate_area(double length, double width)
    {
        return length * width;
    }
     
    
   void registerCompany()
    {
        cout << "Enter the name of the company you want to register with: ";
        cin >> company_name;

        ofstream registrationFile("company_registrations.txt", ios::app);
        if (registrationFile.is_open())
        {
            registrationFile << "Client: " << client_name << endl;
            registrationFile << "Company: " << company_name << endl;
            registrationFile << "Dimensions: " << length << "x" << width << "x" << height << endl;
            registrationFile << "==============================" << endl;
            registrationFile.close();

            cout << "Registration successful!" << endl;
        }
        else
        {
            cout << "Error opening registration file." << endl;
        }
    }

    
    void searchBuilder()
    {
        cout << "Enter the dimensions of the area for construction:" << endl;
        cout << "Length: ";
        cin >> length;
        cout << "Width: ";
        cin >> width;
        cout << "Height: ";
        cin >> height;

        double area = calculate_area(length, width);
        cout << "The area of construction is: " << area << " square units"<<endl;
        
        Host H1;
        H1.calculateStandardSurcharge(area, 1000);

        ifstream builderFile("builders.txt");
        if (builderFile.is_open())
        {
            string builder;
            while (getline(builderFile, builder))
            {
                cout << "Builder: " << builder << endl;
                // Perform additional search or filtering based on dimensions if needed
                cout << "Do you want to Register with a company (y/n)" << endl;
                   cin>> s;
                   if(s == 'y')
                   {
                    registerCompany();
                   }
                   else
                   {
                    cout<<"Not found"<<endl;
                   }

            }
            builderFile.close();
        }
        else
        {
            cout << "Builder file not found." << endl;
        }
    }
    

    void clientMenu()
    {
        do
        {
            cout << "=======Client Menu=======" << endl;
            cout << "1. Create profile" << endl;
            cout << "2. Search for a builder" << endl;
            cout << "3. Text a company" << endl;
            cout << "4. Exit" <<endl;
            cout<<"Enter your choice"<<endl;
            cin>> s;
            switch(s)
            {
                case 1:
                   createProfile();
                   break;
                case 2:
                   searchBuilder();
                     break;
                case 3: 
                   textCompany();
                   break;
                case 4:
                   break;
                default:
                    cout<<"Invalid"<<endl;
            }
            cout << "Do you want to perform another function (y/n): ";
            cin >> s;
     } while (s == 'y' || s == 'Y');
    }

};


int main()
{
    system("CLS");
    Host H;
    Client c;
    
    int choice;
    cout<<"--------Welcome to the App--------"<<endl;
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
           c.clientMenu();
           break;
        default:
           cout<<"Invalid"<<endl;
    }
    return 0;
}  

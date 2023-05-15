#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Host
{
private:
    int ch;              // choice variable
    char c;

public:
    
    double calculateStandardSurcharge(double rate, double amount) {
    // Calculate the surcharge based on the rate and amount
    amount = 1000;       //1000 per square feet
    double surcharge = rate * amount;
    
    // Return the surcharge value
    return surcharge;
    }


    void menu()
    {
        do
        {
            cout << "===== Host Menu =====" << endl;
            cout << "1. Add a builder or user" << endl;
            cout << "2. Remove a builder or user" << endl;
            cout << "3. Upgrade standard charges" << endl;
            cout << "4. Exit" << endl;
            cout << "Choice: ";
            cin >> ch;

            switch (ch)
            {
                case 1:
                    addBuilderOrUser();
                    break;
                case 2:
                    removeBuilderOrUser();
                    break;
                case 3:
                    upgradeStandardCharges();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid Input" << endl;
            }

            cout << "Do you want to perform another function (y/n): ";
            cin >> c;
        } while (c == 'y');
    }

private:
    void addBuilderOrUser()
    {
        ofstream file("builders_users.txt", ios::app);

        string name;
        string type;

        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter the type (builder/user): ";
        cin >> type;

        file << name << " " << type << endl;

        cout << "Builder/User added successfully!" << endl;

        file.close();
    }

    void removeBuilderOrUser()
    {
        ifstream file("builders_users.txt");

        if (!file)
        {
            cout << "File not found!" << endl;
            return;
        }

        string line;
        string nameToRemove;
        string type, name;

        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, nameToRemove);

        ofstream temp("temp.txt", ios::out);

        bool found = false;

        while (getline(file, line))
        {
            istringstream iss(line);
            if (iss >> nameToRemove >> type)
            {
                if (nameToRemove != name)
                    temp << line << endl;
                else
                    found = true;
            }
        }

        file.close();
        temp.close();

        if (found)
        {
            remove("builders_users.txt");
            rename("temp.txt", "builders_users.txt");
            cout << "Builder/User removed successfully!" << endl;
        }
        else
        {
            cout << "Builder/User not found!" << endl;
            remove("temp.txt");
        }
    }

    void upgradeStandardCharges()
    {
        ifstream file("standard_charges.txt");

        if (!file)
        {
            cout << "File not found!" << endl;
            return;
        }

        double charges;

        cout << "Enter the new standard charges: ";
        cin >> charges;

        ofstream temp("temp.txt", ios::out);

        string line;

        while (getline(file, line))
        {
            temp << charges << endl;
        }

        file.close();
        temp.close();

        remove("standard_charges.txt");
        rename("temp.txt", "standard_charges.txt");

        cout << "Standard charges upgraded successfully!" << endl;
    }

};



class Builder : public Host
{
private:
    char x;
    int y, cont, f, z;
    string build_name, em;

public:
    void createProfile()
    {
        cout << "Enter your credentials: " << endl;
        cout << "Enter your name: ";
        cin >> build_name;
        cout << "Enter your contact number: ";
        cin >> cont;
        cout << "Enter your email address: ";
        cin >> em;
        cout << "Enter fax: ";
        cin >> f;
        cout << "Number of projects you have done: ";
        cin >> z;

        ofstream profileFile("profile.txt");
        if (profileFile.is_open())
        {
            profileFile << "Name: " << build_name << endl;
            profileFile << "Contact Number: " << cont << endl;
            profileFile << "Email Address: " << em << endl;
            profileFile << "Fax: " << f << endl;
            profileFile << "Number of Projects: " << z << endl;
            profileFile.close();
            cout << "Profile created and saved successfully!" << endl;
        }
        else
        {
            cout << "Error creating profile file." << endl;
        }
    }

    void openProfile()
    {
        ifstream profileFile("profile.txt");
        if (profileFile.is_open())
        {
            string line;
            while (getline(profileFile, line))
            {
                cout << line << endl;
            }
            profileFile.close();
        }
        else
        {
            cout << "Profile file not found." << endl;
        }
    }

    void upgradeBio()
    {
        cout << "Enter your new bio: ";
        string newBio;
        cin.ignore();
        getline(cin, newBio);

        ofstream bioFile("bio.txt");
        if (bioFile.is_open())
        {
            bioFile << newBio << endl;
            bioFile.close();
            cout << "Bio upgraded and saved successfully!" << endl;
        }
        else
        {
            cout << "Error upgrading bio file." << endl;
        }
    }

    void seeMessages()
    {
        ifstream messageFile("messages.txt");
        if (messageFile.is_open())
        {
            string line;
            while (getline(messageFile, line))
            {
                cout << line << endl;
            }
            messageFile.close();
        }
        else
        {
            cout << "Message file not found." << endl;
        }
    }

    void addAccount()
    {
        cout << "Enter the account name: ";
        string accountName;
        cin >> accountName;

        ofstream accountFile("accounts.txt", ios::app);
        if (accountFile.is_open())
        {
            accountFile << accountName << endl;
            accountFile.close();
            cout << "Account added successfully!" << endl;
        }
        else
        {
            cout << "Error adding account to file." << endl;
        }
    }

    void builderMenu()
    {
        do
        {
            cout << "===== Builder Menu =====" << endl;
            cout << "1. Create your profile" << endl;
            cout << "2. Open your profile" << endl;
            cout << "3. Upgrade your bio" << endl;
            cout << "4. See messages" << endl;
            cout << "5. Add your accounts" << endl;
            cout << "6. Exit" << endl;
            cout << "Your choice: "<<endl;
            cin>> y;
            switch(y)
            {
                case 1:
                   createProfile();
                   break;
                case 2: 
                    openProfile();
                    break;
                case 3:
                    upgradeBio();
                    break;
                case 4: 
                    seeMessages();
                    break;
                case 5:
                    addAccount();
                    break;
                case 6:
                   break;
                default:
                   cout<<"Input Error"<<endl;

            }
            cout << "Do you want to perform another function (y/n): ";
           cin >> x;
    } while (x == 'y' || x == 'Y');
    }
};


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
    Host H;
    Client c;
    Builder B;
    int choice;
    cout<<"--------Welcome to the App--------"<<endl;;
    cout<<"choose your designation: "<<endl;
    cout<<"1: Host"<<endl;
    cout<<"2: Builder"<<endl;
    cout<<"3: Client "<<endl;
    cout<<"Enter Your choice: "<<endl;
    cin>> choice;
    switch(choice)
    {
        case 1: 
           B.menu();
           break;
        case 2:
           B.builderMenu();
           break;
        case 3:
           c.clientMenu();
           break;
        default:
           cout<<"Invalid"<<endl;
    }
    return 0;
}
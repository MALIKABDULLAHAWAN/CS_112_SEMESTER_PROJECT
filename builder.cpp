
class Builder : public Host {
public:
    Builder() {
        cout << "Builder object created" << endl;
    }

    ~Builder() {
        cout << "Builder object destroyed" << endl;
    }

    void menu() override {
        char c;
        do {
            cout << "===== Builder Menu =====" << endl;
            cout << "1. Create your profile" << endl;
            cout << "2. Open your profile" << endl;
            cout << "3. Upgrade your bio" << endl;
            cout << "4. See messages" << endl;
            cout << "5. Add your accounts" << endl;
            cout << "6. Exit" << endl;
            cout << "Your choice: ";
            cin >> c;

            switch (c) {
                case '1':
                   createProfile();
                    break;
                case '2':
                    openProfile();
                    break;
                case '3':
                    upgradeBio();
                    break;
                case '4':
                    seeMessages();
                    break;
                case '5':
                    addAccounts();
                    break;
                case '6':
                    cout << "Exiting Builder Menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (c != '6');
    }

    void createProfile() {
        string name, address, contact;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter your address: ";
        getline(cin, address);

        cout << "Enter your contact number: ";
        getline(cin, contact);

        ofstream profile("builder_profile.txt", ios::app);
        profile << "Name: " << name << endl;
        profile << "Address: " << address << endl;
        profile << "Contact: " << contact << endl;

        cout << "Profile created successfully!" << endl;

        profile.close();
    }

    void openProfile() {
        ifstream profile("builder_profile.txt");

        if (!profile) {
            cout << "Profile not found!" << endl;
            return;
        }

        string line;

        while (getline(profile, line)) {
            cout << line << endl;
        }

        profile.close();
    }

    void upgradeBio() {
        ifstream profile("builder_profile.txt");

        if (!profile) {
            cout << "Profile not found!" << endl;
            return;
        }

        string line;
        string name, address, contact;

        cout << "Enter your updated name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter your updated address: ";
        getline(cin, address);

        cout << "Enter your updated contact number: ";
        getline(cin, contact);

        ofstream temp("temp.txt", ios::out);

        while (getline(profile, line)) {
            if (line.find("Name:") != string::npos)
                temp << "Name: " << name << endl;
            else if (line.find("Address:") != string::npos)
                temp << "Address: " << address << endl;
            else if (line.find("Contact:") != string::npos)
                temp << "Contact: " << contact << endl;
            else
                temp << line << endl;
        }

        profile.close();
        temp.close();

        remove("builder_profile.txt");
        rename("temp.txt", "builder_profile.txt");

        cout << "Profile upgraded successfully!" << endl;
    }

    void seeMessages() {
        ifstream messages("builder_messages.txt");

        if (!messages) {
            cout << "No messages found!" << endl;
            return;
        }

        string line;

        while (getline(messages, line)) {
            cout << line << endl;
        }

        messages.close();
    }

    void addAccounts() {
        string accountType, accountNumber;

        cout << "Enter the account type: ";
        cin.ignore();
        getline(cin, accountType);

        cout << "Enter the account number: ";
        getline(cin, accountNumber);

        ofstream accounts("builder_accounts.txt", ios::app);
        accounts << "Type: " << accountType << endl;
        accounts << "Number: " << accountNumber << endl;

        cout << "Account added successfully!" << endl;

        accounts.close();
    }
};


int main() {
    system("CLS");
    char choice;

    cout << "Are you a builder or a user? (b/u): ";
    cin >> choice;

    Host* host = nullptr;

    if (choice == 'b') {
        host = new Builder();
    } 
    else {
        cout << "Invalid choice. Exiting..." << endl;
        return 0;
    }

   

    return 0;
} 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Host {
public:
    virtual ~Host() {}

    virtual void menu() = 0;

    double calculateStandardSurcharge(double rate, double amount) {
        // Calculate the surcharge based on the rate and amount
        amount = 1000; // 1000 per square feet
        double surcharge = rate * amount;

        // Return the surcharge value
        return surcharge;
    }

    void addBuilderOrUser() {
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

    void removeBuilderOrUser() {
        ifstream file("builders_users.txt");

        if (!file) {
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

        while (getline(file, line)) {
            istringstream iss(line);
            if (iss >> nameToRemove >> type) {
                if (nameToRemove != name)
                    temp << line << endl;
                else
                    found = true;
            }
        }

        file.close();
        temp.close();

        if (found) {
            remove("builders_users.txt");
            rename("temp.txt", "builders_users.txt");
            cout << "Builder/User removed successfully!" << endl;
        } else {
            cout << "Builder/User not found!" << endl;
            remove("temp.txt");
        }
    }

    void upgradeStandardCharges() {
        ifstream file("standard_charges.txt");

        if (!file) {
            cout << "File not found!" << endl;
            return;
        }

        double charges;

        cout << "Enter the new standard charges: ";
        cin >> charges;

        ofstream temp("temp.txt", ios::out);

        string line;

        while (getline(file, line)) {
            temp << charges << endl;
        }

        file.close();
        temp.close();

        remove("standard_charges.txt");
        rename("temp.txt", "standard_charges.txt");

        cout << "Standard charges upgraded successfully!" << endl;
    }
};

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

class User : public Host {
public:
    User() {
        cout << "User object created" << endl;
    }

    ~User() {
        cout <<        "User object destroyed" << endl;
    }

    void menu() override {
        char c;
        do {
            cout << "===== User Menu =====" << endl;
            cout << "1. Search builders" << endl;
            cout << "2. Send message" << endl;
            cout << "3. View standard charges" << endl;
            cout << "4. Calculate surcharge" << endl;
            cout << "5. Exit" << endl;
            cout << "Your choice: ";
            cin >> c;

            switch (c) {
                case '1':
                    searchBuilders();
                    break;
                case '2':
                    sendMessage();
                    break;
                case '3':
                    viewStandardCharges();
                    break;
                case '4':
                    calculateSurcharge();
                    break;
                case '5':
                    cout << "Exiting User Menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (c != '5');
    }

    void searchBuilders() {
        ifstream builders("builders_users.txt");

        if (!builders) {
            cout << "No builders found!" << endl;
            return;
        }

        string line;

        while (getline(builders, line)) {
            istringstream iss(line);
            string name, type;

            if (iss >> name >> type) {
                if (type == "builder")
                    cout << name << endl;
            }
        }

        builders.close();
    }

    void sendMessage() {
        string recipient, message;

        cout << "Enter the recipient's name: ";
        cin.ignore();
        getline(cin, recipient);

        cout << "Enter your message: ";
        getline(cin, message);

        ofstream messages("user_messages.txt", ios::app);
        messages << "To: " << recipient << endl;
        messages << "Message: " << message << endl;

        cout << "Message sent successfully!" << endl;

        messages.close();
    }

    void viewStandardCharges() {
        ifstream charges("standard_charges.txt");

        if (!charges) {
            cout << "Standard charges not found!" << endl;
            return;
        }

        double charge;

        while (charges >> charge) {
            cout << "Standard Charge: " << charge << endl;
        }

        charges.close();
    }

    void calculateSurcharge() {
        double rate, amount;

        cout << "Enter the surcharge rate: ";
        cin >> rate;

        cout << "Enter the area in square feet: ";
        cin >> amount;

        double surcharge = calculateStandardSurcharge(rate, amount);

        cout << "Surcharge Amount: " << surcharge << endl;
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
    } else if (choice == 'u') {
        host = new User();
    } else {
        cout << "Invalid choice. Exiting..." << endl;
        return 0;
    }

    host->menu();

    delete host;

    return 0;
}



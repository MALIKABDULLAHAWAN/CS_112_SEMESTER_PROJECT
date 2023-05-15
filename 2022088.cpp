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

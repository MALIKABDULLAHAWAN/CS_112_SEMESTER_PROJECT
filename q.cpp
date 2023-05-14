#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class User {
protected:
    string fullName;
    string phoneNumber;

public:
    User(const string& name = "", const string& phone = "")
        : fullName(name), phoneNumber(phone) {}

    string getFullName() const {
        return fullName;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    virtual void saveData(ofstream& file) const = 0;
};

class Client : public User {
private:
    int idNumber;
    string dateOfBirth;

public:
    Client(const string& name = "", const string& phone = "", int id = 0, const string& dob = "")
        : User(name, phone), idNumber(id), dateOfBirth(dob) {}

    void saveData(ofstream& file) const override {
        file << "Client" << endl;
        file << fullName << endl;
        file << phoneNumber << endl;
        file << idNumber << endl;
        file << dateOfBirth << endl;
        file << endl;
    }
};

class ConstructionCompany : public User {
private:
    string companyName;
    string emailAddress;
    string registrationNumber;
    string taxId;

public:
    ConstructionCompany(const string& name = "", const string& phone = "", const string& company = "",
        const string& email = "", const string& regNum = "", const string& tax = "")
        : User(name, phone), companyName(company), emailAddress(email),
        registrationNumber(regNum), taxId(tax) {}

    void saveData(ofstream& file) const override {
        file << "ConstructionCompany" << endl;
        file << fullName << endl;
        file << phoneNumber << endl;
        file << companyName << endl;
        file << emailAddress << endl;
        file << registrationNumber << endl;
        file << taxId << endl;
        file << endl;
    }
};

class ConstructionApp {
private:
    vector<Client> clients;
    vector<ConstructionCompany> companies;
    string filename;

public:
    ConstructionApp(const string& file)
        : filename(file) {}

    void registerClient() {
        string name, phone, dob;
        int id;

        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        cout << "Enter ID number: ";
        cin >> id;
        cin.ignore();

        cout << "Enter date of birth: ";
        getline(cin, dob);

        clients.emplace_back(name, phone, id, dob);
        cout << "Registration successful!" << endl;

        saveDataToFile();
    }

    void registerCompany() {
        string name, phone, company, email, regNum, tax;

        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        cout << "Enter company name: ";
        getline(cin, company);

        cout << "Enter email address: ";
        getline(cin, email);

        cout << "Enter registration number: ";
        getline(cin, regNum);

        cout << "Enter tax ID: ";
        getline(cin, tax);

        companies.emplace_back(name, phone, company, email, regNum, tax);
        cout << "Registration successful!" << endl;

        saveDataToFile();
    }

    void saveDataToFile() const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file." << endl;
            return;
        }

    }
};
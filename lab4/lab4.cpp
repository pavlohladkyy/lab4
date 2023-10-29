#include <iostream>
#include <fstream>
using namespace std;

// Base class "PERSON"
class PERSON {
protected:
    string name;
    int age;

public:
    PERSON() : name(""), age(0) {}
    PERSON(string n, int a) : name(n), age(a) {}

    // Function for output to a stream
    virtual void display(ostream& out) const {
        out << "Name: " << name << ", Age: " << age;
    }

    // Function for input from a stream
    virtual void input(istream& in) {
        cout << "Enter name: ";
        in >> name;
        cout << "Enter age: ";
        in >> age;
    }

    // Assignment operation
    void assign(const PERSON& other) {
        name = other.name;
        age = other.age;
    }
};

// Derived class "STUDENT"
class STUDENT : public PERSON {
protected:
    string university;

public:
    STUDENT() : university("") {}
    STUDENT(string n, int a, string u) : PERSON(n, a), university(u) {}

    // Override the output function
    void display(ostream& out) const override {
        PERSON::display(out);
        out << ", University: " << university;
    }

    // Override the input function
    void input(istream& in) override {
        PERSON::input(in);
        cout << "Enter university name: ";
        in >> university;
    }
};

// Derived class "STUDENT_DIPLOMA"
class STUDENT_DIPLOMA : public STUDENT {
protected:
    string thesis_topic;

public:
    STUDENT_DIPLOMA() : thesis_topic("") {}
    STUDENT_DIPLOMA(string n, int a, string u, string topic) : STUDENT(n, a, u), thesis_topic(topic) {}

    // Override the output function
    void display(ostream& out) const override {
        STUDENT::display(out);
        out << ", Thesis Topic: " << thesis_topic;
    }

    // Override the input function
    void input(istream& in) override {
        STUDENT::input(in);
        cout << "Enter thesis topic: ";
        in >> thesis_topic;
    }
};

int main() {
    STUDENT_DIPLOMA studentDiploma;
    STUDENT_DIPLOMA studentDiploma2;

    // Input data for the first student with a diploma
    cout << "Enter data for the first student with a diploma:" << endl;
    studentDiploma.input(cin);

    // Display data for the first student with a diploma
    cout << "Data for the first student with a diploma:" << endl;
    studentDiploma.display(cout);
    cout << endl;

    // Assignment of data from the first student with a diploma to the second
    studentDiploma2.assign(studentDiploma);

    // Display data for the second student with a diploma (after assignment)
    cout << "Data for the second student with a diploma (after assignment):" << endl;
    studentDiploma2.display(cout);
    cout << endl;

    // Write information about students with diplomas to a file
    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        outFile << "Information about the first student with a diploma:" << endl;
        studentDiploma.display(outFile);
        outFile << "Information about the second student with a diploma:" << endl;
        studentDiploma2.display(outFile);
        outFile.close();
        cout << "Data has been written to the file 'students.txt'." << endl;
    }
    else {
        cout << "Error opening the output file." << endl;
    }

    return 0;
}

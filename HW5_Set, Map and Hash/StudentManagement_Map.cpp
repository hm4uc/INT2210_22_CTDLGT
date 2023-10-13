#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student {
    int ID;
    string Name;
    string Class;
};

class University {
private:
    map<int, Student> students;

public:
    void Insert(int ID, string Name, string Class) {
        if (students.find(ID) == students.end()) {
            Student s = {ID, Name, Class};
            students[ID] = s;
        } else {
            cout << "Student with ID: " << ID << " is already exists!" << endl;
        }
    }

    void Delete(int ID) {
        if (students.find(ID) == students.end()) {
            cout << "No student with ID: " << ID << " to delete!" << endl;
            return;
        } else {
            students.erase(ID);
        }
    }

    void Infor(int ID) {
        if (students.find(ID) == students.end()) {
            cout << "NA,NA" << endl;
        } else {
            cout << students[ID].Name << "," << students[ID].Class << endl;
        }
    }
};

int main() {
    University uni;
    uni.Insert(22029, "Hoang Minh Duc", "K67CACLC1");
    uni.Insert(22027, "Dat Co", "K67CACLC1");
    uni.Insert(22022, "Le Thanh Doanh", "K67CACLC3");
    uni.Delete(22022);
    uni.Delete(22021);
    uni.Infor(22029);
    uni.Infor(22022);
    uni.Infor(22027);
}

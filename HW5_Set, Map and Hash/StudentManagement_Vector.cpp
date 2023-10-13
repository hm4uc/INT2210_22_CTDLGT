#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int ID;
    string Name;
    string Class;
};

class University {
private:
    vector<Student> students;

public:
    void Insert(int ID, string Name, string Class) {
        for (const auto& s : students) {
            if (s.ID == ID) {
                cout << "Student with ID: " << ID << " is already exists!" << endl;
                return;
            }
        }
            students.push_back({ID, Name, Class});
    }

    void Delete(int ID) {
        for (auto i = students.begin(); i != students.end(); i++) {
            if (i->ID == ID) {
                students.erase(i);
                return;
            }
        }
            cout << "No student with ID: " << ID << " to delete" << endl;
    }

    void Infor(int ID) {
        for (const auto& s : students) {
            if (s.ID == ID) {
                cout << s.Name << "," << s.Class << endl;
                return;
            }
        }
            cout << "NA,NA" << endl;
    }
};

int main() {
    University uni;
    uni.Insert(22029, "Hoang Minh Duc", "K67CACLC1");
    uni.Insert(22027, "Trox", "K67CACLC1");
    uni.Insert(22022, "Doanh", "K67CACLC3");
    uni.Delete(22022);
    uni.Delete(22023);
    uni.Infor(22029);
    uni.Infor(22026);
}



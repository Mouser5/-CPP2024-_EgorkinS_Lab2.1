#include <vector>
#include <string>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    char mark;
    vector <double> ans;
public:
    Student(const string _name, const int number) {
        name = _name;
        Get_Mark(mark);
        Get_ans(ans, mark, number);
    }
    void Get_Mark(char& mark) {
        srand(time(0));
        int score = rand() % (3) + 3;
        if (score == 3)
            mark = 'C';
        else
            if (score == 4)
                mark = 'B';
            else
                mark = 'A';
    }
    void Get_ans(vector <double>& ans, const char mark, const int number) {
        if (mark == 'A') {
            FindRoots(ans, number);
        }
        if (mark == 'C') {
            ans.resize(1);
            ans[0] = 0;

        }
        if (mark == 'B') {
            int chance = rand() % (20) + 1;
            if (chance <= 11)
                FindRoots(ans, number);
            else {
                ans.resize(1);
                ans[0] = 0.0;
            }

        }
    }
    void InputData(double& a, double& b, double& c, const int number) {
        ifstream file("input.txt");
        string s;
        for (int i = 1; i < number; i++) {
            getline(file, s);
        }
        file >> a >> b >> c;
    }
    void Roots(const double a, const double b, const double D, vector <double>& ans) {
        ans[0] = (-b + sqrt(D)) / (2 * a);
        ans[1] = (-b - sqrt(D)) / (2 * a);
    };
    void Discriminant(const double a, const double b, const double c, double& D) {
        D = b * b - 4 * a * c;
    }
    void FindRoots(vector <double>& ans, const int number) {
        double a, b, c, D;
        InputData(a, b, c, number);
        Discriminant(a, b, c, D);
        if (D < 0) {
            ans.resize(0);
        }
        else {
            if (D == 0.0) {
                ans.resize(1);
                ans[0] = (-b) / (2 * a);
            }
            else {
                ans.resize(2);
                Roots(a, b, D, ans);
            }

        }
    }

    void PrintResult(const int number) {
        cout << "Number:" << number << endl;
        cout << name << endl;
        int size = ans.size();
        if (size == 0)
            cout << "There are no roots." << endl;
        else {
            for (int i = 0; i < size; i++) {
                cout << ans[i] << endl;
            }
        }
    }
};

void prog() {
    string name;
    int number;
    cout << "Enter name...";
    cin >> name;
    cout << "Enter assignment's number...";
    cin >> number;
    Student* a = new Student(name, number);
    a->PrintResult(number);
}

int main()
{     
    char another_attempt;
    do
    {

        prog();
        cout << "Do you want to try another student/number?...(y/n)";
        cin >> another_attempt;
    } while (another_attempt=='y');
    return(0);
}
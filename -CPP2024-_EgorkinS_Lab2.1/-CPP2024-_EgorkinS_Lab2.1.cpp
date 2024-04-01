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
        if (score == 4)
            mark = 'B';
        else
            mark = 'A';
    }
    void Get_ans(vector <double>& ans, const char mark, const int number) {
        ans.resize(2);
        if (mark == 'A') {
            FindRoots(ans, number);
        }
        if (mark == 'C') {
            ans[0] = 0.0;
            ans[1] = NULL;
        }
        if (mark == 'B') {
            int chance = rand() % (20) + 1;
            if (chance <= 11)
                FindRoots(ans, number);
            else
                ans[0] = 0.0;
        }
    } 
    void InputData(double& a, double& b, double& c, const int number) {
            ifstream file("input.txt");
            string s;
            for (int i = 1; i < number; i++) {
                getline(file, s);
            }
            file >> a,b,c;
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
            ans[0] = NULL;
        }
        else {
            if (D == 0.0) {
                ans[0] = (-b) / (2 * a);
                ans[1] = NULL;
            }
            else
                Roots(a, b, D, ans);
        }
    }

    void PrintResult(const int number) {
        cout << "Number:" << number << endl;
        cout << name;
        if (ans[0] == NULL) {
            cout << "There are no roots.";
        }
        else {
            cout << ans[0];
            if (ans[1] != NULL) {
                cout << ans[1];
            }
        }
    }
};

int main()
{    
    //номер уравнения - number
    // Фамилия - name
    // Ответ - ans
    string name;
    int number;
    cout << "Enter name...";
    cin >> name;
    cout << "Enter assignment's number...";
    cin>> number;
    Student* a = new Student(name, number);
    a->PrintResult(number);
}
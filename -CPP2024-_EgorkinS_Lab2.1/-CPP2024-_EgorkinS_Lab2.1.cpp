﻿#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
using namespace std;

class Student {
private:
    string name;
    string mark;
    vector <double> ans;
public:
    Student(string _name, string _mark) {
        name = _name;
        mark = _mark;
        ans = Get_ans(mark);
    }
    vector <double> Get_ans(string mark) {

        if (mark == "A") {


        }
    }
};

int main()
{
    string s = "example";
    Student* a = new Student(s, s);

    // string s = "example";
    // Student* a = new Student(s, s);
    double a, b, c;
    InputData(a, b, c);
}
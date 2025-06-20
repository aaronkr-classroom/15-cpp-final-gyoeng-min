#include <iostream>
#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "intl.h"
#include "grade.h"

using namespace std;

Student_info::Student_info(const Student_info& s) : cp(0) {
    if (s.cp) cp = s.cp->clone();
}

istream& Student_info::read(istream& is) {
    delete cp;
    char ch;
    is >> ch;

    if (ch == 'U')
        cp = new Core(is);
    else if (ch == 'G')
        cp = new Grad(is);
    else if (ch == 'I')
        cp = new intl(is);
    else
        cp = 0; // 방어적 처리

    return is;
}

Student_info& Student_info::operator=(const Student_info& s) {
    if (&s != this) {
        delete cp;
        cp = s.cp ? s.cp->clone() : 0;
    }
    return *this;
}

istream& read_hw(istream& in, Vec<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}
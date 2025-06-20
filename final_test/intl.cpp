#include "intl.h"
#include "grade.h"

std::istream& intl::read(std::istream& in) {
    Core::read(in);    // �̸�, �߰�, �⸻, ���� ���� �б�
    in >> toic;        // ���� ���� �߰��� �б�
    return in;
}

double intl::grade() const {
    // �⺻ ���� 90% + toic 10% �ݿ� ����
    return 0.9 * Core::grade() + 0.1 * toic;
}

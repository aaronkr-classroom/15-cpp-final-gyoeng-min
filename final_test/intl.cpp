#include "intl.h"
#include "grade.h"

std::istream& intl::read(std::istream& in) {
    Core::read(in);    // 이름, 중간, 기말, 과제 점수 읽기
    in >> toic;        // 토익 점수 추가로 읽기
    return in;
}

double intl::grade() const {
    // 기본 성적 90% + toic 10% 반영 예시
    return 0.9 * Core::grade() + 0.1 * toic;
}

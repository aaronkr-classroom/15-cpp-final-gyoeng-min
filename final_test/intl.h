#pragma once
#ifndef GUARD_intl_h
#define GUARD_intl_h

#include <iostream>
#include "Core.h"

class intl : public Core {
public:
    intl() : toic(0) {}
    intl(std::istream& is) { read(is); }
    virtual Core* clone() const override { return new intl(*this); }

    virtual double grade() const override;
    virtual std::istream& read(std::istream& is) override;

private:
    double toic; // 토익 점수
};

#endif
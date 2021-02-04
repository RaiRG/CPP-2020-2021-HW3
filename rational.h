#include <iostream>

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
  int numerator_;
  int denominator_;
  void DoSimple();

public:
  Rational(int num, int denom);
  int GetNumerator() const;
  int GetDenominator() const;
  operator double() const;
  Rational& operator++();    // prefix
  Rational operator++(int);  // postfix
  Rational& operator--();    // prefix
  Rational operator--(int);  // postfix
};
bool operator==(Rational const& a, Rational const& b);
bool operator!=(Rational const& a, Rational const& b);
bool operator<(Rational const& a, Rational const& b);
bool operator>(Rational const& a, Rational const& b);
bool operator<=(Rational const& a, Rational const& b);
bool operator>=(Rational const& a, Rational const& b);
Rational operator+(const Rational& first, const Rational& second);
Rational operator-(const Rational& first, const Rational& second);
Rational operator*(const Rational& first, const Rational& second);
Rational operator/(const Rational& first, const Rational& second);
std::ostream& operator<<(std::ostream& os, const Rational& p);
#endif  // RATIONAL_H

#include "rational.h"
#include <math.h>

int numerator_;
int denominator_;

Rational::Rational(int num, int denom)
{
  numerator_ = num;
  denominator_ = denom;
  Rational::DoSimple();
}

void Rational::DoSimple()
{
  if (denominator_ < 0)
  {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }
  for (int i = 2; i <= abs(denominator_) && i <= abs(numerator_); i++)
    if (numerator_ % i == 0 && denominator_ % i == 0)
    {
      numerator_ /= i;
      denominator_ /= i;
      i--;
    }
}
Rational::operator double() const
{
  return (double)GetNumerator() / GetDenominator();
}

int Rational::GetNumerator() const
{
  return numerator_;
}
int Rational::GetDenominator() const
{
  return denominator_;
}

Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
};  // prefix

Rational Rational::operator++(int)
{
  Rational temp(*this);
  ++*this;
  return temp;
};  // postfix
Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
};  // prefix

Rational Rational::operator--(int)
{
  Rational temp = Rational(numerator_, denominator_);
  --*this;
  return temp;
};  // postfix

bool operator==(Rational const& a, Rational const& b)
{
  return (a.GetNumerator() * b.GetDenominator() == b.GetNumerator() * a.GetDenominator());
};
bool operator!=(Rational const& a, Rational const& b)
{
  return !(a == b);
};
bool operator<(Rational const& a, Rational const& b)
{
  return (a.GetNumerator() * b.GetDenominator() < b.GetNumerator() * a.GetDenominator());
};
bool operator>(Rational const& a, Rational const& b)
{
  return b < a;
};
bool operator<=(Rational const& a, Rational const& b)
{
  return (a.GetNumerator() * b.GetDenominator() <= b.GetNumerator() * a.GetDenominator());
};
bool operator>=(Rational const& a, Rational const& b)
{
  return b <= a;
};

Rational operator+(const Rational& first, const Rational& second)
{
  return Rational(first.GetNumerator() * second.GetDenominator() + second.GetNumerator() * first.GetDenominator(),
                  second.GetDenominator() * first.GetDenominator());
}

Rational operator-(const Rational& first, const Rational& second)
{
  return Rational(first.GetNumerator() * second.GetDenominator() - second.GetNumerator() * first.GetDenominator(),
                  second.GetDenominator() * first.GetDenominator());
}

Rational operator*(const Rational& first, const Rational& second)
{
  return Rational(first.GetNumerator() * second.GetNumerator(), second.GetDenominator() * first.GetDenominator());
}

Rational operator/(const Rational& first, const Rational& second)
{
  return Rational(first.GetNumerator() * second.GetDenominator(), second.GetNumerator() * first.GetDenominator());
}
std::ostream& operator<<(std::ostream& os, const Rational& p)
{
  os << p.GetNumerator() << "/" << p.GetDenominator();
  return os;
}

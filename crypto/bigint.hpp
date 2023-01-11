#ifndef BIGINT_H_
#define BIGINT_H_
#include <compare>
#include <functional>
#include <string>
#include <vector>

using namespace std;

template <typename T> struct OpRes {
  T primary;
  T secondary;
};

class BigInt {
public:
  BigInt() : len(1), bits(vector<bool>{0}){};
  BigInt(string input);
  string to_bit_string() const;
  OpRes<BigInt> div_mod(const BigInt rhs) const;
  BigInt operator-(const BigInt &rhs) const;
  BigInt operator+(const BigInt &rhs) const;
  BigInt operator/(const BigInt &rhs) const;
  BigInt operator*(const BigInt &rhs) const;
  BigInt operator^(const BigInt &rhs) const;
  strong_ordering operator<=>(const BigInt &rhs) const;

private:
  BigInt(vector<bool> _bits, int _len) : len(_len), bits(_bits){};
  void rightshift();
  void leftshift();
  void parse_string(string input);
  BigInt combine(const BigInt &rhs, function<bool(bool, bool)> op,
                 bool default_value) const;

  char to_decimal_char();
  bool positive = true;
  int len;
  vector<bool> bits;
};

#endif // BIGINT_H_

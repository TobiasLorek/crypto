#include <algorithm>
#include <compare>
#include <crypto/bigint.hpp>
#include <functional>
#include <list>
#include <sstream>
#include <string>

struct halfed_string {
  string half;
  bool remainder;
};

halfed_string half_string(string input);

halfed_string half_string(string input) {
  string res = "";
  string next;
  int addative = 0;
  int current = 0;
  for (char &i : input) {
    current = (int)i - (int)'0';
    next = std::to_string((current / 2) + addative);
    res.append(next);
    addative = current % 2 == 0 ? 0 : 5;
  }
  if (res != "0") {
    res.erase(0, res.find_first_not_of("0"));
  }
  return {res, addative != 0};
}

string BigInt::to_bit_string() const {
  stringstream out;
  if (!this->positive) {
    out << "-";
  }
  for (int i = 0; i < len; i++) {
    out << (bits[i] ? "1" : "0");
  }
  return out.str();
}

BigInt::BigInt(string input) { parse_string(input); };

void BigInt::parse_string(string input) {
  list<bool> bits = {};
  if (input[0] == '-') {
    this->positive = false;
    input.erase(0, input.find_first_not_of("-"));
  }
  halfed_string res = {input, false};
  while (res.half != "0") {
    res = half_string(res.half);
    bits.push_back(res.remainder);
  }
  bits.reverse();
  this->bits = vector<bool>{begin(bits), end(bits)};
  this->len = bits.size();
}

strong_ordering BigInt::operator<=>(const BigInt &rhs) const {
  if (this->len > rhs.len) {
    return strong_ordering::greater;
  }
  if (this->len < rhs.len) {
    return strong_ordering::less;
  }
  for (int i = this->len - 1; i >= 0; i--) {
    if (this->bits[i] < rhs.bits[i]) {
      return strong_ordering::less;
    }
    if (this->bits[i] > rhs.bits[i]) {
      return strong_ordering::greater;
    }
  }
  return strong_ordering::equal;
}

BigInt BigInt::combine(const BigInt &rhs, function<bool(bool, bool)> op,
                       bool default_value) const {
  int out_len = max(this->len, rhs.len);
  vector<bool> bits(out_len, default_value);
  int op_len = min(this->len, rhs.len);
  for (int i = 0; i < op_len; i++) {
    bits[i] = op(this->bits[i], rhs.bits[i]);
  }
  return BigInt(bits, out_len);
}

char BigInt::to_decimal_char() {
  BigInt ten("10");
  if (*this >= ten) {
    throw Exception("Not representable!");
  }
  switch (this->to_bit_string()) {
  case '0':
    return '0';
  }
}
void BigInt::leftshift() { this->bits.erase(this->bits.begin()); }
void BigInt::rightshift() { this->bits.insert(this->bits.begin(), 0, false); }

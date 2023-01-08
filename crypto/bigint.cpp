#include <algorithm>
#include <crypto/bigint.hpp>
#include <list>
#include <sstream>
#include <string>

string BigInt::to_string() {
  stringstream out;
  for (int i = 0; i < len; i++) {
    out << (bits[i] ? "1" : "0");
  }
  return out.str();
}

BigInt::BigInt(string input) { parse_string(input); };

void BigInt::parse_string(string input) {
  list<bool> bits = {};
  halfed_string res = {input, false};
  while (res.half != "0") {
    res = half_string(res.half);
    bits.push_back(res.remainder);
  }
  bits.reverse();
  this->bits = new bool[bits.size()];
  copy(bits.begin(), bits.end(), this->bits);
}

BigInt::halfed_string BigInt::half_string(string input) {
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
  res.erase(0, res.find_first_of("0"));
  return {res, addative == 0};
}

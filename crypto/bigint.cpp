#include <algorithm>
#include <crypto/bigint.hpp>
#include <list>

string BigInt::to_string() {}

void BigInt::parse_string(string input) {
  list<bool> bits = {};
  halfed_string res = {input, false};
  while (res.half != "0") {
    res = half_string(res.half);
    bits.push_back(res.remainder);
  }
  this->bits = new bool[bits.size()];
  copy(bits.begin(), bits.end(), this->bits);
}

BigInt::halfed_string BigInt::half_string(string input) {
  return {"TODO", false};
}

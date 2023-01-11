#include <crypto/bigint.hpp>
#include <iostream>

template <typename T> bool assert_equal(T lhs, T rhs, string message = "") {
  if (lhs == rhs) {
    return true;
  }
  std::cout << "Expected " << lhs << " and " << rhs << " to be equal"
            << std::endl;
  std::cout << message << std::endl;
  return false;
}

int test_parse_single() {
  BigInt input("8");
  string expected = "1000";
  return assert_equal(input.to_string(), expected) ? 0 : 1;
}

int test_parse_multi() {
  BigInt input("13");
  string expected = "1101";
  return assert_equal(input.to_string(), expected) ? 0 : 1;
}

int test_parse_negative() {
  BigInt input("-13");
  string expected = "-1101";
  return assert_equal(input.to_string(), expected) ? 0 : 1;
}

int main() {
  return (test_parse_single() + test_parse_multi() + test_parse_negative());
}

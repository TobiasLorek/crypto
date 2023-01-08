#ifndef BIGINT_H_
#define BIGINT_H_
#include <string>

using namespace std;

class BigInt {
public:
  BigInt() : len(1), bits(new bool[1]{0}){};
  BigInt(string input);
  ~BigInt() { delete[] bits; }
  string to_string();
  int len;

private:
  struct halfed_string {
    string half;
    bool remainder;
  };
  void parse_string(string input);
  halfed_string half_string(string input);
  bool *bits;
};

#endif // BIGINT_H_

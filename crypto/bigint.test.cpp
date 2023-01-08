#include <crypto/bigint.hpp>

int main() {
  BigInt eight("8");
  return (int)(eight.to_string() == "1000");
}

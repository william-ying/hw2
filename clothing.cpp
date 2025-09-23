#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand);
  Product("clothing", name, price, qty),
  size_(size),
  brand_(brand)
{}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> ret1 = parseStringToWords(name_);
  std::set<std::string> ret2 = parseStringToWords(brand_);
  ret1.merge(ret2);
  return ret1;
}

std::string Clothing::displayString() const {
  return (name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + price + " " + qty + " left.");
}

void Clothing::dump(std::ostream& os) const {
  os << this.displayString();
}

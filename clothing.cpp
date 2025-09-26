#include "clothing.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) :
  Product("clothing", name, price, qty),
  size_(size),
  brand_(brand)
{}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> ret1 = parseStringToWords(name_);
  std::set<std::string> ret2 = parseStringToWords(brand_);
  ret1.insert(ret2.begin(), ret2.end());
  return ret1;
}

std::string Clothing::displayString() const {
  return (name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.");
}

void Clothing::dump(std::ostream& os) const {
  os << "clothing" << endl;
  os << name_ << endl;
  os << to_string(price_) << endl;
  os << to_string(qty) << endl;
  os << size_ << endl;
  os << brand_ << endl;
}

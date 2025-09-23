#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Clothing : public product {
public:

  Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand);
  std::set<std::string> keywords() const;

  std::string displayString() const;

  void dump(std::ostream& os) const;

protected:
  std::string size_;
  std::string brand_;
}

#endif

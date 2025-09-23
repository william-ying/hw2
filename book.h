#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Book : public product {
public:
  std::set<std::string> keywords() const {
    return parseStringToWords(name_);
  }

  std::string displayString() const {
    return (name_ + "\nAuthor: " + 
  }

  void dump(std::ostream& os) const {
    os << displayString();
  }

protected:
  std::string isbn_;
}

#endif

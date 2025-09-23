#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Movie : public product {
public:

  Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating);
  std::set<std::string> keywords() const;

  std::string displayString() const;

  void dump(std::ostream& os) const;

protected:
  std::string genre_;
  std::string rating_;
}

#endif

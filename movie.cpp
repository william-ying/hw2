#include "movie.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) :
  Product("movie", name, price, qty),
  genre_(genre),
  rating_(rating)
{}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> ret1 = parseStringToWords(name_);
  ret1.insert(genre_);
  return ret1;
}

std::string Movie::displayString() const {
  return (name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.");
}

void Movie::dump(std::ostream& os) const {
  os << "movie" << endl;
  os << name_ << endl;
  os << to_string(price_) << endl;
  os << to_string(qty_) << endl;
  os << genre_ << endl;
  os << rating_ << endl;
}

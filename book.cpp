#include "book.h"

using namespace std;

Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author) :
  Product("book", name, price, qty),
  isbn_(isbn),
  author_(author)
{}

std::set<std::string> Book::keywords() const {
  std::set<std::string> ret1 = util.parseStringToWords(name_);
  std::set<std::string> ret2 = util.parseStringToWords(author_);
  ret1.merge(ret2);
  ret1.insert(isbn_);
  return ret1;
}

std::string Book::displayString() const {
  return (name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + price + " " + qty + " left.");
}

void Book::dump(std::ostream& os) const {
  os << util.displayString();
}

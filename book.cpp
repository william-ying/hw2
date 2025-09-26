#include "book.h"

using namespace std;

Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author) :
  Product("book", name, price, qty),
  isbn_(isbn),
  author_(author)
{}

Book::~Book() {}

std::set<std::string> Book::keywords() const {
  std::set<std::string> ret1 = parseStringToWords(name_);
  std::set<std::string> ret2 = parseStringToWords(author_);
  ret1.insert(ret2.begin(), ret2.end());
  ret1.insert(isbn_);
  return ret1;
}

std::string Book::displayString() const {
  return (name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + price_ + " " + std::to_string(qty_) + " left.");
}

void Book::dump(std::ostream& os) const {
  os << displayString() << endl;
}

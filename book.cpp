#include "book.h"

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

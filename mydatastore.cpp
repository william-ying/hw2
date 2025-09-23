#include "mydatastore.h"

using namespace std;

void MyDataStore::addProduct(Product* p) {
  products.push_back(p);

}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u) {
  users.push_back(u);
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::vector<Product*> ret;
  std::vector<Product*> comparator;
  if (type == 1) {
    for (std::string temp : terms) {
      for (Product* p : products) {
        if (p -> getName() == temp) {
          comparator.push_back(terms);
        }
      }
      ret = setUnion(ret, comparator);
    }
  } else {
    for (Product* p : products) {
      ret.push_back(p);
    }
    for (std::string temp : terms) {
      for (Product* p : products) {
        if (p -> getName() == temp) {
          comparator.push_back(terms);
        }
      }
      ret = setIntersection(ret, comparator);
    }
  }
  return ret;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile) {
  os << "<products>" << endl;
  for (Product* p : products) {
    p->dump(os);
  }
  os << "</products>" << endl << <users> << endl;
  for (User* u : users) {
    u->dump(os);
  }
  os << "</users>";
  
}

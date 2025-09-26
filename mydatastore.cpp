#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::~MyDataStore() {
  for (Product* p : products) {
    delete p;
  }
  products.clear();
  for (User* u : users) {
    delete u;
  }
  users.clear();
}

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
  std::set<Product*> base;
  if (type == 1) {
    for (std::string temp : terms) {
      std::set<Product*> comparator;
      temp = convToLower(temp);
      for (Product* p : products) {
        if (p->keywords().count(temp) == 1) {
          comparator.insert(p);
        }
      }
      base = setUnion(base, comparator);
    }
  } else {
    for (Product* p : products) {
      base.insert(p);
    }
    for (std::string temp : terms) {
      std::set<Product*> comparator;
      temp = convToLower(temp);
      for (Product* p : products) {
        if (p->keywords().count(temp) == 1) {
          comparator.insert(p);
        }
      }
      
      base = setIntersection(base, comparator);
    }
  }
  cout << "converting to ret" << endl;
  std::vector<Product*> ret;
  for (Product* p : base) {
    ret.push_back(p);
  }
  cout << "finished ret conversion" << endl;
  return ret;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << endl;
  for (Product* p : products) {
    p->dump(ofile);
  }
  ofile << "</products>" << endl << "<users>" << endl;
  for (User* u : users) {
    u->dump(ofile);
  }
  ofile << "</users>";
  
}

std::vector<Product*> MyDataStore::getp() {
  return products;
}
std::vector<User*> MyDataStore::getu() {
  return users;
}

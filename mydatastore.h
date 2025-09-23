#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"

/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 */


class MyDataStore {
public:
  void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
  void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
  std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
  void dump(std::ostream& ofile);


  std::vector<Product*> getp();
  std::vector<User*> getu();
protected:
  std::vector<Product*> products;
  std::vector<User*> users;
};

#endif

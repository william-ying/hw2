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


class MyDataStore : DataStore {
protected:
  std::vector<Product*> products;
  std::vector<User*> users;
};

#endif

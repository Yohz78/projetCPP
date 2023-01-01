#ifndef BDD_FUNCS_H_INCLUDED
#define BDD_FUNCS_H_INCLUDED

#include "sqlite3.h"
#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"

#include <vector>

void select_db(char*,sqlite3*);
void buildPro(sqlite3*,std::vector<Contact>*);

void buildPrivate(sqlite3* db, std::vector<Contact>*);
void build_from_database(sqlite3* db, std::vector<Contact>*);
void insert_contact_pro(sqlite3*, Pro*);
void insert_contact_private(sqlite3*, Private*);
void delete_from_database(int,sqlite3*);
void search_by_city(const char*,sqlite3*) ;
void search_by_name(const char*,sqlite3*);


#endif // BDD_FUNCS_H_INCLUDED

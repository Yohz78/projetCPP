#ifndef APP_H
#define APP_H

#include "../contact/contact.h"
#include "../Private/private.h"
#include "../Pro/pro.h"
#include "../bdd_funcs.h"



class app
{
    public:
        app();
        virtual ~app();

        void init();
        void run();
        void affiche();



    private:
        sqlite3 *db;
        std::vector<Contact> p;
};

#endif // APP_H

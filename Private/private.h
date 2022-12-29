#ifndef PRIVATE_H_INCLUDED
#define PRIVATE_H_INCLUDED

#include "../contact/contact.h"

using namespace std;

struct ddn{
    int day;
    int month;
    int year;

    ddn(){};
    ddn(int day, int month, int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
};

typedef struct ddn ddn;

class Private : public Contact
{
    public:
        virtual ~Private();
        Private(int, int, int);

        string Getddn();

    private:
        ddn dateNaissance;
};


#endif // PRIVATE_H_INCLUDED

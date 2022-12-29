#ifndef PRIVATE_H_INCLUDED
#define PRIVATE_H_INCLUDED

#include "../contact/contact.h"

using namespace std;

struct ddn {
    int day;
    int month;
    int year;

    ddn(int day, int month, int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
};

class Private : public Contact
{
    public:
        virtual ~Private();

        string Getddn();
        void Setddn(int day, int month, int year);

    private:
        ddn dateNaissance;
};


#endif // PRIVATE_H_INCLUDED

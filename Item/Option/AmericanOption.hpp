#ifndef AmericanOption_hpp
#define AmericanOption_hpp
#include "Option.hpp"
#include <cmath>
#include <string>
using std::string;

class AmericanOption : public Option
{
    public:
        //----------------------------------------CTORS & DTORS----------------------------------------
        AmericanOption(){};
        AmericanOption(const string &n, double s0, double k, double t, double r, double vol, int steps, bool call) :
            Option(n, s0, k, t, r, vol, steps, call){process();};
        virtual ~AmericanOption(){};

    protected:
        //----------------------------------------METHODS----------------------------------------
        virtual void calculateSpot();
        virtual void process();
};

#endif
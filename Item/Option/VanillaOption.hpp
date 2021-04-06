#ifndef VanillaOption_hpp
#define VanillaOption_hpp
#include "../Item.hpp"
#include <cmath>
#include <vector>
#include <string>
using std::vector;
using std::string;

class VanillaOption : public Item
{
    public:
        //----------------------------------------CTORS & DTORS----------------------------------------
        VanillaOption(){};
        VanillaOption(const string &n, double s0, double k, double t, double r, double vol, int steps, bool call) :
            Item(n),
            stockPrice(s0),
            strike(k),
            timeToExpiry(t),
            interestRate(r/100),
            volatility(vol/100),
            steps(steps),
            callOrPut(call ? 1.0 : -1.0){};
        virtual ~VanillaOption(){};

        //----------------------------------------GETTERS----------------------------------------
        double getSpot();

    protected:
        //----------------------------------------FIELDS----------------------------------------
        double stockPrice, strike, timeToExpiry, interestRate, volatility;
        int steps;
        double callOrPut; // Multiplier to determine whether payoff uses ST - k or k - ST
        double spotPrice = 0.0;

        vector<string> getResults();

        //----------------------------------------METHODS----------------------------------------
        double payoff(double);

        virtual void calculateSpot(){};

        virtual void process(){};
};

#endif
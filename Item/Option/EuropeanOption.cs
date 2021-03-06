using System;
using System.Collections;

namespace OAP_CS
{
    [Serializable]
    class EuropeanOption : VanillaOption
    {
        static ArrayList blank = new ArrayList() { "" };

        //----------------------------------------CTOR & FACTORY----------------------------------------
        public EuropeanOption(ArrayList inputs) : base(inputs)
        {
            process();
        }
        public EuropeanOption(string n, double s0, double k, double t, double r, double vol, int steps, bool call) : base(blank, s0, k, t, r, vol, steps, call)
        {
            process();
        }
        public static Item factory(ArrayList inputs)
        {
            return new EuropeanOption(inputs);
        }
        //----------------------------------------PRICE CALCULATIONS----------------------------------------
        public override void calculateSpot()
        {
            // Implementation of Black-Scholes closed form solution for European Options
            double d1 = (Math.Log(stockPrice / strike) + (interestRate * timeToExpiry) + (Math.Pow(volatility, 2) * timeToExpiry * 0.5)) / (volatility * Math.Sqrt(timeToExpiry));
            double d2 = d1 - (volatility * Math.Sqrt(timeToExpiry));
            if (callOrPut == 1.0)
            {
                spotPrice = (stockPrice * normalCDF(d1)) - (strike * Math.Exp(-1 * interestRate * timeToExpiry) * normalCDF(d2));
            }
            else
            {
                spotPrice = (strike * Math.Exp(-1 * interestRate * timeToExpiry) * (1 - normalCDF(d2))) - (stockPrice * (1 - normalCDF(d1)));
            }
        }

        //----------------------------------------PROCESS----------------------------------------
        public override void process()
        {
            calculateSpot();
        }
    }
}
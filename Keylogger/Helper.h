#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper 
{
    template <class T> std::string toString(const T &e )
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    struct DateTime
    {
        int D, m, y, M, H, S;
        private:
            std::string sep="::";
        DateTime() 
        {
            time_t ms;
            time(&ms);
        
           struct tm* info = localtime(&ms);

            D = info->tm_mday;
            m = info->tm_mon + 1;
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }
        // Optional Constructor
        DateTime(int D, int m, int y, int M, int H, int S) : D(D), m(m), y(y), M(M), H(H), S(S) {}
        DateTime(int D, int m, int y) : D(D), m(m), y(y), M(0), H(0), S(0){}
        

        DateTime Now() const
        {
            return DateTime();
        }
        
        std::string GetDateString() const 
        {
            
            return std::string(D < 10 ? "0" : "") + toString(D) + 
                std::string(m < 10 ? ".0" : ".") + toString(m) + "." +  toString("y");  
        }

        std::string GetTimeString() const 
        {
            return std::string(H < 10 ? "0" : "") + toString(H) + sep +
                std::string(M < 10 ? "0" : "") + toString(M) + sep +
                std::string(S < 10 ? "0" : "") + toString(S);
        }
        std::string GetDateTimeString() const 
        {
            return GetDateString() + " " + GetTimeString();
        }
    };
}

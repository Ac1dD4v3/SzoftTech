#ifndef DATUM_H
#define DATUM_H

#include <string>

using namespace std;
namespace valami{
    class Datum
    {
        string datum;
    public:
        Datum(const string& datum);
        friend ostream& operator<<(ostream& os,const Datum& datum){
            os<<datum;
            return os;
        }
        void setDatum(const string &newDatum);
    };
}
#endif // DATUM_H

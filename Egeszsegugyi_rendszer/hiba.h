#ifndef HIBA_H
#define HIBA_H
#include <exception>

class Hiba : public std::exception
{
public:
    // Konstruktor, amely beállítja az üzenetet, ami a hibát leírja
    Hiba(const char* message) : errorMessage(message) {}

    // Az std::exception-ból örökölt virtuális függvény felülírása, ami visszaadja az üzenetet
    virtual const char* what() const throw() {
        return errorMessage;
    }

private:
    const char* errorMessage;
};

#endif // HIBA_H

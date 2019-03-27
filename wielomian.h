//#include<ostream>

class Wielomian {

private:
int x[5];

public:
Wielomian();
~Wielomian();
friend std::ostream &operator<<(std::ostream &, const Wielomian &);
friend std::istream &operator>>(std::istream &, Wielomian &);
bool operator==(const Wielomian &) const;
bool operator!=(const Wielomian &) const;
Wielomian operator+(const Wielomian &) const;
void operator+=(Wielomian const&);
void operator-=(Wielomian const&);
Wielomian operator-(const Wielomian &) const;
Wielomian dx();

};

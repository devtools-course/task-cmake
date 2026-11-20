#include "logic.hxx"

string Implies::toString() const {
    return lhs.toString() + " -> " + rhs.toString();
}

string Var::toString() const {
    return name;
}

bool Var::operator==(const Var &b) const {
    return this->name == b.name;
}

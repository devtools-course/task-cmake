#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <string>

using std::string;

struct Term {
    virtual ~Term() = default;
    [[nodiscard]] virtual string toString() const = 0;
};

struct Var : Term {
    explicit Var(string &&name) : name(std::move(name)) {}
    [[nodiscard]] string toString() const override;

    bool operator==(const Var& b) const;

    string name;
};

struct Implies : Term {
    Implies(Var &lhs, Term &rhs) : lhs(lhs), rhs(rhs) {}
    [[nodiscard]] string toString() const override;

    Var  &lhs;
    Term &rhs;
};

Term *modus_ponens(const Var &A, const Implies &AB) {
    if (AB.lhs == A) {
        return &AB.rhs;
    }

    return nullptr;
}

#endif //LOGIC_HPP

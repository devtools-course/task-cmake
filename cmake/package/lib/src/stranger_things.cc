#include "stranger_things.hh"


namespace upside_down {
    bool Ctx::summon(std::string name) {
        Ctx::vecna_army()[name] = VecnaSoldier(name);
        return true; // dummy out
    }

    bool Ctx::steve_babysitter(std::string name, int power) {
        Ctx::hawkins()[name] = Human(name, power);
        return true; // dummy out
    }

    bool VecnaSoldier::operator==(const VecnaSoldier &other) const {
        return other.name == this->name;
    }

    bool Human::operator==(const Human &other) const {
        return this->name == other.name;
    }

    void Ctx::fight_helper(upside_down::Human &human, upside_down::VecnaSoldier &beast) {
        if (!human.is_alive) {
            std::cout << human.name << " is already dead!\n";
            return;
        }

        if (human.power <= beast.power) {
            human.is_alive = false;
            std::cout << human.name << " is dead!\n";
        } else {
            human.power -= beast.power;
            beast.power /= 2;
            std::cout << human.name << " has won!\n";
        }
    }

    bool Ctx::fight(upside_down::Human &human, upside_down::VecnaSoldier &beast) {
        upside_down::Ctx::battles().emplace_back([&]() {
            std::cout << human.name << " VS " << beast.name << '\n';
            Ctx::fight_helper(human, beast);
        });

        return true; // dummy output
    }

    std::map<std::string, VecnaSoldier> &Ctx::vecna_army() {
        static std::map<std::string, VecnaSoldier> instance;
        return instance;
    }

    std::map<std::string, Human> &Ctx::hawkins() {
        static std::map<std::string, Human> instance;
        return instance;
    }

    std::vector<std::function<void()>> &Ctx::battles() {
        static std::vector<std::function<void()>> instance;
        return instance;
    }
}

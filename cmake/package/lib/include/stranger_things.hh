#ifndef STRANGER_THINGS_HH
#define STRANGER_THINGS_HH

#include <string>
#include <utility>
#include <map>
#include <vector>
#include <iostream>
#include <functional>


namespace upside_down {
    struct Human {
        std::string name;
        int power = 0;
        bool is_alive = true;

        Human() = default;
        Human(std::string &name, int power) : name(name), power(power) {}
        Human(Human &)  = default;
        Human(Human &&) = default;

        Human(const Human &) = default;

        Human &operator=(Human &&)     = default;
        Human &operator=(Human const&) = default;
        bool operator==(const Human &other) const;
    };

    struct VecnaSoldier {
        std::string name;
        int power = 11;

        VecnaSoldier() = default;
        explicit VecnaSoldier(std::string &name) : name(name) {}
        VecnaSoldier(VecnaSoldier &)  = default;
        VecnaSoldier(VecnaSoldier &&) = default;

        VecnaSoldier(const VecnaSoldier &) = default;

        VecnaSoldier &operator=(VecnaSoldier &&)     = default;
        VecnaSoldier &operator=(VecnaSoldier const&) = default;
        bool operator==(const VecnaSoldier &other) const;
    };

    struct Ctx {
        static std::map<std::string, VecnaSoldier> &vecna_army();
        static std::map<std::string, Human> &hawkins();
        static std::vector<std::function<void()>> &battles();

        static bool summon(std::string name);
        static bool steve_babysitter(std::string name, int power);
        static bool fight(upside_down::Human &human, upside_down::VecnaSoldier &beast);
      private:
        static void fight_helper(upside_down::Human &human, upside_down::VecnaSoldier &beast);
    };
}

#define VECNA_SOLDIER(name) static bool name = upside_down::Ctx::summon(#name);
#define HUMAN(name, power) static bool name = upside_down::Ctx::steve_babysitter(#name, power);
#define BATTLE(human, beast) static bool human##_##beast = upside_down::Ctx::fight(\
    upside_down::Ctx::hawkins()[#human], \
    upside_down::Ctx::vecna_army()[#beast]);

#endif //STRANGER_THINGS_HH

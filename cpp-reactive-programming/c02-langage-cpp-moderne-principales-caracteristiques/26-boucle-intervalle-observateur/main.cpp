// объекты можно использовать в конструкциях наподобие
// for (auto l : EnumerableRange<5, 25>())
// { std::cout << l << ' '; }
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
template <long Start, long End>
class EnumerableRange
{
public:
    class iterable : public std::iterator<
                         std::input_iterator_tag, // catégorie
                         long,                    // type de valeur
                         long,                    // type de différence
                         const long *,            // type de pointeur
                         long>                    // type de référence
    {
        long current_num = Start;

    public:
        reference operator*() const { return current_num; }
        explicit iterable(long val = 0) : current_num(val) {}
        iterable &operator++()
        {
            current_num = (End >= Start)
                              ? current_num + 1
                              : current_num - 1;
            return *this;
        }
        iterable operator++(int)
        {
            iterable retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(iterable other) const
        {
            return current_num == other.current_num;
        }
        bool operator!=(iterable other) const
        {
            return !(*this == other);
        }
    };

    iterable begin() { return iterable(Start); }
    iterable end()
    {
        return iterable(End >= Start ? End + 1 : End - 1);
    }
};

// Ainsi, la classe définie ci-dessus peut être utilisée
// dans des structures de code de ce type :
for (auto l : EnumerableRange<5, 25>())
{
    std::cout << l << ' ';
}

struct Observer
{
    std::function<void(const long &)> ondata;
    std::function<void()> oncompleted;
    std::function<void(const std::exception &)> onexception;
};

template <long Start, long End>
class ObservableRange
{
private:
    // Conteneur des observateurs
    std::vector<std::pair<const Observer &, int>> _observers;
    int _id = 0;

    class iterable : public std::iterator<
                         std::input_iterator_tag, // catégorie
                         long,                    // type de valeur
                         long,                    // type de différence
                         const long *,            // type de pointeur
                         long>                    // type de référence
    {
        long current_num = Start;

    public:
        reference operator*() const
        {
            return current_num;
        }
        explicit iterable(long val = 0) : current_num(val)
        {
        }
        iterable &operator++()
        {
            current_num = (End >= Start)
                              ? current_num + 1
                              : current_num - 1;
            return *this;
        }
        iterable operator++(int)
        {
            iterable retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(iterable other) const
        {
            return current_num == other.current_num;
        }
        bool operator!=(iterable other) const
        {
            return !(*this == other);
        }
    };
    iterable begin()
    {
        return iterable(Start);
    }
    iterable end()
    {
        return iterable(End >= Start ? End + 1 : End - 1);
    }
    // Générer des valeurs dans un certain intervalle ;
    // Ce serait préférable d'appeler cette méthode avec std::async
    void generate_async()
    {
        auto &subscribers = _observers;
        for (auto l : *this)
            for (const auto &obs : subscribers)
            {
                const Observer &ob = obs.first;
                ob.ondata(l);
            }
    }

public:
    // Génération de séquence ; la méthode generate_async est préférable
    // Elle doit être appelée via std::async pour libérer immédiatement le contrôle
    void generate() { generate_async(); }
    // Abonnement des observateurs
    virtual int subscribe(const Observer &call)
    {
        _observers.emplace_back(call, ++_id);
        return _id;
    }
    // La désinscription d'un observateur n'est pas implémentée
    // ici pour simplifier l'exemple
    virtual void unsubscribe(const int subscription)
    {
    }
};

int main()
{
    // Utiliser une boucle pour parcourir un intervalle
    for (long l : EnumerableRange<5, 25>())
    {
        std::cout << l << ' ';
    }
    std::cout << std::endl;
    // Créer une instance de la classe ObservableRange
    auto j = ObservableRange<10, 20>();
    // Créer un observateur
    Observer test_handler;
    test_handler.ondata = [=](const long &r)
    {
        std::cout << r << std::endl;
    };
    // Abonner l'observateur aux événements de la source
    int cnt = j.subscribe(test_handler);
    j.generate(); // Démarrer le générateur
    return 0;
}

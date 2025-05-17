#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    bool operator==(const Character& other) const {
        return name == other.name && health == other.health;
    }

    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        os << "Персонаж: " << character.name
           << ", ХП: " << character.health
           << ", Aтака: " << character.attack
           << ", Защита: " << character.defense;
        return os;
    }
};

class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(const std::string& n, int d) : name(n), damage(d) {}

    std::string getName() const { return name; }
    int getDamage() const { return damage; }

    Weapon operator+(const Weapon& other) const {
        std::string newName = name + "-" + other.name;
        int newDamage = damage + other.damage;
        return Weapon(newName, newDamage);
    }

    bool operator>(const Weapon& other) const {
        return damage > other.damage;
    }

    bool operator==(const Weapon& other) const {
        return name == other.name && damage == other.damage;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Оружие: " << weapon.name << ", Урон: " << weapon.damage;
        return os;
    }
};

int main() {
    Character hero1("Герой", 100, 20, 10);
    Character hero2("Герой", 100, 25, 15); 

    if (hero1 == hero2) {
        std::cout << "Герой 1 и Герой 2 одинаковы!\n";
    }
    else {
        std::cout << "Герой 1 и Герой 2 разные!\n";
    }

    std::cout << hero1 << std::endl;

    Weapon sword("Меч", 40);
    Weapon bow("Лук", 30);

    Weapon combined = sword + bow;
    std::cout << "Парное оружие: " << combined << std::endl;

    if (sword > bow) {
        std::cout << sword.getName() << " сильнее чем " << bow.getName() << std::endl;
    }

    if (sword == Weapon("Меч", 40)) {
        std::cout << "Меч соответствует ожидаемому оружию.\n";
    }

    std::cout << sword << std::endl;
    std::cout << bow << std::endl;

    return 0;
}

#ifndef CRPGAME_ITEMS_H
#define CRPGAME_ITEMS_H

template <class T>
concept is_have_hp = requires(T m) {
    m.setHitPoint();
    m.getHitPoint();
};

class HealthPotion
{
private:
    int potion_power;
public:
    explicit HealthPotion(int potion_power = 0):potion_power(potion_power) { }

    template<is_have_hp T>
    void Use(T target)
    {
        target.setHitPoint(target.getHitPoint()+potion_power);
    }
};



#endif

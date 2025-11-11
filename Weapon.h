#ifndef WEAPON_H_
#define WEAPON_H_

#include "Structs.h"
#include "Defines.h"
#include <iostream>

class Weapon
{
public:
    Weapon(const WeaponDamage damagePerRound,
           const ClipSizes clipSize,
           const AmmoCapacity remainingAmmo,
           const WeaponAccuracy accuracy) : _damagePerRound(static_cast<int>(damagePerRound)),
                                            _clipSize(static_cast<int>(clipSize)),
                                            _currClipBullets(static_cast<int>(clipSize)),
                                            _remainingAmmo(static_cast<int>(remainingAmmo)),
                                            _accuracy(static_cast<int>(accuracy)) {}

    virtual ~Weapon() = default;

    virtual bool fire(PlayerVitalData& enemyPlayerData) = 0;

    void reload()
    {
        if (_remainingAmmo == 0)
        {
            std::cout << "No ammo left\n";
            return;
        }

        while ((_currClipBullets < _clipSize) && (_remainingAmmo > 0))
        {
            --_remainingAmmo;
            ++_currClipBullets;
        }

        std::cout << "Reloading...\n"
                  << "currClipBullets: " << _currClipBullets
                  << ", remainingAmmo: " << _remainingAmmo << '\n';
    }

    int getCurrClipBullets() const { return _currClipBullets; }

protected:
    void applyDamage(PlayerVitalData& enemy, double armorFraction)
    {
        int armorDamage = static_cast<int>(_damagePerRound * armorFraction);
        int healthDamage = _damagePerRound - armorDamage;

        if (enemy.armor > 0)
        {
            if (enemy.armor >= armorDamage)
            {
                enemy.armor -= armorDamage;
                enemy.health -= healthDamage;
            }
            else
            {
                int leftover = armorDamage - enemy.armor;
                enemy.armor = 0;
                enemy.health -= healthDamage + leftover;
            }
        }
        else
        {
            enemy.health -= _damagePerRound;
        }

        if (enemy.health < 0){ 
            enemy.health = 0;
            enemy.armor = 0;
        }

        std::cout << "Enemy left with: " << enemy.health 
                  << " health and " << enemy.armor << " armor\n";
    }

protected:
    int _damagePerRound;
    int _clipSize;
    int _currClipBullets;
    int _remainingAmmo;
    int _accuracy;
};

#endif /* WEAPON_H_ */

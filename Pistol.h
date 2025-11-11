#ifndef PISTOL_H_
#define PISTOL_H_

#include "Structs.h"
#include "Defines.h"
#include "Weapon.h"

#include <iostream>

class Pistol : public Weapon
{
	public:
		Pistol(const WeaponDamage damagePerRound,
			   const ClipSizes clipSize,
			   const AmmoCapacity remainingAmmo,
			   const WeaponAccuracy accuracy) : Weapon(damagePerRound, clipSize, remainingAmmo, accuracy){}
};

#endif /* PISTOL_H_ */

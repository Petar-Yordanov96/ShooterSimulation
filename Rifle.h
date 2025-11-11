#ifndef RIFLE_H_
#define RIFLE_H_

#include "Structs.h"
#include "Defines.h"
#include "Weapon.h"

#include <iostream>

class Rifle : public Weapon
{
	public:
		Rifle(const WeaponDamage damagePerRound,
			  const ClipSizes clipSize,
			  const AmmoCapacity remainingAmmo,
			  const WeaponAccuracy accuracy) : Weapon(damagePerRound, clipSize, remainingAmmo, accuracy){}

};

#endif /* RIFLE_H_ */

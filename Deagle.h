#ifndef DEAGLE_H
#define DEAGLE_H

#include "Pistol.h"

class Deagle : public Pistol
{	

	public:
		Deagle(const WeaponDamage damagePerRound,
			   const ClipSizes clipSize,
			   const AmmoCapacity remainingAmmo,
			   const WeaponAccuracy accuracy);

		virtual ~Deagle() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;
};

#endif /* DEAGLE_H_ */
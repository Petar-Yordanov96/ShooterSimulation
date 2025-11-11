#ifndef GALIL_H_
#define GALIL_H_

#include "Rifle.h"

class Galil : public Rifle
{	

	public:
		Galil(const WeaponDamage damagePerRound,
			  const ClipSizes clipSize,
			  const AmmoCapacity remainingAmmo,
			  const WeaponAccuracy accuracy);

		virtual ~Galil() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;
};

#endif /* GALIL_H_ */
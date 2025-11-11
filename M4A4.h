#ifndef M4A4_H_
#define M4A4_H_

#include "Rifle.h"

class M4A4 : public Rifle
{	

	public:
		M4A4(const WeaponDamage damagePerRound,
			 const ClipSizes clipSize,
			 const AmmoCapacity remainingAmmo,
			 const WeaponAccuracy accuracy);

		virtual ~M4A4() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;
};

#endif /* M4A4_H_ */
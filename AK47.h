#ifndef AK47_H_
#define AK47_H_

#include "Rifle.h"

class AK47 : public Rifle
{	

	public:
		AK47(const WeaponDamage damagePerRound,
			 const ClipSizes clipSize,
			 const AmmoCapacity remainingAmmo,
			 const WeaponAccuracy accuracy);

		virtual ~AK47() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;
};

#endif /* AK47_H_ */

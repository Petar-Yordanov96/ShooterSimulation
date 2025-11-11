#ifndef USP_H_
#define USP_H_

#include "Pistol.h"

class Usp : public Pistol
{	

	public:
		Usp(const WeaponDamage damagePerRound,
			const ClipSizes clipSize,
			const AmmoCapacity remainingAmmo,
			const WeaponAccuracy accuracy);

		virtual ~Usp() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;
};

#endif /* USP_H_ */
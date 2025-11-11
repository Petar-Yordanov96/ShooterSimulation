#ifndef GLOCK_H_
#define GLOCK_H_

#include "Pistol.h"

class Glock : public Pistol
{

	public:
		Glock(const WeaponDamage damagePerRound,
			  const ClipSizes clipSize,
			  const AmmoCapacity remainingAmmo,
			  const WeaponAccuracy accuracy);

		virtual ~Glock() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;

	private:
		enum InternalDefines
		{
			ROUNDS_PER_FIRE = 3
		};
};

#endif /* GLOCK_H_ */

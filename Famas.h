#ifndef FAMAS_H_
#define FAMAS_H_

#include "Rifle.h"

class Famas : public Rifle
{

	public:
		Famas(const WeaponDamage damagePerRound,
			  const ClipSizes clipSize,
			  const AmmoCapacity remainingAmmo,
			  const WeaponAccuracy accuracy);

		virtual ~Famas() = default;

		virtual bool fire(PlayerVitalData & enemyPlayerData) override;

	private:
		enum InternalDefines
		{
			ROUNDS_PER_FIRE = 3
		};
};

#endif /* FAMAS_H_ */

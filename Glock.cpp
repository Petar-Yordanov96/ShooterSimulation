#include "Pistol.h"
#include "Glock.h"


Glock::Glock(const WeaponDamage damagePerRound,
			 const ClipSizes clipSize,
			 const AmmoCapacity remainingAmmo,
			 const WeaponAccuracy accuracy) : Pistol(damagePerRound, clipSize, remainingAmmo, accuracy) {};

bool Glock::fire(PlayerVitalData & enemyPlayerData){
			bool dead = false;

			for(int i = 0; i < ROUNDS_PER_FIRE; i++){

				if(_currClipBullets == 0){
					reload();
					return false;
				}
				_currClipBullets--;

				int roll = rand() % 100; // random 0-99
				if (roll < _accuracy)
				{
					std::cout << "Hit!\n";
					applyDamage(enemyPlayerData, 0.45);
				}
				else
				{
					std::cout << "Missed the shot!\n";
				}
				
				if(enemyPlayerData.health <= 0){
					dead = true;
					return dead;
				}
			}

			return dead;			
};              
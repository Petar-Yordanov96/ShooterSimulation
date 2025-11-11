#include "Rifle.h"
#include "Player.h"
#include "Famas.h"
#include "AK47.h"

Famas::Famas(const WeaponDamage damagePerRound,
			 const ClipSizes clipSize,
			 const AmmoCapacity remainingAmmo,
			 const WeaponAccuracy accuracy) : Rifle(damagePerRound, clipSize, remainingAmmo, accuracy) {};

bool Famas::fire(PlayerVitalData & enemyPlayerData){
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
					applyDamage(enemyPlayerData, 0.35);
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
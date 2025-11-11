#include "Pistol.h"
#include "Player.h"
#include "Deagle.h"

Deagle::Deagle(const WeaponDamage damagePerRound,
			   const ClipSizes clipSize,
			   const AmmoCapacity remainingAmmo,
			   const WeaponAccuracy accuracy) : Pistol (damagePerRound, clipSize, remainingAmmo, accuracy) {};

bool Deagle::fire(PlayerVitalData & enemyPlayerData){

			if(_currClipBullets == 0){
				reload();
				return false;
			}
			_currClipBullets--;

			int roll = rand() % 100; // random 0-99
			if (roll < _accuracy)
			{
				std::cout << "Hit!\n";
				applyDamage(enemyPlayerData, 0.20);
			}
			else
			{
				std::cout << "Missed the shot!\n";
			}
				
			return enemyPlayerData.health <= 0;
};
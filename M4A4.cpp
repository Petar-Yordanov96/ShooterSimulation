#include "Rifle.h"
#include "Player.h"
#include "M4A4.h"

M4A4::M4A4(const WeaponDamage damagePerRound,
		   const ClipSizes clipSize,
		   const AmmoCapacity remainingAmmo,
		   const WeaponAccuracy accuracy) : Rifle(damagePerRound, clipSize, remainingAmmo, accuracy) {};
					
bool M4A4::fire(PlayerVitalData & enemyPlayerData){

			if(_currClipBullets == 0){
				reload();
				return false;
			}
			_currClipBullets--;

			int roll = rand() % 100; // random 0-99
			if (roll < _accuracy)
			{
				std::cout << "Hit!\n";
				applyDamage(enemyPlayerData, 0.25);
			}
			else
			{
				std::cout << "Missed the shot!\n";
			}
				
			return enemyPlayerData.health <= 0;
};
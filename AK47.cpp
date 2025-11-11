#include "Rifle.h"
#include "Player.h"
#include "AK47.h"

AK47::AK47(const WeaponDamage damagePerRound,
		   const ClipSizes clipSize,
		   const AmmoCapacity remainingAmmo,
		   const WeaponAccuracy accuracy) : Rifle(damagePerRound, clipSize, remainingAmmo, accuracy) {};
					
bool AK47::fire(PlayerVitalData & enemyPlayerData){
	
			if(_currClipBullets == 0){
				reload();
				return false;
			}

			_currClipBullets--;

			int roll = rand() % 100; 
			if (roll < _accuracy)
			{
				std::cout << "Hit!\n";
				applyDamage(enemyPlayerData, 0.15);
			}
			else
			{
				std::cout << "Missed the shot!\n";
			}
				
			return enemyPlayerData.health <= 0;
};
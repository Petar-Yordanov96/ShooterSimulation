#ifndef PLAYER_H_
#define PLAYER_H_

#include "Rifle.h"
#include "Pistol.h"
#include "Defines.h"
#include "Structs.h"

class Player
{
	public:
		Player(const int health,
			   const int armor,
			   const int funds,
			   const int playerId) : _currWeapon(nullptr),
			   						 _rifle(nullptr),
									 _pistol(nullptr),
									 _vitalData(health, armor),
									 _playerId(playerId),
									 _funds(funds)
		{

		}

		~Player()
		{
			delete _rifle;
			delete _pistol;
		}

		bool canAfford(const int cost) const {
			return _funds >= cost;
		}

		void spendFunds(const int cost){
			_funds -= cost;
		}

		int getFunds() const {
			return _funds;
		}

		void buyRifle(const RifleType rifleType);
		void buyPistol(const PistolType pistolType);
		

		bool fireAtEnemy(PlayerVitalData & enemyPlayerData)
		{
			std::cout << "PlayerID " << _playerId << " turn:\n";

			const bool result = _currWeapon->fire(enemyPlayerData);

			std::cout << '\n';

			if(_rifle != nullptr && _rifle->getCurrClipBullets() == 0 && _pistol != nullptr){
				std::cout << "Rifle magazine empty! Switching to pistol.\n";
				_currWeapon = _pistol;
			}

			return result;
		}

		PlayerVitalData & getVitalData()
		{
			return _vitalData;
		}

	private:
		Weapon * 		_currWeapon;
		Rifle*  		_rifle;
    	Pistol* 		_pistol;

		PlayerVitalData _vitalData;

		int             _playerId;
		int 			_funds;
};

#endif /* PLAYER_H_ */

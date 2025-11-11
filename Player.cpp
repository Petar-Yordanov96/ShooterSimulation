#include "Rifle.h"
#include "Pistol.h"
#include "Player.h"
#include "Famas.h"
#include "AK47.h"
#include "Galil.h"
#include "M4A4.h"
#include "Glock.h"
#include "Usp.h"
#include "Deagle.h"

void Player::buyRifle(const RifleType rifleType)
{
	switch(rifleType){
		case RifleType::AK47:
			_rifle = new AK47(WeaponDamage::AK47, ClipSizes::AK47, AmmoCapacity::AK47, WeaponAccuracy::AK47);
		break;

		case RifleType::M4A4:
			_rifle = new M4A4(WeaponDamage::M4A4, ClipSizes::M4A4, AmmoCapacity::M4A4, WeaponAccuracy::M4A4);
		break;

		case RifleType::GALIL:
			_rifle = new Galil( WeaponDamage::GALIL,  ClipSizes::GALIL, AmmoCapacity::GALIL, WeaponAccuracy::GALIL);
		break;

		case RifleType::FAMAS:
			_rifle = new Famas(WeaponDamage::FAMAS, ClipSizes::FAMAS, AmmoCapacity::FAMAS, WeaponAccuracy::FAMAS);
		break;
	}
	
	_currWeapon = _rifle;
}

void Player::buyPistol(const PistolType pistolType)
{
	switch(pistolType){
		case PistolType::GLOCK:
			_pistol = new Glock(WeaponDamage::GLOCK, ClipSizes::GLOCK, AmmoCapacity::GLOCK, WeaponAccuracy::GLOCK);
		break;

		case PistolType::USP:
			_pistol = new Usp(WeaponDamage::USP, ClipSizes::USP, AmmoCapacity::USP, WeaponAccuracy::USP);
		break;

		case PistolType::DEAGLE:
			_pistol = new Deagle(WeaponDamage::DEAGLE, ClipSizes::DEAGLE, AmmoCapacity::DEAGLE, WeaponAccuracy::DEAGLE);
		break;
	}

	if(_currWeapon == nullptr && _rifle == nullptr) 
		_currWeapon = _pistol;
}					   
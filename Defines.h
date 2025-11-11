#ifndef DEFINES_H_
#define DEFINES_H_

enum class WeaponPrice
{
    GLOCK  = 300,
    USP    = 500,
    DEAGLE = 650,

    GALIL  = 2000,
    FAMAS  = 2250,
    AK47   = 2700,
    M4A4   = 3100
};

enum class WeaponDamage
{
    GLOCK  = 20,
    USP    = 25,
    DEAGLE = 60,

    GALIL  = 28,
    FAMAS  = 28,
    AK47   = 35,
    M4A4   = 32
};

enum class WeaponAccuracy
{
    M4A4  = 80,   
    AK47  = 75,
    FAMAS = 70,
    GALIL = 65,

    USP    = 75,
    GLOCK  = 70,
    DEAGLE = 60
};

enum class RifleType
{
	FAMAS		 = 0,
	GALIL        = 1,
	AK47         = 2,
	M4A4         = 3,
};

enum class PistolType
{
	GLOCK		 = 0,
	USP          = 1,
	DEAGLE       = 2,
};

enum class ClipSizes{
	FAMAS		 = 25,
	GALIL        = 35,
	AK47         = 30,
	M4A4         = 20,
	//Pistols
	GLOCK        = 17,
	USP          = 12,
	DEAGLE       = 7

};

enum class AmmoCapacity
{
    // Rifles
    AK47   = 90,
    GALIL  = 70,
    M4A4   = 80,
    FAMAS  = 75,

    // Pistols
    DEAGLE = 35,
    GLOCK  = 51,
    USP    = 60
};

enum GeneralDefines
{
	PLAYER_ONE    = 0,
	PLAYER_TWO    = 1,

	PLAYERS_COUNT = 2
};


#endif /* DEFINES_H_ */

#include <iostream>
#include <vector>
#include <ctime>

#include "Player.h"

int main()
{   
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
	std::vector<Player> players;
	players.reserve(PLAYERS_COUNT);

	for (int i = 0; i < PLAYERS_COUNT; ++i){
    
        int health, armor, funds;
        std::cout << "Enter health and armor for player " << i << ": ";
        std::cin >> health >> armor;

        std::cout << "Enter funds for player " << i << ": ";
        std::cin >> funds;

        // Check minimum funds
        while ((i == 0 && funds < 300) || (i == 1 && funds < 500))
        {
            std::cout << "Insufficient funds, please add more: ";
            std::cin >> funds;
        }

        players.emplace_back(health, armor, funds, i);

        // Available weapon options differ for each player
        std::cout << "\nPlayer " << i << " can buy:\n\n";

        if (i == 0)
        {
            std::cout << "Rifles: 1. Galil " << (int)WeaponPrice::GALIL
                      << "$" << std::endl << "        2. AK-47 " << (int)WeaponPrice::AK47 << "$\n";
			std::cout << std::endl;
            std::cout << "Pistols: 1. Glock  " << (int)WeaponPrice::GLOCK << "$ " << std::endl 
					  << "         2. Deagle " << (int)WeaponPrice::DEAGLE << "$\n";
        }
        else
        {	
            std::cout << "Rifles: 1. Famas " << (int)WeaponPrice::FAMAS
                      << "$" << std::endl << "        2. M4A4  " << (int)WeaponPrice::M4A4 << "$\n";
			std::cout << std::endl;
            std::cout << "Pistols: 1. USP    " << (int)WeaponPrice::USP << "$ " << std::endl 
					  << "         2. Deagle " << (int)WeaponPrice::DEAGLE << "$\n";			
        }

        int choice;
        std::cout << "Choose a rifle (1/2 or 0 for none): ";
        std::cin >> choice;

        if (i == 0)
        {
            if (choice == 1){
                if (players[i].canAfford((int)WeaponPrice::GALIL))
                {
                    players[i].buyRifle(RifleType::GALIL);
                    players[i].spendFunds((int)WeaponPrice::GALIL);
                }
                else
                {
                    std::cout << "Not enough funds to buy Galil!\n";
                }
            }
            else if (choice == 2){
                if (players[i].canAfford((int)WeaponPrice::AK47))
                {
                    players[i].buyRifle(RifleType::AK47);
                    players[i].spendFunds((int)WeaponPrice::AK47);
                }
                else
                {
                    std::cout << "Not enough funds to buy AK-47!\n";
                }
            }
        }
        else
        {
            if (choice == 1){
                if (players[i].canAfford((int)WeaponPrice::FAMAS))
                {
                    players[i].buyRifle(RifleType::FAMAS);
                    players[i].spendFunds((int)WeaponPrice::FAMAS);
                }
                else
                {
                    std::cout << "Not enough funds to buy Famas!\n";
                }
            }
            else if (choice == 2){
                if (players[i].canAfford((int)WeaponPrice::M4A4))
                {
                    players[i].buyRifle(RifleType::M4A4);
                    players[i].spendFunds((int)WeaponPrice::M4A4);
                }
                
                else
                {
                    std::cout << "Not enough funds to buy M4A4!\n";
                }
            }
        }

        std::cout << "Choose a pistol (1/2 or 0 for none): ";
        std::cin >> choice;

        if (i == 0)
        {
            if (choice == 1){
                if (players[i].canAfford((int)WeaponPrice::GLOCK))
                {
                    players[i].buyPistol(PistolType::GLOCK);
                    players[i].spendFunds((int)WeaponPrice::GLOCK);
                }
                else
                {
                    std::cout << "Not enough funds to buy Glock!\n";
                }
            }
            else if (choice == 2){
                if (players[i].canAfford((int)WeaponPrice::DEAGLE))
                {
                    players[i].buyPistol(PistolType::DEAGLE);
                    players[i].spendFunds((int)WeaponPrice::DEAGLE);
                }
                else
                {
                    std::cout << "Not enough funds to buy Deagle!\n";
                }
            }
        }
        else
        {
            if (choice == 1){
                if (players[i].canAfford((int)WeaponPrice::USP))
                {
                    players[i].buyPistol(PistolType::USP);
                    players[i].spendFunds((int)WeaponPrice::USP);
                }
                else
                {
                    std::cout << "Not enough funds to buy USP!\n";
                }
            }
            else if (choice == 2){
                if (players[i].canAfford((int)WeaponPrice::DEAGLE))
                {
                    players[i].buyPistol(PistolType::DEAGLE);
                    players[i].spendFunds((int)WeaponPrice::DEAGLE);
                }
                else
                {
                    std::cout << "Not enough funds to buy Deagle!\n";
                }
            }
        }

        std::cout << "Remaining funds: $" << players[i].getFunds() << "\n\n";
    }

	while(true)
	{
		if(players[PLAYER_ONE].fireAtEnemy(players[PLAYER_TWO].getVitalData())){
			std::cout << "Player with ID: " << PLAYER_ONE << " wins!\n";
			break;
		}

		if(players[PLAYER_TWO].fireAtEnemy(players[PLAYER_ONE].getVitalData())){
			std::cout << "Player with ID: " << PLAYER_TWO << " wins!\n";
			break;
		}
	}

	return 0;
}

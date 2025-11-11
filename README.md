# ShooterSimulation
A basic C++ console game simulating a 1v1 Counter-Strike–style gunfight between two players.   Players can purchase rifles and pistols, manage funds, and engage in alternating attacks with hit/miss probabilities and armor-based damage calculations.

## Gameplay Overview

1. **Setup Phase:**
   - Each player inputs their health, armor, and available funds.
   - Players use their funds to buy one rifle and one pistol (if funds are sufficient).
   - If a player doesn’t have enough money for a weapon, the program displays a “Not enough funds!” message.

2. **Combat Phase:**
   - Players take turns firing at each other.
   - Each shot rolls a random number against the weapon’s accuracy.
   - If the shot hits, damage is applied to the opponent’s armor and health.
   - When a weapon’s magazine is empty, the player automatically reloads or switches to their pistol if rifle ammo is depleted.
   - The game continues until one player’s health reaches zero.

---

## Weapon System

Each weapon is defined by:
- **Damage per round**
- **Clip size**
- **Ammo capacity**
- **Accuracy percentage**

### Rifles
| Weapon | Damage | Accuracy | Ammo | Price |
|---------|---------|-----------|--------|--------|
| M4A4   | 32 | 80% | 80 | $3100 |
| AK-47  | 35 | 75% | 90 | $2700 |
| Famas  | 28 | 70% | 75 | $2250 |
| Galil  | 28 | 65% | 70 | $2000 |

### Pistols
| Weapon | Damage | Accuracy | Ammo | Price |
|---------|---------|-----------|--------|--------|
| USP     | 25 | 75% | 60 | $500 |
| Glock   | 20 | 70% | 51 | $300 |
| Deagle  | 60 | 60% | 35 | $650 |

---

## Class Structure

- **`Weapon`** – Abstract base class for all firearms. Handles ammo, reloading, and applying damage.  
- **`Rifle`** / **`Pistol`** – Derived weapon types that inherit from `Weapon`.  
- **Specific weapons** (e.g., `AK47`, `M4A4`, `Glock`, `Deagle`) override the `fire()` method with custom logic.  
- **`Player`** – Manages health, armor, funds, and owned weapons. Handles buying and switching between rifle/pistol.  
- **`main.cpp`** – Game loop for setup, weapon selection, and turn-based combat.  

---

## Technical Highlights

- Uses `enum class` for strong typing and clarity.
- Random hit chance determined via `rand()` seeded with `time(nullptr)`.
- Automatic pistol switching when rifle ammo depletes.
- Armor-based damage reduction with proportional health loss.
- Fully modular — new weapons can be added easily by extending the hierarchy.

🍔 Fast‑Food Ordering System — Code Description
🎯 Overview
This project implements a modular, object‑oriented Fast‑Food ordering system in C++.
It allows users to purchase individual items (drinks and foods), create discounted combos, and apply account‑specific dietary restrictions.
The system is fully polymorphic, memory‑safe, and designed for extensibility.

🧱 Architecture
1. Item Hierarchy
At the core of the system is the abstract base class:
class Item {
    virtual double price() const = 0;
    virtual bool healthy() const = 0;
    virtual void print() const = 0;
};


Every product in the system inherits from Item, ensuring:
- consistent interface
- polymorphic behavior
- clean printing
- unified price calculation
Drink subclasses
- Cola
- Orange_juce
- Water
Each drink stores:
- volume (ml)
- sugar flag
- price calculation
- health evaluation
Food subclasses
- Hamburger
- Pizza
- Fries
Each food stores:
- weight (g)
- spicy/unhealthy flag
- price calculation
- health evaluation

2. Combo System
The Combo<T1, T2> template class allows combining any two Item objects into a single discounted product.
Key features:
- Stores Item* pointers (avoids slicing)
- Owns and deletes its items safely
- Applies automatic discounts:
- 10% for same‑type combos (Drink+Drink or Food+Food)
- 15% for mixed combos (Drink+Food or Food+Drink)
- Fully polymorphic: behaves like any other Item

3. Account Types
The system supports three account categories:
Kid_account
- Cannot purchase unhealthy/spicy foods
- System asks whether to remove restricted items
Special_account
- Cannot consume sugar or unhealthy foods
- For sugary drinks, user may:
- remove the item
- convert it to sugar‑free
Adult_account
- No restrictions
Each account type inherits from Account and uses runtime polymorphism (dynamic_cast) to enforce rules.

4. Buying Workflow
The Account::buy() function handles the entire user interaction:
Features:
- Live cart preview before each menu display
- Menu for selecting:
- individual items
- combos
- Items stored in std::vector<Item*>
- After buying, restrictions are applied
- Final cart is printed with total price
The system ensures:
- no memory leaks
- no double deletes
- correct polymorphic behavior

5. Offers Menu
The FastFood::show_offers() function displays predefined combo offers:
- Drink + Drink (10% OFF)
- Drink + Food (15% OFF)
- Food + Drink (15% OFF)
- Food + Food (10% OFF)
These offers match the discount logic implemented in Combo::price().

🧠 Design Strengths
✔ Strong OOP design
Clear separation of concerns, polymorphism, and virtual functions.
✔ Extensible
Adding new items or account types requires minimal changes.
✔ Safe memory management
Combos own their items; accounts delete purchased items.
✔ Realistic dietary restrictions
Kid and special accounts enforce health rules interactively.
✔ Clean user experience
Live cart preview, readable menus, and consistent formatting.
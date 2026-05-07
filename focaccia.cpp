/**
 * focaccia.cpp
 *
 * Gabriel Lang
 * gabelang
 *
 * EECS 183: Project 1
 * Winter 2022
 * 
 * Project UID: fde244392017fe65ebcc34f01c226b11f113bb3dc6dae8af4cb6ea11bf76f7c8
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    // Assign constant values for number of needed ammounts of each ingredient
    // per loaf and total ammounts of each ingredient per package of each
    // ingredient. calculates the number of loaves needed to feed a given
    // number of people. assign formulas to calculate the number of needed
    // packages of each ingredient to make a given number of loaves rounded up
    // to the nearest whole number.
    
    const double CUPS_FLOUR_PER_BAG = 20;
    const double CUPS_FLOUR_PER_LOAF = 5;
    const double TEASPOONS_YEAST_PER_PACK = 2.25;
    const double TEASPOONS_YEAST_PER_LOAF = 1.75;
    const double TEASPOONS_SALT_PER_CANISTER = 6;
    const double TEASPOONS_SALT_PER_LOAF = 1.875;
    const double TABLESPOONS_OLIVEOIL_PER_BOTTLE = (500 / 14.8);
    const double TABLESPOONS_OIVEOIL_PER_LOAF = 2;
    const double PEOPLE_PER_LOAF = 4.0;
    int loaves = ceil(people / PEOPLE_PER_LOAF);
    int bagsFlour = ceil((CUPS_FLOUR_PER_LOAF * loaves) / (CUPS_FLOUR_PER_BAG));
    int packsYeast = ceil((loaves * TEASPOONS_YEAST_PER_LOAF) /
                          (TEASPOONS_YEAST_PER_PACK));
    int canistersSalt = ceil((loaves * TEASPOONS_SALT_PER_LOAF) /
                             (TEASPOONS_SALT_PER_CANISTER));
    int bottlesOliveOil = ceil((loaves * TABLESPOONS_OIVEOIL_PER_LOAF) /
                               (TABLESPOONS_OLIVEOIL_PER_BOTTLE));
    
    // assign constant prices for each ingredient per package and calculates
    // the total cost of the needed number of packages of each ingredient and
    // the total cost of ingredients for a given number of loaves
    
    const double PRICE_PER_BAG_FLOUR = 2.69;
    double costBagsFlour = (bagsFlour * PRICE_PER_BAG_FLOUR);
    const double PRICE_PER_PACK_YEAST = 0.40;
    double costPacksYeast = (packsYeast * PRICE_PER_PACK_YEAST);
    const double PRICE_PER_CANISTER_SALT = 0.49;
    double costCanistersSalt = (canistersSalt * PRICE_PER_CANISTER_SALT);
    const double PRICE_PER_BOTTLE_OLIVE_OIL = 6.39;
    double costBottlesOliveOil = (bottlesOliveOil * PRICE_PER_BOTTLE_OLIVE_OIL);
    double totalCostIngredients = (costBagsFlour + costPacksYeast +
                                   costCanistersSalt + costBottlesOliveOil);
    
    cout << "You need to make: " << loaves << " "
    << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl;
    cout << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    cout << bagsFlour << " " << pluralize("bag", "bags", bagsFlour)
    << " of flour" << endl;
    cout << packsYeast << " " << pluralize("package", "packages", packsYeast)
    << " of yeast" << endl;
    cout << canistersSalt << " "
    << pluralize("canister", "canisters", canistersSalt) << " of salt" << endl;
    cout << bottlesOliveOil << " "
    << pluralize("bottle", "bottles", bottlesOliveOil) << " of olive oil" << endl;
    cout << endl;
    cout << "Total expected cost of ingredients: " << "$"
    << totalCostIngredients << endl;
    cout << endl;
    cout << "Have a great party!" << endl;
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}

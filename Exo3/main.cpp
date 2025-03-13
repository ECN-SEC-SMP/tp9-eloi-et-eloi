/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 3 LES LISTES
 *        — Créez une liste de huit entiers.
 *        — Supprimez le troisième élément.
 *        — Affichez à nouveau votre liste.
 *        Remarque : vous devezutiliser des itérateurs
 * @version 0.1
 * @date 13-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief main
 * 
 * @return int 
 */
int main()
{
    // Créez une liste de huit entiers.
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};
    
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    // Supprimez le troisième élément.
    list.erase(list.begin() + 2);

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
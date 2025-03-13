/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @brief 1 VECTEUR D’ENTIERS
 *        Créez un code qui permet de faire les actions suivantes :
 *        — définissez d’un vecteur stockant des entiers sans spécifier de taille
 *        — dimensionnez le a une taille de 3
 *        — affectez 3 valeurs
 *        — parcourez et affichez votre vecteur de 3 manières différentes :
 *        — avec des indices
 *        — en exécutant une boucle sur une plage de nombres (C++11 rangebasedloophttps:
 *        //en.cppreference.com/w/cpp/language/range-for)
 *        — à l’aide d’un itérateur
 *        — ajoutez un nouvel élément en fin de vecteur avec vérifiez que la taille a été modifiée
 *        — copiez le premier vecteur dans d’autres vecteurs en utilisant copy et/ou assign
 * @version 0.1
 * @date 13-03-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Définissez d’un vecteur stockant des entiers sans spécifier de taille
    vector<int> vec;

    // Dimensionnez le a une taille de 3
    vec.resize(3);

    // Affectez 3 valeurs
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;

    // Parcourez et affichez votre vecteur de 3 manières différentes :
    /* Avec des indices */
    cout << "Avec des indices" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    /* En exécutant une boucle sur une plage de nombres (C++11 rangebasedloop) */
    cout << "En exécutant une boucle" << endl;
    for (int i : vec)
    {
        cout << i << endl;
    }

    /* À l’aide d’un itérateur */
    cout << "En utilisant un itérateur" << endl;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }

    // Ajoutez un nouvel élément en fin de vecteur avec vérifiez que la taille a été modifiée
    cout << "Taille initiale   : " << vec.size() << endl;
    vec.push_back(4);
    cout << "Taille après push : " << vec.size() << endl;

    // Copiez le premier vecteur dans d’autres vecteurs en utilisant copy et/ou assign
    vector<int> vec2;
    copy(vec.begin(), vec.end(), back_inserter(vec2));
    cout << "vec2 copy de vec" << endl;
    for (int i : vec2)
    {
        cout << i << endl;
    }

    vector<int> vec3;
    vec3.assign(vec.begin(), vec.end());
    cout << "vec3 assign de vec" << endl;
    for (int i : vec3)
    {
        cout << i << endl;
    }

    return 0;
}
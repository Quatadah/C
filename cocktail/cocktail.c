#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INGREDIENTS 10

struct product {
  int id;           // `id` correspond à son indice dans le stock.
  const char *name; // Le nom d'un produit
  int quantity;     // La quantité disponible dans le stock
  int unit_price;   // Le prix unitaire d'un produit
};

struct ingredient {
  int product_id; // `product_id` correspond à son indice dans le stock.
  int quantity;   // La quantité nécessaire d'un produit pour réaliser
                  // le cocktail
};

struct recipe {
  const char *name; // Le nom d'un cocktail
  int price;        // Le prix de vente d'un cocktail
  int ingredient_count; // Le nombre d'ingredients
  struct ingredient ingredients[MAX_INGREDIENTS]; // La liste des ingredients
};

// Le stock de produits et le nombre d'élements du stock
#define STOCK_LENGTH 12
extern struct product stock[STOCK_LENGTH];

// L'ensemble des cocktails disponibles et le nombre de cocktails
#define MENU_LENGTH 5
extern struct recipe menu[MENU_LENGTH];

/**
 * Cette fonction retourne un pointeur sur un produit du stock nommé
 * `name`.  S'il n'existe pas de tel produit, elle retourne NULL.
 */
struct product *product_by_name(const char *name)
{
    for(int i=0;i<STOCK_LENGTH; i++)
    {
        if(!strcmp(stock[i].name,name))
            return &stock[i];
    }
    return NULL;
}

/**
 * Cette fonction retourne le coût d'un `cocktail`. 
 * Le coût est la somme des coûts unitaires de chaque produit
 * multiplié par le quantité d'un produit dans la recette
 */
int cost(struct recipe cocktail)
{
    int cost = 0;
    for(int i = 0; i<cocktail.ingredient_count ; i++)
    {
        cost += stock[cocktail.ingredients[i].product_id].unit_price * cocktail.ingredients[i].quantity;
    }
    return cost;
}

/**
 * Retourne la recette la plus rentable parmi le tableau `list` de taille
 * `size`, i.e. celle où la différence entre le prix et le coût est la plus
 * élevée.
 * Cette fonction retourne NULL si la liste est vide;
 *
 * Attention: on est autorisé à vendre à perte.
 */ 
const struct recipe *most_profitable(int size, const struct recipe list[])
{
    if (!size)
        return NULL;
    int index = 0; 
    for (int i = 1; i < size   ;i++)
    {
        int maxGain = list[index].price - cost(list[index]);
        int gain = list[i].price - cost(list[i]);
        if (gain>maxGain)
            index = i;
    }
    return &list[index];
}

/**
 * Affiche une recette sous la forme :
 * `<Nom> (<Prix>e): <Ing1> (<Qty1>), <Ing2> (<Qty2>), ...`
 * Remarque: Il n'y a pas de virgule inutile en fin de liste d'ingrédients
 * Exemple:
 * Sex on the beach (3e): Vodka (3), Peach (2), Chambord (2), Pineapple (5), Cramberry (6)
 */
void print_recipe(struct recipe cocktail)
{
    printf("%s (%de): ",cocktail.name,cocktail.price);
    for(int i = 0 ; i < cocktail.ingredient_count - 1 ; i++)
    {
        char *ingredientName = stock[cocktail.ingredients[i].product_id].name;
        int ingredientPrice = cocktail.ingredients[i].quantity;
        printf("%s (%d), ",ingredientName,ingredientPrice);
    }
    char *lastIngredient = stock[cocktail.ingredients[cocktail.ingredient_count-1].product_id].name;
    int lastIngredientPrice = cocktail.ingredients[cocktail.ingredient_count-1].quantity;
    printf("%s (%d)",lastIngredient,lastIngredientPrice);
}

/**
 * Si la recette `cocktail` contient un ingrédient de même `id` que
 * `product_id`, retourne l'adresse de cet ingrédient, sinon NULL.
 */
struct ingredient *recipe_contains(struct recipe *cocktail, int product_id)
{
    if (product_id < 12 )
    {
        for(int i = 0 ;cocktail->ingredient_count;i++ )
        {
            if (cocktail->ingredients[i].product_id== product_id)
                return &cocktail->ingredients[i];
        }
    }
    return NULL;
}

/**
 * Rajoute l'`ingredient` à la recette `cocktail`. Si la recette contenait
 * déjà un tel produit, la quantité est rajoutée à la précédente.
 * 
 * Remarque: Attention à MAX_INGREDIENTS
 */
void merge_ingredient(struct recipe *cocktail, const struct ingredient ingredient)
{
    if(cocktail->ingredient_count < MAX_INGREDIENTS)
    {
        int bool = 1;
        for (int i = 0;i<cocktail->ingredient_count;i++)
        {
            if (cocktail->ingredients[i].product_id == ingredient.product_id)
            {
                cocktail->ingredients[i].quantity += ingredient.quantity;
                bool = 0;
                break;
            }
        }
        if(bool)
        {
            cocktail->ingredients[cocktail->ingredient_count]=ingredient;
            cocktail->ingredient_count++;
        }
    }
}

/**
 * Retourne 1 si le `cocktail` est réalisable compte tenu des stocks donnés.
 * i.e. il y a tous les produits nécessaires en quantités suffisantes. Sinon
 * cette fonction retourne 0.
 */
int can_mix_cocktail(struct recipe cocktail)
{
    int isPossible = 1;
    for(int i=0 ;i<cocktail.ingredient_count;i++)
    {
        
        for(int j=0; j<STOCK_LENGTH;j++)
        {
            if(cocktail.ingredients[i].product_id == stock[j].id)
            {
                if(cocktail.ingredients[i].quantity > stock[cocktail.ingredients[i].product_id].quantity)
                {
                    isPossible = 0;
                    break;
                }
            }
        }

    }
    return isPossible;
}

/**
 * Cette fonction réalise un `cocktail`, i.e. soustrait du stock les
 * quantités nécessaires pour le réaliser.
 *
 * Cette fonction ne prépare le cocktail que s'il est réalisable.
 *
 * Remarque: Cette fonction n'a pas encore de test
 */
void mix_cocktail(struct recipe cocktail)
{
    if (can_mix_cocktail(cocktail))
    {
        for(int i=0; i<cocktail.ingredient_count;i++)
        {
            stock[cocktail.ingredients[i].product_id].quantity -= cocktail.ingredients[i].quantity;
        }
    }
}

/**
 * Remplit dans `cocktails_left`, la liste des cocktails encore réalisables
 * avec le stock actuel.
 * Cette fonction retourne le nombre d'élements présents dans `cocktail_left`
 */
int recipes_available(int size, const struct recipe cocktails[],struct recipe cocktails_left[])
{
    int index = 0;
    for(int i=0;i<size;i++)
    {
        if (can_mix_cocktail(cocktails[i]))
            {
                mix_cocktail(cocktails[i]);
                cocktails_left[index] = cocktails[i];
                index++;
            }
    }       
    return index;
}

/**
 * Remplit dans `proposals`, la liste des `cocktails` (de taille
 * `cocktails_count`) contenant au moins tous les produits spécifiés par
 * `products_ids` (de taille `products_count`). La fonction retourne le
 * nombre d'éléments présents dans `proposal`.
 */
int cocktails_with(int products_count, const int products_ids[],
    int cocktails_count, struct recipe cocktails[],
    struct recipe proposals[])
{
    int index = 0;
    for (int i = 0;i<cocktails_count;i++)
    {
        int allproducts = 0;
        for(int j = 0;j < cocktails[i].ingredient_count;j++)
        {
            for(int k=0; k< products_count;k++)
            {
                if(cocktails[i].ingredients[j].product_id == products_ids[k])
                    allproducts++;
            }
        }

        if(allproducts==products_count)
                {
                    proposals[index] = cocktails[i];
                    index++;
                }
    }
    return index;
}

/**
 * Retourne le nom recette la plus rentable contenant au moins tous les produits
 * `product_ids` (de taille `products_count`) parmis les recettes proposées
 * `cocktails` de taille cocktails_count, encores réaliasables.
 * S'il n'y a pas de solution cette fonction retoune NULL.
 */
const char *sneaky_bartender(
    int products_count, const int products_ids[],
    int cocktails_count, struct recipe cocktails[])
{
    struct recipe proposals[cocktails_count];
    int total = cocktails_with(products_count,products_ids,cocktails_count,cocktails,proposals);

    struct recipe finals[total];
    int index = 0;
    for(int i = 0;i<total;i++)
    {
        if(can_mix_cocktail(proposals[i]))
        {
            finals[index]=proposals[i];
            index++;
        }
    }
    return most_profitable(index,finals)->name;

}

/**
 * Concatène les `n` chaînes de caractères contenues dans
 * `strs` dans `result` et retourne la longueur de la chaîne
 * ainsi créée.
 * Remarque:
 *  - `result` est supposé assez grand pour contenir le résultat.
 *  - L'utilisation de strcat est interdite (car inutile)
 */
int concat(int n, const char *strs[], char *result)
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<strlen(strs[i]);j++)
        {
            result[index]=strs[i][j];
            index++;
        }
    }
    result[index]='\0';
    return index;
}

/**
 * Cette fonction fabrique un nom pour la recette `cocktail`, le nom sera
 * retourné via `name`. Le nom proposé est la concaténation séparé par des
 * `-` de tous les noms de produits contenu dans la recette (et dans
 * l'ordre de la recette).
 * Eg. { { Vodka, 3}, { Orange, 6 } } => Vodka-Orange
 */
void name_recipe(struct recipe *cocktail, char name[])
{
    char *strs[cocktail->ingredient_count];
    for(int i=0;i<cocktail->ingredient_count-1;i++)
    {
        strcpy(strs[i],stock[cocktail->ingredients[i].product_id].name);
        strs[strlen(stock[cocktail->ingredients[i].product_id].name)]="-";
    }
    strcpy(strs[cocktail->ingredient_count-1],stock[cocktail->ingredients[cocktail->ingredient_count-1].product_id].name);
    
    concat(cocktail->ingredient_count,(const char **)strs,name);
}

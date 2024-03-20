#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[20];
    int price;
    int quantity;
};

struct cart_item {
    struct product item;
    int quantity;
};

struct cart {
    struct cart_item items[MAX_PRODUCTS];
    int count;
};

void display_products(struct product products[], int n) {
    printf("Available Products:\n");
    printf("--------------------------------------------------\n");
    printf("No.  | Product Name | Price (per unit) | Quantity\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-12s | %-16d | %-8d\n", i + 1, products[i].name, products[i].price, products[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

void add_to_cart(struct product products[], struct cart* shopping_cart, int product_index, int quantity) {
    if (product_index < 0 || product_index >= MAX_PRODUCTS) {
        printf("Invalid product index.\n");
        return;
    }

    if (quantity <= 0) {
        printf("Invalid quantity.\n");
        return;
    }

    struct product* selected_product = &products[product_index];
    if (selected_product->quantity < quantity) {
        printf("Insufficient stock.\n");
        return;
    }

    struct cart_item* item = &(shopping_cart->items[shopping_cart->count]);
    item->item = *selected_product;
    item->quantity = quantity;
    shopping_cart->count++;

    selected_product->quantity -= quantity;

    printf("Added to cart: %s x %d\n", item->item.name, item->quantity);
}

void remove_from_cart(struct product products[], struct cart* shopping_cart, int cart_item_index) {
    if (cart_item_index < 0 || cart_item_index >= shopping_cart->count) {
        printf("Invalid cart item index.\n");
        return;
    }

    struct cart_item* item = &(shopping_cart->items[cart_item_index]);
    struct product* selected_product = &(item->item);
    selected_product->quantity += item->quantity;

    printf("Removed from cart: %s x %d\n", item->item.name, item->quantity);


    for (int i = cart_item_index; i < shopping_cart->count - 1; i++) {
        shopping_cart->items[i] = shopping_cart->items[i + 1];
    }
    shopping_cart->count--;
}

void display_cart(struct cart* shopping_cart) {
    printf("Shopping Cart:\n");
    printf("--------------------------------------------------\n");
    printf("No.  | Product Name | Price (per unit) | Quantity\n");
    printf("--------------------------------------------------\n");
    int total_amount = 0;
    for (int i = 0; i < shopping_cart->count; i++) {
        struct cart_item* item = &(shopping_cart->items[i]);
        printf("%-4d | %-12s | %-16d | %-8d\n", i + 1, item->item.name, item->item.price, item->quantity);
        total_amount += item->item.price * item->quantity;
    }
    printf("--------------------------------------------------\n");
    printf("Total Amount: %d\n", total_amount);
}

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products;

    printf("Enter the number of products: ");
    scanf("%d", &num_products);

    if (num_products <= 0 || num_products > MAX_PRODUCTS) {
        printf("Invalid number of products.\n");
        return 1;
    }

    for (int i = 0; i < num_products; i++) {
        printf("Product %d\n", i + 1);
        printf("Enter product name: ");
        scanf("%s", products[i].name);
        printf("Enter price: ");
        scanf("%d", &products[i].price);
        printf("Enter quantity: ");
        scanf("%d", &products[i].quantity);
    }

    struct cart shopping_cart;
    shopping_cart.count = 0;

    int choice;
    int product_index, quantity, cart_item_index;

    while (1) {
        printf("\nOnline Shopping Store\n");
        printf("---------------------------\n");
        printf("1. Display Products\n");
        printf("2. Add to Cart\n");
        printf("3. Remove from Cart\n");
        printf("4. View Cart\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_products(products, num_products);
                break;
            case 2:
                printf("Enter the product number: ");
                scanf("%d", &product_index);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                add_to_cart(products, &shopping_cart, product_index - 1, quantity);
                break;
            case 3:
                printf("Enter the cart item number: ");
                scanf("%d", &cart_item_index);
                remove_from_cart(products, &shopping_cart, cart_item_index - 1);
                break;
            case 4:
                display_cart(&shopping_cart);
                break;
            case 5:
                printf("Thank you for shopping with us!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to hold customer, menu item, and order information
typedef struct {
    int id;
    char name[50];
    char email[50];
    char password[20];
    char address[100];
} Customer;

typedef struct {
    int item_id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int order_id;
    int customer_id;
    int item_id;
    int quantity;
    float total_price;
    char status[20];
} Order;

// Function prototypes
void register_customer();
void login_customer();
void view_menu();
void place_order(int customer_id);
void view_orders(int customer_id);
int file_exists(const char *filename);
void initialize_files();

// Constants for file paths
const char *CUSTOMERS_FILE = "customers.dat";
const char *MENU_FILE = "menu.dat";
const char *ORDERS_FILE = "orders.dat";

// Check if a file exists
int file_exists(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fclose(file);
        return 1; // File exists
    }
    return 0; // File doesn't exist
}

// Initialize required files (creating them if they don't exist)
void initialize_files() {
    if (!file_exists(MENU_FILE)) {
        FILE *file = fopen(MENU_FILE, "wb");
        if (!file) {
            perror("Failed to create menu file");
            exit(1);
        }

        // Sample menu items
        MenuItem items[] = {
            {1, "Burger", 499.00},
            {2, "Cheese Pizza", 799.00},
            {3, "Sandwich", 249.00},
            {4, "French Fries", 149.00},
            {5, "Pasta", 599.00},
            {6, "Samosa", 149.00},
            {7, "Margherita Pizza", 799.00},
            {8, "Garlic Bread", 249.00},
            {9, "Vegetable Pulao", 499.00},
            {10, "Pasta Alfredo", 699.00}
        };

        // Write sample menu items to file
        for (int i = 0; i < 10; i++) {
            fwrite(&items[i], sizeof(MenuItem), 1, file);
        }
        fclose(file);
        printf("Menu file created with sample items.\n");
    }

    // Create customers file if it doesn't exist
    if (!file_exists(CUSTOMERS_FILE)) {
        FILE *file = fopen(CUSTOMERS_FILE, "wb");
        if (!file) {
            perror("Failed to create customers file");
            exit(1);
        }
        fclose(file);
        printf("Customers file created.\n");
    }

    // Create orders file if it doesn't exist
    if (!file_exists(ORDERS_FILE)) {
        FILE *file = fopen(ORDERS_FILE, "wb");
        if (!file) {
            perror("Failed to create orders file");
            exit(1);
        }
        fclose(file);
        printf("Orders file created.\n");
    }
}

// Main function
int main() {
    int choice;
    printf("==== Welcome to the Food Delivery System ====\n");

    // Initialize files
    initialize_files();

    do {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_customer();
                break;
            case 2:
                login_customer();
                break;
            case 3:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Register a new customer
void register_customer() {
    FILE *file = fopen(CUSTOMERS_FILE, "ab");
    if (!file) {
        perror("Failed to open customers file");
        return;
    }

    Customer customer;
    printf("Enter your name: ");
    scanf(" %[^\n]", customer.name);
    printf("Enter your email: ");
    scanf("%s", customer.email);
    printf("Enter your password: ");
    scanf("%s", customer.password);
    printf("Enter your address: ");
    scanf(" %[^\n]", customer.address);

    // Generate a unique customer ID
    fseek(file, 0, SEEK_END);
    customer.id = ftell(file) / sizeof(Customer) + 1;

    // Write customer to file
    fwrite(&customer, sizeof(Customer), 1, file);
    fclose(file);

    printf("Registration successful! Your ID is %d\n", customer.id);
}

// Handle customer login
void login_customer() {
    FILE *file = fopen(CUSTOMERS_FILE, "rb");
    if (!file) {
        perror("Failed to open customers file");
        return;
    }

    int id;
    char password[20];
    printf("Enter your Customer ID: ");
    scanf("%d", &id);
    printf("Enter your password: ");
    scanf("%s", password);

    Customer customer;
    int found = 0;
    while (fread(&customer, sizeof(Customer), 1, file)) {
        if (customer.id == id && strcmp(customer.password, password) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("Login successful! Welcome, %s.\n", customer.name);
        int choice;
        do {
            printf("\n1. View Menu\n");
            printf("2. Place Order\n");
            printf("3. View Orders\n");
            printf("4. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    view_menu();
                    break;
                case 2:
                    place_order(customer.id);
                    break;
                case 3:
                    view_orders(customer.id);
                    break;
                case 4:
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 4);
    } else {
        printf("Invalid ID or password.\n");
    }
}

// View the menu
void view_menu() {
    FILE *file = fopen(MENU_FILE, "rb");
    if (!file) {
        perror("Failed to open menu file");
        return;
    }

    MenuItem item;
    printf("\n==== Menu ====\n");
    while (fread(&item, sizeof(MenuItem), 1, file)) {
        printf("%d. %s - %.2f\n", item.item_id, item.name, item.price);
    }
    fclose(file);
}

// Place a new order
void place_order(int customer_id) {
    FILE *menu_file = fopen(MENU_FILE, "rb");
    if (!menu_file) {
        perror("Failed to open menu file");
        return;
    }

    int item_id, quantity;
    printf("Enter the Item ID you want to order: ");
    scanf("%d", &item_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    MenuItem item;
    int found = 0;
    while (fread(&item, sizeof(MenuItem), 1, menu_file)) {
        if (item.item_id == item_id) {
            found = 1;
            break;
        }
    }
    fclose(menu_file);

    if (found) {
        Order order;
        FILE *order_file = fopen(ORDERS_FILE, "ab");
        if (!order_file) {
            perror("Failed to open orders file");
            return;
        }

        order.order_id = ftell(order_file) / sizeof(Order) + 1;
        order.customer_id = customer_id;
        order.item_id = item_id;
        order.quantity = quantity;
        order.total_price = item.price * quantity;
        strcpy(order.status, "Pending");

        fwrite(&order, sizeof(Order), 1, order_file);
        fclose(order_file);

        printf("Order placed successfully! Total: %.2f\n", order.total_price);
    } else {
        printf("Item not found in menu.\n");
    }
}

// View all orders placed by the customer
void view_orders(int customer_id) {
    FILE *file = fopen(ORDERS_FILE, "rb");
    if (!file) {
        perror("Failed to open orders file");
        return;
    }

    Order order;
    int found = 0;
    printf("\n==== Your Orders ====\n");
    while (fread(&order, sizeof(Order), 1, file)) {
        if (order.customer_id == customer_id) {
            found = 1;
            printf("Order ID: %d | Item ID: %d | Quantity: %d | Total: %.2f | Status: %s\n",
                   order.order_id, order.item_id, order.quantity, order.total_price, order.status);
        }
    }
    fclose(file);

    if (!found) {
        printf("No orders found.\n");
    }
}
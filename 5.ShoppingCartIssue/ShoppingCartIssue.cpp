#include <iostream>
#include <vector>
using namespace std;

vector <string> products (int quantity1);
vector <int> data (int quantity1);
vector <vector<int> > knapsack(int quantity1, int capacityTruck, vector <int> price, vector <int> weights, vector<int> &selectedItems );

int main(){
    int quantity;
    int capacityContainer = 250;
    
    cout<<"* * * * Knapsack Problem Solver: Optimal Item Selection * * * * \n"<<endl;
    cout<<"You have a truck with a load capacity of 250 kg\n"<<endl;
    cout<<"How many items do you have? Enter the quantity: "<<endl;
    cin>>quantity;
    cout<<"Enter the names of all products: "<<endl;
    vector <string> typeOfProduct = products(quantity);
    //#2
    cout<<"Enter the prices for each product (enter a whole number): "<<endl;
    vector <int> price = data(quantity);
    //#3
    cout<<"Enter the weight for each product (enter a whole number): "<<endl;
    vector <int> weights = data(quantity); 

    vector<int> selectedItems;  // Vector for storing the indices of selected items
    
    
    // Here, I call the function with a 2D array dp, passing "quantity" (number of items) and "capacityContainer" (weight) 
    // Calling the knapsack function and getting a 2D vector dp
    vector<vector<int> > dp = knapsack(quantity, capacityContainer, price, weights, selectedItems);

    // here I can use dp to output the maximum value and other results
    cout << "The maximum value that can be achieved is: " << dp[quantity][capacityContainer] << " Euro"<< endl;

    cout << "Selected items (index and name):" << endl;
    for (int index : selectedItems) {
        cout << "Item " << (index + 1) << " (" << typeOfProduct[index] << ")" << endl;
    }
}

vector <string> products (int quantity1){

    vector <string> type (quantity1);
    for(int i = 0; i < quantity1; i++ ){
        cin>>type[i];
    }
    return type;
}

vector <int> data (int quantity1){

    vector <int> quantity (quantity1);
    for(int i = 0; i < quantity1; i++ ){
        cin>>quantity[i];
    }
    return quantity;
}

vector<vector<int> > knapsack(int quantity1, int capacityTruck, vector<int> price, vector<int> weights, vector<int> &selectedItems) {
    
    vector<vector<int> > dp(quantity1 + 1, vector<int>(capacityTruck + 1, 0)); // Creating a 2D vector to store the results

    // Filling the DP table
    for (int i = 1; i <= quantity1; i++) {
        for (int j = 1; j <= capacityTruck; j++) {
            // If the current item can be added (fits by weight)
            if (weights[i - 1] <= j) { // Here, it seems like i - 1, meaning the first product is at index 0, and we take its weight and compare it to j, which is the allowed weight at the moment
                // Comparing: whether to take the current item or not
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                // If the item does not fit, take the previous result
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    
    int j = capacityTruck;   // Restoring the selected items
    for (int i = quantity1; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(i - 1); // Adding the item index
            j -= weights[i - 1]; // Reducing the remaining capacity
        }
    }

    return dp;
}
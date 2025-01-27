#include<iostream> 
#include<vector>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<ctime>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std; 

struct  Product
{
    int productID;
    string name;
    string category;
};

struct Order
{
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};


int main()
 { 
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Mobile", "Electronics"},
        {103, "Cofee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Lamp", "Home"}
    };

    deque<string> recentCustomer = {"C001","C002","C002"};

    recentCustomer.push_back("C004");
    recentCustomer.push_front("C005");

    list<Order> orderHistory;

    orderHistory.push_back({1,101,1,"C001",time(0)});
    orderHistory.push_back({2,102,2,"C002",time(0)});
    orderHistory.push_back({3,103,1,"C003",time(0)});

    set<string> categories;

    for (const auto &product : products)
    {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 5},
        {105, 7},
    };

    multimap<string, Order> customerOrder;

    for (const auto &order : orderHistory)
    {
        customerOrder.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData = {
        {"C001","Alice"},
        {"C002","Sam"},
        {"C003","Bob"},
        {"C004","Xavier"},
        {"C005","Ron"},
    };
    
    unordered_set<int> uniqueProductID;
    for (const auto &product : products)
    {
        uniqueProductID.insert(product.productID);
    }
    

    // for (auto order : orderHistory)
    // {
    //     cout<<order.productID<<endl;
    // }



    // for (auto customer : customerData)
    // {
    //     cout<<customer.first<<" : "<<customer.second<<endl;
    // }
    


    // for (auto product : products)
    // {
    //     cout<<product.productID<<","<<product.name<<","<<product.category<<endl;
    // }
    
    
    return 0; 
 } 
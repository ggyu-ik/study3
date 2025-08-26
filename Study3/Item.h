#pragma once
#include <string>
using namespace std;

class Item
{
private:
    string name;
    int price;

public:
    Item(string n = "", int p = 0) : name(n), price(p)
    {
    }
    int GetPrice() const
    {
        return price;
    }
    string GetName() const
    {
        return name;
    }
};
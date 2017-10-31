# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This program calculates the cost of moving furniture in terms
# of weight in pounds and distance in miles

def Calc_Labour(weight): # Function to calculate cost of labour
    cost = weight / 100
    cost = cost * 4
    return cost

def Calc_Travel(distance): # Function to calculate cost of moving furniture
    cost = 50 + (distance * 1.75)
    return cost

def Display_Charges(labour,travel): # Function to find total cost and print cost
    display = labour + travel
    print("The total cost of the operation is: $",display)

def main():
    print("This program calculates the cost for moving furniture.")
    print()
    weight = eval(input("What is the weight of the object in pounds: "))
    distance = eval(input("What is the distance you want it moved in miles: "))

    labour_cost = Calc_Labour(weight)
    travel_cost = Calc_Travel(distance)

    Display_Charges(labour_cost,travel_cost)

main()

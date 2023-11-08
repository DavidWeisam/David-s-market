import json

# The shopping cart
shooping_cart = []

prise_list = []


# Data of the market
with open('data.json') as f:
    data = json.load(f)

section_names = data['sections'].keys()
fruits = data['sections']['fruits']
vegetables = data['sections']['vegetables']
breads = data['sections']['breads']
meats = data['sections']['meats']


# Function that gets item and list of item, and checks if the item is in the list
def input_check(new_item, item_list):
    for item in item_list:
        if(new_item == item["name"]):
            return True
    return False

# Function that shows the sections the the market have
def section():
    print("What section would you like to see? \n")
    num = 1
    for section_name in section_names:
        print(str(num) + ". " + section_name + "\n")
        num = num + 1

    input_num = input("Type the number of the section that you want to see: ")
    
    return input_num


# Function that shows what the fruit section hava
def fruit_section():
    num = 1
    for fruit in fruits:
        print(str(num) + ". " + fruit["name"] + ", " + str(fruit["price"]) + "\n")
        num = num + 1
    
    print("If you want to exit enter ""exit"" ")
    
    # If you want to add something to the shopping cart
    input_fruit = input("Enter what fruit you want: ")
    
    # If you want to exit to the homepage
    if(input_fruit == "exit"):
        section_continue(section())

    while(input_check(input_fruit, fruits) == False):
        input_fruit = input("Please type an existing item: ")
    shooping_cart.append(input_fruit)
    

    for fruit in fruits:
        if fruit['name'] == input_fruit:
            prise_list.append(fruit['price'])


# Function that shows what the vegetabl section hava
def vegetables_section():
    num = 1
    for vegetable in vegetables:
        print(str(num) + ". " + vegetable["name"] + ", " + str(vegetable["price"]) + "\n")
        num = num + 1
    
    print("If you want to exit enter ""exit"" ")
    
    # If you want to add something to the shopping cart
    input_vegetable = input("Enter what vegetable you want: ")

    if(input_vegetable == "exit"):
        section_continue(section())

    while(input_check(input_vegetable, vegetables) == False):
        input_vegetable = input("Please type an existing item: ")
    shooping_cart.append(input_vegetable)

    for vegetable in vegetables:
        if vegetable['name'] == input_vegetable:
            prise_list.append(vegetable['price'])


# Function that shows what the bread section hava
def breads_section():
    num = 1
    for bread in breads:
        print(str(num) + ". " + bread["name"] + ", " + str(bread["price"]) + "\n")
        num = num + 1

    print("If you want to exit enter ""exit"" ")

    # If you want to add something to the shopping cart
    input_bread = input("Enter what bread you want: ")

    if(input_bread == "exit"):
        section_continue(section())

    while(input_check(input_bread, breads) == False):
        input_bread = input("Please type an existing item: ")
    shooping_cart.append(input_bread)

    for bread in breads:
        if bread['name'] == input_bread:
            prise_list.append(bread['price'])


# Function that shows what the meat section hava
def meats_section():
    num = 1
    for meat in meats:
        print(str(num) + ". " + meat["name"] + ", " + str(meat["price"]) + "\n")
        num = num + 1

    print("If you want to exit enter ""exit"" ")

    # If you want to add something to the shopping cart
    input_meat = input("Enter what fruit you want: ")

    if(input_meat == "exit"):
        section_continue(section())

    while(input_check(input_meat, meats) == False):
        input_finput_meatruit = input("Please type an existing item: ")
    shooping_cart.append(input_meat)

    for meat in meats:
        if meat['name'] == input_meat:
            prise_list.append(meat['price'])

# Function that controls the input from the homepage
def section_continue(num):
    if(num == 1):
        vegetables_section()
    elif(num == 2):
        breads_section()
    elif(num == 3):
        meats_section()
    elif(num == 4):
        fruit_section()

# Function that controls what the costomer want to do
def customer_questions():
    print("If you want to return to the home screen enter ""1"".\n")
    print("If you want to stop type ""2"".\n")
    print("If you want to see the shopping cart type ""3"".\n")
    num = input("what would you like to do: ")

    while(num < 0 or num > 3):
        num = input("what would you like to do: ")

    return num

# Function of the shopping cart
def show_shopping_cart():
    
    len_of_items = len(shooping_cart)
    for x in range(0, len_of_items):
        print(shooping_cart[x] + ", " + str(prise_list[x]) + "\n")
    
def delete_item():
    # If the costomer want to remove something from the shooping cart he can
    rm = input("Do you want to remote an item from the car? (Y/N): ")
    while(rm != "Y" and rm != "N"):
        rm = input("Do you want to remote an item from the car? (Y/N): ")

    if(rm == "Y"):
        item_rm = input("What item do you want to rmove: ")
        if((item_rm in shooping_cart) == False):
            print("This item is'nt exitst in the car")
        else:
            index = shooping_cart.index(item_rm)
            shooping_cart.pop(index)
            prise_list.pop(index)



#Homepage
section_continue(section())


to_stop = 0
while(to_stop != 1):
    num = customer_questions()
    if(num == 2):
        to_stop = 1
    elif(num == 1):
        section_continue(section())
    elif(num == 3):
        show_shopping_cart()
 
show_shopping_cart()

sum = 0
for item in prise_list:
    sum = sum + item

print("You have to pay " + str(sum) + "$")

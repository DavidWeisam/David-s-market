#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char **shopping_cart;
int space = 0;



void show_cart(){

    for(int i = 0; i < space; i++){
        printf("%s\n", shopping_cart[i]);
    }
}

void add_to_cart(char str[]){
    shopping_cart[space] = (char*)malloc(20 * sizeof(char));
	strcpy(shopping_cart[space], str);
    space++;
}

int exit_section(char str_new[]){

    char str[] = "exit";
    int counter = 0;
    for(int i =0; i < 4; i++){
        if(str[i] == str_new[i])
            counter++;
    }

    if(counter == 4)
        return 1;

    return 0;
}

int sections(){
	printf("What would you like to buy?\n\n");
	printf("1. Fruits \t 3. Breads \n");
	printf("2. Vegetables \t 4. Meats \n");
	
	int num_of_section = 0;
	printf("Type the section number you want to see: ");
	scanf("%d", &num_of_section);

	while(num_of_section < 0 || num_of_section > 6){
		printf("Please type an existing section: ");
		scanf("%d", &num_of_section);
	}
	return num_of_section;
}

int check_input(char str[], char **arry){
	char *ptr;
	int counter = 0;
	int len_str = strlen(str);
	for(int i = 0; i < 4; i++){
	
		ptr = arry[i];

		for(int j = 0; j < len_str; j++){
			if(ptr[j] == str[j])
				counter++;
		}
	
		if (counter == len_str)
			return 1;

		counter = 0;
	}

	return 0;
}

int fruits_section(){
	printf("\nWhat fruit would you like to buy?\n\n");
	printf("1. Appel \t 3. Orange\n");
	printf("2. Banana \t 4. Strawberry\n\n");
	
	char fruit[20];
    char *fruits[4] = {"Appel", "Banana", "Orange", "Strawberry"};

    printf("If you want to exit type ""exit"". \n");
	printf("Type the fruit you want to see: ");
    
	scanf("%s", fruit);
    
    if(exit_section(fruit) == 1)
        return 1;
    
    while(check_input(fruit, fruits) == 0){
        printf("Please type an existing fruit: ");
        scanf("%s", fruit);

        if(exit_section(fruit) == 1)
        return 1;
    }

    add_to_cart(fruit);
    return 0;
}

int vegetables_section(){
	printf("\nWhat Vegetables would you like to buy?\n\n");
	printf("1. Carrot \t 3. Broccoli\n");
	printf("2. Tomato \t 4. Spinach\n\n");
	
	char vegetable[20];
    char *vegetables[4] = {"Carrot", "Tomato", "Broccoli", "Spinach"};
	
    printf("Type the vegetable you want to see: ");
	scanf("%s", vegetable);
    
    if(exit_section(vegetable) == 1)
        return 1;
    
    while(check_input(vegetable, vegetables) == 0){
        printf("Please type an existing vegetable: ");
        scanf("%s", vegetable);

        if(exit_section(vegetable) == 1)
        return 1;
    }
    add_to_cart(vegetable);
    return 0;
}

int breads_section(){
	printf("\nWhat bread would you like to buy?\n\n");
	printf("1. Baguette \t 3. Sourdough\n\n");
	printf("2. Naan \t 4. Pita\n");
	
	char bread[20];
    char *breads[4] = {"Baguette", "Naan", "Sourdough", "Pita"};
	
    printf("Type the bread you want to see: ");
	scanf("%s", bread);
    
    if(exit_section(bread) == 1)
        return 1;
    
    while(check_input(bread, breads) == 0){
        printf("Please type an existing bread: ");
        scanf("%s", bread);

        if(exit_section(bread) == 1)
        return 1;
    }
    add_to_cart(bread);
    return 0;
}

int meats_section(){
	printf("\nWhat meat would you like to buy?\n\n");
	printf("1. Chicken \t 3. Pork\n");
	printf("2. Beef \t 4. Salmon\n\n");
	
	char meat[20];
    char *meats[4] = {"Chicken", "Beef", "Pork", "Salmon"};
	
    printf("Type the meat you want to see: ");
	scanf("%s", meat);
    
    if(exit_section(meat) == 1)
        return 1;
    
    while(check_input(meat, meats) == 0){
        printf("Please type an existing meat: ");
        scanf("%s", meat);

        if(exit_section(meat) == 1)
        return 1;
    }
    add_to_cart(meat);
    return 0;
}


int customer_questions(){
    int num;
    printf("If you want to return to the home screen enter ""1"".\n");
    printf("If you want to stop type ""2"".\n");
    printf("If you want to see the shopping cart type ""3"".\n");
    printf("what would you like to do: ");
    scanf("%d", &num);
    while(num < 0 || num > 3){
        printf("what would you like to do: ");
        scanf("%d", &num);
    }
    return num;

}

void sections_continue(int num){
    switch(num) {
        case 1:
            if(fruits_section() == 1)
                sections_continue(sections());
            break;
        case 2:
            if(vegetables_section() == 1)
                sections_continue(sections());
            break;
        case 3:
            if(breads_section() == 1)
                sections_continue(sections());
            break;
        case 4:
            if(meats_section() == 1)
                sections_continue(sections());
            break;
        default:
            printf("ERRO");
    }


}

int main(){
	
	printf("\n\t\tWelcome to David's market\n");
	printf("\t\t_________________________\n\n");
	
	shopping_cart = (char**)malloc(30 * sizeof(char*));
	sections_continue(sections());
    int to_stop = 0;
    int num;
    while(to_stop != 1){
        num = customer_questions();
        if(num == 2)
            to_stop = 1;
        else if(num == 1)
            sections_continue(sections());
        else if(num == 3)
            show_cart();
        else 
            to_stop = 1;
    }
	return 0;
}





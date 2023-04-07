#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    char name[25];
    double price;
    int id;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    struct item itm;
};



void showMenu(){
    printf("\n======WELCOME TO OUR MENU======\n\n");
    struct item item1={"pizza thon",10.50};
    struct item item2={"cheese burger",7.00};
    struct item item3={"chapati mahdia",4.00};
    struct item item4={"mlewi shawarma",6.00};
    struct item item5={"coca cola",1.50};
    struct item item6={"pizza 4 season",15.00};
    struct item item7={"chapati omlet",3.00};
    struct item item8={"ma9loub",7.00};

    struct item items[]={item1,item2,item3,item4,item5,item6,item7,item8};

    printf("ITEM \t \t \t \t PRICE\n\n");
    int length=sizeof items /sizeof items[0];
    for (int i = 0; i < length; i++)
    {
        printf("%s \t \t \t%.2lf DT\n",items[i].name,items[i].price);
    }
    
    
}
void generateBillHeader(char name[50],char date[30]){
    printf("\n \n");
    printf("\t STARK RESTAURANT\n");
    printf("----------------------------------\n");
    printf("Date: %s\n",date);
    printf("Customer name: %s\n",name);
    printf("--------------------------------------\n");
    printf("items: \t\t");
    printf("Quantity: \t\t");
    printf("Total: \t\t");
    printf("\n--------------------------------------\n\n");


}



void showBill(char item[50],int qty,double price){
    printf("%s \t \t",item);
    printf("%d \t \t",qty);
    printf("%.2lf \t \t DT\n",price*qty);
}


int main()
{
    FILE *fp;
    struct orders order;
    
    printf("\n");
    printf("=============STARK RESTAURANT=============\n");
    printf("\n");
    printf("Please select your prefered operation:\n");
    printf("1.Show Menu\n");
    printf("2.order meal\n");
    printf("3.show orders\n");
    printf("4.Exit\n");
    int option;
    printf("\nyour choice: ");
    scanf("%d",&option);
    while (!(option<=4)&&(option>=1))
    {
        printf("Please set a valid option!");
        scanf("%d",&option);
    }
    switch (option)
    {
    case 1:
        system("cls");
        showMenu();
        printf("press [1] to go to main page\n");
        printf("press [0] to exit\n");
        int answer;
        scanf("%d",&answer);
        if (answer==1)
        {
            system("cls");
            main();
        }else if (answer==0)
        {
            exit(0);
        }
        break;
    case 2:
        system("cls");
        int id;

        struct item item1={"pizza thon",10.50,1};
        struct item item2={"cheese burger",7.00,2};
        struct item item3={"chapati mahdia",4.00,3};
        struct item item4={"mlewi shawarma",6.00,4};
        struct item item5={"coca cola",1.50,5};
        struct item item6={"pizza 4 season",15.00,6};
        struct item item7={"chapati omlet",3.00,7};
        struct item item8={"ma9loub",7.00,8};

        struct item items[]={item1,item2,item3,item4,item5,item6,item7,item8};
        struct orders ord;
        char name[50];
        fgetc(stdin); //removes buffer
        printf("Please enter the name of the customer :");
        fgets(ord.customer,50,stdin);

        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
            for (int j = 0; j <sizeof items/sizeof items[0] ; j++)
            {
                printf("%s [%d]\n",items[j].name,items[j].id);
            }
            
            printf("\nplease enter item id: ");
            scanf("%d",&id);
            strcpy(ord.itm.name,items[id-1].name);


            printf("\nPlease enter the quantity of item: ");
            scanf("%d",&ord.itm.qty);
            ord.itm.price=items[id-1].price;

        system("cls");
        printf("\n \n");
        printf("\t STARK RESTAURANT\n");
        printf("--------------------------------------\n");
        printf("Date: %s\n",ord.date);
        printf("Customer name: %s\n",ord.customer);
        printf("--------------------------------------\n");
        printf("items: \t\t");
        printf("Quantity: \t\t");
        printf("Total: \t\t");
        printf("\n-------------------------------------\n\n");;
        showBill(ord.itm.name,ord.itm.qty,ord.itm.price);
        char saveBill;
        printf("Do you want to save this order? [y/n]");
        scanf("%c",&saveBill);
        if (saveBill=='y')
        {
            
        
        break;
        }
    case 3:
        system("cls");
        fp = fopen("RestaurantBill.dat","r");
        printf("\n  *****Your Previous Orders*****\n");
        generateBillHeader(ord.customer,ord.date);
        showBill(ord.itm.name,ord.itm.qty,ord.itm.price);
        break;
    case 4:
        exit(0);
        break;
    }
    


    return 0;
}

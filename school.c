#include <stdio.h>
#include <windows.h>

struct student
{
    char name[50];
    char class[10];
    double average;
};


void showlist(){
    system("cls");
    printf("\t\tSTUDENTS LIST\n");
    printf("--------------------------------------------\n");
    printf("Student name \t \t class \t\t Average ");
    FILE *fh_input;
    fh_input=fopen("io.txt","r");
    char singleline[150];
    
    while (!feof(fh_input))
    {
        fgets(singleline,150,fh_input);
        puts(singleline);
    }
    
    
    fclose(fh_input);

}

void addStudent(){
    int option;

    FILE *fh_output;
    system("cls");
    int n;
    
    printf("how many students would you like to add?: ");
    scanf("%d",&n);
    getchar();
    struct student students[n];
    for (int i = 0; i < n; i++)
    {
        printf("student name: ");
        fgets(students[i].name,50,stdin);
        students[i].name[strlen(students[i].name)-1]='\0';
        printf("student class: ");
        scanf("%s",&students[i].class);
        printf("student average: ");
        scanf("%lf",&students[i].average);
        getchar();
        system("cls");
        printf("\tSTUDENT ADDED SUCCESSFULLY !!\n------------------------------------------\n");
        printf("student: %s\nclass: %s\naverage: %.2lf\n",students[i].name,students[i].class,students[i].average);
        printf("------------------------------------------------\n");
        fh_output=fopen("io.txt","a");
        fprintf(fh_output,"\n%s \t\t %s \t\t %.2lf",students[i].name,students[i].class,students[i].average);
        fclose(fh_output);
    }
    
}   

void mainmenu(){
    printf("\n\tSCHOOL MANAGEMENT SYSTEM\n");
    printf("-------------------------------------\n");
    printf("1.Show student list \n");
    printf("2.add student\n");
}



int main()
{
    system("cls");
    int option;
    mainmenu();
    printf("set option: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        system("cls");
        showlist();
        break;
    
    case 2:
        addStudent();
         printf("1.Main menu\n");
        printf("2.Exit\n");
        scanf("%d",&option);
        if (option==1)
        {
            main();
        }
        else{
            exit(0);
        }
        break;
    }
    
    return 0;
}

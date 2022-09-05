#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>

// Data's
float totalBazar=0;
float totalDeposit = 0;

float totalMeal = 0;
float mealRate;
float balance;
float mealCostPerson;

struct Member
{
    char name[100];
    int meal;
    int deposit;
    float cost;;
    float balance;;

};

int memberIndex = 0;
char nullStr[20] = {"\0"};
bool isRunning = true;
void Home();
void AddMember();
void ShowAllInfo();
void SetMessCosts();
void ShowMessDetails();
void EditBazar();
void MemberDepositMeal();
void EditDeposit();
void EditMeal();
void DeleteMember();
void DeleteAllMember();
void GoBack();
void Exit();
void messData();



int main(){
    system("cls");

    while(isRunning == true){
        Home();
    int option;
    scanf("%d", &option);
    switch(option){
    case 1:
        AddMember();
        break;

    case 2:
        ShowAllInfo();
        break;

    case 3:
        SetMessCosts();
        break;

    case 4:
        ShowMessDetails();
        break;

    case 5:
        EditBazar();
        break;

    case 6:
        MemberDepositMeal();
        break;

    case 7:
        DeleteMember();
        break;
    case 8:
        DeleteAllMember();
        break;
    case 0:
        Exit();
        break;

    default:
        system("cls");
        printf("Invalid Request! Try Again!");

    }
    }
}


void Home(){
    printf("\n\t -------------------------------------\n");
    printf("     \t\tMess Manager System    ");
    printf("\n\t -------------------------------------\n");
    printf("\t\t[1] Add a new Member\n\n");
    printf("\t\t[2] Show all Members & their info\n\n");
    printf("\t\t[3] Add Bazar Cost\n\n");
    printf("\t\t[4] Show Mess Details\n\n");
    printf("\t\t[5] Edit Bazar Cost\n\n");
    printf("\t\t[6] Edit Member Deposit & Meal Info\n\n");
    printf("\t\t[7] Delete a Member\n\n");
    printf("\t\t[8] Delete All Member\n\n");
    printf("\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice: ");
}

struct Member member[100];

void AddMember()
{
    system("cls");
    printf("\n\t ------------------------------\n");
    printf("     \t\tAdd New Member    ");
    printf("\n\t ------------------------------\n");


    printf("\t  Enter Member's Name: ");
    scanf(" %[^\n]s", &member[memberIndex].name);


    printf("\t  Enter Member's current Meal: ");
    scanf("%d", &member[memberIndex].meal);

    printf("\t  Enter Member's current Deposit: ");
    scanf("%d", &member[memberIndex].deposit);

    memberIndex++;

    printf("\n\t  Member Added Succesfully. \n\t  Press 'Y' to add another Member & press any key to go back: ");

    char option;
    getchar();
    scanf("%c", &option);
    if(option == 'y'){
        AddMember();
    }
    else{
        system("cls");
    }


}



void ShowAllInfo()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tShowing All Member's Info    ");
    printf("\n\t -----------------------------------\n");

    int i;

    for(i=0; i<memberIndex; i++){
        member[i].cost = mealRate * member[i].meal;
        member[i].balance = member[i].deposit - member[i].cost;
        printf("\t  Member %d: \n", i+1);
        printf("\t  -----------------\n");
        printf("\t  Name: \t\t %s\n", member[i].name);
        printf("\t  Meal: \t\t %d\n", member[i].meal);
        printf("\t  Deposit: \t\t %d\n", member[i].deposit);
        printf("\t  Cost: \t\t %.2f\n", member[i].cost);
        printf("\t  Balance: \t\t %.2f\n", member[i].balance);

        printf("\t  ------------------\n");


    }

    GoBack();
}

void SetMessCosts()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tSet Mess's Costs    ");
    printf("\n\t -----------------------------------\n");
    printf("\t\t[1] Sum with Previous One\n\n");
    printf("\t\t[2] Direct Update the New One\n\n");
    printf("\t\tEnter Your Choice: ");
    int option;
    scanf("%d", &option);
    switch(option){
    case 1:
        printf("\n\t\tPrevious: %.2f", totalBazar);
        printf("\n\t\tHow much you want to sum?: ");
        float sumBazar;
        scanf("%f", &sumBazar);
        totalBazar += sumBazar;
        printf("\n\t\tYour Bazar added successfully\n");
        break;
    case 2:
        printf("\t\tTotal Bazar: ");
        scanf("%f", &totalBazar);
        printf("\n\t\tYour Bazar added successfully\n");
        break;
    }



    GoBack();
}

void ShowMessDetails()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tKureghor Mess Details    ");
    printf("\n\t -----------------------------------\n");

    int i;
    for(i=0; i<memberIndex; i++){
        totalMeal += member[i].meal;
        totalDeposit += member[i].deposit;
    }

    balance = totalDeposit - totalBazar;
    mealRate = totalBazar / totalMeal;
    mealCostPerson = mealRate / (memberIndex);

    printf("\t_____________________________________________\n\n\n");
        printf("\t\tBalance: \t\t %.2f\n\n", balance);

        printf("\t\tTotal Meal: \t\t %.2f\n\n", totalMeal);
        printf("\t\tTotal Deposit: \t\t %.2f\n\n", totalDeposit);
        printf("\t\tTotal Cost: \t\t %.2f\n\n", totalBazar);
        printf("\t\tMeal Rate: \t\t %.2f\n\n", mealRate);
        printf("\t\tMeal Cost Person: \t %.2f\n\n", mealCostPerson);

        printf("\t_____________________________________________\n\n");

        GoBack();

}

void EditBazar()
{
    system("cls");
    printf("\n\t\t ---------------------------------------\n");
    printf("     \t\t\t  Edit Bazar Cost    ");
    printf("\n\t\t ---------------------------------------\n");

    printf("\t\t\tNow Bazar Cost is: %.2f\n", totalBazar);
    float updatedBazar;
    printf("\t\t\tWhat will be the updated bazar?");
    scanf("%f", &updatedBazar);
    totalBazar = updatedBazar;

    GoBack();
}


void MemberDepositMeal()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tChose What you want to Edit    ");
    printf("\n\t -----------------------------------\n");
     printf("\t\t[1] Member's Meal\n\n");
    printf("\t\t[2] Member's Deposit\n\n");
    printf("\t\tEnter Your Choice: ");
    int option;
    scanf("%d", &option);
    switch(option){
    case 1:
        EditMeal();
        break;
    case 2:
        EditDeposit();
        break;
    }
}

void EditMeal()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tEdit Member's Meal    ");
    printf("\n\t -----------------------------------\n");
    int i;
    for(i=0; i<memberIndex; i++){
        printf("\t\t[%d]Edit %s's Meal\n\t\tCurrently it's %d\n\n", i+1, member[i].name, member[i].meal);
    }
    int option;
    printf("\n\n\t\tEnter Your Choice: ");
    scanf("%d", &option);

    if(option > memberIndex){
            system("cls");
        printf("Invalid Option!\n");

    }
    else{

        printf("\n\t\tUpdated to: ");
        int newMeal;
        scanf("%d", &newMeal);

        member[option-1].meal = newMeal;

        printf("\n\t\tUpdated Successfully\n");


    }

    GoBack();
}

void EditDeposit(){
        system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tEdit Member's Deposit    ");
    printf("\n\t -----------------------------------\n");
    int i;
    for(i=0; i<memberIndex; i++){
        printf("\t\t[%d]Edit %s's Deposit\n\t\tCurrently it's %d\n\n", i+1, member[i].name, member[i].deposit);
    }
    int option;
    printf("\n\n\t\tEnter Your Choice: ");
    scanf("%d", &option);

    if(option > memberIndex){
        system("cls");
        printf("Invalid Option!\n");

    }
    else{

        printf("\n\t\tUpdated to: ");
        int newDeposit;
        scanf("%d", &newDeposit);

        member[option-1].deposit = newDeposit;

        printf("\n\t\tUpdated Successfully\n");


    }

    GoBack();
}

void DeleteMember()
{
    system("cls");
    printf("\n\t -----------------------------------\n");
    printf("     \t\tDelete a Member    ");
    printf("\n\t -----------------------------------\n");
    int i;
    for(i=0; i<memberIndex; i++){
        printf("\t\t[%d] Delete Member %s\n", i+1, member[i].name);
    }
    int option;
    printf("\n\n\t\tEnter Your Choice: ");
    scanf("%d", &option);

    if(option > memberIndex){
        system("cls");
        printf("Invalid Option!\n");

    }
    else{

        int i;
        for(i=option-1; i<memberIndex; i++){
         strcpy(member[i].name, member[i+1].name);
         member[i].meal = member[i+1].meal;
         member[i].deposit = member[i+1].deposit;
        }
        memberIndex--;

        printf("\n\t\tDeleted Successfully\n");


    }

    GoBack();
}

void DeleteAllMember()
{
    getchar();
    printf("\n\t\tAre You Sure Want to Delete All Members? (Y,N): ");
    char YesOrNO;
    scanf("%c",&YesOrNO);
    if(YesOrNO == 'Y' || YesOrNO == 'y'){
        int i;
        for(i=0; i<memberIndex; i++){
            strcpy(member[i].name, nullStr);
            member[i].meal = 0;
            member[i].deposit = 0;
        }
        memberIndex=0;

        system("cls");
        printf("\t\tDeleted All Members Successfully\n");
    }
}


void GoBack()
{
    char option;
    getchar();
    printf("\n\t\tGo Back(b)? or Exit(0)?");
    scanf("%c",&option);
    if(option =='b'){
        system("cls");
    }else if(option == '0'){
        Exit();
    }
}

void Exit(){
    getchar();
    printf("\n\t\tAre You Sure Want to Exit? (Y,N): ");
    char YesOrNO;
    scanf("%c",&YesOrNO);
    if(YesOrNO == 'Y' || YesOrNO == 'y'){
        system("cls");

        char ThankYou[200] = "=====Thanks For Using Mess Manager=====\n";
        char SeeYouSoon[100] = "=====See You Soon=====\n";
        int i=0;
        printf("\n\n\t\t\t\t");
        for(i=0;i<strlen(ThankYou);i++){
            printf("%c",ThankYou[i]);
            Sleep(40);
        }
        printf("\n \t\t\t\t\t");
        for(i=0;i<strlen(SeeYouSoon);i++){
            printf("%c",SeeYouSoon[i]);
            Sleep(40);
        }
        isRunning =  false;
    }
}


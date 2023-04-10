#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct person
{
    int indeks;
    char p_fullname[45];
    char p_email[40];
    char p_password[40];
    float p_amount;
    float p_debt;
    char p_adress[40];
    char p_contact[40];


};

void menu_page(int *n);
void loggin_account(int n, struct person *Person, int num_users);
void registration_account(int n, struct person *Person, int num_users);
void file_function(struct person *Person, int num_users, FILE *dat);
void person_information(struct person *Person, int f_indeks);
void transfer_function(struct person *Person, int n);


int main(void)
{
    FILE *dat;
    dat = fopen("P1_Loggin.system","w");
    if(dat==NULL)
    {
        printf("File error");
        return 1;
    }
    int n,num_users=3;

    struct person *Person;
    Person = (struct person *) malloc(num_users*sizeof(struct person));
    if(Person==NULL)
    {
        printf("Memory error");
        return 1;
    }
    menu_page(&n);
    registration_account(n,Person,num_users);
    file_function(Person,num_users,dat);







}
void file_function(struct person *Person, int num_users, FILE *dat)
{
    fprintf(dat,"Information about %d person in bank.\n",num_users);
    for(int i=1; i<=num_users; i++)
    {

        fprintf(dat,"\n\t%d. person\n\n",i);
        fprintf(dat,"\nName : %s",(Person+i)->p_fullname);
        fprintf(dat,"e-mail : %s",(Person+i)->p_email);
        fprintf(dat,"password : %s",(Person+i)->p_password);
        fprintf(dat,"\nAmount of money : %.2f$\n",(Person+i)->p_amount);
        fprintf(dat,"Debt : %.2f$\n",(Person+i)->p_debt);
        fprintf(dat,"Adress : %s",(Person+i)->p_adress);


    }

    fclose(dat);

}

void menu_page(int *n)
{


    printf("\n\n\t----------------------------------Wellcome to banking system----------------------------------\n\n\n");
    printf("|Wellcome to my first coding project. Any suggestion are welcome and appreciated.|\n|Instruction : First go on registration page to create your account(Test all incorrect password/name...), then proceed to the loggin page.|\n\n\n");
    printf("1. Loggin me.\n2. Register me.\n3. Exit.\n");
    printf("\nSelect number : ");
    scanf("%d",&(*n));




}


void transfer_function(struct person *Person, int n)
{
    int log_n;
    int transfer_name, transfer_amount;
    printf("\nChoose the tasks you want to do:  \n1. Transfer money to another user.\n2. Taking a loan.\n3. Exit.\n");
    scanf("%d",&log_n);
    switch(log_n)
    {

    case 1:
        printf("\nName of the person you want to send money to: \n");
        scanf("%s",&transfer_name);
        printf("\nAmout of money : \n");
        scanf("%d",&transfer_amount);

        break;

    case 2:
        printf("Your choose is taking a loan.\n Please give me  : \n");
        break;

    case 3 :
        menu_page(&n);
        break;
    }


}

void person_information(struct person *Person, int f_indeks)
{


    printf("\n\n\n----------\nYour id code is : 1928300%d\n",f_indeks);
    printf("Your amount of money : %.2f\n",(Person+f_indeks)->p_amount);
    printf("Your debt : %.2f\n",(Person+f_indeks)->p_debt);
    printf("Your adress : %s",(Person+f_indeks)->p_adress);
    printf("Your contact : %s",(Person+f_indeks)->p_contact);
    printf("\n----------\n\n\n");




}

void loggin_account(int n, struct person *Person, int num_users)
{
    bool email_found = false;
    int tries=3;
    char lemail[40];
    char  lpassword[40];
    int current_indeks;
    printf("\n\n\t--------------------------------------Banking system--------------------------------------\n\n\n");
    printf("\t\nPlease Loggin your account... \n");



    do
    {


        printf("Your e-mail: ");
        fgets(lemail,40,stdin);
        for(int j=1; j<=num_users; j++)                                     // 6 GRESKA
        {
            if(strcmp(lemail,(Person+j)->p_email)==0)
            {
                //email_correct


                current_indeks = (Person+j)->indeks;
                email_found = true;
                break;
            }


        }
        if(!email_found)                                                    //7 GRESKA
        {


            printf("Your email, does not exit in data, please try again..\n");


        }



    }
    while(!email_found);
    do
    {
        while(tries>0)
        {
            printf("Your password : ");
            scanf("%s",lpassword);                                  // 4 GRESKA


            if(strcmp(lpassword,(Person+current_indeks)->p_password)==0)
            {
                //password_correct
                break;
            }

            else
            {
                tries--;
                printf("Your password is incorrect, please try again..\n");

                printf("\nRemmaining %d attempts.",tries);
            }

            if(tries==0)
            {
                printf("\nYou have no more attempts.. ");

            }
        }


    }
    while(strcmp(lpassword,(Person+current_indeks)->p_password)!=0);

    printf("\n\n\n--------------------------------------------------------------------------------------------------------------");
    printf("\n\n\nWellcome back %s your current state :",(Person+current_indeks)->p_fullname);



    person_information(Person,current_indeks);
    transfer_function(Person,n);




}
void registration_account(int n,struct person *Person,int num_users)
{
    char password1[40];
    char *at_symbol;
    int tries=4;
    int size_name =0;

    while(n!=3)                                 // GRESKA 5
    {
        for(int i=1; i<=num_users; i++)
        {
            switch(n)
            {
            case 1:
                // clear_buffer
                while(getchar() != '\n');
                loggin_account(n,Person, num_users);
                menu_page(&n);
                break;

            case 2:

                printf("\n\n\t--------------------------------------You have chosen register account--------------------------------------\n\n\n");
                while(getchar() != '\n');                           // 3 GRESKA

                do
                {

                    printf("\nEnter your full name : ");
                    (Person+i)->indeks=i;
                    fgets((Person+i)->p_fullname,45,stdin);             // 2 GRESKA
                    size_name = strlen((Person+i)->p_fullname);
                    //check_name_validity

                    if(size_name>39 || size_name == 1)
                    {
                        printf("Your name has too many charachters, please try again..");
                    }
                    if(size_name<39 && size_name>1)
                    {
                        printf("Welcome %s, please press enter to continue registration..",(Person+i)->p_fullname);
                    }
                    while(getchar() != '\n');                           //1 GRESKA
                }
                while(size_name>39 || size_name==1);

                do
                {
                    printf("\nEnter your e-mail : ");
                    fgets((Person+i)->p_email,40,stdin);

                    //check_email_validity


                    at_symbol = strchr((Person+i)->p_email, '@');
                    if(at_symbol==NULL)
                    {
                        printf("Invalid e-mail adress..\nPlease try again.\n");
                    }

                }
                while(at_symbol == NULL);

                while(tries>0)
                {


                    printf("Enter your password : ");
                    scanf("%s",(Person+i)->p_password);
                    printf("Please repeat your password : ");
                    scanf("%s",password1);

                    //check_password_validity

                    if(strcmp((Person+i)->p_password,password1)==0)
                    {
                        break;

                    }
                    else
                    {
                        tries--;
                        printf("Your password do not match, please try again..\n");
                        printf("Remmaining attempts %d.\n",tries);

                    }
                    if(tries==0)
                    {
                        printf("\nYou have no more attempts.");
                    }

                }



                /* while(getchar() != '\n');
                 printf("\nYour contact : ");
                 fgets((Person+i)->p_contact,40,stdin);
                 printf("Your adress : ");
                 fgets((Person+i)->p_adress,40,stdin);
                 printf("Your amount of money that you have: ");
                 scanf("%f",&(Person+i)->p_amount);
                 printf("\nDo you have debt ?");
                 int askq;

                 do{
                 printf("\n0 - Yes, 1 - No.");
                 scanf("%d",&askq);
                 if(askq==0)
                 {
                     printf("How much debt do you have : ");
                     scanf("%f",&(Person+i)->p_debt);
                 }
                 if(askq==1)
                 {
                     printf("So your debt is 0$");
                     (Person+i)->p_debt = 0;
                 }
                 else
                     printf("\nWrong button, try again..");
                 }while(askq!=1 && askq!=0);
                 printf("\nCongratulations, you have successufully created an banking account!\n\nGo to loggin section!");*/
                //back to menu
                menu_page(&n);
                break;

            default :
                printf("Choosen the wrong number...");
                n=3;
                i = num_users+1;
                break;
            }

        }









    }










}

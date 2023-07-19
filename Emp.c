#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

 typedef struct 
 {
    char employeeFirstName[30];
    char employeeLastName[30];
    char designation[30];
    char gender;
    int age;
    char address[30];
    char contact[10];
    float salary;

 }employee;

    FILE *fp;
    employee e;


    void title();
    void login();
    void menu();
    void appoint();
    void viewAll();
    void searchByName();
    void searchByDesignation();
    void modify();
    void delete();
    void deleteAll();
    void guideline();


   
    void main(){
        title();
        login();
        menu();
    }
    


    void title(){
        system("cls");
        printf("\n > Employee Management System");
        printf("\n   --------------------------");
        printf("\n\n > A Simple Console Based Application For ");
        printf("\n > Performing Various Operation on Employee Records");
        printf("\n > Press Any Key To Continue");
        getch();
        system("cls");
        
    }

        //Login interface to access Main Menu

    void login()
    {
        system("cls");
        char tempUsername[10];
        char tempPass[10];
        int limit=0;
        
        do{
        printf("\n\n > Authenticate Credentials | ");
        printf("\n\n\n > Enter Username: ");
        fgets(tempUsername, sizeof(tempUsername), stdin);
        tempUsername[strcspn(tempUsername, "\n")] = '\0'; // remove newline character

        printf("\n > Enter Password:  ");
        fgets(tempPass, sizeof(tempPass), stdin);
        tempPass[strcspn(tempPass, "\n")] = '\0'; // remove newline character

        if ((strcmp(tempUsername, "Admin") == 0) && (strcmp(tempPass, "1234") == 0))
            {
                printf("\n > Login Successful!");
                //
                return;
            }
                else{
                    printf("\n > Wrong Credentials!");
                    printf("\n > Press Any Key To Retry..!");
                    getch();
                    system("cls");
                    limit++;
                    }
                    if(limit==3)
                {
                    printf("\n > You Have Exceeded Login Limit | Try Again Later :) \n\n");
                    getch();
                }

        }while(limit<3);
                    exit(0);
                
    }


        //Appoointing new employee in the file
        void appoint(){
            system("cls");
            
            fp=fopen("employee.txt","ab+");
            int tempAge;
  

            printf("\n > Appoint Employee |\n");
            
            printf("\n > Enter First Name: ");
            fflush(stdin);
            fgets(e.employeeFirstName, sizeof(e.employeeFirstName), stdin);
            e.employeeFirstName[strcspn(e.employeeFirstName, "\n")] = '\0'; // remove newline character

            printf("\n > Enter SurName: ");
            fflush(stdin);
            fgets(e.employeeLastName, sizeof(e.employeeLastName), stdin);
            e.employeeLastName[strcspn(e.employeeLastName, "\n")] = '\0'; // remove newline character

            printf("\n > Enter Designation [ Manager | Support | Cleaner ]: ");
            fflush(stdin);
            fgets(e.designation, sizeof(e.designation), stdin);
            e.designation[strcspn(e.designation, "\n")] = '\0'; // remove newline character


            printf("\n > Enter Gender [ M/F]: ");
            scanf("%c",&e.gender);
           
            printf("\n > Enter Age: ");
            scanf("%d",&e.age);
            if (e.age < 18 || e.age > 60){
                printf("\n Age Should be Above 18 & Below 60...!");
                getch();
                system("cls");
                printf("\n > Enter Age: ");
                scanf("%d",&e.age);
            }

            printf("\n > Enter Address: ");
            fflush(stdin);
            fgets(e.address, sizeof(e.address), stdin);
            e.address[strcspn(e.address, "\n")] = '\0'; // remove newline character

            printf("\n > Enter Contact [10 Digit]: ");
            fflush(stdin);
            gets(e.contact);
            
            printf("\n > Enter Salary: ");
            scanf("%f",&e.salary);
            
        
            fwrite(&e,sizeof(employee),1,fp);
           
            fclose(fp);
            printf("\n > Employee Appointed...!");
            printf("\n > Press Any Key To Return To Main Menu.!");
            getch();
            menu();
           
            }


            //Viewing all the Exisiting Records
            void viewAll(){

                system("cls");
                int i=1;
                printf("\n > Employee Records | \n\n");
                fp=fopen("employee.txt","r");
               

                while(fread(&e,sizeof(employee),1,fp)==1){
                     
                     printf("\n > Sr No: %d\n > Name: %s\n > Surname: %s\n > Designation: %s\n > Gender: %c\n > Age: %d\n > Address: %s\n > Contact: %s\n > Salary: %f ",i,e.employeeFirstName,e.employeeLastName,e.designation,e.gender,e.age,e.address,e.contact,e.salary);
                     printf("\n----------------------------------------------\n\n");
                            i++;
                }
                fclose(fp);
                printf("\n > Press Any Key To Return To Main Menu.!");
                getch();
                menu();

            }


        // Searching Particular EMployee By Name
        void searchByName(){
            char name[30];
            int i=1, found=0;
            system("cls");
            printf("\nEnter First Name to Search: ");
            fflush(stdin);
            fgets(name,sizeof(name),stdin);
            name[strcspn(name, "\n")] = '\0'; // remove newline character
            fp= fopen("employee.txt","r");
               while(fread(&e,sizeof(employee),1,fp)==1)
               {
                 if(strcmpi(name,e.employeeFirstName)==0){
            found=1;
            printf("\n > Sr No: %d\n > Name: %s\n > Surname: %s\n > Designation: %s\n > Gender: %c\n > Age: %d\n > Address: %s\n > Contact: %s\n > Salary: %f ",i,e.employeeFirstName,e.employeeLastName,e.designation,e.gender,e.age,e.address,e.contact,e.salary);
            printf("\n----------------------------------------------\n\n");
                break;
            }
               }
               
            fclose(fp);
                  if(found==0){
                      printf("\n > Record Not Found....!\n");
                  }
                 else {
                     printf("\n > Record Found Successfully...!\n");
                     }
                    
                 getch();
                 printf("\n > Press Any Key To Return To Main Menu");
                 getch();
                 menu();
                 
            }

            // Searching Particular Employee By Designation
            void searchByDesignation(){
            char designation[30];
            int i=1, found=0;
            system("cls");
            printf("\nEnter Designation to Search: ");
            fflush(stdin);
            fgets(designation,sizeof(designation),stdin);
            designation[strcspn(designation, "\n")] = '\0'; // remove newline character
            fp= fopen("employee.txt","r");
               while(fread(&e,sizeof(employee),1,fp)==1)
               {
                 if(strcmpi(designation,e.designation)==0){
            found=1;
            printf("\n > Sr No: %d\n > Name: %s\n > Surname: %s\n > Designation: %s\n > Gender: %c\n > Age: %d\n > Address: %s\n > Contact: %s\n > Salary: %f ",i,e.employeeFirstName,e.employeeLastName,e.designation,e.gender,e.age,e.address,e.contact,e.salary);
            printf("\n----------------------------------------------\n\n");
            i++;
            }
               }
               
            fclose(fp);
                  if(found==0){
                      printf("\n > Record Not Found....!\n");
                  }
                 else {
                     printf("\n > Record Found Successfully...!\n");
                     }
                    
                 getch();
                 printf("\n > Press Any Key To Return To Main Menu");
                 getch();
                 menu();
            }
            

        // Modifying the exisiting Record
            
    void modify() {
    system("cls");
    int found = 0;
    char tempName[30];
    fp = fopen("employee.txt", "r+");

    printf("\n > Enter First Name of the Employee to be Modified: ");
    fflush(stdin);
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] = '\0'; // remove newline character

    while (fread(&e, sizeof(employee), 1, fp) == 1) {
        if (strcmpi(tempName, e.employeeFirstName) == 0) {
            found = 1;

            printf("\n > Enter First Name: ");
            fflush(stdin);
            fgets(e.employeeFirstName, sizeof(e.employeeFirstName), stdin);
            e.employeeFirstName[strcspn(e.employeeFirstName, "\n")] = '\0'; // remove newline character

            printf("\n > Enter SurName: ");
            fflush(stdin);
            fgets(e.employeeLastName, sizeof(e.employeeLastName), stdin);
            e.employeeLastName[strcspn(e.employeeLastName, "\n")] = '\0'; // remove newline character

            printf("\n > Enter Designation [ Manager | Support | Cleaner ]: ");
            fflush(stdin);
            fgets(e.designation, sizeof(e.designation), stdin);
            e.designation[strcspn(e.designation, "\n")] = '\0'; // remove newline character

            printf("\n > Enter Gender [ M/F]: ");
            scanf(" %c", &e.gender);

            printf("\n > Enter Age: ");
            scanf("%d", &e.age);
            if (e.age < 18 || e.age > 60) {
                printf("\n Age Should be Above 18 & Below 60...!");
                getch();
                system("cls");
                printf("\n > Enter Age: ");
                scanf("%d", &e.age);
            }

            printf("\n > Enter Address: ");
            fflush(stdin);
            fgets(e.address, sizeof(e.address), stdin);
            e.address[strcspn(e.address, "\n")] = '\0'; // remove newline character

            printf("\n > Enter Contact [10 Digit]: ");
            fflush(stdin);
            gets(e.contact);
            
            printf("\n > Enter Salary: ");
            scanf("%f", &e.salary);

            fseek(fp, -sizeof(employee), SEEK_CUR);
            fwrite(&e, sizeof(employee), 1, fp);
            break; // Exit the loop after modifying the employee record
        }
    }

    fclose(fp);

    if (found == 0) {
        printf("\n > Record Doesn't Exist..!");
        getch();
        menu();
    } else {
        printf("\n > Record Updated...!");
        printf("\n > Press Any Key To Return To Main Menu.!");
        getch();
        menu();
    }
}


        void delete(){

            FILE *ftemp; // This is a temporary file for deleting the record from the original file.
            system("cls");
            int found=0;
            char tempName[30];
            printf("\n > Delete a Record | \n");
            printf("------------------------\n\n");
            printf("Enter Name of The Employee To Be Deleted: ");
            fflush(stdin);
            fgets(tempName, sizeof(tempName), stdin);
            tempName[strcspn(tempName, "\n")] = '\0'; // remove newline character

            fp=fopen("employee.txt","r");
            ftemp=fopen("temp.txt","ab+");

                 while (fread(&e, sizeof(employee), 1, fp) == 1) 
                 {
                    if (strcmpi(tempName, e.employeeFirstName) == 0)
                     {
                          found = 1;
                     }
                     else{
                        fwrite(&e, sizeof(employee), 1, ftemp);
                     }
                 }
                 fclose(fp);
                 fclose(ftemp);
                 //Removing the original File
                 remove("employee.txt");

                //Renaming the Temp File as that Name of Original File
                 rename("temp.txt","employee.txt");
                 if (found == 0) {
                printf("\n > Record Doesn't Exist..!");
                getch();
                 menu();
                } else {
                    printf("\n > Record Deleted...!");
                    printf("\n > Press Any Key To Return To Main Menu.!");
                    getch();
                    menu();
                }

        }

        void deleteAll(){
            system("cls");
            int choice;
            
            printf("\n > Delete All The Records | \n");
            printf("-----------------------------\n");

            printf(" \n > Warning : This Operation is Removes all the exising Data..!\n ");
            printf(" > Press '1' To Continue Or '0' To Cancel: ");
            scanf("%d",&choice);
            if(choice==1){
                //fp=fopen("employee.txt","r+");
                 remove("employee.txt");
                 printf("\n > Records Deleted Successfully..!");
                 printf("\n > Press Any Key To Return..!");
                 getch();
                 system("cls");
                 menu();
                 //fclose(fp);
            }
            else{
                printf("\n > Press Any Key To Return To Main Menu |");
                getch();
                system("cls");
                menu();
            }
            if(choice != 1 && choice !=0){
                printf("\n > Invalid Selection..!");
                getch();
                system("cls");
                menu();

            }
        }


        void guideline(){
            system("cls");
            printf("\n > User Guideline | ");
            printf("\n-----------------------\n");
            printf("\n > This a 'C' Language Bases Application.");
            printf("\n > As C Language Does not Support Error Handling be Careful while Inserting Data.");
            printf("\n > Always Insert Right Data Into Right Field To Avoid Program Termination.");
            printf("\n > This is a Simple Project To ");
            printf("\n To Store | To Access | To Delete | To Modify |");
            printf("\n > Employee Records in Efficient & Paper Less Manner");
            printf("\n--------------------------------------------------------\n");
            printf("\n\n > About Us");
            printf("\n > Linkedin:  https://www.linkedin.com/in/swanand-bobade-20473b262");
            printf("\n--------------------------------------------------------\n");
            printf("\n >  Thank You");
            printf("\n > Press ANy Key To Exit..!");
            getch();
            exit(0);
        }

                
            


        void menu(){
            system("cls");
            int choice;
            printf("\n > Main Menu | \n\n");
            printf("\n > 1. Appoint Employee");
            printf("\n > 2. View All");
            printf("\n > 3. Search By Name");
            printf("\n > 4. Search By Designation");
            printf("\n > 5. Modify Record");
            printf("\n > 6. Delete Record");
            printf("\n > 7. Delete All");
            printf("\n > 8. View Guideline");
            printf("\n > 0. Exit");
            
            printf("\n > Enter Appropriate Option [ 0 - 9 ] ");
            scanf("%d",&choice);
            
            switch (choice)
            {
                case 0:
                printf("\n > Thank You..!");
                getch();
                exit(0);
            
            case 1:
                appoint();
                break;

            case 2:
                viewAll();
                break;

            case 3:
                searchByName();
                break;

            case 4:
                 searchByDesignation();
                 break;

            case 5:
                modify();
                break;

            case 6:
                delete();
                break;

            case 7:
                deleteAll();
                break;

            case 8:
                guideline();
                break;

            
           
            default:
            printf("\n > Invalid Choice..!");
                break;
            }

            }
    
    

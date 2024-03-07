#include<stdio.h>
#include<conio.h>

void add_stu();
void stu_re();
void searchstudent();
void Delect();

struct student_sys
{
    char first_name[20];
    char last_name[20];
    int stu_id;
    char Class[10];
    char vill[20];
    float per;
};
void main(){
    int choice;
    while(choice!=5){
        printf("\t\t\t=====STUDENT DATABASE MANAGEMENT SYSTEM=====");
        printf("\n\n\n\t\t\t\t 1.Add Student Records\n");
        printf("\t\t\t\t 2.Student Records\n");
        printf("\t\t\t\t 3.Search Student\n");
        printf("\t\t\t\t 4.Delete Records\n");
        printf("\t\t\t\t 5.Exit\n");
        printf("\t\t\t\t_________________________________\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            system("cls");
            add_stu();
            system("cls");
            break;

        case 2:
            system("cls");
            stu_re();
            printf("\t\t\t\tPress any key to exit\n");
            getch();
            system("cls");
            break;

        case 3:
            system("cls");
            searchstudent();
            printf("\n\t\t\t\tPress any key to exit\n");
            getch();
            system("cls");
            break;

        case 4:
            system("cls");
            Delect();
            printf("\n\t\t\t\tPress any key to exit\n");
            getch();
            system("cls");
            break;

        default:
            system("cls");
            getch();
            printf("\n\t\t\tNot service!!\n\n");
            printf("\n\t\t\tPress any key to countinue....\n\n");
            getch();
            system("cls");
            break;
        case 5:
            system("cls");
            printf("\n\t\t\tThank you for used us!!\n\n");
            exit(0);
            break;
        }
    }
}
void add_stu(){
    char another;
    FILE *fp;
    struct student_sys info;

    do{
        system("cls");
        printf("\t\t\t\t=====Add Student info=====\n\n\n");
        fp=fopen("student_info","a");
        printf("\n\t\t\tEnter first name :");
        scanf("%s",&info.first_name);
        printf("\n\t\t\tEnter last name  :");
        scanf("%s",&info.last_name);
        printf("\n\t\t\tEnter Student ID :");
        scanf("%d",&info.stu_id);
        printf("\n\t\t\tEnter class      :");
        scanf("%s",&info.Class);
        printf("\n\t\t\tEnter address    :");
        scanf("%s",&info.vill);
        printf("\n\t\t\tEnter percentage :");
        scanf("%f",&info.per);
        printf("\n\t\t\t_______________________\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\tCan't open file");
        }else{
            printf("\t\t\tRecord stored successfuly\n");
        }
        fwrite(&info,sizeof(struct student_sys),1,fp);
        fclose(fp);
        printf("\t\t\tDo you want to add another record? (y/n) :");
        scanf("%s",&another);
    }while(another=='y' || another=='Y');
}

void stu_re(){
    FILE *fp;
    struct student_sys info;
    fp=fopen("student_info","r");

    printf("\t\t\t\t=====Student Records=====\n\n\n");

    if(fp==NULL){
        fprintf(stderr,"\t\t\tCan't open file\n");
        }else{
            printf("\t\t\tRecords\n");
            printf("\t\t\t___________________\n\n");
        }
        while(fread(&info,sizeof(struct student_sys),1,fp)){
            printf("\n\t\t\t\tStudent name : %s %s",info.first_name,info.last_name);
            printf("\n\t\t\t\tStudent ID   : %d",info.stu_id);
            printf("\n\t\t\t\tClass        : %s",info.Class);
            printf("\n\t\t\t\tAddress      : %s",info.vill);
            printf("\n\t\t\t\tPercentage   : %f",info.per);
            printf("\n\t\t\t\t__________________________________\n");
        }
        fclose(fp);
        getch();
    }
void searchstudent(){
    FILE *fp;
    struct student_sys info;
    int stu_id,found=0;

    fp=fopen("student_info","r");

    printf("\t\t\t\t=====Search Student=====\n\n\n");
    printf("\t\t\t\tEnter Student ID : ");
    scanf("%d",&stu_id);

     while(fread(&info,sizeof(struct student_sys),1,fp)){
            if(info.stu_id==stu_id){
            found=1;
            printf("\n\t\t\t\tStudent name : %s %s",info.first_name,info.last_name);
            printf("\n\t\t\t\tStudent ID   : %d",info.stu_id);
            printf("\n\t\t\t\tClass        : %s",info.Class);
            printf("\n\t\t\t\tAddress      : %s",info.vill);
            printf("\n\t\t\t\tPercentage   : %f",info.per);
            printf("\n\t\t\t\t__________________________________\n");
        }
     }
        if(!found){
            printf("\n\t\t\t\tRecord not found!!\n");
        }
        fclose(fp);
        getch();
}
void Delect(){
    FILE *fp,*fp1;
    struct student_sys info;
    int stu_id,found=0;

    printf("\t\t\t\t=====Delect Student Record=====\n\n\n");
    fp=fopen("student_info","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter Student ID : ");
    scanf("%d",&stu_id);

     if(fp==NULL){
        fprintf(stderr,"\t\t\tCan't open file\n");
    }
    while(fread(&info,sizeof(struct student_sys),1,fp)){
            if(info.stu_id==stu_id){
            found=1;
            }else{
                fwrite(&info,sizeof(struct student_sys),1,fp1);
            }
        }
        fclose(fp);
        fclose(fp1);

        if(found){
            remove("student_info");
            rename("temp.txt","student_info");
            printf("\n\t\t\tRecord deleted successfully!!");
        }
        if(!found){
            printf("\n\t\t\tRecord not found!!");
        }
        getch();
}


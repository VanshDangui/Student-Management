 #include <stdio.h>
struct student{
    char name[100];
    char branch[100];
    int rollNo;
    float cgpa;
};           //keyword is stu
int main(){
struct student information[5];
for(int i=0;i<5;i++){           // loop
printf("Enter Student name:");
scanf("%s",information[i].name);
printf("Enter Student branch:");
scanf("%s",information[i].branch);
printf("Enter Student Roll no:");
scanf("%d",&information[i].rollNo);
printf("Enter Student cgpa:");
scanf("%f",&information[i].cgpa);
}
FILE*fptr;
fptr=fopen("store.txt","ab");       // data stored in file store.txt
if(fptr==NULL){
    printf("file could not be found");
    return 1;
}
fwrite(information,sizeof(struct student),5,fptr);
fclose(fptr);
return 0;

}
#include<stdio.h>
struct student{
    char name[100];
    char branch[100];
    int rollNo;
    float cgpa;
};
int main(){
int rollno ;
printf("Enter the Roll Number of the Student");
scanf("%d",&rollno);
FILE*fptr;
fptr=fopen("store.txt","rb");
if(fptr==NULL){
    printf("file could not be found");
    return 1;
}
struct student temp;
int found=0;
for( ;fread(&temp,sizeof(struct student),1,fptr)==1; ){  
     //freads returns 1 if it reads the full record,0 if it hits end of file
     // so ant end of file it will return 0 and loop will stop
       
    if(temp.rollNo==rollno){
        printf("Name:%s\n",temp.name);
        printf("Branch:%s\n",temp.branch);
        printf("Roll Number:%d\n",temp.rollNo);
        printf("cgpa:%f\n",temp.cgpa);
        found=1;
        break;
    }
}
   if(found==0){
    printf("Student with Roll Number %d is not found",rollno);
   }
   fclose(fptr);

return 0;
}
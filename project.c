    #include <stdio.h>
    #include <string.h>
    #include <time.h>
    #include<math.h>


    struct Date{
        int day;
        int month;
        int year;
    };

    void setDay(struct Date date,int d){
        date.day=d;
    }
    void setMonth(struct Date date,int m){
        date.month=m;
    }
    void setYear(struct Date date,int y){
        date.year=y;
    }
    struct Student {

        struct StudentName {
            char firstName [30];
            char middleName [30];
            char lastName[30];
        }studentName;

        char nationality [30];
        
        struct StudentID{
            char typeOfId [30];
            char idNumber[30];
            struct Date expiryDate;
        }studentID;

        char homeAddress [200];

        struct StudentAge{
            struct Date dateOfBirth;
            int age ;
        }studentAge;

        char gender [6];

        char department[50];

        struct Tutor {
            char name[50];
            char code[10];
        }tutor;

        struct CreditHours{
            int totalHours;
            int finishedHours;
            int currentTerm;
        }creditHours;

        struct Contact {
            char email [100];
            char homePhone[15];
            char studentMobile[15];
        }contact;
        
        double GPA;
        double fees;
        double discount;
    };
    void setStudentFirstName(struct Student s[],char firstName[]){
        strncpy(s[0].studentName.firstName,firstName,30);
    }

    void setStudentMiddleName(struct Student s[],char middleName[]){
        strncpy(s[0].studentName.middleName,middleName,30);
    }

    void setStudenLastName(struct Student s[],char lastName[]){
        strncpy(s[0].studentName.lastName,lastName,30);
    }

    // void setStudentName(struct Student s[],char firstName[],char middleName[],char lastName[]){
    //     setStudentFirstName(s,firstName);
    //     setStudentMiddleName(s,middleName);
    //     setStudenLastName(s,lastName);
    // }
    
    void setNationality(struct Student s[],char nationality[]){
        strcpy(s[0].nationality,nationality);
    }

    void setStudentIdTypeOfId(struct Student s[],char type[]){
        strcpy(s[0].studentID.typeOfId,type);
    }
    void setStudentIdIdNumber(struct Student s[],char number[]){
        strcpy(s[0].studentID.idNumber,number);
    }
    void setStudentIdExpiryDate(struct Student s[],int d,int m,int y){
        s[0].studentID.expiryDate.day=d;
        s[0].studentID.expiryDate.month=m;
        s[0].studentID.expiryDate.year=y;
    }
    void setStudentId(struct Student s[],char type[],char number[],int d,int m,int y){
        setStudentIdTypeOfId(s,type);
        setStudentIdIdNumber(s,number);
        setStudentIdExpiryDate(s,d,m,y);
    }
    void setHomeAddress(struct Student s[], char homeAddress[]){
        strcpy(s[0].homeAddress,homeAddress);
    }
    void setStudentAge(struct Student s[],int d,int m,int y){
       s[0].studentAge.dateOfBirth.day=d;
       s[0].studentAge.dateOfBirth.month=m;
       s[0].studentAge.dateOfBirth.year=y;
        //set student age automatically
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[0].studentAge.age = (tm.tm_year+1900) - y;
    }
    void setGender(struct Student s[],char g[]){
        strcpy(s[0].gender,g);
    }
    void setDepartment(struct Student s[],char d[]){
        strcpy(s[0].department,d);
    }
    void setTutorName(struct Student s[], char name[]){
        strcpy(s[0].tutor.name,name);
    }
    void setTutorCode(struct Student s[],char c[]){
        strcpy(s[0].tutor.code,c);
    }
    void setTutor(struct Student s[],char name[],char code[]){
        setTutorName(s,name);
        setTutorCode(s,code);
    }
    void setCreditHours(struct Student s[],int total,int finished){
        s[0].creditHours.totalHours = total ;
        s[0].creditHours.finishedHours = finished;
        s[0].creditHours.currentTerm = ceil(finished/18.0);
    }
    void updateCreditHours(struct Student s[],int finished){
        s[0].creditHours.finishedHours = finished;
        s[0].creditHours.currentTerm = ceil(finished/18.0);
    }
    void setContactEmail(struct Student s[],char email[]){
        strcpy(s[0].contact.email , email);
    }
    void setContactHomePhone(struct Student s[],char homePhone[]){
        strcpy(s[0].contact.homePhone , homePhone);
    }
    void setContactStudentMobile(struct Student s[],char studentmobile[]){
        strcpy( s[0].contact.studentMobile,studentmobile);
    }
    void setContact(struct Student s[],char email[],char homePhone[],char studentmobile[]){
        setContactEmail(s,email);
        setContactHomePhone(s,homePhone);
        setContactStudentMobile(s,studentmobile);
    }
    void setGPA(struct Student s[],double GPA){
        s[0].GPA=GPA;
    }
    void updateCourseGPA(struct Student s[],double courseGPA,int courseHours){
        int finishedCoursesWithoutEditedCourse=s[0].creditHours.finishedHours-courseHours;
        s[0].GPA = (((s[0].GPA*finishedCoursesWithoutEditedCourse)+(courseGPA*courseHours))/s[0].creditHours.finishedHours);
    }
    void addCourse(struct Student s[],int courseHours){
        s[0].creditHours.finishedHours=s[0].creditHours.finishedHours+courseHours;
    }
    void setFees(struct Student s[], double fees){
            s[0].fees = fees;
    }
    void setDiscount(struct Student s[],double discount){
        s[0].discount=discount;
        if(s[0].fees>0){
            double mult = (s[0].fees)*(s[0].discount);
            mult = mult /100;
             s[0].fees=(s[0].fees)-mult;
        }
    }
    char * getFirstName(struct Student s[]){
        char *str =s[0].studentName.firstName;
        return str ;
    }
    char * getMiddleName(struct Student s[]){
        char *str =s[0].studentName.middleName;
        return str ;
    }
    char * getLastName(struct Student s[]){
        char *str =s[0].studentName.lastName;
        return str;
    }
    
    char * getNationality(struct Student s[]){
       char *str =s[0].nationality ;
       return str;
    }

    char * getTypeOfId(struct Student s[]){
        char *str = s[0].studentID.typeOfId;
         return str;
    }
    char * getIdNumber(struct Student s[]){
       char *str = s[0].studentID.idNumber;
        return str;
    }
    int getExpiryDay(struct Student s[]){
        return (s[0].studentID.expiryDate.day);
    }
    int getExpiryMonth(struct Student s[]){
        return (s[0].studentID.expiryDate.month);
    }
    int getExpiryYear(struct Student s[]){
        return (s[0].studentID.expiryDate.year);
    }
    char * getHomeAddres(struct Student s[]){
        char *str = s[0].homeAddress;
        return str;
    }
    int getBirthDay(struct Student s[]){
        return s[0].studentAge.dateOfBirth.day;
    }
    int getBirthMonth(struct Student s[]){
        return s[0].studentAge.dateOfBirth.month;
    }
    int getBirthYear(struct Student s[]){
        return s[0].studentAge.dateOfBirth.year;
    }
    int getAge(struct Student s[]){
        return s[0].studentAge.age;
    }
    char * getGender(struct Student s[]){
        char *str = s[0].gender;
         return str;
    }
    char * getDepartment(struct Student s[]){
        char *str = s[0].department;
         return str;
    }
    char * getTutorName(struct Student s[]){
        char *str = s[0].tutor.name;
        return str;
    }
    char * getTutorCode(struct Student s[]){
        char *str = s[0].tutor.code;
         return str;
    }
    int getTotalCreditHours(struct Student s[]){
        return s[0].creditHours.totalHours;
    }
    int getFinishedCreditHours(struct Student s[]){
        return s[0].creditHours.finishedHours;
    }
    int getCurrentTerm(struct Student s[]){
        return (s[0].creditHours.currentTerm);
    }
    double getGPA(struct Student s[]){
        return s[0].GPA;
    }
    char * getEmail(struct Student s[]){
       char *str = (s[0].contact.email);
        return str;
    }
    char * getHomePhone(struct Student s[]){
        char *str = s[0].contact.homePhone;
         return str;
    }
    char * getMobile(struct Student s[]){
        char *str = s[0].contact.studentMobile;
         return str;
    }
    double getFees(struct Student s[]){
        return s[0].fees;
    }
    double getDiscount(struct Student s[]){
        return s[0].discount;
    }
    //todo : add fees & discount in set student data 

    void setStudentData(struct Student s[]){
        printf("enter Student First name: \n");
        char fName[30];
        scanf("%s",fName);
        printf("enter Student middle name: \n");
        char mName[30];
        scanf("%s",mName);
        printf("enter Student last name: \n");
        char lName[30];
        scanf("%s",lName);
        setStudentFirstName(s,fName);
        setStudentMiddleName(s,mName);
        setStudenLastName(s,lName);
        printf("enter Student Nationality: \n");
        char nationality[30];
        scanf("%s",nationality);
        setNationality(s,nationality);
        printf("\nenter Student ID data \n what is your Id type :\n");
        char type[30];
        scanf("%s",type);
        printf("\nenter your id number :\n");
        char idNumber[30];
        scanf("%s",idNumber);
        printf("\nenter expiry date day :\n");

        int day=0;
        do{
            scanf("%d",&day);
            if(!(day <= 31 && day > 0)){

                printf("please enter a valid day\n");
            }
        } while(!(day <= 31 && day > 0));
        
        printf("enter expiry date month :\n");
        int month;
        do{
            scanf("%d",&month);
            if(!(month <= 12 && month > 0)){
                printf("please enter a valid month\n");
            }
        } while(!(month <= 12 && month > 0));
        printf("enter expiry date year :\n");
        int year;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t); 
        do{
            scanf("%d",&year);
            if(!( year >= 1980)){
                printf("please enter a valid year\n");
            }
        } while(!( year >= 1980));
        setStudentIdTypeOfId(s,type);
        setStudentIdIdNumber(s,idNumber);
        setStudentIdExpiryDate(s,day,month,year);
        char address[200];
        printf("enter student Home Address :\n(with out spaces)\n");
        scanf("%s",address);
        setHomeAddress(s,address);
        printf("enter Birth date day :\n");
        int Birthday;
    
         do{
            scanf("%d",&Birthday);
            if(!(Birthday <= 31 && Birthday > 0)){
                printf("please enter a valid day\n");
            }
        } while(!(Birthday <= 31 && Birthday > 0));

        printf("enter Birth date month :\n");
        int BirthMonth;

        do{
            scanf("%d",&BirthMonth);
            if(!(BirthMonth <= 12 && BirthMonth > 0)){
                printf("please enter a valid month\n");
            }
        } while(!(BirthMonth <= 12 && BirthMonth > 0));

        printf("enter Birth date year :\n");
        int Birthyear;
    
        do{
            scanf("%d",&Birthyear);
            if(!(Birthyear <= (tm.tm_year+1900) && Birthyear >= 1980)){
                printf("please enter a valid year\n");
            }
        } while(!(Birthyear <= (tm.tm_year+1900) && Birthyear >= 1980));

        setStudentAge(s,Birthday,BirthMonth,Birthyear);
        char gender[30];
        printf("enter student gender :\n");
        scanf("%s",gender); 
        setGender(s,gender);
        printf("enter student department :\n");
        char department[30];
        scanf("%s",department);
        setDepartment(s,department);
        printf("enter student Tutor Name :\n");
        char tutorname[50];
        scanf("%s",tutorname);
        setTutorName(s,tutorname);
        printf("enter student Tutor Code :\n");
        char tutorCode[10];
        scanf("%s",tutorCode);
        setTutorCode(s,tutorCode);
        printf("enter total credit Hours :\n");
        int total;
        scanf("%d",&total);
        printf("enter finished credit Hours :\n");
        int finished;
        scanf("%d",&finished);
        setCreditHours(s,total,finished);
        if(finished>0){
            printf("enter finished hours GPA \n");
            double gpa;
            scanf("%lf",&gpa);
            setGPA(s,gpa);
        }else{
            setGPA(s,0);
        }
        printf("contact information \n enter your mail : \n");
        char mail[100];
        scanf("%s",mail);
        printf("enter your home phone :\n");
        char homePhone[15];
        scanf("%s",homePhone);
        printf("enter your phone number :\n");
        char phone[20];
        scanf("%s",phone);

        setContactEmail(s,mail);
        setContactHomePhone(s,homePhone);
        setContactStudentMobile(s,phone);

        printf("enter the fees requested : \n");
        double fees;
        scanf("%lf",&fees);
        setFees(s,fees);
        printf("there is any discount ? \n enter :\n y for yes \n n for no\n");
        char yes[1] ;
        scanf("%s",yes);
        if(yes[0] == 'y'){
            printf("enter discount in precentage : \n");
            double disc;
            scanf("%lf",&disc);
            setDiscount(s,disc);
        }
        printf("\n student added \n thank you !");
    }

    void setData(struct Student s[],char fName[],char mName[],char lName[],char nationality[],char type[]
                            ,char idNumber[],int day,int month,int year,char address[],int Birthday,int BirthMonth
                            ,int Birthyear, char gender[],char department[],char tutorname[],char tutorCode [],
                            int total,int finished,double gpa,char mail [],char homePhone[],char phone[],
                            double fees,double disc){
        setStudentFirstName(s,fName);
        setStudentMiddleName(s,mName);
        setStudenLastName(s,lName);
        setNationality(s,nationality);
        setStudentIdTypeOfId(s,type);
        setStudentIdIdNumber(s,idNumber);
        setStudentIdExpiryDate(s,day,month,year);
        setHomeAddress(s,address);
        setStudentAge(s,Birthday,BirthMonth,Birthyear);
        setGender(s,gender);
        setDepartment(s,department);
        setTutorName(s,tutorname);
        setTutorCode(s,tutorCode);
        setCreditHours(s,total,finished);
        setGPA(s,gpa);
        setContactEmail(s,mail);
        setContactHomePhone(s,homePhone);
        setContactStudentMobile(s,phone);
        setFees(s,fees);
        setDiscount(s,disc);
    }



    void printStudent(struct Student s[]){
        printf("\n-------------Student Name-------------\n");
        printf(" %s %s %s\n",getFirstName(s),getMiddleName(s),getLastName(s));
        printf("\n-------------Nationality-------------\n");
        printf(" %s \n",getNationality(s));
        printf("\n-----------------ID------------------\n");
        printf("type of Id : %s\n",getTypeOfId(s));
        printf("ID number : %s\n",getIdNumber(s));
        printf("expiry date : %d / %d / %d \n",getExpiryDay(s),getExpiryMonth(s),getExpiryYear(s));
        printf("\n------------Home Address-------------\n");
        printf(" %s",getHomeAddres(s));
        printf("\n--------------BirthDate--------------\n");
        printf(" %d / %d / %d",getBirthDay(s),getBirthMonth(s),getBirthYear(s));
        printf("\nAge : %d",getAge(s));
        printf("\n---------------Gender----------------\n");
        printf(" %s",getGender(s));
        printf("\n--------------Department--------------\n");
        printf(" %s",getDepartment(s));
        printf("\n----------------Tutor-----------------\n");
        printf("name : %s \n",getTutorName(s));
        printf("code : %s",getTutorCode(s));
        printf("\n-------------Credit hours-------------\n");
        printf("Total : %d \n",getTotalCreditHours(s));
        printf("Finished : %d \n",getFinishedCreditHours(s));
        printf("Current Term : %d \n",getCurrentTerm(s));        
        printf("GPA : %f \n",getGPA(s));
        printf("\n---------------Contacts--------------\n");
        printf("E-mail : %s \n",getEmail(s));
        printf("Home Phone : %s \n",getHomePhone(s));
        printf("Student Mobile : %s ",getMobile(s));
        printf("\n----------fees after discount--------\n");
        printf("fees: %f",getFees(s));
        printf("\n---------------------------------------\n");
        printf("\n---------------------------------------\n");
        
    } 

    int getStudentsNumberInDept(struct Student s[][1],int n ,char dept[]){
        int k = 0;
        for(int i = 0 ; i<n;i++){
            if(strcmp(s[i][0].department,dept)==0){
                k++;
            }
        }
        return k;
    }
     void sortDesc(struct Student list[][1], int s){
        int i, j;
        struct Student temp;
        
        for (i = 0; i < s - 1; i++)
        {
            for (j = 0; j < (s - 1-i); j++)
            {
                if (list[j][0].GPA < list[j + 1][0].GPA)
                {
                    temp = list[j][0];
                    list[j][0] = list[j + 1][0];
                    list[j + 1][0] = temp;
                } 
            }
        }
    }
    // void swap(struct Student *A, struct Student *B){
    // struct Student temp = *A;
    // *A = *B;
    // *B = temp;
    // }
    void sortDepartmetStudentByGPA(struct Student s[][1],int n,char dept[]){
        int num = getStudentsNumberInDept(s,n,dept);
        struct Student arr[num][1];
        int k = 0 ;
        for(int i = 0 ; i<n;i++){
            if(strcmp(s[i][0].department,dept)==0){
                struct Student std[1] ;
                 setData(std,getFirstName(s[i]),getMiddleName(s[i]),getLastName(s[i]),getNationality(s[i]),getTypeOfId(s[i]),
                getIdNumber(s[i]),getExpiryDay(s[i]),getExpiryMonth(s[i]),getExpiryYear(s[i]),getHomeAddres(s[i]),getBirthDay(s[i]),getBirthMonth(s[i]),
                getBirthYear(s[i]),getGender(s[i]),getDepartment(s[i]),getTutorName(s[i]),getTutorCode(s[i]),getTotalCreditHours(s[i]),getFinishedCreditHours(s[i]),
                getGPA(s[i]),getEmail(s[i]),getHomePhone(s[i]),getMobile(s[i]),getFees(s[i]),getDiscount(s[i]));
                arr[k][0] = std[0];
                k++;
            }
        }
        sortDesc(arr,num+1);
        for(int i = 0 ;i<num;i++){
            printStudent(arr[i]);
        }
    }


    void addData(struct Student s[][1]){
                 setData(s[0],"Kiroles","Rimon","Mouris","egyptian","national","30011241600676",2,1,2024,"Tanta",24,11,2000,"male","mechanical"
                 ,"Dr:Noha","90",180,90,3.01,"kiro.rimon@gmail.com","0403314484","01280112482",800000,10);

                 setData(s[1],"Sarah","Ibrahem","Massod","egyptian","national","30011247252862",9,11,2025,"cairo",2,1,2000,"female","mechanical"
                 ,"Dr:Nagwa","120",180,18,3.52,"sarah@gmail.com","0803314484","01025112482",1000000,0);

                 setData(s[2],"assad","osama","ghaly","egyptian","national","30067258268254",26,10,2026,"komhamada",9,8,2000,"male","mechanical"
                 ,"Dr:Heba","600",180,100,3.61,"kiro.rimon@gmail.com","0303314484","01100112482",600000,5);

                 setData(s[3],"mohamed","farid","samy","egyptian","national","30011241656416",8,12,2027,"alexanderia",1,1,2002,"male","mechanical"
                 ,"Dr:Lara","60",180,82,3.9,"farid@gmail.com","03403314484","012725725752",800000,50);

                 setData(s[4],"sameh","abbas","kamel","egyptian","national","30011585100676",9,3,2023,"demmiatta",30,5,2004,"male","electrical"
                 ,"Dr:Nahla","500",180,0,0,"sameh@gmail.com","0303314484","012285712482",500000,3);
    }


   

    int main() {
        struct Student s[6][1];
        addData(s);
        printf("five students added \n \n");


        setStudentData(s[5]);


        for(int i =0 ; i<6 ;i++)
           printStudent(s[i]);
        
        printf("\nenter department to show their students orderd by GPA \n");
        char d [20];
        scanf("%s",d);
        sortDepartmetStudentByGPA(s,6,d);
        return 0 ;
    }

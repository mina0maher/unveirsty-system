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
    void setTutorName(struct Student s[],char n[]){
        strcpy(s[0].tutor.name,n);
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
        if(s[0].discount>0){
            s[0].fees=((fees*(s[0].discount))/100);
        }else{
            s[0].fees = fees;
        }
    }
    void setDiscount(struct Student s[],double discount){
        s[0].discount=discount;
        if(s[0].fees>0){
             s[0].fees=((s[0].fees*s[0].discount)/100.0);
        }
    }
    char * getFirstName(struct Student s){
        char *str =s.studentName.firstName;
        return str ;
    }
    char * getMiddleName(struct Student s){
        char *str =s.studentName.middleName;
        return str ;
    }
    char * getLastName(struct Student s){
        char *str =s.studentName.lastName;
        return str;
    }
    
    char * getNationality(struct Student s){
       char *str =s.nationality ;
       return str;
    }

    char * getTypeOfId(struct Student s){
        char *str = s.studentID.typeOfId;
         return str;
    }
    char * getIdNumber(struct Student s){
       char *str = s.studentID.idNumber;
        return str;
    }
    int getExpiryDay(struct Student s){
        return (s.studentID.expiryDate.day);
    }
    int getExpiryMonth(struct Student s){
        return (s.studentID.expiryDate.month);
    }
    int getExpiryYear(struct Student s){
        return (s.studentID.expiryDate.year);
    }
    char * getHomeAddres(struct Student s){
        char *str = s.homeAddress;
        return str;
    }
    int getBirthDay(struct Student s){
        return s.studentAge.dateOfBirth.day;
    }
    int getBirthMonth(struct Student s){
        return s.studentAge.dateOfBirth.month;
    }
    int getBirthYear(struct Student s){
        return s.studentAge.dateOfBirth.year;
    }
    int getAge(struct Student s){
        return s.studentAge.age;
    }
    char * getGender(struct Student s){
        char *str = s.gender;
         return str;
    }
    char * getDepartment(struct Student s){
        char *str = s.department;
         return str;
    }
    char * getTutorName(struct Student s){
        char *str = (s.tutor.name);
         return str;
    }
    char * getTutorCode(struct Student s){
        char *str = s.tutor.code;
         return str;
    }
    int getTotalCreditHours(struct Student s){
        return s.creditHours.totalHours;
    }
    int getFinishedCreditHours(struct Student s){
        return s.creditHours.finishedHours;
    }
    int getCurrentTerm(struct Student s){
        return (s.creditHours.currentTerm);
    }
    double getGPA(struct Student s){
        return s.GPA;
    }
    char * getEmail(struct Student s){
       char *str = (s.contact.email);
        return str;
    }
    char * getHomePhone(struct Student s){
        char *str = s.contact.homePhone;
         return str;
    }
    char * getMobile(struct Student s){
        char *str = s.contact.studentMobile;
         return str;
    }
    double getFees(struct Student s){
        return s.fees;
    }
    double getDiscount(struct Student s){
        return s.discount;
    }
    //todo : add fees & discount in set student data 

    void setStudentData(struct Student s[]){
        printf("enter Student First name: \n");
        char fName[30];
        fgets(fName, 30, stdin);
        printf("enter Student middle name: \n");
        char mName[30];
        fgets(mName, 30, stdin);
        printf("enter Student last name: \n");
        char lName[30];
        fgets(lName, 30, stdin);
        setStudentFirstName(s,fName);
        setStudentMiddleName(s,mName);
        setStudenLastName(s,lName);
        printf("enter Student Nationality: \n");
        char nationality[30];
        fgets(nationality, 30, stdin);
        setNationality(s,nationality);
        printf("\nenter Student ID data \n what is your Id type :\n");
        char type[30];
        fgets(type, 30, stdin);
        printf("\nenter your id number :\n");
        char idNumber[30];
        fgets(idNumber, 30, stdin);
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
            if(!(year <= (tm.tm_year+1900) && year >= 1980)){
                printf("please enter a valid year\n");
            }
        } while(!(year <= (tm.tm_year+1900) && year >= 1980));
        setStudentIdTypeOfId(s,type);
        setStudentIdIdNumber(s,idNumber);
        setStudentIdExpiryDate(s,day,month,year);
        char address[200];
        printf("enter student Home Address :\n(with out spaces)\n");
        scanf("%s",&address);
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
        fgets(department, 30, stdin);
        setDepartment(s,department);
        printf("enter student Tutor Name :\n");
        char tutorname[50];
        fgets(tutorname, 50, stdin);
        printf("enter student Tutor Code :\n");
        char tutorCode[10];
        fgets(tutorCode, 10, stdin);
        setTutorName(s,tutorname);
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
            int gpa;
            scanf("%d",&gpa);
            setGPA(s,gpa);
        }else{
            setGPA(s,0);
        }
        printf("contact information \n enter your mail : \n");
        char mail[100];
        scanf("%s",mail);
        printf("enter your home phone :\n");
        char homePhone[15];
        fgets(homePhone, 15, stdin);
        printf("enter your phone number :\n");
        char phone[20];
        fgets(phone, 20, stdin);

        setContactEmail(s,mail);
        setContactHomePhone(s,homePhone);
        setContactStudentMobile(s,phone);

        printf("enter the fees requested : \n");
        double fees;
        scanf("%lf",&fees);
        setFees(s,fees);
        printf("there is any discount ? \n enter :\n y for yes \n n for no\n");
        char yes ;
        scanf("%c",&yes);
        if(yes == 'y'){
            printf("enter discount in precentage : \n");
            double disc;
            scanf("%lf",&disc);
            setDiscount(s,disc);
        }
        printf("student added \n thank you !");
    }
    void printStudent(struct Student s){
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
        printf("\n---------------Gender----------------\n");
        printf(" %s",getGender(s));
        printf("\n--------------Department--------------\n");
        printf(" %s",getGender(s));
        printf("\n----------------Tutor-----------------\n");
        printf("name : %s",getTutorName(s));
        printf("code : %s",getTutorCode(s));
        printf("\n-------------Credit hours-------------\n");
        printf("Total : %d \n",getTotalCreditHours(s));
        printf("Finished : %d \n",getFinishedCreditHours(s));
        printf("Current Term : %d \n",getCurrentTerm(s));
        printf("\n---------------Contacts--------------\n");
        printf("E-mail : %s \n",getEmail(s));
        printf("Home Phone : %s \n",getHomePhone(s));
        printf("Student Mobile : %s ",getMobile(s));
        printf("\n---------------------------------------\n");
        
    } 

    int getStudentsNumberInDept(struct Student s[],int n ,char dept[]){
        int k = 0;
        for(int i = 0 ; i<n;i++){
            if(strcmp(s[i].department,dept)==0){
                k++;
            }
        }
        return k;
    }
     void sortDesc(struct Student list[], int s){
        int i, j;
        struct Student temp;
        
        for (i = 0; i < s - 1; i++)
        {
            for (j = 0; j < (s - 1-i); j++)
            {
                if (list[j].GPA < list[j + 1].GPA)
                {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                } 
            }
        }
    }
    // void swap(struct Student *A, struct Student *B){
    // struct Student temp = *A;
    // *A = *B;
    // *B = temp;
    // }
    void sortDepartmetStudentByGPA(struct Student s[],int n,char dept[]){
        int num = getStudentsNumberInDept(s,n,dept);
        struct Student arr[num];
        int k = 0 ;
        for(int i = 0 ; i<n;i++){
            if(strcmp(s[i].department,dept)==0){
                struct Student std ;
                // setStudentName(std,getFirstName(s[i]),getMiddleName(s[i]),getLastName(s[i]));
                // setNationality(std,getNationality(s[i]));
                //todo:set the rest of std attributes
                arr[k] = std;
                k++;
            }
        }
        sortDesc(arr,num+1);
        for(int i = 0 ;i<=num;i++){
            printStudent(arr[i]);
        }
    }


   

    int main() {
        struct Student s[1];
        setStudentData(s);
        printStudent(s[0]);
        return 0 ;
    }
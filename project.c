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
    };

    void setStudentFirstName(struct Student s,char firstName[]){
        strcpy(s.studentName.firstName,firstName);
    }

    void setStudentMiddleName(struct Student s,char middleName[]){
        strcpy(s.studentName.middleName,middleName);
    }

    void setStudenLastName(struct Student s,char lastName[]){
        strcpy(s.studentName.lastName,lastName);
    }

    void setStudentName(struct Student s,char firstName[],char middleName[],char lastName[]){
        setStudentFirstName(s,firstName);
        setStudentMiddleName(s,middleName);
        setStudenLastName(s,lastName);
    }
    
    void setNationality(struct Student s,char nationality[]){
        strcpy(s.nationality,nationality);
    }

    void setStudentIdTypeOfId(struct Student s,char type[]){
        strcpy(s.studentID.typeOfId,type);
    }
    void setStudentIdIdNumber(struct Student s,char number[]){
        strcpy(s.studentID.idNumber,number);
    }
    void setStudentIdExpiryDate(struct Student s,int d,int m,int y){
        setDay(s.studentID.expiryDate,d);
        setMonth(s.studentID.expiryDate,m);
        setYear(s.studentID.expiryDate,y);
    }
    void setStudentId(struct Student s,char type[],char number[],int d,int m,int y){
        setStudentIdTypeOfId(s,type);
        setStudentIdIdNumber(s,number);
        setStudentIdExpiryDate(s,d,m,y);
    }
    void setHomeAddress(struct Student s, char homeAddress[]){
        strcpy(s.homeAddress,homeAddress);
    }
    void setStudentAge(struct Student s,int d,int m,int y){
        setDay(s.studentAge.dateOfBirth,d);
        setMonth(s.studentAge.dateOfBirth,m);
        setYear(s.studentAge.dateOfBirth,y);
        //set student age automatically
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s.studentAge.age = tm.tm_year - y;
    }
    void setGender(struct Student s,char g[]){
        strcpy(s.gender,g);
    }
    void setDepartment(struct Student s,char d[]){
        strcpy(s.department,d);
    }
    void setTutorName(struct Student s,char n[]){
        strcpy(s.tutor.name,n);
    }
    void setTutorCode(struct Student s,char c[]){
        strcpy(s.tutor.code,c);
    }
    void setTutor(struct Student s,char name[],char code[]){
        setTutorName(s,name);
        setTutorCode(s,code);
    }
    void setCreditHours(struct Student s,int total,int finished){
        s.creditHours.totalHours = total ;
        s.creditHours.finishedHours = finished;
        s.creditHours.currentTerm = ceil(finished/18);
    }
    void updateCreditHours(struct Student s,int finished){
        s.creditHours.finishedHours = finished;
        s.creditHours.currentTerm = ceil(finished/18);
    }
    void setContactEmail(struct Student s,char email[]){
        strcpy(s.contact.email , email);
    }
    void setContactHomePhone(struct Student s,char homePhone[]){
        strcpy(s.contact.homePhone , homePhone);
    }
    void setContactStudentMobile(struct Student s,char studentmobile[]){
        strcpy( s.contact.studentMobile,studentmobile);
    }
    void setContact(struct Student s,char email[],char homePhone[],char studentmobile[]){
        setContactEmail(s,email);
        setContactHomePhone(s,homePhone);
        setContactStudentMobile(s,studentmobile);
    }
    void setGPA(struct Student s,double GPA){
        s.GPA=GPA;
    }
    void updateCourseGPA(struct Student s,double courseGPA,int courseHours){
        int finishedCoursesWithoutEditedCourse=s.creditHours.finishedHours-courseHours;
        s.GPA = (((s.GPA*finishedCoursesWithoutEditedCourse)+(courseGPA*courseHours))/s.creditHours.finishedHours);
    }
    void addCourse(struct Student s,int courseHours){
        s.creditHours.finishedHours=s.creditHours.finishedHours+courseHours;
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
        return s.studentID.expiryDate.day;
    }
    int getExpiryMonth(struct Student s){
        return s.studentID.expiryDate.month;
    }
    int getExpiryYear(struct Student s){
        return s.studentID.expiryDate.month;
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
        char *str = s.tutor.name;
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
        return s.creditHours.currentTerm;
    }
    double getGPA(struct Student s){
        return s.GPA;
    }
    char * getEmail(struct Student s){
       char *str = s.contact.email;
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
    

    void setStudentData(struct Student s){
        printf("enter Student First name: \n");
        char fName[30];
        gets(fName);
        printf("enter Student middle name: \n");
        char mName[30];
        gets(mName);
        printf("enter Student last name: \n");
        char lName[30];
        gets(lName);
        setStudentName(s,fName,mName,lName);
        printf("enter Student Nationality: \n");
        char nationality[30];
        gets(nationality);
        setNationality(s,nationality);
        printf("enter Student ID data \n what is your Id type :\n");
        char type[30];
        gets(type);
        printf("enter your id number :\n");
        char idNumber[30];
        gets(idNumber);
        printf("enter expiry date day :\n");
        int day;

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
            if(!(day <= tm.tm_year && day >= 1980)){
                printf("please enter a valid year\n");
            }
        } while(!(day <= tm.tm_year && day >= 1980));
        setStudentId(s,type,idNumber,day,month,year);
        printf("enter student Home Address :\n");
        char address[200];
        gets(address);
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
            if(!(day <= tm.tm_year && Birthyear >= 1980)){
                printf("please enter a valid year\n");
            }
        } while(!(day <= tm.tm_year && Birthyear >= 1980));

        setStudentAge(s,Birthday,BirthMonth,Birthyear);
        printf("enter student gender :\n");
        char gender[30];
        gets(gender);
        setGender(s,gender);
        printf("enter student department :\n");
        char department[30];
        gets(department);
        setDepartment(s,department);
        printf("enter student Tutor Name :\n");
        char tutorname[30];
        gets(tutorname);
        printf("enter student Tutor Code :\n");
        char tutorCode[30];
        gets(tutorCode);
        setTutor(s,tutorname,tutorCode);
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
        gets(mail);
        printf("enter your home phone :\n");
        char homePhone[15];
        gets(homePhone);
        printf("enter your phone number :\n");
        char phone[20];
        gets(phone);
        setContact(s,mail,homePhone,phone);
    }
    void printStudent(struct Student s){
        printf("-------------Student Name-------------\n");
        printf(" %s %s %s\n",getFirstName(s),getMiddleName(s),getLastName(s));
        printf("-------------Nationality-------------\n");
        printf(" %s \n",getNationality(s));
        printf("-----------------ID------------------\n");
        printf("type of Id : %s\n",getTypeOfId(s));
        printf("ID number : %s\n",getIdNumber(s));
        printf("expiry date : %d / %d / %d \n",getExpiryDay(s),getExpiryMonth(s),getExpiryYear(s));
        printf("------------Home Address-------------\n");
        printf(" %s",getHomeAddres(s));
        printf("--------------BirthDate--------------\n");
        printf(" %d / %d / %d",getBirthDay(s),getBirthMonth(s),getBirthYear(s));
        printf("---------------Gender----------------\n");
        printf(" %s",getGender(s));
        printf("--------------Department--------------\n");
        printf(" %s",getGender(s));
        printf("----------------Tutor-----------------\n");
        printf("name : %s",getTutorName(s));
        printf("code : %s",getTutorCode(s));
        printf("-------------Credit hours-------------\n");
        printf("Total : %d",getTotalCreditHours(s));
        printf("Finished : %d",getFinishedCreditHours(s));
        printf("Current Term : %d",getCurrentTerm(s));
        printf("---------------Contacts--------------\n");
        printf("E-mail : %s",getEmail(s));
        printf("Home Phone : %s",getHomePhone(s));
        printf("Student Mobile : %s",getMobile(s));
        printf("---------------------------------------");
        
    } 

    
    int main() {
        printf("hello world");
    }
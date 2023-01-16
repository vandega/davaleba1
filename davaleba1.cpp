#include <iostream>
using namespace std;

class abstract_lecturer{
    protected:
        string F_name;
        string L_name;
        string Lecture;
    
    public:
        abstract_lecturer(string F_name, string L_name, string Lecture){
            this -> F_name = F_name;
            this -> L_name = L_name;
            this -> Lecture = Lecture;
        }
    
    //get / set
    string getF_name(){
        return F_name;
    }
    
    void setF_name(string F_name){
        this -> F_name = F_name;
    }
    
    string getL_name(){
        return L_name;
    }
    
    void setL_name(string L_name){
        this -> L_name = L_name;
    }
    
    string getLecture(){
        return Lecture;
    }
    
    void setLecture(string Lecture){
        this -> Lecture = Lecture;
    }
    
    virtual void Lecture_teaching () = 0;
    
};

class Skillwill_lecture: public abstract_lecturer{
    protected:
        string Level;
        string Chapter;
        
    public:
        Skillwill_lecture(string F_name, string L_name, string Lecture, string Chapter, string Level):abstract_lecturer(F_name, L_name, Lecture)
        {
            this -> Level = Level;
            this -> Chapter = Chapter;
        }
    void Lecture_teaching(){
        cout << F_name << " " << L_name << " is on " << Lecture << " lection" << endl;
    }
};

class abstract_student{
    protected:
        string First_name;
        string Last_name;
        int Age;
        string Subject;
        
    public:
        abstract_student(string First_name, string Last_name, int Age, string Subject){
            this -> First_name = First_name;
            this -> Last_name = Last_name;
            this -> Age = Age;
            this -> Subject = Subject;
        }
        
    virtual void Student_On_lection() = 0;
    
    // get / set 
    string getFirst_name(){
        return First_name;
    }
    
    void setFirst_name(string First_name){
        this -> First_name = First_name;
    }
    
    string getLast_name(){
        return Last_name;
    }
    
    void setLast_name(string Last_name){
        this -> Last_name = Last_name;
    }
    
    int getAge(){
        return Age;
    }
    
    void setAge(int Age){
        this -> Age = Age;
    }
    
    string getSubject(){
        return Subject;
    }
    
    void setSubject(string Subject){
        this -> Subject = Subject;
    }
};

class skillwill_Student:public abstract_student{
    protected:
        string Section;
        string Course; 
        int Quiz;
    
    public:
        skillwill_Student(string First_name, string Last_name, int Age, string Subject, string Section, string Course, int Quiz):abstract_student(First_name, Last_name, Age, Subject){
            this -> Section = Section;
            this -> Course = Course;
            this -> Quiz = Quiz;
        }
    
    void Student_On_lection(){
        cout << First_name << " " << Last_name << " from " << Section << " section is on " << Course << " lesson: status online" << endl;
    }
    
    
    int getQuiz(){
        return Quiz;
    }
    void updateQuiz(int newQuiz){
        Quiz += newQuiz;
    }
    
    void Totalscore(){
        cout << getFirst_name() << " " << getLast_name() << " Quiz final score is: " << getQuiz() << endl;
    }
    
};

class abstract_Subject{
    protected:
        string Subject_name;
        string Start_data;
        int Duration;
        
    public:
        abstract_Subject(string Subject_name, string Start_data, int Duration){
            this -> Subject_name = Subject_name;
            this -> Start_data = Start_data;
            this -> Duration = Duration;
        }
        
        string getSubject_name(){
            return Subject_name;
        }
        
        void setSubject_name(string Subject_name){
            this -> Subject_name = Subject_name;
        }
        
        string getStart_data(){
            return Start_data;
        }
        
        void setStart_data(string Start_data){
            this -> Start_data = Start_data;
        }
        
        int getDuration(){
            return Duration;
        }
        
        void setDuration(int Duration){
            this -> Duration = Duration;
        }
        
        virtual void first_lecture_name() = 0;
};

class skillwill_Subject: public abstract_Subject{
    protected:
        string Last_lecture_Title;
        
    public:
        skillwill_Subject(string Last_lecture_Title):abstract_Subject(Subject_name, Start_data, Duration){
            this -> Last_lecture_Title = Last_lecture_Title;
        }
        
        
        void first_lecture_name(){
            cout << "greeting: " << Last_lecture_Title << endl;
        }
        
};



int main()
{
    //7 variables (string First_name, string Last_name, int Age, string Subject, string Section, string Course, int Quiz)
    skillwill_Student student1("joni", "sturua", 25, "back_end", "A", "IT", 1000);
    skillwill_Student student2("name", "lastname", 99, "front_end", "B", "IT", 123);
    
    student1.Student_On_lection();
    
    Skillwill_lecture lecturer1("Jane", "Smith", "Programming", "Chapter 1", "senior");
    
    student1.updateQuiz(85);
    student1.updateQuiz(100);
    student1.Totalscore();
    student2.updateQuiz(3000);
    student2.Totalscore();
    
    return 0;
}



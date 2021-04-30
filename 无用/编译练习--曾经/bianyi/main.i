# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.cpp"
# 1 "student.h" 1
class Student {
public:
    const char *name;
    int age;
    float score;
    void say();
    void leineilian(){
        int a = 0;
        return;
    }:
};

inline int neilianhanshu();
# 2 "main.cpp" 2
int main() {
    Student *pStu = new Student;
    pStu->name = "小明";
    pStu->age = 15;
    pStu->score = 92.5f;
    pStu->say();
    delete pStu;
    return 0;
}

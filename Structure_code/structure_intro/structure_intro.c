// structure is a user defines data type

#include<stdio.h>
#include <string.h>

struct A
{
    int x;
};

struct Student
{
    char name[50];
    int age;
    float grade;
};

// typedef 
typedef struct Students {
    char name[50];
    char branch[50];
    int ID_no;
} stu;



// Child structure declaration
struct child {
    int x;
    char c;
};

// Parent structure declaration
struct parent {
    int a;
    struct child b;
};


//A union is a user-defined data type that allows storing different data types in the same memory location. 
//At any given time, only one member can hold a valid value because all members share the same memory.

union std {
    int rollNo;
    float height;
    char firstLetter;
};


//An enumeration (enum) is a user-defined data type that assigns meaningful names to a set of integer constants.
//By default, the first enum constant has the value 0, and each subsequent constant is incremented by 1.

enum direction {
    EAST, NORTH, WEST, SOUTH
};


// Function to increment values  (b is a pointer to A)
void increment(struct A a, struct A* b) {
    a.x++;
  	b->x++;
}

int main(){
struct A a;
// (.) is used to access a member in the structure
a.x =11;
printf("%d\n",a.x);

// Declaring and initializing a structure variable
struct Student s1 = {"Rahul", 20, 18.5};

// Designated Initializing another structure (a diffrent way)
struct Student s2 = {.age = 18, .name = "Vikas", .grade = 22};

printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.grade);
printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.grade);

// copy a structure 

struct Student s1c= s1;
printf("%s\t%d\t%.2f\n", s1c.name, s1c.age, s1c.grade);

// pass structure to function 

struct A b  = { 10 };
  
// Passing a by value and b by pointer
increment(a, &b);  
printf("a.x: %d \tb.x: %d", a.x, b.x);


// Type def a structure
// it is used to make a new name alias for exixting data type
// global declaration
stu s;
    strcpy(s.name , "Geeks");
    strcpy(s.branch, "CSE");
    s.ID_no = 108;

    printf("%s\n", s.name);
    printf("%s\n", s.branch);
    printf("%d", s.ID_no);

// Nested structure 
struct parent p = { 25, 195, 'A' };

    // Accessing and printing nested members
    printf("p.a = %d\n", p.a);
    printf("p.b.x = %d\n", p.b.x);
    printf("p.b.c = %c", p.b.c);


// union
union std data;
data.rollNo = 21;
printf("%d\n", data.rollNo);
data.height = 5.2;
printf("%.2f\n", data.height);
data.firstLetter = 'N';
printf("%c", data.firstLetter);

// enum
enum direction dir = NORTH;
printf("%d\n", dir);
// This is valid too
dir = 3;
printf("%d", dir);
return 0;
}

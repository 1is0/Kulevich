using System;

namespace Lab5
{   
    class Student : Human
    {
        public string Specialty { get; set; }
        public enum Courses
        {
            first = 1,
            second,
            third,
            fourth
        }
        public Courses Course { get; set; }

        
        public Student(string name, string surname, int age, string specialty) : base(name, surname, age)
        {
            Course = Courses.first;
            Specialty = specialty;
        }

        public Student() : base()
        {
            Course = Courses.second;
            Specialty = "Informatics";
        }

        public override string ToString()
        {
            return base.ToString() + "\n Course: " + Course + ";" + "\n Specialty: " + Specialty + ";";
        }
    }

    public struct Marks
    {
        public int Math { get; set; }
        public int Programming { get; set; }
        public int Logics { get; set; }
        
    }
}

using System;
using System.Collections;

namespace Lab8
{
    class Student : Human, IComparable, ICloneable, IStudent
    {
        public string GroupNumber { get; set; }
        public string Specialty { get; set; }
        public Courses Course { get; set; }
        public Level CountLevel()
        {
            int avMark = (int)AvMark();
            switch (avMark)
            {
                case 10:
                case 9:
                    return Level.Ultra;
                case 8:
                case 7:
                    return Level.High;
                case 6:
                case 5:
                case 4:
                    return Level.Mid;
                default:
                    return Level.Low;
            }
        }
        delegate int Mark(int x, int y, int z);
        public float AvMark()
        {
            Mark marks = (x, y, z) => x + y + z;
            int sum = marks(studentMarks.logics, studentMarks.math, studentMarks.programming);
            if (sum == 0)
                throw new Exception("There are no marks");
            return (float)sum / 3;
        }

        public int CompareTo(object obj)
        {
            if (this.Programming > ((Student)obj).Programming)
            {
                return 1;
            }
            if (this.Programming < ((Student)obj).Programming)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        public object Clone()
        {
            return (Student)this.MemberwiseClone();
        }

        public Marks studentMarks;

        public int Math
        {
            get { return studentMarks.math; }
            protected set { studentMarks.math = value; }
        }

        public int Programming
        {
            get { return studentMarks.programming; }
            protected set { studentMarks.programming = value; }
        }

        public int Logics
        {
            get { return studentMarks.logics; }
            protected set { studentMarks.logics = value; }
        }
        public bool Equals(Student other)
        {
            if (other != null && this.Course == other.Course)
                return true;
            else
                return false;
        }

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
            DoMyEvent();
            return base.ToString() + "\n Course: " + Course + ";" + "\n Specialty: " + Specialty + ";";
        }

        public delegate void Output(Student student);

        public event Output MyEvent;

        protected virtual void DoMyEvent()
        {
            if (MyEvent != null)
                MyEvent(this);
        }
    }
    struct Marks
    {
        public int math;
        public int programming;
        public int logics;
    }
    public enum Courses
    {
        first = 1,
        second,
        third,
        fourth
    }
    enum Level { Low, Mid, High, Ultra }
}

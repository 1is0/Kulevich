using System;
using System.Collections;

namespace Lab6
{
    class Informatics : Student
    {


        public Informatics() : base()
        {
            GroupNumber = "953502";
            studentMarks.math = 9;
            studentMarks.programming = 9;
            studentMarks.logics = 9;
        }


        public Informatics(string name, string surname, int age, int math, int programming, int logics) : base(name, surname, age, "Informatics")
        {
            GroupNumber = "953502";
            studentMarks.math = math;
            studentMarks.programming = programming;
            studentMarks.logics = logics;
        }

        public override string ToString()
        {
            return base.ToString() + " Group: " + GroupNumber + ";\n " + "Marks: \n " + "Math - " + studentMarks.math + ";\n" + " Programming - " + studentMarks.programming + ";\n" + " Logics - " + studentMarks.logics + ";\n";
        }
    }
}

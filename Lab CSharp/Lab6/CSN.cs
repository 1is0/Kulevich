using System;
using System.Collections;

namespace Lab6
{
    class CSN : Student
    {

        public CSN() : base()
        {
            GroupNumber = "950501";
            studentMarks.math = 9;
            studentMarks.programming = 9;
            studentMarks.logics = 9;
        }


        public CSN(string name, string surname, int age, int math, int programming, int logics) : base(name, surname, age, "Computing Systems and Networks")
        {
            GroupNumber = "950501";
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

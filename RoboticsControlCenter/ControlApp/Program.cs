using System;
using System.IO.Ports;

namespace ControlApp
{
    class Program
    {
        static void Main(string[] args)
        {
            SerialPort serial = new SerialPort("com8", 9600);
            serial.Open();

            for (;;)
            {
                string input = Console.ReadLine();

                if (input == "q")
                {
                    break;
                }

                byte value = (byte)Convert.ToInt16(input);
                byte[] data = new byte[] { value };
                serial.Write(data, 0, 1);
            }

            serial.Close();
        }
    }
}

using System;

namespace FuzzSQL
{
    class Program
    {
        static void Main(string[] args)
        {
            string url = args[0];
            int index = url.IndexOf('?');
            string[] par = url.Remove(0, index + 1).Split("&");

            foreach (string p in par) {
                string xssUrl = url.Replace(p, p+"fd<xss>sa");
                string sqlUrl = url.Replace(p, p + "fd'sa");
                Console.WriteLine(xssUrl);
                Console.WriteLine(sqlUrl);
            }
        }
    }
}

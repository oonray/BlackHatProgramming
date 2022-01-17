using System;

namespace ch1_hello_world {
    public static void main(string[] args){
        string hello = "Hello Wordl";
        DateTime now = DateTime.Now;
        Console.Write(hello);
        Conosle.WriteLine(" The time is "+now.ToLongDateString());
    }
}

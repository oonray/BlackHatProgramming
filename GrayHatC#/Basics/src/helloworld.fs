open System;

let greeting name =
    Console.WriteLine("Hello "+name+"!")

[<EntryPoint>]
let main argv =
    greeting "Alex"

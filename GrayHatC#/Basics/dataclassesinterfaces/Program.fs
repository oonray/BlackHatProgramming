// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp

open System

type IPerson =
    abstract member Name: string
    abstract member Age: int

type FireFighter(name,age) =
    interface IPerson with
        member this.Name = name
        member this.Age = age


[<EntryPoint>]
let main argv =
    let message = from "F#" // Call the function
    printfn "Hello world %s" message
    0 // return an integer exit code

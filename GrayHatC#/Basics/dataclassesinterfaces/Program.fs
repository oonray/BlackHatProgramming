open System

type Person =
    abstract name:string
    abstract age:int

type PublicServant =
    abstract salary: int
    abstract work: unit

type FireMan(name,age,salary) =
    interface Person with
        member this.name = name
        member this.age = age
    interface PublicServant with
        member this.salary = salary
        member this.work =
            printfn "%s is driving to The fire!" (this:>Person).name


[<EntryPoint>]
let main argv =
    let fire: FireMan = new FireMan("John Smith",45,1500)
    printfn "Hello %s" (fire:> Person).name
    (fire:> PublicServant).work
    0

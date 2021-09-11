open System
open System.Runtime.InteropServices

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
            scanf "%s is driving to The fire!" (this:>Person).name

module usr32 =
    [<DllImport("user32")>]
    extern int MessageBox(IntPtr hWnd,String text,String Caption,int option)

[<EntryPoint>]
let main argv =
    let fire: FireMan = new FireMan("John Smith",45,1500)
    usr32.MessageBox(IntPtr.Zero,(fire:>PublicServant).work,(fire:>Person).name,0) |> ignore
    0

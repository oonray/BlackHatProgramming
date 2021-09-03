using System;
using System.Runtime.InteropServices;

namespace Main{
	class MainClass {
		[Dllimport("user32",CharSet=CharSet.Autp)]
		static extern int MessageBox(IntPtr hWnd, String text, String caption, int options);

		[Dllimport("libc")]
		static extern void printf(string message);

		static void Main(string []args){
				OperatingSystem os = Environment.OSVersion;
				if(os.Platform == PlatformID.Win32Windows || os.Platform == PlatformID.Win32NT){
							MessageBox(IntPtr.Zero,"Hello World!",0);
				}else{
					printf("Hello World!");
				}
		}
	}

}

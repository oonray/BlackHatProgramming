using System;

namespace Interfaces{
	public interface IPerson {
		string Name {get; set;}
		int 	 Age 	{get; set;}
	}
}

namespace Classes{
	public abstract class PublicServant{ 
		public int PensionAmount {get; set;}
		public delegate void DriveToPlaceOfInterestDelegate(); 
		public DriveToPlaceOfInterestDelegate DriveToPlaceOfInterest{get;set;}
	}

	public class Firefigther : PublicServant, Interfaces.IPerson {
			public string Name {get; set;}
			public int 	 Age 	{get; set;}
			
			public Firefigther(string name,int age){
				this.Age = age;
				this.Name = name;
				this.DriveToPlaceOfInterest += delegate{
						Console.WriteLine("Driving the firetruck");
						GetInFireTruck();
						TurnOnSiren();
						FollowDirections();
				};
			}

			private void	GetInFireTruck(){}
			private void	TurnOnSiren(){}
			private void	FollowDirections(){}
	}

	public class PoliceOfficer : PublicServant, Interfaces.IPerson {
		public string Name {get; set;}
		public int 	 Age 	{get; set;}

		private bool _hasEmergancy;

		public PoliceOfficer(string name, int age,bool HasEmergancy = false){
			this.Name			= name;
			this.Age			= age;
			_hasEmergancy = HasEmergancy;
			if(this.HasEmergancy){
				this.DriveToPlaceOfInterest += delegate {
						Console.WriteLine("Driveing the police car with a siren");
						GetInPoliceCar();
						TurnOnSiren();
					};
				}
				else {
					this.DriveToPlaceOfInterest = delegate {
						Console.WriteLine("Driveing the police car");
						GetInPoliceCar();
						FollowDirections();
					};
				}
			}
		

		public bool HasEmergancy{
			get { return _hasEmergancy;  }
			set { _hasEmergancy = value; }
		}

		private void	GetInPoliceCar(){}
		private void	TurnOnSiren(){}
		private void	FollowDirections(){}
	}
}




namespace Main{
	class MainClass{
		public static void Main(string[] args){
			Classes.Firefigther firefigther = new Classes.Firefigther("Joe Carrington",35);	
			Classes.PoliceOfficer policeofficer = new Classes.PoliceOfficer("Jane Hope",32);
			Classes.PoliceOfficer policeofficer2 = new Classes.PoliceOfficer("Jane Valir",32,true);

			PrintNameAndAge(firefigther);
			firefigther.PensionAmount = 5000;
			PrintPensionAmount(firefigther);
			firefigther.DriveToPlaceOfInterest();
			Console.WriteLine();

			PrintNameAndAge(policeofficer);
			policeofficer.PensionAmount = 5500;
			PrintPensionAmount(policeofficer);
			policeofficer.DriveToPlaceOfInterest();
			Console.WriteLine();

			PrintNameAndAge(policeofficer2);
			policeofficer2.PensionAmount = 5500;
			PrintPensionAmount(policeofficer2);
			policeofficer2.DriveToPlaceOfInterest();
			Console.WriteLine();
		}

		static void PrintNameAndAge(Interfaces.IPerson person){
				Console.WriteLine("Name: "+person.Name);
				Console.WriteLine("Age: "+person.Age);
		}

		static void PrintPensionAmount(Classes.PublicServant servant){
			if(servant is Classes.Firefigther){
				Console.WriteLine("Pension of firefigther: "+servant.PensionAmount);
			}else if(servant is Classes.PoliceOfficer){
					Console.WriteLine("Penison of Police officer:"+servant.PensionAmount);
			}
		}
	}


}

A local speedway has asked you to calculate the sound levels of several cars at differing speeds. They have assembled a data file with the following structure for a test set of 6 vehicles

  struct noiseLevel
	{
		short	vehicleNo;
		short	noise[7];
	};
	
This program should:

Read the data file into a two-way array

Calculate the average for each vehicle

Calculate the average for each speed

Print the information on the screen in a format similar to the example following

Car	10 MPH	20 MPH	30 MPH	40 MPH	50 MPH	60 MPH	70 MPH	Car Avg
1099	60	70	80	90	100	110	120	87.1
1350	65	70	75	80	85	90	95	80.0
1298	xx	xx	xx	xx	xx	xx	xx	xx.x
and so on....
Spd Avg	62.5	70	77.5	85	92.5	xx.x	xx.x	xx.x

Programmatically, determine and print which vehicle is the quietest overall

Programmatically, determine and print which speed is the quietest overall

# DayZ-Road-Hazard-Sign-Template
A simple and clean template for creating custom static signs for your DayZ server or mod.

I have designed this in a way that allows you to pack these files as a mod(RoadHazardSign). Then you will unzip the YellowSignTemplate PSD and create your custom texture(s) and assign them via your Server Mod Pack config. This saves you the headache of having to open the p3d and point to all the many variations of the sign. 

Your Server Pack config would look similar to this:
```
class CfgPatches
{
	class MyServerPack
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		// This line tells the game it MUST load your core mod first.
		requiredAddons[]={"RoadHazardSign"}; 
	};
};

class CfgVehicles
{
	// First, it tells the game it knows about your base class.
	class RoadHazardSign_Base; 

	// Now, it creates a NEW sign by inheriting from your base class.
	class MyAwesomeSign1 : RoadHazardSign_Base
	{
		scope = 2; // scope = 2 makes this one visible in-game.
		displayName = "My Awesome Custom Sign #1";
		
		// It only overrides the texture. All other properties are inherited.
		hiddenSelectionsTextures[] = 
		{
			"MyServerPack\data\textures\my_cool_texture1.paa" 
		};
	};
 	class MyAwesomeSign2 : RoadHazardSign_Base
	{
		scope = 2; // scope = 2 makes this one visible in-game.
		displayName = "My Awesome Custom Sign #2";
		
		// It only overrides the texture. All other properties are inherited.
		hiddenSelectionsTextures[] = 
		{
			"MyServerPack\data\textures\my_cool_texture2.paa" 
		};
	};
};
```


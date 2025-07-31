class CfgPatches
{
	class RoadHazardSign_Core // This name is important for the dependency.
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;

	class RoadHazardSign_Base : HouseNoDestruct
	{
		scope = 1; // scope = 1 makes this a hidden template.
		model = "RoadHazardSign\data\roadhazard_sign.p3d";
		hiddenSelections[] = { "sign_base" };
		hiddenSelectionsTextures[] = { "RoadHazardSign\data\textures\signbase_co.paa" };
	};
};
/*
 * Rewards Server Configs and Settings
 *
 * Made by Andrew_S90
 */

class CfgPatches
{
	class rewards_server
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"exile_client",
			"exile_assets",
			"exile_server"
		};
		units[]={};
		weapons[]={};
		magazines[]={};
		ammo[]={};
	};
};
class CfgFunctions
{
	class rewards_server
	{
		class Bootstrap
		{
			file="rewards_server\bootstrap";
			class preInit
			{
				preInit=1;
			};
			class postInit
			{
				postInit=1;
			};
		};
	};
};

class CfgRewards
{
	class Logging
	{
		//If this is one it will use extDB to log to a file when someone claims an item
		rewardsLogging = 1;
	};
	
	class AllowedUIDS
	{
		//If this is 1 it will check for a valid input/caller - either a UID from an admin or mission or event
		checkRewards = 1;
		/**
		 ** Paste Admin UIDs in here to allow them to give rewards to players
		 ** 
		 ** NOTHING IN THE FOLLOWING ARRAY CAN BE EQUAL TO 8 CHARACTERS!!!!!!
		 **/
		AllowedRewardGivers[] = 
		{
			"12341234123412340", //admin uid 1
			"dms_mission", //name for server usage
			"event",
			"mission"
		};
	};
	
	//Examples of kits that can be customizable
	class RewardKits
	{
		BaseObjectsWood[] =
		{
			"Exile_Item_Flag",
			"Exile_Melee_Axe",
			{"Exile_Item_Codelock",2},
			{"Exile_Item_SafeKit",2},
			"Exile_Item_WorkBenchKit",
			{"Exile_Item_WoodDoorKit",5},
			{"Exile_Item_WoodFloorKit",5},
			{"Exile_Item_WoodWallKit",5}
		};
			
		BaseObjectsConcrete[] =
		{
			"Exile_Item_Flag",
			{"Exile_Item_Codelock",2},
			"Exile_Item_ConcreteFloorPortKit",
			{"Exile_Item_SafeKit",2},
			"Exile_Item_WorkBenchKit",
			{"Exile_Item_ConcreteDoorKit",5},
			"Exile_Item_ConcreteGateKit",
			{"Exile_Item_ConcreteFloorKit",5},
			{"Exile_Item_ConcreteWallKit",5}
		};
		
		CurrencyKit[] =
		{
			{"ExileScore",2000},
			{"ExileMoney",2000}
		};
		
		VehicleKit[] =
		{
			{"Exile_Car_Lada_Green",2},
			{"B_MRAP_01_F",1},
			{"Exile_Chopper_Huey_Green",1}
		};
	};
};
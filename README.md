# ExilePlayerRewards
Player Rewards Script
Exile Player Rewards

This is a system that allows admins to add rewards for players to go claim at any locker.

This system in no way will auto generate rewards for your players for doing missions, logging in, donating, playing, gaining respect or anything like that. You are free to use it to do any of those things but out of the box it just accepts rewards and items and allows the player to claim them.



https://www.youtube.com/watch?v=Cb9XOe8NcMA



As I explained in the above video

You need a players UID and an array of items to pass to the server to add items. It will also take the players UID and the name of a kit which is exactly like infistar spawn boxes, the format is almost 1:1 so you could copy paste them over.

It takes and will give players poptabs, respect, items, weapons, backpacks, uniforms, vests and vehicles. It will also allow you to set quantities for these items and the players can create their own pin# for the claimed vehicles.



Here is an example I used to test via admin menu to add items to my own character.

["addRewardsRequest", [getplayeruid player, [["ExileScore",1000],["ExileMoney",2000],"Exile_Item_Flag","Exile_Item_SafeKit",["Exile_Car_Lada_Green",3],"Exile_Chopper_Huey_Green"]]] call ExileClient_system_network_send;

["addKitRequest", [getplayeruid player, "BaseObjectsWood"]] call ExileClient_system_network_send;

The first one allows any array of items and set quantities to be based the other will take a predefined kit that is located server side for customization.

If any items are already in the players collection box it will stack items so that the space is controlled on the database.



There are some settings that can be changed in the config.cpp server side, right off the bat you will need to add your UID to the "AllowedRewardGivers" array or it will deny adding items from players from your UID. This security check for admins can be turned off if you want, its there to not allow people or names not in the list to not be able to give rewards to themselves or other players.

All these settings can be found in rewards_server\config.cpp



This uses EXTDB2, you can update for EXTDB3 if you wish.



Installation 

Download the files from here: https://github.com/Andrew-S90/ExilePlayerRewards/
Client: Place "custom" folder inside of your root Exile.Altis folder
Client: Modify your class CfgNetworkMessages and paste the following (also available via github in the config.cpp file)



	class claimItemRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"STRING"
		};
	};
	class claimItemResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"SCALAR",
			"STRING",
			"ARRAY"
		};
	};
	class claimVehicleRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class claimVehicleResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"ARRAY"
		};
	};
	class claimTabsRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class claimTabsResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"SCALAR",
			"ARRAY"
		};
	};
	class hasRewardsRequest
	{
		module="system_rewards";
		parameters[]={};
	};
	class hasRewardsResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"ARRAY"
		};
	};
	class addRewardsRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class addKitRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};






Client: In your init.sqf please paste the following (also available via github in the init.sqf file)
Spoiler

{
    _x params [['_function',''],['_file','']];
    _code = compileFinal (preprocessFileLineNumbers _file);
    missionNamespace setVariable [_function,_code];
} 
forEach
[
   ['ExileClient_gui_rewardsDialog_event_onClaimButtonClick','custom\rewards\ExileClient_gui_rewardsDialog_event_onClaimButtonClick.sqf'],
   ['ExileClient_gui_rewardsDialog_event_onClaimVehicle','custom\rewards\ExileClient_gui_rewardsDialog_event_onClaimVehicle.sqf'],
   ['ExileClient_gui_rewardsDialog_event_onClaimVehicleButtonClick','custom\rewards\ExileClient_gui_rewardsDialog_event_onClaimVehicleButtonClick.sqf'],
   ['ExileClient_gui_rewardsDialog_event_onDropDownSelectionChanged','custom\rewards\ExileClient_gui_rewardsDialog_event_onDropDownSelectionChanged.sqf'],
   ['ExileClient_gui_rewardsDialog_event_onInputBoxChars','custom\rewards\ExileClient_gui_rewardsDialog_event_onInputBoxChars.sqf'],
   ['ExileClient_gui_rewardsDialog_event_onListBoxSelectionChanged','custom\rewards\ExileClient_gui_rewardsDialog_event_onListBoxSelectionChanged.sqf'],
   ['ExileClient_gui_rewardsDialog_show','custom\rewards\ExileClient_gui_rewardsDialog_show.sqf'],
   ['ExileClient_gui_rewardsDialog_updateListBox','custom\rewards\ExileClient_gui_rewardsDialog_updateListBox.sqf'],
   ['ExileClient_gui_rewardsDialog_updateSelection','custom\rewards\ExileClient_gui_rewardsDialog_updateSelection.sqf'],
   ['ExileClient_system_rewards_network_claimItemResponse','custom\rewards\ExileClient_system_rewards_network_claimItemResponse.sqf'],
   ['ExileClient_system_rewards_network_claimTabsResponse','custom\rewards\ExileClient_system_rewards_network_claimTabsResponse.sqf'],
   ['ExileClient_system_rewards_network_claimVehicleResponse','custom\rewards\ExileClient_system_rewards_network_claimVehicleResponse.sqf'],
   ['ExileClient_system_rewards_network_hasRewardsResponse','custom\rewards\ExileClient_system_rewards_network_hasRewardsResponse.sqf']
];


_position = worldSize/2;
_center = [_position,_position,0];

_lockers = nearestObjects [_center, ["Exile_Locker"], worldSize];

{
	_x addAction ["<t color='#FF0000'>Rewards</t>", {[] call ExileClient_gui_rewardsDialog_show;},"",-4,true ,true ,"","true",3];
} forEach _lockers;








Server: Open the rewards_server folder and open config.cpp and then either add your desired admin UIDs to the "AllowedRewardsGivers" array OR change checkRewards to a 0 this is a security function which will check if a legit sender is trying to reward your players.
Server: In config.cpp feel free to change logging to a 0 if you do not want extdb2 logs to be created. As well you can add any custom kits, I have included some examples for you.
Server: Run the following rewards.sql on your database to add a rewards table for your players (also available via github in Server\database_additions folder in the rewards.sql file)


CREATE TABLE IF NOT EXISTS `rewards` (
  `uid` varchar(32) NOT NULL,
  `rewards_player` varchar(1024) NOT NULL DEFAULT '[]',
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;





Server: Paste the following additions to your exile.ini file at the bottom (also available via github in Server\database_additions in the exile_additions.ini file)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;	PLAYER REWARDS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[hasRewardsPlayer]
SQL1_1 = SELECT CASE WHEN EXISTS(SELECT uid FROM rewards WHERE uid = ?) THEN 'true' ELSE 'false' END
Number of Inputs = 1
SQL1_INPUTS = 1
OUTPUT = 1

[loadRewards]
SQL1_1 = SELECT rewards_player FROM rewards WHERE uid = ?
Number Of Inputs = 1
SQL1_INPUTS = 1
OUTPUT = 1

[createRewards]
SQL1_1 = INSERT INTO rewards SET uid = ?, rewards_player = ?
Number Of Inputs = 2
SQL1_INPUTS = 1,2

[setPlayerRewards]
SQL1_1 = UPDATE rewards SET rewards_player = ? WHERE uid = ?
Number of Inputs = 2
SQL1_INPUTS = 1,2 








Example code snippets to call files to add items to players.



ExileServer_system_rewards_network_addKitRequest Example calls

From infistar to player ["addKitRequest", ["UID_OF_PLAYER_TARGET", "BaseObjectsWood"]] call ExileClient_system_network_send;

From server mission(i.e dms) to server ["dms_mission", ["UID_OF_PLAYER_TARGET", "BaseObjectsWood"]] call ExileServer_system_rewards_network_addRewardsRequest;

ExileServer_system_rewards_network_addRewardsRequest Example calls

From infistar to player ["addRewardsRequest", ["UID_OF_PLAYER_TARGET", [["ExileScore",1000],["ExileMoney",2000],"Exile_Item_Flag","Exile_Item_SafeKit"]]] call ExileClient_system_network_send;

From server mission(i.e dms) to server ["dms_mission", ["UID_OF_PLAYER_TARGET", [["ExileScore",1000],["ExileMoney",2000],"Exile_Item_Flag","Exile_Item_SafeKit"]]] call ExileServer_system_rewards_network_addRewardsRequest;


ExileServer_system_rewards_updatePlayer Example usage
Example Usage: - This is only used to update the player that they have new rewards - if you add to their rewards via DB you could call this with their UID
It would then notify and update their client rewards.
From server to server "UID OF PLAYER" call ExileServer_system_rewards_updatePlayer;
The last function could be called from a DLL when someone joins your website or someone has rewards added manually via db - could be called via MARMA etc. Mainly just to notify and update players if they are online.





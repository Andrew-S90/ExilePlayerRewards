waitUntil {!isNull (findDisplay 46)};

/* ~~ Rewards Claim Vendor by Andrew_S90 Script Start ~~ */
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

/* ~~ Rewards Claim Vendor by Andrew_S90 Script End ~~ */
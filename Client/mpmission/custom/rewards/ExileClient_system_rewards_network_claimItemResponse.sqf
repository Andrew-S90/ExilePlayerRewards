/*
 * ExileClient_system_rewards_network_claimItemResponse
 *
 * Rewards Client - Made by Andrew_S90
 *
 * Derived from ExileMod Code
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private ["_responseCode", "_itemClassName", "_containerType", "_containerNetID", "_containersBefore", "_vehicle", "_dialog", "_listBox"];
_responseCode = _this select 0;
_itemClassName = _this select 1;
_containerType = _this select 2;
_containerNetID = _this select 3;
ExileClientPlayerRewards = _this select 4;

ExileClientIsWaitingForServerTradeResponse = false;
if (_responseCode isEqualTo 0) then
{
	switch (_containerType) do
	{
		case 1:
		{
			_containersBefore = [uniform player, vest player, backpack player];
			[player, _itemClassName] call ExileClient_util_playerCargo_add;
		};
		case 2:
		{
			_vehicle = objectFromNetId _containerNetID;
			[_vehicle, _itemClassName] call ExileClient_util_containerCargo_add;
		};
	};
	["SuccessTitleAndText", ["Item claimed!", "Your reward has been successfully claimed"]] call ExileClient_gui_toaster_addTemplateToast;
	
	_dialog = uiNameSpace getVariable ["RscExileRewardsDialog", displayNull];
	if !(_dialog isEqualTo displayNull) then
	{
		call ExileClient_gui_rewardsDialog_updateListBox;
		call ExileClient_gui_rewardsDialog_updateSelection;
		_listBox = _dialog displayCtrl 2003;
		[_listBox, lbCurSel _listBox] call ExileClient_gui_rewardsDialog_event_onListBoxSelectionChanged;
	};
}
else 
{
	["ErrorTitleAndText", ["Whoops!", format ["Something went really wrong. Please tell a server admin that you have tried to claim an item and tell them the code '%1'. Thank you!", _responseCode]]] call ExileClient_gui_toaster_addTemplateToast;
};
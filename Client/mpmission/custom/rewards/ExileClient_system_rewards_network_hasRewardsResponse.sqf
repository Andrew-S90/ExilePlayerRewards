/*
 * ExileClient_system_rewards_network_hasRewardsResponse
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
 
private ["_responseCode", "_rewardsData", "_dialog", "_listBox"];
_responseCode = _this select 0;
_rewardsData = _this select 1;


ExileClientIsWaitingForServerTradeResponse = false;
if (_responseCode isEqualTo 0) then
{

	ExileClientPlayerRewards = _rewardsData;
	if(count ExileClientPlayerRewards != 0) then {
		["SuccessTitleAndText", ["Rewards Added!", "You have new rewards to claim!"]] call ExileClient_gui_toaster_addTemplateToast;
	};
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
	["ErrorTitleAndText", ["Whoops!", format ["Something went really wrong. Please tell a server admin that you got updated rewards and tell them the code '%1'. Thank you!", _responseCode]]] call ExileClient_gui_toaster_addTemplateToast;
};
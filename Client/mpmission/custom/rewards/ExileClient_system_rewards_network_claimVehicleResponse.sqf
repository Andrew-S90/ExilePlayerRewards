/*
 * ExileClient_system_rewards_network_claimVehicleResponse
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
 
private ["_responseCode", "_vehicleNetID", "_vehicleObject"];
_responseCode = _this select 0;
_vehicleNetID = _this select 1;
ExileClientPlayerRewards = _this select 2;
if (_responseCode isEqualTo 0) then
{
	_vehicleObject = objectFromNetId _vehicleNetID;
	player moveInDriver _vehicleObject;
	["SuccessTitleAndText", ["Vehicle claimed!", "Your reward has been successfully claimed"]] call ExileClient_gui_toaster_addTemplateToast;
}
else 
{
	["ErrorTitleAndText", ["Whoops!", format ["Something went really wrong. Please tell a server admin that you have tried to claim a vehicle and tell them the code '%1'. Thank you!", _responseCode]]] call ExileClient_gui_toaster_addTemplateToast;
};
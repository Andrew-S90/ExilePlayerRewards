/*
 * ExileServer_system_rewards_updatePlayer
 *
 * Rewards Server - Made by Andrew_S90
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
 
//Example Usage: - This is only used to update the player that they have new rewards - if you add to their rewards via DB you could call this with their UID
//It would then notify and update their client rewards.
// From server to player "UID OF PLAYER" call ExileServer_system_rewards_updatePlayer;

 
private ["_playerUID", "_targetPlayerObject", "_targetSessionID", "_rewardsData", "_hasRewardsPlayer", "_targetUID", "_responseCode", "_bad"];
_playerUID = _this select 0;

try 
{	
	_targetPlayerObject = _playerUID call ExileClient_util_player_objectFromPlayerUID;
	_targetSessionID = _targetPlayerObject getVariable ["ExileSessionID", -1];
	
	_rewardsData = [];
	_hasRewardsPlayer = format["hasRewardsPlayer:%1", _targetUID] call ExileServer_system_database_query_selectSingleField;
	
	if(_hasRewardsPlayer) then {
		_rewardsData = format["loadRewards:%1", _targetUID] call ExileServer_system_database_query_selectSingle;
		_rewardsData = (_rewardsData select 0);
		_targetPlayerObject setVariable ["ExileClientPlayerRewards", _rewardsData];
	} else {
		format["createRewards:%1:%2", _targetUID, []] call ExileServer_system_database_query_insertSingle;
		_targetPlayerObject setVariable ["ExileClientPlayerRewards", _rewardsData];
	};
	
	[_targetSessionID, "hasRewardsResponse", [0,_rewardsData]] call ExileServer_system_network_send_to;
}
catch
{
	_responseCode = _exception;
	[_bad, "hasRewardsResponse", [_responseCode, []]] call ExileServer_system_network_send_to;
};
true
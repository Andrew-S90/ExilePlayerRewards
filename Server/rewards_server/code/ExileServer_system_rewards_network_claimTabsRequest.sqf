/*
 * ExileServer_system_rewards_network_claimTabsRequest
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
 
private ["_sessionID", "_parameters", "_itemClassName", "_amount", "_playerObject", "_rewardsData", "_index", "_playerUID", "_playerRespect", "_playerMoney", "_logging", "_rewardsLogging", "_traderLog", "_responseCode"];
_sessionID = _this select 0;
_parameters = _this select 1;
_itemClassName = _parameters select 0;
_amount = _parameters select 1;

try 
{
	_playerObject = _sessionID call ExileServer_system_session_getPlayerObject;
	if (_playerObject getVariable ["ExileMutex",false]) then
	{
		throw 12;
	};
	_playerObject setVariable ["ExileMutex",true];
	if (isNull _playerObject) then
	{
		throw 1;
	};
	if !(alive _playerObject) then
	{
		throw 2;
	};
	
	_rewardsData = _playerObject getVariable ["ExileClientPlayerRewards", []];
	
	_index = [_rewardsData,_itemClassName] call ExileServer_util_searchArray;
	
	if(_index == -1) then {
		throw 3;
	};
	
	_rewardsData deleteAt _index;
	_playerObject setVariable ["ExileClientPlayerRewards", _rewardsData];
	_playerUID = _playerObject getVariable ["ExileOwnerUID", -1];
	format["setPlayerRewards:%1:%2", _rewardsData, _playerUID] call ExileServer_system_database_query_fireAndForget;
	
	if(_itemClassName == "ExileScore") then {
		_playerRespect = _playerObject getVariable ["ExileScore", 0];
		_playerRespect = _playerRespect + _amount;
		_playerObject setVariable ["ExileScore", _playerRespect];
		format["setAccountScore:%1:%2", _playerRespect, (getPlayerUID _playerObject)] call ExileServer_system_database_query_fireAndForget;
	} else {
		_playerMoney = _playerObject getVariable ["ExileMoney", 0];
		_playerMoney = _playerMoney + _amount;
		_playerObject setVariable ["ExileMoney", _playerMoney, true];
		format["setPlayerMoney:%1:%2", _playerMoney, _playerObject getVariable ["ExileDatabaseID", 0]] call ExileServer_system_database_query_fireAndForget;
	};
		
		
	
	[_sessionID, "claimTabsResponse", [0, _itemClassName, _amount,_rewardsData]] call ExileServer_system_network_send_to;
	
	_logging = getNumber(configFile >> "CfgSettings" >> "Logging" >> "traderLogging");
	_rewardsLogging = getNumber(configFile >> "CfgRewards" >> "Logging" >> "rewardsLogging");
	if (_logging isEqualTo 1 || _rewardsLogging  isEqualTo 1) then
	{
		_traderLog = format ["PLAYER: ( %1 ) %2 CLAIMED %3 FROM CLAIM VENDOR",getPlayerUID _playerObject,_playerObject,_itemClassName];
		"extDB2" callExtension format["1:TRADING:%1",_traderLog];
	};
	_playerObject call ExileServer_object_player_database_update;
}
catch 
{
	_responseCode = _exception;
	[_sessionID, "claimTabsResponse", [_responseCode, "", 0,_rewardsData]] call ExileServer_system_network_send_to;
};	
_playerObject setVariable ["ExileMutex",false];
true
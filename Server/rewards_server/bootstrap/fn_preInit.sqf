/*
 * Rewards Server preInit
 *
 * Made by Andrew_S90
 */
 
private ['_code', '_function', '_file', '_fileContent'];

{
    _code = '';
    _function = _x select 0;
    _file = _x select 1;

    _fileContent = preprocessFileLineNumbers _file;

    _code = compileFinal _fileContent;                    

    missionNamespace setVariable [_function, _code];
}
forEach 
[
	['ExileServer_system_rewards_network_addKitRequest', 'rewards_server\code\ExileServer_system_rewards_network_addKitRequest.sqf'],
	['ExileServer_system_rewards_network_addRewardsRequest', 'rewards_server\code\ExileServer_system_rewards_network_addRewardsRequest.sqf'],
	['ExileServer_system_rewards_network_claimItemRequest', 'rewards_server\code\ExileServer_system_rewards_network_claimItemRequest.sqf'],
	['ExileServer_system_rewards_network_claimTabsRequest', 'rewards_server\code\ExileServer_system_rewards_network_claimTabsRequest.sqf'],
	['ExileServer_system_rewards_network_claimVehicleRequest', 'rewards_server\code\ExileServer_system_rewards_network_claimVehicleRequest.sqf'],
	['ExileServer_system_rewards_network_hasRewardsRequest','rewards_server\code\ExileServer_system_rewards_network_hasRewardsRequest.sqf'],
	['ExileServer_system_rewards_updatePlayer', 'rewards_server\code\ExileServer_system_rewards_updatePlayer.sqf'],
	['ExileServer_util_searchArray','rewards_server\code\ExileServer_util_searchArray.sqf']
];

diag_log "REWARDS SERVER - Loaded.";

true
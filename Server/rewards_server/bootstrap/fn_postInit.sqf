/*
 * Rewards Server postInit Spammer
 *
 * Made by Andrew_S90
 */

_check = getNumber(configFile >> "CfgRewards" >> "AllowedUIDS" >> "checkRewards");

if(_check isEqualTo 1) then {
	_allowedRewardGivers = getArray(configFile >> "CfgRewards" >> "AllowedUIDS" >> "AllowedRewardGivers");
	_bad = false;
	{
		if(count _x == 8) exitWith {
			_bad = true;
		};
	} forEach _allowedRewardGivers;
	
	if(_bad) then {
		for "_i" from 0 to 100 do {
			diag_log "REWARDS SERVER - ERROR IN ENTERED CFGREWARDS - NOTHING IN AllowedRewardGivers ARRAY CAN BE 8 CHARACTERS LONG!!!!!!!!!";
		};
	};
};

true
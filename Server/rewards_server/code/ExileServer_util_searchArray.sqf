/*
 * ExileServer_util_searchArray
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
 
private ["_data", "_classname", "_index", "_i"];
 
_data = (_this select 0);
_classname = (_this select 1); 
_index = -1;

for "_i" from 0 to (count _data - 1) do {
	if ( ((_data select _i) select 0) isEqualTo _classname) exitWith {
		_index = _i;
	};
};
_index
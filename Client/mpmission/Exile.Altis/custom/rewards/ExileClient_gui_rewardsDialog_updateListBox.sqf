/*
 * ExileClient_gui_rewardsDialog_updateListBox
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
 
private ["_dialog", "_rewardsListBox", "_claim", "_dropdown", "_itemClassName", "_itemQuantity", "_indexEntryIndex", "_configName", "_qualityColor", "_popTabColor", "_imageColor"]; 
disableSerialization;
_dialog = uiNameSpace getVariable ["RscExileRewardsDialog", displayNull];

_rewardsListBox = _dialog displayCtrl 2003;
_claim = _dialog displayCtrl 2004;
_dropdown = _dialog displayCtrl 2005;

lbClear _rewardsListBox;

if(!isNil "ExileClientPlayerRewards") then {
	if(count ExileClientPlayerRewards != 0) then {
		{
			_itemClassName = (_x select 0);
			_itemQuantity = (_x select 1);
			_indexEntryIndex = 1;
		
		
			switch (_itemClassName) do
			{
				case "ExileScore": { 
					_indexEntryIndex = _rewardsListBox lbAdd "Respect";
					_rewardsListBox lbSetPicture [_indexEntryIndex, "exile_assets\texture\ui\fail_ca.paa"]; 
				};
				case "ExileMoney": { 
					_indexEntryIndex = _rewardsListBox lbAdd "Poptabs";
					_rewardsListBox lbSetPicture [_indexEntryIndex, "exile_assets\texture\ui\poptab_ca.paa"];
				};
				default {
					_configName = _itemClassName call ExileClient_util_gear_getConfigNameByClassName;
					_indexEntryIndex = _rewardsListBox lbAdd getText(configFile >> _configName >> _itemClassName >> "displayName");
					_rewardsListBox lbSetPicture [_indexEntryIndex, getText(configFile >> _configName >> _itemClassName >> "picture")];
				};
			};
						
			_qualityColor = [1, 1, 1, 1];
			_popTabColor = [1, 1, 1, 1];
			_imageColor = [1, 1, 1, 1];
						
			_rewardsListBox lbSetData [_indexEntryIndex, _itemClassName];
			_rewardsListBox lbSetColor [_indexEntryIndex, _qualityColor];
						
			_rewardsListBox lbSetPictureColor [_indexEntryIndex, _imageColor];
			_rewardsListBox lbSetTextRight [_indexEntryIndex, format["%1", _itemQuantity]];
			_rewardsListBox lbSetColorRight [_indexEntryIndex, _popTabColor];
			_rewardsListBox lbSetPictureRightColor [_indexEntryIndex, _popTabColor];



		} forEach ExileClientPlayerRewards;
		
		_dropdown ctrlEnable true;
		_claim ctrlEnable true;
		_dropdown ctrlCommit 0;
		_claim ctrlCommit 0;
	} else {
		_dropdown ctrlEnable false;
		_claim ctrlEnable false;
		_dropdown ctrlCommit 0;
		_claim ctrlCommit 0;
	};
} else {
	_dropdown ctrlEnable false;
	_claim ctrlEnable false;
	_dropdown ctrlCommit 0;
	_claim ctrlCommit 0;
};
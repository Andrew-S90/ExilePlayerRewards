/*
 * rewardsDialog.hpp
 *
 * Made by Andrew_S90
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

class RscExileRewardsDialog
{
	idd = 57347;
	onLoad="uiNamespace setVariable ['RscExileRewardsDialog', _this select 0]";
	onUnload="call ExileClient_gui_traderDialog_event_onUnload; uiNamespace setVariable ['RscExileRewardsDialog', displayNull]";
	
	class ControlsBackground
	{
		class BackgroundImage
		{
			type = 0;
			idc = 2000;
			x="14 * (0.025) + (0)";
			y="1 * (0.04) + (0)";
			w="17.5 * (0.025)";
			h="24 * (0.04)";
			colorBackground[]={0.050000001,0.050000001,0.050000001,0.69999999};
			style = 0;
			text = "";
			colorText[] = {0.3176,0.3294,0.4745,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		
		class DialogCaptionMain: BackgroundImage
		{
			idc=2001;
			text="Rewards Vendor";
			x="14 * (0.025) + (0)";
			y="-0.1 * (0.04) + (0)";
			w="17.5 * (0.025)";
			h="1 * (0.04)";
			colorBackground[]={0.1,0.1,0.1,1};
			colorText[] = {1.0,1.0,1.0,1};
		};
		
		class DialogCaptionCode: DialogCaptionMain
		{
			idc=3000;
			text="Pin Code";
			x="7 * (0.025) + (0)";
			y="19.9 * (0.04) + (0)";
			w="5.5 * (0.025)";
			h="1 * (0.04)";
		};
		class BackgroundImageCode: BackgroundImage
		{
			idc=3001;
			x="7 * (0.025) + (0)";
			y="21 * (0.04) + (0)";
			w="5.5 * (0.025)";
			h="4 * (0.04)";
		};
	};
	class Controls
	{
		class closebtn
		{
			type = 1;
			idc = 2002;
			shadow=2;
			tooltipColorText[]={1,1,1,1};
			tooltipColorBox[]={1,1,1,1};
			tooltipColorShade[]={0,0,0,0.64999998};
			x = safeZoneX + safeZoneW * 0.601;
			y = safeZoneY + safeZoneH * 0.2275;
			w = safeZoneW * 0.02125;
			h = safeZoneH * 0.01333334;
			action="closeDialog 0;";
			style=2096;
			color[]={1,1,1,0.69999999};
			colorText[]={1,1,1,0.69999999};
			colorActive[]={1,1,1,1};
			tooltip="Close";
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
			borderSize = 0;
			colorBackground[] = {0.5098,0.0353,0.6667,0};
			colorBackgroundActive[] = {1,0,0,0};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,0};
			colorFocused[] = {0.2,0.2,0.2,0};
			colorShadow[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.0;
			offsetPressedY = 0.0;
			offsetX = 0.0;
			offsetY = 0.0;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		
		class RewardsListBox
		{
			idc=2003;
			font="RobotoCondensed";
			colorSelect[]={0,0,0,1};
			colorPictureRightSelected[]={1,1,1,1};
			soundSelect[]=
			{
				"\A3\ui_f\data\sound\RscListbox\soundSelect",
				0.090000004,
				1
			};
			class ListScrollBar
			{
				color[]={1,1,1,1};
				autoScrollEnabled=1;
				colorActive[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.30000001};
				thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				shadow=0;
				scrollSpeed=0.059999999;
				width=0;
				height=0;
				autoScrollSpeed=-1;
				autoScrollDelay=5;
				autoScrollRewind=0;
			};
			sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag=0;
			itemSpacing=0.001;
			period=1.2;
			shadow=0;
			maxHistoryDelay=1;
			fade=0;
			deletable=0;
			type=5;
			style=16;
			colorDisabled[]={1,1,1,0.25};
			colorPicture[]={1,1,1,1};
			colorPictureDisabled[]={1,1,1,0.25};
			colorPictureRight[]={1,1,1,1};
			colorPictureRightDisabled[]={1,1,1,0.25};
			colorPictureSelected[]={1,1,1,1};
			colorScrollbar[]={1,0,0,0};
			colorSelect2[]={0,0,0,1};
			colorSelect2Right[]={0,0,0,1};
			colorSelectBackground2[]={1,1,1,0.5};
			colorSelectBackground[]={0.94999999,0.94999999,0.94999999,1};
			colorSelectRight[]={0,0,0,1};
			colorShadow[]={0,0,0,0.5};
			colorText[]={1,1,1,1};
			colorTextRight[]={1,1,1,1};
			disabledCtrlColor[]={1,1,1,0.5};
			itemBackground[]={1,1,1,0.1};
			tooltipColorBox[]={1,1,1,1};
			tooltipColorShade[]={0,0,0,0.64999998};
			tooltipColorText[]={1,1,1,1};
			x="14.5 * (0.025) + (0)";
			y="1.5 * (0.04) + (0)";
			w="16.5 * (0.025)";
			h="20 * (0.04)";
			colorBackground[]={1,1,1,0.1};
			onLBSelChanged="_this call ExileClient_gui_rewardsDialog_event_onListBoxSelectionChanged";
		};
		
		class ClaimButton
		{
			idc=2004;
			text="Claim";
			class HitZone
			{
				left=0;
				top=0;
				right=0;
				bottom=0;
			};
			action="";
			class AttributesImage
			{
				font="RobotoCondensed";
				color="#E5E5E5";
				align="left";
			};
			type=16;
			style="0x02 + 0xC0";
			default=0;
			shadow=0;
			animTextureNormal="#(argb,8,8,3)color(1,1,1,1)";
			animTextureDisabled="#(argb,8,8,3)color(1,1,1,1)";
			animTextureOver="#(argb,8,8,3)color(1,1,1,1)";
			animTextureFocused="#(argb,8,8,3)color(1,1,1,1)";
			animTexturePressed="#(argb,8,8,3)color(1,1,1,1)";
			animTextureDefault="#(argb,8,8,3)color(1,1,1,1)";
			colorBackgroundFocused[]={1,1,1,1};
			colorBackground2[]={0.75,0.75,0.75,1};
			color[]={1,1,1,1};
			colorFocused[]={0,0,0,1};
			color2[]={0,0,0,1};
			colorDisabled[]={1,1,1,0.25};
			textSecondary="";
			colorSecondary[]={1,1,1,1};
			colorFocusedSecondary[]={0,0,0,1};
			color2Secondary[]={0,0,0,1};
			colorDisabledSecondary[]={1,1,1,0.25};
			sizeExSecondary="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			fontSecondary="PuristaLight";
			period=1.2;
			periodFocus=1.2;
			periodOver=1.2;
			size="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			tooltipColorText[]={1,1,1,1};
			tooltipColorBox[]={1,1,1,1};
			tooltipColorShade[]={0,0,0,0.64999998};
			textureNoShortcut="";
			class TextPos
			{
				left="0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
				top="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
				right=0.0049999999;
				bottom=0;
			};
			class Attributes
			{
				font="PuristaLight";
				color="#E5E5E5";
				align="left";
				shadow="false";
			};
			class ShortcutPos
			{
				left="5.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
				top=0;
				w="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
				h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			};
			soundEnter[]=
			{
				"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",
				0.090000004,
				1
			};
			soundPush[]=
			{
				"\A3\ui_f\data\sound\RscButtonMenu\soundPush",
				0.090000004,
				1
			};
			soundClick[]=
			{
				"\A3\ui_f\data\sound\RscButtonMenu\soundClick",
				0.090000004,
				1
			};
			soundEscape[]=
			{
				"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",
				0.090000004,
				1
			};
			x="14.5 * (0.025) + (0)";
			y="23.5 * (0.04) + (0)";
			w="8 * (0.025)";
			h="1 * (0.04)";
			colorText[]={1,1,1,1};
			colorBackground[]={0,0,0,0.80000001};
			onMouseButtonClick="_this call ExileClient_gui_rewardsDialog_event_onClaimButtonClick";
		};
		
		class ClaimBox
		{
			type = 4;
			idc = 2005;
			x = "24.5 * (0.025) + (0)";
			y = "23.5 * (0.04) + (0)";
			w="6.5 * (0.025)";
			h="1 * (0.04)";
			style = 16;
			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\RscCombo\arrow_combo_ca.paa";
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\RscCombo\arrow_combo_active_ca.paa";
			onLBSelChanged="_this call ExileClient_gui_rewardsDialog_event_onDropDownSelectionChanged";
			colorBackground[] = {0.0,0.0,0.0,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {0.627,0.875,0.231,1};
			colorSelectBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			maxHistoryDelay = 0;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1.0};
			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1.0};
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1.0};
			wholeHeight = 0.3;
			class ComboScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
		};
		class LoadBackground
		{
			idc=2006;
			type = 0;
			style = 0;
			shadow=1;
			colorShadow[]={0,0,0,0.5};
			font="RobotoCondensed";
			SizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			colorText[]={1,1,1,1};
			linespacing=1;
			tooltipColorText[]={1,1,1,1};
			tooltipColorBox[]={1,1,1,1};
			tooltipColorShade[]={0,0,0,0.64999998};
			x="14.5 * (0.025) + (0)";
			y="22 * (0.04) + (0)";
			w="16.5 * (0.025)";
			h="1 * (0.04)";
			colorBackground[]={0,0,0,0.5};
			text ="";
		};
		class LoadProgress
		{
			idc=2007;
			type = 8;
			style = 0;
			shadow=2;
			x="14.5 * (0.025) + (0)";
			y="22 * (0.04) + (0)";
			w="16.5 * (0.025)";
			h="1 * (0.04)";
			colorBar[] = {1,1,1,1};
			colorFrame[] = {0,0,0,1};
			texture = "#(argb,8,8,3)color(1,1,1,1)";
			colorText[]={1,1,1,0.25};
			colorBackground[]={1,1,1,0.25};
		};
		class LoadText
		{
			idc=2008;
			type = 13;
			style = 0;
			size="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			shadow=1;
			class Attributes
			{
				font="RobotoCondensed";
				color="#ffffff";
				colorLink="#D09B43";
				align="left";
				shadow=1;
			};
			x="14.5 * (0.025) + (0)";
			y="22 * (0.04) + (0)";
			w="16.5 * (0.025)";
			h="1 * (0.04)";
			colorBackground[]={0,0,0,0};
			colorText[] = {1,0,0,1};
			sizeEx = 0.04;
			font = "PuristaMedium";
			text ="10/10 meme";
		};
		class ClaimButtonCode: ClaimButton
		{
			idc=3002;
			text="Claim";
			x="7.75 * (0.025) + (0)";
			y="23.5 * (0.04) + (0)";
			w="4 * (0.025)";
			h="1 * (0.04)";
			onMouseButtonClick="_this call ExileClient_gui_rewardsDialog_event_onClaimVehicleButtonClick";
		};
		class CodeEdit
		{
			idc=3003;
			style="0x00 + 0x40";
			font="RobotoCondensed";
			shadow=2;
			sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			colorDisabled[]={1,1,1,0.25};
			colorSelection[]=
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
				1
			};
			canModify=1;
			tooltipColorText[]={1,1,1,1};
			tooltipColorBox[]={1,1,1,1};
			tooltipColorShade[]={0,0,0,0.64999998};
			autocomplete="general";
			colorBackground[]={0.05,0.05,0.05,0.7};
			type = 2;
			text = "";
			colorText[] = {1,1,1,1};
			x="7.75 * (0.025) + (0)";
			y="21.5 * (0.04) + (0)";
			w="4 * (0.025)";
			h="1 * (0.04)";
			onChar="_this spawn ExileClient_gui_rewardsDialog_event_onInputBoxChars";
		};
	};
	
};
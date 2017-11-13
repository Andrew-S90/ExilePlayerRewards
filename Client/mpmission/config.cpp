class CfgNetworkMessages
{
	/* ~~ Rewards Claim Vendor by Andrew_S90 CfgNetworkMessages Start ~~ */
	class claimItemRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"STRING"
		};
	};
	class claimItemResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"SCALAR",
			"STRING",
			"ARRAY"
		};
	};
	class claimVehicleRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class claimVehicleResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"ARRAY"
		};
	};
	class claimTabsRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class claimTabsResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"SCALAR",
			"ARRAY"
		};
	};
	class hasRewardsRequest
	{
		module="system_rewards";
		parameters[]={};
	};
	class hasRewardsResponse
	{
		module="system_rewards";
		parameters[]=
		{
			"SCALAR",
			"ARRAY"
		};
	};
	class addRewardsRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class addKitRequest
	{
		module="system_rewards";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	/* ~~ Rewards Claim Vendor by Andrew_S90 CfgNetworkMessages End ~~ */
};
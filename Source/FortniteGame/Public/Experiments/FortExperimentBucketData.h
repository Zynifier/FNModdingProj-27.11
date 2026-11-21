// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExperimentBucketData.generated.h"

UENUM()
enum class EBattlePassExperimentBucketType : uint8
{
	ExistingCrew = 0,
	RedesignBattlePass = 1,
	RedesignCrew = 2,
};

UENUM()
enum class EBattlePassPurchaseScreenExperimentBucketType : uint8
{
	ShowBattlePassPurchaseScreen = 0,
	SkipBattlePassPurchaseScreen = 1,
};

UENUM()
enum class EItemShopExperimentBucketType : uint8
{
	AthenaItemShop = 0,
	MPItemShopWithItemPreview = 1,
	MPItemShopWithoutItemPreview = 2,
};

UENUM()
enum class EMPLobbyExperimentBucketType : uint8
{
	OldLobby = 0,
	MultiproductLobby = 1,
	MultiproductLobbyWithSearch = 2,
};

UENUM()
enum class EReloadMtxExperimentBucketType : uint8
{
	Disabled = 0,
	ReloadMtxIncremental = 1,
	ReloadMtxStatic = 2,
};

UENUM()
enum class ETwoOptionExperimentBucketType : uint8
{
	Option1 = 0,
	Option2 = 1,
};


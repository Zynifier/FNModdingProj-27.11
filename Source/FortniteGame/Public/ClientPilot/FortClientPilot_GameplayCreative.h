// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilot/FortClientPilot_GameplayBase.h"
#include "FortClientPilot_GameplayCreative.generated.h"

UENUM(BlueprintType)
enum class ECreativeBotIslandIterationType : uint8
{
	CBI_NONE = 0,
	CBI_Mnemonics = 1,
	CBI_User = 2,
};

UENUM(BlueprintType)
enum class ECreativeBotIslandLoadingState : uint8
{
	ILS_NONE = 0,
	ILS_LoadNotStarted = 1,
	ILS_GrantPlotItem = 2,
	ILS_WaitingUserPlotReady = 3,
	ILS_LoadInProgress = 4,
	ILS_LoadComplete = 5,
	ILS_Teleporting = 6,
	ILS_Returning = 7,
	ILS_Items = 8,
};

UENUM(BlueprintType)
enum class ECreativeBotItemTestingState : uint8
{
	ITS_NONE = 0,
	ITS_Teleporting = 1,
	ITS_Landing = 2,
	ITS_Grant = 3,
	ITS_Equip = 4,
	ITS_Place = 5,
	ITS_Cleanup = 6,
};

UCLASS()
class UFortClientPilot_GameplayCreative : public UFortClientPilot_GameplayBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void IslandCreationCompleted(bool bSuccess, const FText& Reason);

};


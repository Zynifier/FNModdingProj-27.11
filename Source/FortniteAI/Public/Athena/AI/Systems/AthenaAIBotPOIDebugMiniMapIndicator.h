// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/Systems/FortBotPOI.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "AthenaAIBotPOIDebugMiniMapIndicator.generated.h"

USTRUCT()
struct FBotPOIDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 ID;

	UPROPERTY(Transient)
	bool bEnabled;

	UPROPERTY(Transient)
	FBox Box;

	UPROPERTY(Transient)
	int32 Weight;

	UPROPERTY(Transient)
	EBotPOIType Type;

	UPROPERTY(Transient)
	uint8 Usage;

	UPROPERTY(Transient)
	int32 NavMeshLocationsCount;

	UPROPERTY(Transient)
	bool bIsMainPOI;

	UPROPERTY(Transient)
	FString DebugInfo;

};

USTRUCT()
struct FBotPOIExcludedZonesDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FBox Box;

	UPROPERTY(Transient)
	uint8 UsagesToExclude;

};

UCLASS()
class UAthenaAIBotPOIDebugMiniMapIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	TArray<FBotPOIDebugInfo> BotPOIDebugInfoList;

	UPROPERTY(Replicated)
	TArray<FBotPOIExcludedZonesDebugInfo> BotPOIExcludedZonesDebugInfoList;

	UPROPERTY(Replicated)
	TArray<FVector> ClusteredLootLocationsDebug;

	UPROPERTY(Replicated)
	TArray<FString> ClusteredLootNamesDebug;

	UPROPERTY(Replicated)
	int32 ClusteredLootDrawDebugLevel;

	UPROPERTY(Replicated)
	int32 DynamicPOIDrawDebugLevel;

};


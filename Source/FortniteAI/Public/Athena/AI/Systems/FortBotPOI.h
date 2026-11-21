// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortBotPOI.generated.h"

UENUM()
enum class EBotPOIType : uint8
{
	Unknown = 0,
	ClusterLoot = 1,
	MidMatchObjective = 2,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EBotPOIUsageBitmask : uint8
{
	/** Empty */
	None = 0 UMETA(Hidden),
	/** Can use this POI to Jump from bus */
	BotJumpOffBus = 1,
	/** Can use this POI to Navigate during the game */
	BotNavigation = 2,
};

USTRUCT()
struct FBotPOI
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
	TArray<FVector> NavMeshLocations;

	UPROPERTY(Transient)
	bool bIsMainPOI;

	UPROPERTY(Transient)
	uint8 Usage;

};

USTRUCT()
struct FBotPOIExcludedZone
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FBox Box;

	UPROPERTY(Transient)
	uint8 UsagesToExclude;

};

USTRUCT()
struct FFortBotPOIExcludedZoneDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BotPOI ExcludedZone")
	FVector Location;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BotPOI ExcludedZone")
	FVector BoxHalfSize;

	UPROPERTY(EditDefaultsOnly, Category="BotPOI ExcludedZone", meta=(AllowPrivateAccess="true", BitMask, BitmaskEnum="/Script/FortniteAI.EBotPOIUsageBitmask"))
	uint8 UsagesToExclude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BotPOI ExcludedZone")
	FGameplayTagQuery PlaylistQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BotPOI ExcludedZone")
	FString MapPath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BotPOI ExcludedZone")
	bool bEnabled;

};


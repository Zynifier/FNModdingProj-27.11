// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "Items/FortItemEntry.h"
#include "FortInventorySerializationTypes.generated.h"

class AFortMinigame;
class AFortPlayerControllerAthena;
class APlayerState;
class UFortMinigameStatFilter;

UENUM(BlueprintType)
enum EMinigameStatSavePolicy
{
	Never = 0,
	Always = 1,
	OnlyIfLower = 2,
	OnlyIfHigher = 3,
};

USTRUCT()
struct FFortInventory_CheckpointEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid LevelSpawnableGuid;

	UPROPERTY()
	FDateTime MostRecentUseTime;

};

USTRUCT()
struct FFortInventory_PlayerStatEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortMinigameStatFilter> StatFilter;

	UPROPERTY()
	int32 LastRoundValue;

	UPROPERTY()
	int32 AllExceptLastRoundValue;

};

USTRUCT()
struct FFortInventory_SaveEntryBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	bool bHasBeenStored;

};

USTRUCT()
struct FFortInventory_SaveEntryAttributeBase : public FFortInventory_SaveEntryBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortInventory_MinigameStats : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortInventory_PlayerStatEntry> PlayerStatsList;

};

USTRUCT()
struct FFortInventory_SaveEntryCheckpoints : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortInventory_CheckpointEntry> CheckpointsList;

};

USTRUCT()
struct FFortInventory_SaveEntryFloat : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Value;

};

USTRUCT()
struct FFortInventory_SaveEntryItemStacked
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortItemEntry ItemEntry;

	UPROPERTY()
	TArray<int32> StacksPerInstance;

};

USTRUCT()
struct FFortInventory_SaveEntryItems : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortItemEntry> FortItemEntries;

	UPROPERTY()
	TArray<FFortInventory_SaveEntryItemStacked> StackedItems;

};

USTRUCT()
struct FFortInventory_SaveEntryTransform : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector LocationValue;

	UPROPERTY()
	FQuat RotationValue;

};

USTRUCT()
struct FFortInventory_SaveEntryUint8 : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 Value;

};

USTRUCT()
struct FFortInventory_SaveEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime MostRecentUseTime;

	UPROPERTY()
	FFortInventory_SaveEntryFloat Health;

	UPROPERTY()
	FFortInventory_SaveEntryFloat Shield;

	UPROPERTY()
	FFortInventory_SaveEntryUint8 ClassSlot;

	UPROPERTY()
	FFortInventory_SaveEntryUint8 TeamIndex;

	UPROPERTY()
	FFortInventory_SaveEntryItems Items;

	UPROPERTY()
	FFortInventory_SaveEntryItems Resources;

	UPROPERTY()
	FFortInventory_SaveEntryItems Gold;

	UPROPERTY()
	FFortInventory_SaveEntryCheckpoints Checkpoints;

	UPROPERTY()
	FFortInventory_SaveEntryTransform PlayerTransform;

	UPROPERTY()
	FFortInventory_MinigameStats MinigameStats;

};

USTRUCT()
struct FFortInventory_SaveEntryInt32 : public FFortInventory_SaveEntryAttributeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Value;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortInventory_SavePolicyForStat
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SavePolicyForStat")
	TObjectPtr<UFortMinigameStatFilter> Stat;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SavePolicyForStat")
	TEnumAsByte<EMinigameStatSavePolicy> Policy;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SavePolicyForStat")
	int32 Count;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortInventory_SaveEntrySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeHealthAndShield;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeClassSlot;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeTeamIndex;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	TArray<FFortInventory_SavePolicyForStat> MinigameScoreStats;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeInventory;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeFullAmmoMagazine;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeResources;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeGold;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludeCheckpoints;

	UPROPERTY(BlueprintReadWrite, Category="FortInventory_SaveEntrySettings")
	int32 bIncludePlayerLocation;

};

USTRUCT()
struct FPendingToApplyData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerControllerAthena> PlayerController;

	UPROPERTY(Transient)
	TWeakObjectPtr<APlayerState> PlayerState;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortMinigame> Minigame;

	UPROPERTY(Transient)
	FFortInventory_SaveEntry SaveEntry;

};


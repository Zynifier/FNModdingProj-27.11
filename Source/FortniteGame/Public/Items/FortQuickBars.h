// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "FortClientOnlyActor.h"
#include "Items/FortItemTypeEnum.h"
#include "FortQuickBars.generated.h"

class UFortItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;

UENUM(BlueprintType, meta=(ScriptName="FortQuickBarType"))
enum class EFortQuickBars : uint8
{
	Primary = 0,
	Secondary = 1,
	Creative = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

USTRUCT()
struct FQuickBarSlotData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FQuickBarSlot")
	TArray<EFortItemType> AcceptedItemTypes;

	UPROPERTY(EditDefaultsOnly, Category="QuickBarSlotData")
	FGameplayTagQuery AcceptedItemTagQuery;

	UPROPERTY(EditAnywhere, Category="FQuickBarSlot")
	bool bStaticSlot;

	UPROPERTY(EditAnywhere, Category="FQuickBarSlot")
	TSoftObjectPtr<UFortWorldItemDefinition> DefaultItem;

};

USTRUCT()
struct FQuickBarData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FQuickBarData")
	TArray<FQuickBarSlotData> QuickbarSlots;

};

USTRUCT()
struct FQuickBarSlot
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FGuid> Items;

	UPROPERTY(Transient, NotReplicated)
	uint8 bEnabled : 1;

	UPROPERTY(Transient, NotReplicated)
	uint8 bIsDirty : 1;

	UPROPERTY(Transient, NotReplicated)
	uint8 bIsReserved : 1;

	UPROPERTY(Transient, NotReplicated)
	uint8 bIsOccupied : 1;

	UPROPERTY(Transient, NotReplicated)
	int32 UsedBySlotIndex;

	UPROPERTY(Transient, NotReplicated)
	FGuid UsedByItemGuid;

};

USTRUCT()
struct FQuickBar
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	int32 CurrentFocusedSlot;

	UPROPERTY(Transient, NotReplicated)
	int32 PreviousFocusedSlot;

	UPROPERTY(Transient, NotReplicated)
	int32 SecondaryFocusedSlot;

private:
	UPROPERTY()
	TArray<FQuickBarSlot> Slots;

	UPROPERTY(Transient, NotReplicated)
	FQuickBarData DataDefinition;

	UPROPERTY(Transient, NotReplicated)
	TSet<TObjectPtr<UFortItemDefinition>> EquippedItemDefinitions;

	UPROPERTY(Transient, NotReplicated)
	TArray<int32> SharedVisibleSlotIndicesWhenUsingGamepad;

};

USTRUCT()
struct FQuickBarAndSlot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortQuickBars QuickBarType;

	UPROPERTY()
	int32 QuickBarSlot;

};

USTRUCT()
struct FQuickBarEquippedItemGuids
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGuid EquippedItemGuids[10];

	UPROPERTY()
	int32 NumEnabledSlots;

};

UCLASS(MinimalAPI)
class AFortQuickBars : public AFortClientOnlyActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FQuickBar PrimaryQuickBar;

	UPROPERTY()
	FQuickBar SecondaryQuickBar;

	UPROPERTY()
	FQuickBar CreativeQuickBar;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItem>> AllCachedTraps;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItem>> CachedFloorTraps;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItem>> CachedWallTraps;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWorldItem>> CachedCeilingTraps;

};


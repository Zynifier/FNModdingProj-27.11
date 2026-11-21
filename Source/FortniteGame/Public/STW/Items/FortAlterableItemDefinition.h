// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortItemQuantityPair.h"
#include "FortRarityEnum.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortAlterableItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct FAlterationWeightData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationWeightData")
	FString AID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationWeightData")
	int32 InitialRollWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationWeightData")
	TArray<FString> ExclusionNames;

};

USTRUCT(BlueprintType)
struct FAlterationWeightSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationWeightSet")
	TArray<FAlterationWeightData> WeightData;

};

USTRUCT(BlueprintType)
struct FAlterationGroup : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationGroup")
	TMap<EFortRarity, FAlterationWeightSet> RarityMapping;

};

USTRUCT(BlueprintType)
struct FAlterationIntrinsicMapping : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationIntrinsicMapping")
	FString NewAlteration;

};

USTRUCT(BlueprintType)
struct FAlterationMapping : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationMapping")
	FString NewAlteration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationMapping")
	FString AdditionalAlteration;

};

USTRUCT(BlueprintType)
struct FAlterationNamedExclusions : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationNamedExclusions")
	TArray<FString> ExclusionNames;

};

USTRUCT(BlueprintType)
struct FAlterationSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlocking")
	int32 UnlockLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Unlocking")
	EFortRarity UnlockRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Alterations")
	FName SlotDefinitionRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Alterations")
	bool bRespeccable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InitialRarity")
	FName SlotRarityInitRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InitialRarity")
	EFortRarity SlotInitMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InitialRarity")
	EFortRarity SlotInitMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InitialRarity")
	int32 SlotInitIndex;

};

USTRUCT(BlueprintType)
struct FAlterationSlotDefinition : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Alterations")
	FName InitTierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Alterations")
	TArray<FFortItemQuantityPair> BaseRespecCosts;

};

USTRUCT(BlueprintType)
struct FAlterationSlotRarity : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationSlotRarity")
	TMap<EFortRarity, int32> RarityWeights;

};

USTRUCT(BlueprintType)
struct FAlterationSlotsLoadout : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AlterationSlotsLoadout")
	TArray<FAlterationSlot> AlterationSlots;

};

UCLASS(NotBlueprintable)
class UFortAlterableItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

};


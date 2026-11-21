// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/FortGameStateComponent.h"
#include "FortGamestateComponent_DynamicRollTableManager.generated.h"

class AFortGameStateAthena;
class UFortItemDefinition;
class UFortPlaylist;

UENUM(BlueprintType)
enum class ERollModifierOperation : uint8
{
	/** Adds from an items weight based on the sign of the modifier magnitude. To subtract, use negative values. Add operation is the ideal way to modify roll values.*/
	Add = 0,
	/** Multiplies sum up to multiply against the final weight. These are more complex and generally should be avoided in favor of Add operations.*/
	Multiply = 1,
	/** This will be used to zero out an entries weight,  regardless of other modifiers. Used to completely disable entries based on some state. */
	Zero = 2,
};

USTRUCT()
struct FDynamicRollModifiersActivatedByPlayerTagContainer
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortDynamicRollBaseWeightTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	float BaseWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	TArray<FGameplayTag> ModTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	bool bOwningItemZerosWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	float MaxModifiedWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollBaseWeightTableRow")
	float MinModifiedWeight;

};

USTRUCT(BlueprintType)
struct FFortDynamicRollWeightModifierTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollWeightModifierTableRow")
	FGameplayTag ActivatingPlayerTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollWeightModifierTableRow")
	FGameplayTag TargetModTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollWeightModifierTableRow")
	ERollModifierOperation WeightModifierOperation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDynamicRollWeightModifierTableRow")
	float WeightModificationValue;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class DYNAMICROLLTABLESRUNTIME_API UFortGamestateComponent_DynamicRollTableManager : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	FDataRegistryType DataRegistryType_BaseWeights;

	UPROPERTY(Config)
	FDataRegistryType DataRegistryType_WeightModifiers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGamestateComponent_DynamicRollTableManager")
	FScalableFloat Enabled;

private:
	UFUNCTION()
	void HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};


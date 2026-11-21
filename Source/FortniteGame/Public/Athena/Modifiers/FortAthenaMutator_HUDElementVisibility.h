// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_HUDElementVisibility.generated.h"

class AFortMinigame;
class AFortVolume;
class APlayerState;
class UFortPlaysetItemDefinition;
enum class EFortHUDElementVisibiltyPriority : uint8;

UENUM(BlueprintType)
enum class EFortHUDElementVisibiltyOption : uint8
{
	DoNotOverride = 0,
	// Do not modify the existing setting

	ShowElement = 1,
	// Show the HUD element

	HideElement = 2,
};

UENUM(BlueprintType)
enum class EFortHUDElementVisibiltyPriority : uint8
{
	Lowest = 0,
	VeryLow = 1,
	Low = 2,
	Normal = 3,
	High = 4,
	VeryHigh = 5,
	Highest = 6,
	// Max Value

	COUNT = 7 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortReticleVisibiltyOption : uint8
{
	DoNotOverride = 0,
	ShowAlways = 1,
	ShowPickaxeOnly = 2,
	ShowNonPickaxeOnly = 3,
	HideAlways = 4,
};

USTRUCT(BlueprintType)
struct FHUDElementVisibilityRepData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	FGameplayTagContainer HiddenHUDElements;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	FGameplayTagContainer ShownHUDElements;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	TArray<EFortHUDElementVisibiltyOption> WorldResourceVisibilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	TArray<EFortHUDElementVisibiltyOption> GamePhaseStateVisibilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	EFortReticleVisibiltyOption ReticleVisibilityOption;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	int32 ModSourceID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	int32 TeamSpecifier;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	int32 ClassSpecifier;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	bool bInvertTeamSelection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	bool bInvertClassSelection;

};

USTRUCT(BlueprintType)
struct FHUDElementVisibilityModSourceStack
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	TArray<FHUDElementVisibilityRepData> HUDElementVisbilityModSources;

};

USTRUCT(BlueprintType)
struct FHUDElementVisibilityPriorityStacks
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="HUD")
	TArray<FHUDElementVisibilityModSourceStack> HUDElementVisbilityStacksByPriority;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API AFortAthenaMutator_HUDElementVisibility : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void MulticastAddVisibilityModData(const EFortHUDElementVisibiltyPriority Priority, const FHUDElementVisibilityRepData VisibilityData);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void MulticastRemoveVisibilityModData(const EFortHUDElementVisibiltyPriority Priority, const FHUDElementVisibilityRepData VisibilityData);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void MulticastUpdateVisibilityModData(const FHUDElementVisibilityRepData UpdatedVisibilityData);

	UFUNCTION(BlueprintPure)
	int32 RequestVisibilityModSourceID() const;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastClearVisibilityModData();

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_PriorityStacksRepData, Category="HUD")
	FHUDElementVisibilityPriorityStacks PriorityStacksRepData;

private:
	UFUNCTION()
	void OnClientEnteredVolume(APlayerState* Client, AFortVolume* Volume);

	UFUNCTION()
	void OnClientPlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

	UFUNCTION()
	void OnCreativeLinkedVolumeChangedForPC(AFortVolume* Volume);

	UFUNCTION()
	void OnMinigameSetUp(AFortMinigame* Minigame);

	UFUNCTION()
	void OnRep_PriorityStacksRepData();

	UFUNCTION()
	void OnVolumePlaysetChanged(const UFortPlaysetItemDefinition* PlaysetItemDef);

};


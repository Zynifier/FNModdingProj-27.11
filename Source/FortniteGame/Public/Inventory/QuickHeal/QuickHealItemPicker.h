// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Inventory/QuickHeal/QuickHealPriority.h"
#include "QuickHealItemPicker.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawn;

UENUM()
enum class EQuickHealingRequirementFlags : uint8
{
	Nothing = 0,
	NeedsHealing = 1,
	NeedsShields = 2,
	NeedsBoth = 3,
	Invalid = 4,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UQuickHealItemPicker : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleLocalPlayerDBNOStateChanged(AFortPawn* Pawn, bool bNewDBNOState);

	UFUNCTION()
	void HandleOnSafeZoneOccupancyChanged(AFortPlayerPawn* PlayerPawn, bool bIsInSafeZone);

	UFUNCTION()
	void HandleOnVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION()
	void HandlePlayerHealthOrShieldChanged();

	UPROPERTY(EditAnywhere, Category="Priorities")
	TArray<FQuickHealPriority> QuickHealPriorities;

	UPROPERTY(EditAnywhere, Category="Comparison Tags")
	FGameplayTag HealingItemComparisonTag;

	UPROPERTY(EditAnywhere, Category="Comparison Tags")
	FGameplayTag ShieldItemComparisonTag;

	UPROPERTY(EditAnywhere, Category="Comparison Tags")
	FGameplayTagContainer SpecialActionTags;

};


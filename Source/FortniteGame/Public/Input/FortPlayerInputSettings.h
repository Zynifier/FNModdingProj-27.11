// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "UObject/NoExportTypes.h"
#include "Input/FortPlayerInput.h"
#include "FortPlayerInputSettings.generated.h"

UCLASS(Config=Input, PerObjectConfig)
class UFortPlayerInputSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FText FriendlyName;

	UPROPERTY(Config)
	FText Description;

	UPROPERTY(Config)
	FText SubDescription;

	UPROPERTY(Config)
	TArray<FInputActionKeyMapping> ActionMappings;

	UPROPERTY(Config)
	TArray<FFortInputActionKeyAlias> ActionKeyAliases;

	UPROPERTY(Config)
	TArray<FFortInputActionThatShouldAlwaysBeBound> ActionsThatShouldAlwaysBeBound;

	UPROPERTY(Config)
	float HoldInputTime;

	UPROPERTY(Config)
	float HoldCraftAmmoTime;

	UPROPERTY(Config)
	float HoldHudChatTime;

	UPROPERTY(Config)
	float HoldVoteDialogTime;

	UPROPERTY(Config)
	bool bBuildingPickerOnlyChoosesCategories;

	UPROPERTY(Config)
	bool bWeaponPickerShowOnlySlottedItems;

	UPROPERTY(Config)
	bool bTrapPickerUsesRadial;

	UPROPERTY(Config)
	bool bRadialClosesOnRelease;

	UPROPERTY(Config)
	int32 NumActiveTrapSlots;

	UPROPERTY(Config)
	bool bWeaponSlotsAreSharedWhenUsingGamepad;

	UPROPERTY(Config)
	bool bEditModeUsableFromCombatMode;

	UPROPERTY(Config)
	bool bOnlyShowNextPrevBuildingSlotKeybinds;

	UPROPERTY(Config)
	bool bEnabledForCampaign;

	UPROPERTY(Config)
	bool bEnabledForAthena;

};


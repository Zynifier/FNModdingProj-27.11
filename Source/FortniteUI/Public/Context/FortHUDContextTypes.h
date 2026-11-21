// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDContextTypes.generated.h"

USTRUCT(BlueprintType, meta=(DisplayName="Fort HUD State"))
struct FORTNITEUI_API FFortHUDState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInBuildMode : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInCombatMode : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInEditMode : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInCreativeMode : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsParachuteOpen : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsFreeFalling : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInLockedBus : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bInUnlockedBus : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bOnTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bOnUsingScopeTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bOnCanTarget : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bOnCanUseScopeTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bOnCanUseSecondaryAbility : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bCanOpenChute : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bDBNO : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsControllingRCPawn : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsInVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsDrivingVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bCanSwapSeats : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsCarryingDBNO : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsCarryingHeldObject : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsZiplining : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bIsCreativeFlying : 1;

	UPROPERTY(BlueprintReadOnly, Category="HUD State")
	uint8 bImprovedDBNO : 1;

};


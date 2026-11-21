// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Bacchus/FortMobileHUDElement.h"
#include "Context/FortHUDContextTypes.h"
#include "UI/Bacchus/BacchusHudTypes.h"
#include "BacchusHUDElement.generated.h"

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UBacchusHUDElement : public UFortMobileHUDElement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEUI_API void HandleInputMethodChanged(ECommonInputType CurrentInputType);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Events")
	FORTNITEUI_API void OnHUDStateUpdate(const FFortHUDState& NewState);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void ShowHighlight(bool Show);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI Visibility")
	bool bHideWhenNotUsingTouch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility")
	bool bUpdatesWithHUDState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility")
	bool bAlwaysShow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Modes")
	EBacchusHUDStateType OnInBuildMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Modes")
	EBacchusHUDStateType OnInCombatMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Modes")
	EBacchusHUDStateType OnInEditMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Modes")
	EBacchusHUDStateType OnInCreativeMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Modes")
	EBacchusHUDStateType OnInBattleLabMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Parachute")
	EBacchusHUDStateType IsFreeFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Parachute")
	EBacchusHUDStateType IsGliding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Parachute")
	EBacchusHUDStateType CanOpenChute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Pre-Game")
	EBacchusHUDStateType InLockedBus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Pre-Game")
	EBacchusHUDStateType InUnlockedBus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnUsingScopeTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCanTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCanUseScopeTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCanUseSecondaryAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCarryingDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnCarryingHeldObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Weapons")
	EBacchusHUDStateType OnImprovedDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - RC")
	EBacchusHUDStateType OnControllingRCPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Vehicle")
	EBacchusHUDStateType OnInVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Vehicle")
	EBacchusHUDStateType OnDrivingVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility - Zipline")
	EBacchusHUDStateType OnZiplining;

};


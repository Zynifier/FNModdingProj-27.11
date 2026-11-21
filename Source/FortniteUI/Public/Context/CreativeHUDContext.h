// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "BlueprintContextBase.h"
#include "Creative/CreativeQuickbarComponent.h"
#include "Player/FortPlayerControllerGameplay.h"
#include "Weapons/FortCreativeMoveTool.h"
#include "CreativeHUDContext.generated.h"

class AFortCreativeMoveTool;
class AFortPlayerPawn;
class AFortPlayerState;
class AFortWeapon;
class UDataTable;
enum class EHitTraceRule : uint8;
enum class EScaleAxis : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeQuickMenuDisplayedChanged, bool, bIsDisplayed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericBooleanStateChangedEvent, bool, bStateOn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGenericCountDownEvent, FText, CountDownEventDisplayText, float, TimeRemaining);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsCreativeModeratorModeActiveChanged, bool, bIsCreativeModeratorModeActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolEquippedChanged, bool, bIsEquipped);

UCLASS(MinimalAPI)
class UCreativeHUDLContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ForwardOnCreativeGhostChanged(bool bIsGhostEnabled);

	UFUNCTION()
	void ForwardOnCreativeHeatmapTogged(bool bIsHeatmapToggled);

	UFUNCTION()
	void ForwardOnCreativeInvulnerableChanged(bool bIsInvulnerable);

	UFUNCTION()
	void ForwardOnCreativeQuickbarActiveChanged(bool bIsActive);

	UFUNCTION()
	void ForwardOnCreativeQuickbarEnabledChanged(bool bIsEnabled);

	UFUNCTION()
	void ForwardOnCreativeQuickbarEquippedChanged(bool bIsEquipped);

	UFUNCTION(BlueprintCallable)
	void ForwardOnCreativeQuickMenuDisplayedChanged(bool bIsDisplayed);

	UFUNCTION()
	void ForwardOnDropToFloorChanged(bool bDropToFloorOn);

	UFUNCTION()
	void ForwardOnLOSChanged(EHitTraceRule HitTraceRule);

	UFUNCTION()
	void ForwardOnMoveToolRotationModified(FQuat currentRotationOffset);

	UFUNCTION()
	void ForwardOnMoveToolScaleModified(FVector currentVector);

	UFUNCTION()
	void ForwardOnPrecisionChanged(bool bPrecisionOn, uint8 GridSnapIndex);

	UFUNCTION(BlueprintCallable)
	void ForwardOnPropLockedInPlacedChanged(bool bLockedInPlace);

	UFUNCTION()
	void ForwardOnRotationAxisChanged(uint8 AxisIndex);

	UFUNCTION()
	void ForwardOnScaleAxisChanged(EScaleAxis Axis);

	UFUNCTION(BlueprintPure)
	UDataTable* GetCreativeItemListSourceFromPlaylist() const;

	UFUNCTION(BlueprintPure)
	EHitTraceRule GetCurrentHitTraceRule() const;

	UFUNCTION(BlueprintPure)
	bool GetDropToFloorEnabled() const;

	UFUNCTION()
	AFortPlayerPawn* GetOwningPlayerPawn() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerState* GetOwningPlayerState() const;

	UFUNCTION(BlueprintPure)
	void GetPrecisionLevel(bool& SnappingEnabled, uint8& GridSnappingIndex) const;

	UFUNCTION(BlueprintPure)
	FRotator GetRotationAxis() const;

	UFUNCTION(BlueprintPure)
	EScaleAxis GetScaleAxis() const;

	UFUNCTION()
	void HandleOnCreativeModeEnabledChanged(bool bIsEnabled);

	UFUNCTION(BlueprintPure)
	bool IsPropLockedInPlace() const;

	UFUNCTION()
	void OnCreativeQuickbarComponentLoaded();

	UFUNCTION()
	void OnPlayerControllerSet();

	UFUNCTION()
	void OnPlayerPawnSet();

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnMoveToolRotationAxisChanged OnRotationAxisChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnMoveToolScaleAxisChanged OnScaleAxisChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnCreativeGhostChanged OnCreativeGhostChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnCreativeInvulnerableChanged OnCreativeInvulnerableChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnCreativeHeatmapToggled OnCreativeHeatmapToggled;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnMoveToolDropToFloorChanged OnDropToFloorChanged;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="HUD")
	FOnMoveToolPrecisionChanged OnPrecisionChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolLineOfSightBlockingChanged OnMoveToolLineOfSightBlockingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolEquippedChanged OnMoveToolEquippedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolScaleModified OnMoveToolScaleModified;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickMenuDisplayedChanged OnCreativeQuickMenuDisplayedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolRotationModified OnMoveToolRotationModified;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarEnabledChanged OnCreativeQuickbarEnabledChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeModeEnabledChanged OnCreativeModeEnabledChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarActiveChanged OnCreativeQuickbarActiveChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeQuickbarEquippedChanged OnCreativeQuickbarEquippedChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnGenericCountDownEvent OnPropPlaySoundCountdownChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnGenericBooleanStateChangedEvent OnPropLockInPlaceChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnIsCreativeModeratorModeActiveChanged OnIsCreativeModeratorModeActiveChanged;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortCreativeMoveTool> CurrentMoveTool;

	UPROPERTY(Transient)
	bool bPropLockedInPlace;

};


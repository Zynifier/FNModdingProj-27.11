// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Building/BuildingGameplayActor.h"
#include "FortTeamEnum.h"
#include "AthenaCapturePoint.generated.h"

class AActor;
class AAthenaCapturePoint;
class AFortPlayerPawnAthena;
class AFortTeamInfoAthena;
class UBoxComponent;
class UFortSlateHUDIndicator;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;
enum class ECapturePointState : uint8;

UENUM(BlueprintType)
enum class ECapturePointState : uint8
{
	Idle = 0,
	Capturing = 1,
	Contested = 2,
	Resetting = 3,
	Captured = 4,
	Reset = 5,
};

UENUM(BlueprintType)
enum class ECapturePointUnlockRules : uint8
{
	Reset = 0,
	MaintainState = 1,
	ResetDeactivate = 2,
};

UENUM(BlueprintType)
enum class EContentionRuleType : uint8
{
	MajorityWins = 0,
	OneTeamOnlyWins = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCaptureLockBroken, AAthenaCapturePoint*, CapturePoint, uint8, LockTeam, uint8, BreakTeam);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCaptureLock, AAthenaCapturePoint*, CapturePoint, uint8, LockTeam, bool, bIsNewLock);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCaptureStateChanged, ECapturePointState, CaptureState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTeamOwningCapturePointChanged, uint8, OldTeam, uint8, NewTeam);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaCapturePoint : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CapturePoint Methods")
	ECapturePointState GetCaptureState() const;

	UFUNCTION(BlueprintCallable, Category="CapturePoint Methods")
	int32 GetNumDancingPlayers();

	UFUNCTION(BlueprintCallable, Category="CapturePoint Methods")
	bool HasDancingPlayer();

	UFUNCTION(BlueprintNativeEvent, Category="CapturePoint Methods")
	void OnCapturePointActiveStateChange(bool bInActive);

	UFUNCTION(BlueprintNativeEvent, Category="CapturePoint Methods")
	void OnCapturePointLockStateChange(bool bInLocked);

	UFUNCTION(BlueprintNativeEvent, Category="CapturePoint Methods")
	void OnCapturePointStateChange(ECapturePointState InState, uint8 InTeam);

	UFUNCTION()
	void OnRep_bPermanentShutdown();

	UFUNCTION()
	void OnRep_IconMaterialIndexParameter();

	UFUNCTION(BlueprintCallable, Category="CapturePoint Methods")
	void SetActivatedState(bool bInActivated);

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> HUDIndicatorMID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCapturePoint")
	FSlateBrush IndicatorBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCapturePoint")
	FSlateBrush MapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCapturePoint")
	FSlateBrush CompassIconBrush;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IconMaterialIndexParameter)
	int32 IconMaterialIndexParameter;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bPermanentShutdown, Category="AthenaCapturePoint")
	bool bPermanentShutdown;

	UPROPERTY(Transient)
	float ShutdownTime;

	UPROPERTY(Transient)
	TObjectPtr<UFortSlateHUDIndicator> HUDIndicatorRef;

	UPROPERTY()
	FVector2D CurrHUDIndicatorSize;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CapturePointMID_Neutral;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CapturePointMID_AllyCaptured;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CapturePointMID_AllyCapping;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CapturePointMID_EnemyCaptured;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CapturePointMID_EnemyCapping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="CapturePoint Components", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> StructuralComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="CapturePoint Components", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> CaptureComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaCapturePoint")
	TArray<TObjectPtr<AFortPlayerPawnAthena>> OverlappedAthenaPawns;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCaptureLock OnCaptureLockEvent;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCaptureLockBroken OnCaptureLockBrokenEvent;

protected:
	UFUNCTION()
	void OnEnterCapturePoint(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaveCapturePoint(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnRep_bActivated();

	UFUNCTION()
	void OnRep_bLocked();

	UFUNCTION()
	void OnRep_CaptureState();

	UFUNCTION()
	void OnRep_ReplicatedCapturePercentage();

	UPROPERTY(EditDefaultsOnly, Category="HUD")
	uint8 bUseHUDIndicator : 1;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	FName HUDStyle;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	FVector HUDOffset;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	uint8 bHUDClampToScreenEdge : 1;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	FVector2D MinHUDIndicatorSize;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	FVector2D MaxHUDIndicatorSize;

	UPROPERTY(EditDefaultsOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	float DistanceForMinHUDSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	TObjectPtr<UMaterialInstance> CapturePointMat_Neutral;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	TObjectPtr<UMaterialInstance> CapturePointMat_AllyCaptured;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	TObjectPtr<UMaterialInstance> CapturePointMat_AllyCapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	TObjectPtr<UMaterialInstance> CapturePointMat_EnemyCaptured;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HUD", meta=(EditCondition="bUseHUDIndicator"))
	TObjectPtr<UMaterialInstance> CapturePointMat_EnemyCapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing=OnRep_bActivated, Category="Read/Write Data")
	uint8 bActivated : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	EContentionRuleType ContentionRules;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Read/Write Data")
	TArray<TEnumAsByte<EFortTeam::Type>> TeamsBarredFromCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	bool bSupportsPerPlayerCapturing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	FScalableFloat PercentIncreasePerPlayerCaptor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	FScalableFloat BonusPercentIncreasePerPlayerCaptor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	TArray<FScalableFloat> CaptureSpeedPerPlayerList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	FScalableFloat PercentDecreaseNoCaptor;

	UPROPERTY(Transient)
	float CachedPercentIncreasePerPlayerCaptor;

	UPROPERTY(Transient)
	float CachedBonusPercentIncreasePerPlayerCaptor;

	UPROPERTY(Transient)
	float CachedPercentDecreaseNoCaptor;

	UPROPERTY(Transient)
	TArray<float> CachedCaptureSpeedPerPlayerList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_bLocked, Category="Read/Write Data")
	uint8 bLocked : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	float UnlockInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Read/Write Data")
	ECapturePointUnlockRules UnlockRules;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="ReadOnly Data")
	int32 NumCapturingPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="ReadOnly Data")
	uint8 TeamCapturingPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="ReadOnly Data")
	uint8 TeamControllingPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="ReadOnly Data")
	TObjectPtr<AFortTeamInfoAthena> TeamInfoControllingPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="ReadOnly Data")
	uint8 TeamOwningPoint;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_CaptureState, Category="ReadOnly Data")
	ECapturePointState CaptureState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="ReadOnly Data")
	float CapturePercentage;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_ReplicatedCapturePercentage, Category="ReadOnly Data")
	float ReplicatedCapturePercentage;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnCaptureStateChanged OnCapturePointStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnTeamOwningCapturePointChanged OnTeamOwningPointChanges;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortSafeZoneIndicator.generated.h"

class AFortAthenaMapInfo;
class AFortSafeZoneIndicator;
class AFortSafeZoneIndicatorFuture;
class UAudioComponent;
class UCurveFloat;
class UFortMiniMapComponent;
class UMaterialParameterCollection;
class UObject;
class USplineComponent;
class UStaticMeshComponent;
enum class EFortSafeZoneState : uint8;

UENUM(BlueprintType)
enum class EFortSafeZoneState : uint8
{
	None = 0,
	Starting = 1,
	Holding = 2,
	Shrinking = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSafeZonePhaseIndexChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSafeZoneStateChangedDelegate, AFortSafeZoneIndicator*, SafeZoneIndicator, EFortSafeZoneState, SafeZoneState);

USTRUCT(BlueprintType)
struct FFortSafeZoneDamageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZoneDamageInfo")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZoneDamageInfo")
	bool bPercentageBasedDamage;

};

USTRUCT()
struct FFortSafeZoneDamageUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortSafeZoneDamageInfo DamageInfo;

};

USTRUCT(BlueprintType)
struct FFortSafeZoneDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat Count;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat Radius;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat ForceDistanceMin;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat ForceDistanceMax;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat RejectRadius;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat RejectOuterDistance;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat WaitTime;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat ShrinkTime;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat MegaStormGridCellThickness;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat PlayerCapSolo;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat PlayerCapDuo;

	UPROPERTY(EditAnywhere, Category="FortSafeZoneDefinition")
	FScalableFloat PlayerCapSquad;

};

USTRUCT()
struct FFortSafeZonePhaseCountUpdatedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PhaseCount;

};

USTRUCT(BlueprintType)
struct FFortSafeZonePhaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	FVector Center;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float WaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float ShrinkTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	FFortSafeZoneDamageInfo DamageInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	int32 PlayerCap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float TimeBetweenStormCapDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float StormCapDamagePerTick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float StormCampingIncrementTimeAfterDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	float StormCampingInitialDelayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	int32 MegaStormGridCellThickness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSafeZonePhaseInfo")
	bool UsePOIStormCenter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortSafeZonePhaseInfo")
	TWeakObjectPtr<USplineComponent> TravelSplineComponent;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortSafeZoneIndicator : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="SafeZone")
	bool ConstructMapDefaultPhase(const int32 PhaseToConstruct, FFortSafeZonePhaseInfo& OutConstructedPhase) const;

	UFUNCTION(BlueprintPure, Category="SafeZone", meta=(DisplayName="GetSafeZoneIndicator", WorldContext="WorldContextObject"))
	static AFortSafeZoneIndicator* Get(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="SafeZone")
	const FFortSafeZoneDamageInfo& GetCurrentDamageInfo() const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	int32 GetCurrentPhaseIndex() const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	int32 GetPhaseCount() const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	bool GetPhaseInfo(FFortSafeZonePhaseInfo& OutSafeZonePhase, const int32 InPhaseToGet = -1) const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	FVector GetSafeZoneCenter() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetSafeZoneFinishShrinkTime() const;

	UFUNCTION(BlueprintCallable, Category="SafeZone")
	bool GetSafeZonePausedForPreview();

	UFUNCTION(BlueprintPure, Category="SafeZone")
	const TArray<FFortSafeZonePhaseInfo>& GetSafeZonePhases() const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	float GetSafeZoneRadius() const;

	UFUNCTION(BlueprintCallable, Category="SafeZone")
	float GetSafeZoneShrinkSpeed();

	UFUNCTION(BlueprintCallable, Category="SafeZone")
	float GetSafeZoneShrinkSpeedRelativeTo(float DistanceToTravel);

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetSafeZoneStartShrinkTime() const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	EFortSafeZoneState GetSafeZoneState() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void InitializeWithMapDefaultPhases();

	UFUNCTION()
	void MegaStormMinTimerExpired();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void ModifyPhase(const int32 PhaseToModify, const FFortSafeZonePhaseInfo& NewPhase);

	UFUNCTION()
	void OnBeginStartingStateEffects();

	UFUNCTION(BlueprintImplementableEvent, Category="SafeZone")
	void OnBeginStartingStateEffectsEvent();

	UFUNCTION(BlueprintImplementableEvent, Category="SafeZone")
	void OnForceResetCloudStartingBias();

	UFUNCTION(BlueprintImplementableEvent, Category="SafeZone")
	void OnForceStopStormFadeTimer();

	UFUNCTION()
	void OnRep_NumActiveMegaStormCircles(int32 PrevNumActiveMegaStormCircles);

	UFUNCTION(BlueprintImplementableEvent, Category="SafeZone")
	void OnSafeZoneStateChange(EFortSafeZoneState NewState, bool bInitial);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void PauseAndPreviewPhase(const int32 PhaseToPreview);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="SafeZone")
	void SetPhaseInfoRadius(FFortSafeZonePhaseInfo& InOutPhase, const float InRadius, const int32 PhaseIndex, const AFortAthenaMapInfo* MapInfo) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void SetSafeZonePausedForPreview(bool bSetTo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void SetSafeZonePhases(const TArray<FFortSafeZonePhaseInfo>& InPhases);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void SetSafeZoneRadius(const float InRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void SetSafeZoneRadiusAndCenter(float InRadius, FVector InLocation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MiniMap")
	void SetShowWarmupPreview(const bool bNewPreviewDuringWarmup);

	UFUNCTION(BlueprintPure, Category="MiniMap")
	bool ShouldShowWarmupPreview() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void StartPhase(const int32 InPhaseIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SafeZone")
	void StopPreviewingPhase();

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMiniMapComponent> MinimapComp;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	float PreviousRadius;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	float NextRadius;

	UPROPERTY(BlueprintReadOnly, Category="SafeZone")
	float NextNextRadius;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="SafeZone")
	FVector_NetQuantize100 PreviousCenter;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="SafeZone")
	FVector_NetQuantize100 NextCenter;

	UPROPERTY(BlueprintReadOnly, Category="SafeZone")
	FVector_NetQuantize100 NextNextCenter;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentTravelSplineComponent, Export, Category="SafeZone")
	TWeakObjectPtr<USplineComponent> CurrentTravelSplineComponent;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	bool bSafezoneEventDriven;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	bool bPaused;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	bool bPausedForPreview;

	UPROPERTY()
	bool bPausedForPreview_Previous;

	UPROPERTY(Transient)
	int32 PlaylistMaxSafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag MegaStormGameplayCueTag;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	int32 NextNextMegaStormGridCellThickness;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	int32 NextMegaStormGridCellThickness;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="MegaStorm")
	float MegaStormDelayTimeBeforeDestruction;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_NumActiveMegaStormCircles, Category="MegaStorm")
	int32 NumActiveMegaStormCircles;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="MegaStorm")
	int32 ActiveMegaStormCircleGridCellCountFromEdge;

	UPROPERTY(Transient)
	float SafeZoneHeight;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush FarOffMiniMapIconBrush;

	UPROPERTY(BlueprintAssignable, Category="SafeZone")
	FOnSafeZoneStateChangedDelegate SafezoneStateChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnSafeZonePhaseIndexChanged OnSafeZonePhaseChanged;

protected:
	UFUNCTION(BlueprintPure, Category="Audio")
	void GetClockTickingAudioCurveValues(float Time, float& VolumeModValue, float& PitchModValue) const;

	UFUNCTION(BlueprintPure, Category="Audio")
	void GetMovementAudioCurveValues(float Time, float& CrossfadeValue, float& PitchModValue) const;

	UFUNCTION(BlueprintPure, Category="SafeZone")
	float GetTimeSinceSafeZonesStart() const;

	UFUNCTION()
	void OnRep_CurrentDamageInfo();

	UFUNCTION()
	void OnRep_CurrentPhase();

	UFUNCTION()
	void OnRep_CurrentTravelSplineComponent();

	UFUNCTION()
	void OnRep_PhaseCount();

	UFUNCTION(BlueprintCallable)
	void SetSafeZoneHeight(float NewWaterHeight);

	UPROPERTY(Replicated)
	TArray<FFortSafeZonePhaseInfo> SafeZonePhases;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentPhase)
	int32 CurrentPhase;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentDamageInfo)
	FFortSafeZoneDamageInfo CurrentDamageInfo;

	UPROPERTY(ReplicatedUsing=OnRep_PhaseCount)
	int32 PhaseCount;

	UPROPERTY(BlueprintGetter=GetSafeZoneStartShrinkTime, Replicated, Category="SafeZone")
	float SafeZoneStartShrinkTime;

	UPROPERTY(BlueprintGetter=GetSafeZoneFinishShrinkTime, Replicated, Category="SafeZone")
	float SafeZoneFinishShrinkTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	float Radius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="SafeZone", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SafeZoneMesh;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> MovementAudioCrossfadeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> MovementAudioPitchModCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> ClockTickingAudioVolumeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<UCurveFloat> ClockTickingAudioPitchCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FVector2D SafeZoneAudioSpeedRange;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float AudioDopplerInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SafeZoneIndicator")
	TObjectPtr<UMaterialParameterCollection> MaterialCollection;

	UPROPERTY(EditDefaultsOnly, Category="SafeZoneIndicator")
	FName SafeZoneLocName;

	UPROPERTY(EditDefaultsOnly, Category="SafeZoneIndicator")
	FName SafeZoneScaleName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SafeZoneIndicator")
	float SafeZoneWorldScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SafeZoneIndicator")
	FVector ViewTargetLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SafeZoneIndicator")
	FVector SafeZoneAudioLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SafeZoneIndicator")
	bool bIsViewTargetPawnOutside;

	UPROPERTY(EditDefaultsOnly, Category="SafeZoneIndicator")
	FName SuperStormActiveName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MegaStorm")
	float MegaStormFXAlphaFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MegaStorm")
	float MegaStormFXFadeInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MegaStorm")
	float MegaStormFXFadeOutTime;

	UPROPERTY(Transient)
	bool bMegaStormGameplayCueStarted;

	UPROPERTY(Transient)
	bool bMegaStormStopPending;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MegaStorm")
	bool bCleanupFXWithAlphaFactor;

	UPROPERTY(Transient)
	float MegaStormOneOverFXFadeInTime;

	UPROPERTY(Transient)
	float MegaStormOneOverFXFadeOutTime;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortSafeZoneIndicator", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ShieldBoundaryAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortSafeZoneIndicator", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> HoldingAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortSafeZoneIndicator", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> HoldingTickAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	bool bMegastormAudioActive;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	float AudioLowPassValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	float AudioPitchMod;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	float AudioCrossfade;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	float MegastormAudioIntensity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortSafeZoneIndicator")
	float HoldingStartTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="SafeZone")
	bool bPreviewDuringWarmup;

	UPROPERTY(Transient)
	TObjectPtr<AFortSafeZoneIndicatorFuture> FutureReplicator;

private:
	UPROPERTY(Replicated)
	float TimeRemainingWhenPhasePaused;

	UPROPERTY(Replicated)
	uint8 ForceUpdateCount;

};


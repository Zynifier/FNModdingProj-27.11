// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorSentry.generated.h"

class AActor;
class ABuildingGameplayActorSentry;
class UCurveFloat;
class USpotLightComponent;
class UStaticMeshComponent;
enum class EBuildingGameplayActorSentry_State : uint8;

UENUM(BlueprintType)
enum class EBuildingGameplayActorSentry_State : uint8
{
	/** Idles, no players are near by. */
	PassiveIdle = 0,
	/** Idle, but players are near by.
	*	During this state the turret will slowly pan left then right with brief pauses in between. */
	ActiveIdle = 1,
	/** Currently aiming at a player, not currently attacking that player. */
	Tracking = 2,
	/** Attacking a target */
	Aggro = 3,
	/** Turret is currently doing nothing, same behavior as deactivated. */
	Dormant = 4,
	/** Turret is disabled, same behavior as dormant. */
	Deactivated = 5,
	/** Turret is rotating back to one of its default positions. */
	ReturningToIdle = 6,
	/** Turning to the location of damage. */
	LocatingDamager = 7,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBGASentryStateChanged, ABuildingGameplayActorSentry*, Sentry, EBuildingGameplayActorSentry_State, State);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorSentry : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BPOnSentryStateChanged(const EBuildingGameplayActorSentry_State PreviousSentryState);

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnTrackedActorSet(AActor* TrackedActorPrevious);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayStartedIdleRotationAudio();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayStoppedIdleRotationAudio();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetActorToTrack(AActor* InActorToTrack);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFixedRotationGoalForReplication(const FRotator& InFixedRotationGoal);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetLaserActive(bool bIsActive);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetSentryState(EBuildingGameplayActorSentry_State InSentryState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetStartingIdleRotation(const FRotator& InStartingIdleRotation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StopRotationSound();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorSentry", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> CameraStaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorSentry", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> BaseStaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="BuildingGameplayActorSentry", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> AngleRaysStaticMeshComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USpotLightComponent> SpotLightComp;

	UPROPERTY(EditDefaultsOnly, Category="BuildingGameplayActorSentry")
	bool bYawLimitWhileTracking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float TrackingYawLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry", meta=(ExposeOnSpawn="TRUE"))
	bool bDoesNotRotate;

	UPROPERTY(Config)
	bool bLocateDamagerIfHitWhileIdle;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentSentryState, Category="BuildingGameplayActorSentry")
	EBuildingGameplayActorSentry_State CurrentSentryState;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="BuildingGameplayActorSentry")
	TObjectPtr<AActor> ActorBeingTracked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	FScalableFloat TrackedToAggroDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float TrackedToAggroDelayMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	bool bIdleRotationStopped;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	float IdleRotationPauseTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	float PauseTimeBeforeIdleState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float ReturnToIdleRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float TrackingRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	float LocatingDamagerRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	float TrackingAdditionalZLook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	bool bGoDormantAfterPassiveIdle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingGameplayActorSentry")
	bool bSetRayScaleOnTrackTick;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	float AngleRaysTrackingYScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGameplayActorSentry")
	float AngleRaysTrackingZScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingGameplayActorSentry")
	FVector AngleRaysTargetScale;

	UPROPERTY(EditAnywhere, Category="GameplayCues")
	FGameplayTag ReturnToIdleGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="GameplayCues")
	FGameplayTag TrackedGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="GameplayCues")
	FGameplayTag AggroedGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSentry")
	bool bBaseFollowsTargetRotation;

	UPROPERTY(Transient)
	bool bWasIdleStopped;

	UPROPERTY(Transient)
	bool bIdleRotatingRight;

	UPROPERTY(Transient)
	FVector LastActorBeingTrackedLocation;

	UPROPERTY(Transient)
	float LastNetworkReceiveTime;

	UPROPERTY(Config)
	float DisableTickAfterNoNetworkTrafficTime;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSentry")
	float SentryPitchClampMin;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorSentry")
	float SentryPitchClampMax;

	UPROPERTY(EditAnywhere, Category="SpotLight")
	FVector2D SpotLightDistanceMinMax;

	UPROPERTY(EditAnywhere, Category="SpotLight")
	FVector2D SpotLightRadiusMinMax;

	UPROPERTY(EditAnywhere, Category="SpotLight")
	FVector2D SpotLightOuterConeAngleMinMax;

	UPROPERTY(EditAnywhere, Category="SpotLight")
	float SpotLightRadiusLerpSpeed;

	UPROPERTY(EditAnywhere, Category="SpotLight")
	float SpotLightOuterConeAngleLerpSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingGameplayActorSentry")
	TArray<TObjectPtr<AActor>> TargetActorsInRange;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	FRotator TargetRotation;

	UPROPERTY(ReplicatedUsing=OnRep_ExactIdleRotationForInitialization)
	FRotator ExactIdleRotationForInitialization;

	UPROPERTY(ReplicatedUsing=OnRep_ForceReplicateTargetRotation)
	FRotator ForceReplicateTargetRotation;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	FRotator TargetRotationRight;

	UPROPERTY(BlueprintReadWrite, Category="BuildingGameplayActorSentry")
	FRotator TargetRotationLeft;

	UPROPERTY(BlueprintAssignable)
	FOnBGASentryStateChanged OnSentryStateChanged;

protected:
	UFUNCTION()
	void OnRep_CurrentSentryState(const EBuildingGameplayActorSentry_State PreviousSentryState);

	UFUNCTION()
	void OnRep_ExactIdleRotationForInitialization();

	UFUNCTION()
	void OnRep_FixedRotationGoalReplicated();

	UFUNCTION()
	void OnRep_ForceReplicateTargetRotation();

	UPROPERTY(BlueprintReadOnly, Replicated, Category="BuildingGameplayActorSentry")
	FRotator StartingIdleRotation;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_FixedRotationGoalReplicated, Category="BuildingGameplayActorSentry")
	FRotator FixedRotationGoalReplicated;

	UPROPERTY(Replicated)
	FRotator LocatingDamage_OvershootRotationDestination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Locating Damager")
	float LocatingDamage_NextIdleMinimumAngularDifference_Degrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Locating Damager")
	FScalableFloat LocatingDamage_OverRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Locating Damager")
	float LocatingDamage_UpdateTarget_PauseTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Locating Damager")
	TObjectPtr<UCurveFloat> LocatingDamage_RotationSpeedScalarByAngularDistanceCurve;

	UPROPERTY(Transient, Replicated)
	float LocatingDamage_RotationSpeedScalar;

};


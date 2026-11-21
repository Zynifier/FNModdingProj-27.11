// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Abilities/FortAbilityTypes.h"
#include "Abilities/FortTargetSelectionInterface.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingActor.h"
#include "FortAnalyticsInterface.h"
#include "FortProjectileMovementInterface.h"
#include "BuildingGameplayActor.generated.h"

class AActor;
class ABuildingGameplayActor;
class AFortPawn;
class AFortPlayerPawn;
class UFortAbilitySet;
class UPrimitiveComponent;
class UWidget;
enum class EFortAbilityTargetingSource : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeliverableAbilityInfoAppliedToTouchingActor, AActor*, AffectedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeliverableAbilityInfoChangedForExitingTouchActor, AActor*, AffectedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProximityEffectsApplied, AActor*, TargetActor, FGameplayTag, BucketTag);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProximityPrePulse);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProximityPulse);

USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryBucket
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	FGameplayTag Tag;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FProximityBasedGEDeliveryInfo> ProximityBasedEffectBuckets_DEPRECATED;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	TArray<FProximityBasedGEDeliveryInfoHard> ProximityEffectBuckets;

	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	TArray<FFortAbilitySetDeliveryInfo> PawnPersistentAbilitySetBuckets;

	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> PersistentlyAppliedAbilitySets;

	UPROPERTY(Transient)
	uint8 bEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	uint8 bEnabledByDefault : 1;

	UPROPERTY()
	uint8 bHasGEsToApplyOnTouch : 1;

	UPROPERTY()
	uint8 bHasGEsToApplyOnExit : 1;

	UPROPERTY()
	uint8 bHasGEsToApplyOnPulseTimer : 1;

	UPROPERTY()
	uint8 bHasPersistentEffects : 1;

};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorAbilityDeliveryInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	TArray<FBuildingGameplayActorAbilityDeliveryBucket> DeliveryBuckets;

	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	FScalableFloat ProximityPulseInterval;

	UPROPERTY(EditDefaultsOnly, Category="Delivery")
	FScalableFloat ProximityPrePulseTime;

	UPROPERTY()
	uint8 bHasGEsToApplyOnTouch : 1;

	UPROPERTY()
	uint8 bHasGEsToApplyOnExit : 1;

	UPROPERTY()
	uint8 bHasGEsToApplyOnPulseTimer : 1;

	UPROPERTY()
	uint8 bHasPersistentEffects : 1;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingGameplayActor> OwningActor;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> DeferredTouchActorsToProcess;

};

USTRUCT(BlueprintType)
struct FBuildingGameplayActorClassData : public FBuildingActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActor : public ABuildingActor, public IFortTargetSelectionInterface, public IFortProjectileMovementInterface, public IFortAnalyticsInterface, public IFortMarkableActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Gameplay")
	FORTNITEGAME_API bool AcceptsEmoteSprays() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AbilitySystem")
	FORTNITEGAME_API void DisableAbilityDeliveryInfo(FGameplayTag BucketTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AbilitySystem")
	FORTNITEGAME_API void EnableAbilityDeliveryInfo(FGameplayTag BucketTag);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Targeting")
	FORTNITEGAME_API FTransform GetTargetingSourceTransform(EFortAbilityTargetingSource Source) const;

	UFUNCTION()
	FORTNITEGAME_API void HandleCleanupMoveIgnoreActor(AActor* EndPlayActor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="Add GameplayCue Replicated", GameplayTagFilter="GameplayCue"))
	FORTNITEGAME_API virtual void K2_AddGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="Add GameplayCueWithParams Replicated", GameplayTagFilter="GameplayCue"))
	FORTNITEGAME_API virtual void K2_AddGameplayCueWithParams(FGameplayTag GameplayCueTag, const FGameplayCueParameters& GameplayCueParameters);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="Execute GameplayCue Replicated", GameplayTagFilter="GameplayCue"))
	FORTNITEGAME_API virtual void K2_ExecuteGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="Execute GameplayCueWithParams Replicated", GameplayTagFilter="GameplayCue"))
	FORTNITEGAME_API virtual void K2_ExecuteGameplayCueWithParams(FGameplayTag GameplayCueTag, const FGameplayCueParameters& GameplayCueParameters);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(DisplayName="Remove GameplayCue Replicated", GameplayTagFilter="GameplayCue"))
	FORTNITEGAME_API virtual void K2_RemoveGameplayCue(FGameplayTag GameplayCueTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Carry")
	FORTNITEGAME_API void OnDropped(bool bValidLocation, bool bPassesPlacementRestrictions, bool bWasIntentionallyPlaced);

	UFUNCTION(BlueprintImplementableEvent, Category="Movement")
	FORTNITEGAME_API void OnReplicatedVelocityStartOrStop(bool bStart);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Gameplay")
	FORTNITEGAME_API void OnSpawned(AFortPawn* InInstigatorPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Damage")
	FORTNITEGAME_API void SetAbilitySourceLevel(int32 NewAbilitySourceLevel);

	UFUNCTION(BlueprintCallable, Category="Collision")
	FORTNITEGAME_API void SetIgnoreInstigatorCollision(bool bShouldIgnore);

	UFUNCTION(BlueprintCallable, Category="Movement")
	FORTNITEGAME_API void SetInitialVelocity(const FVector& InitialVelocity);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AbilitySystem")
	FORTNITEGAME_API void SetTouchComponentForAbilityDeliveryInfo(UPrimitiveComponent* PrimitiveComponent);

	UPROPERTY()
	TObjectPtr<UFortAbilitySet> AbilitySet_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	TObjectPtr<UFortAbilitySet> InherentAbilitySets[5];

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
	FDataTableRowHandle DamageStatHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingGameplayActor")
	bool bAllowRidingOnActor;

	UPROPERTY(BlueprintAssignable)
	FOnProximityPulse OnProximityPulseDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnProximityPrePulse OnProximityPrePulseDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnProximityEffectsApplied OnProximityEffectsAppliedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnDeliverableAbilityInfoAppliedToTouchingActor OnDeliverableAbilityInfoAppliedToTouchingActor;

	UPROPERTY(BlueprintAssignable)
	FOnDeliverableAbilityInfoChangedForExitingTouchActor OnDeliverableAbilityInfoChangedForExitingTouchActor;

protected:
	UFUNCTION()
	FORTNITEGAME_API virtual void OnRegisteredTouchComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRegisteredTouchComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API void OnServerNotifyEndLongUse(AFortPlayerPawn* InteractingPawn, bool bUseCompleted);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API void OnServerNotifyStartLongUse(AFortPlayerPawn* InteractingPawn);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void OverrideMarkerDisplayInfo(const FMarkedActorDisplayInfo& NewDisplayInfo);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision")
	bool bIgnoreInstigatorCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bAddOwnerVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Damage")
	int32 AbilitySourceLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AbilitySystem")
	FBuildingGameplayActorAbilityDeliveryInfo DeliverableAbilityInfo;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	uint8 bApplyDefaultEnabledAbilityBucketsOnInit : 1;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	uint8 bUseSimpleActorTouchSetupForAbilityBuckets : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bShowInteractKeybind : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FVector MarkerPositionOffset;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> RegisteredTouchComponent;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer AnalyticsTags;

	UPROPERTY(EditDefaultsOnly, Category="Post Process Volume")
	float PostProcessOverlapBlendWeight;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> CustomInteractionWidget;

};


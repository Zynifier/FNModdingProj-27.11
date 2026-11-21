// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Core/FortManagedTickSubsystem.h"
#include "FortInteractInterface.h"
#include "FortProjectileMovementInterface.h"
#include "Items/FortItemEntry.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "FortPickup.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class AFortPickupEffect;
class AFortPlayerController;
class AFortPlayerPawn;
class IFortSpatialGameplayInterface;
class UAudioComponent;
class UCapsuleComponent;
class UFortItem;
class UFortItemDefinition;
class UFortLinkToActorComponent;
class UFortProjectileMovementComponent;
class UFortSimpleMiniMapIndicator;
class UFortSlateHUDIndicator;
class UFortWaterInteractionComponent;
class UFortWorldItemDefinition;
class UObject;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USoundBase;
class UStaticMeshComponent;
enum class EFortPickupSourceTypeFlag : uint8;
enum class EFortPickupSpawnSource : uint8;
enum class EFortQuestObjectiveStatEvent : uint8;

UENUM()
enum class EFortPickupTossState : uint8
{
	NotTossed = 0,
	InProgress = 1,
	AtRest = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPickupOnCombinedOverflow, AFortPickup*, NewPickup, AFortPickup*, ThisPickup);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPickupOnCombined, AFortPickup*, ThisPickup, AFortPickup*, TargetPickup);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickupOnDespawn, AFortPickup*, SelfActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FPickupOnPickup, AFortPickup*, SelfActor, AFortPawn*, InteractingPawn, const UFortWorldItemDefinition*, WorldItemDefinition, FVector, PickupLocation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickupOnSetPawnWhoDroppedPickup, AFortPickup*, SelfActor);

USTRUCT()
struct FCanInteractResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPlayerPawn> RequestingPawn;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerController> RequestingPlayerController;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> InteractComponent;

};

USTRUCT()
struct FFortPickupLocationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPawn> PickupTarget;

	UPROPERTY()
	TObjectPtr<AFortPickup> CombineTarget;

	UPROPERTY()
	TWeakObjectPtr<AFortPawn> ItemOwner;

	UPROPERTY()
	FVector_NetQuantize10 LootInitialPosition;

	UPROPERTY()
	FVector_NetQuantize10 LootFinalPosition;

	UPROPERTY()
	float FlyTime;

	UPROPERTY()
	FVector_NetQuantizeNormal StartDirection;

	UPROPERTY()
	FVector_NetQuantize10 FinalTossRestLocation;

	UPROPERTY()
	EFortPickupTossState TossState;

	UPROPERTY()
	bool bPlayPickupSound;

private:
	UPROPERTY(NotReplicated, meta=(IgnoreForMemberInitializationTest))
	FGuid PickupGuid;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class AFortPickup : public AActor, public IFortInteractInterface, public IFortMarkableActorInterface, public IFortProjectileMovementInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddSpawnSourceTags(const FGameplayTagContainer& AdditionalTagsToAdd);

	UFUNCTION(BlueprintNativeEvent, Category="Long Range Auto Pickup")
	bool AllowLongRangeAutoPickup(const AFortPlayerPawn* FortPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Pickup")
	void BlueprintSetPickupTarget(AFortPawn* PickupTarget, bool bPlayPickupSound);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Pickup", meta=(UnsafeDuringActorConstruction="true"))
	FText GetDisplayName() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	virtual bool GetInteractErrorText(FText& OutInteractErrorText, FGameplayTag& OutInteractErrorIconTag);

	UFUNCTION(BlueprintCallable, Category="Pickup")
	virtual bool GetInteractText(FText& InteractText);

	UFUNCTION(BlueprintPure, Category="Pickup")
	const FFortItemEntry& GetItemEntry(int32 ItemIndex) const;

	UFUNCTION(BlueprintPure, Category="Pickup")
	int32 GetItemEntryNum() const;

	UFUNCTION(BlueprintPure)
	static float GetMovementCapsuleHalfHeight();

	UFUNCTION(BlueprintPure)
	static float GetMovementCapsuleRadius();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="PlayerInfo")
	AFortPlayerController* GetOwnerPlayerController() const;

	UFUNCTION(BlueprintPure, Category="Pickup")
	AFortPawn* GetPawnWhoDroppedPickup() const;

	UFUNCTION(BlueprintPure)
	AFortPickupEffect* GetPickupEffectBlueprint() const;

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetPickupSkeletalMeshComponent() const;

	UFUNCTION(BlueprintPure)
	UStaticMeshComponent* GetPickupStaticMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="Pickup")
	const UFortItemDefinition* GetPrimaryItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Pickup")
	const FFortItemEntry& GetPrimaryItemEntry() const;

	UFUNCTION(BlueprintPure, Category="Pickup")
	FGuid GetTrackerGuid() const;

	UFUNCTION()
	void HandleConnectedActorDestroyed(AActor* DamageCauser);

	UFUNCTION()
	void HandleConnectedPhysicsActorWake(AActor* PhysicsActor);

	UFUNCTION()
	void HandleMoveIgnoredActorEndPlay(AActor* EndPlayActor, EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintPure)
	bool IsSkeletalMeshComponent() const;

	UFUNCTION(BlueprintCallable)
	void NotifyQuestManager(EFortQuestObjectiveStatEvent StatEvent, const FGameplayTagContainer& EventTags);

	UFUNCTION()
	virtual void OnServerBounceCallback(const FHitResult& Hit, const FVector& OldVelocity);

	UFUNCTION()
	virtual void OnServerStopCallback(const FHitResult& Hit);

	UFUNCTION(BlueprintPure, Category="Pickup")
	bool PickedUp() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetCombinePickupsWhenTossCompletes(const bool CombinePickupsWhenTossCompletes);

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetDespawnTime(float InDespawnTime);

	UFUNCTION(BlueprintCallable)
	void SetDropper(const AFortPlayerController* Dropper);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Pickup")
	void SetOverrideInteractRadius(float NewRadius);

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetPickedUp(const bool bInPickedUp);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Pickup", meta=(OverrideMaxStackCount="0", UnsafeDuringActorConstruction="true"))
	void TossPickup(const FVector FinalLocation, AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss = true, bool bShouldCombinePickupsWhenTossCompletes = true, const EFortPickupSourceTypeFlag InPickupSourceTypeFlags = EFortPickupSourceTypeFlag::Tossed, const EFortPickupSpawnSource InPickupSpawnSource = EFortPickupSpawnSource::Unset);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(WorldContext="WorldContext"))
	void UpdateVolumeToNearestSpatialInterface(FVector InNewLocation, const UObject* WorldContext);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickup")
	bool bUsePickupWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickup")
	bool bSuppressInteractionWidget;

	UPROPERTY(Config)
	bool bWeaponsCanBeAutoPickups;

	UPROPERTY(Config)
	bool bAutoUpgradeWeapons;

	UPROPERTY(Config)
	bool bDoServerHandlePickupTrace;

	UPROPERTY(Config)
	float SimulatingTooLongLength;

	UPROPERTY(Config)
	float SimulatingTooLongLengthInWaterMoving;

	UPROPERTY(Config)
	float SimulatingTooLongLengthInWaterBobbing;

	UPROPERTY(Config)
	float SimulatingTooLongLengthInWaterVelocityThreshold;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnPickup OnPickup;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnPickup OnPickupAttempted;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnDespawn OnPickupDespawned;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnDespawn OnPickupDestroyed;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnCombined OnPickupCombined;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnCombinedOverflow OnPickupCombinedOverflow;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FPickupOnSetPawnWhoDroppedPickup OnSetPawnWhoDroppedPickup;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	bool BlueprintCanInteract(const AFortPlayerPawn* FortPawn, bool& bCanInteractOverride);

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	bool BlueprintGetInteractErrorText(FText& OverrideInteractErrorText);

	UFUNCTION()
	void HandleGiveItemSpawnedPickup(const AFortPlayerController* PlayerController, AFortPickup* Pickup);

	UFUNCTION()
	void OnOwnerEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	virtual void OnRep_bPickedUp();

	UFUNCTION()
	virtual void OnRep_ForceHideMinimapIndicator();

	UFUNCTION()
	virtual void OnRep_PickupLocationData();

	UFUNCTION()
	virtual void OnRep_PickupOwnerData();

	UFUNCTION()
	virtual void OnRep_PrimaryPickupItemEntry();

	UFUNCTION()
	virtual void OnRep_ServerImpactSoundFlash();

	UFUNCTION()
	virtual void OnRep_ServerStoppedSimulation();

	UFUNCTION()
	virtual void OnRep_TossedFromContainer();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PrimaryPickupItemEntry)
	FFortItemEntry PrimaryPickupItemEntry;

	UPROPERTY(Transient, Replicated)
	TArray<FFortItemEntry> MultiItemPickupEntries;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PickupLocationData)
	FFortPickupLocationData PickupLocationData;

	UPROPERTY(Transient)
	EFortPickupSourceTypeFlag PickupSourceTypeFlags;

	UPROPERTY(Transient)
	EFortPickupSpawnSource PickupSpawnSource;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> OwnerInstigator;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PickupOwnerData)
	int16 OptionalOwnerID;

	UPROPERTY(Transient)
	int16 DropperID;

	UPROPERTY(Transient)
	FGuid OptionalMissionGuid;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickup")
	TObjectPtr<UFortItem> PrimaryPickupDummyItem;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPickupEffect> PickupEffectBlueprint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UCapsuleComponent> TouchCapsule;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortPickup", meta=(EditInline="true"))
	TObjectPtr<UFortProjectileMovementComponent> MovementComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWaterInteractionComponent> WaterInteractionComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLinkToActorComponent> LinkToActorComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bPickedUp)
	bool bPickedUp;

	UPROPERTY(Transient)
	bool bSplitOnPickup;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TossedFromContainer)
	bool bTossedFromContainer;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ForceHideMinimapIndicator)
	bool bForceHideMinimapIndicator;

	UPROPERTY(Transient, Replicated)
	bool bCombinePickupsWhenTossCompletes;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerStoppedSimulation)
	bool bServerStoppedSimulation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickup")
	bool bClientUseInterpolationOnly;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerImpactSoundFlash)
	uint8 ServerImpactSoundFlash;

	UPROPERTY(Transient)
	float LastLandedSoundPlayTime;

	UPROPERTY(Transient, Replicated)
	float OverrideInteractAimRadius;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	float LandSoundZForceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float DefaultFlyTime;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	bool bForceDefaultFlyTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> DroppedLoopingSoundComps;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> LandedSoundOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortPickup")
	TWeakObjectPtr<AFortPawn> PawnWhoDroppedPickup;

	UPROPERTY(Transient)
	int32 CachedSpecialActorIdx;

	UPROPERTY(Transient, Replicated)
	FName SpecialActorID;

	UPROPERTY(Transient)
	TObjectPtr<UFortSimpleMiniMapIndicator> MiniMapIndicator;

	UPROPERTY(Transient)
	TObjectPtr<UFortSlateHUDIndicator> HUDLabel;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortPickup")
	bool bRandomRotation;

private:
	UPROPERTY(Transient)
	TScriptInterface<IFortSpatialGameplayInterface> VolumeAtSpawn;

	UPROPERTY()
	float DespawnTime;

	UPROPERTY()
	float StormDespawnTime;

	UPROPERTY(Transient)
	float StartSimulatingTime;

};

UCLASS(MinimalAPI)
class UFortPickupTickSubsystem : public UFortManagedActorTickSubsystem
{
	GENERATED_BODY()

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Perception/AISightTargetInterface.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "Abilities/FortTargetSelectionInterface.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingInfoIndicatorInterface.h"
#include "Building/BuildingSMActor.h"
#include "STW/Items/FortCosmeticModification.h"
#include "BuildingTrap.generated.h"

class AActor;
class ABuildingSMActor;
class AController;
class UAthenaTrapAIPerceptionStimuliSourceComponent;
class UFortAbilitySet;
class UFortAlterationItemDefinition;
class UFortTrapItemDefinition;
class UMaterialInstance;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMesh;
class UStaticMesh;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FBuildingTrapActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrap : public ABuildingSMActor, public IAISightTargetInterface, public IFortTargetSelectionInterface, public IBuildingInfoIndicatorInterface, public IFortMarkableActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Trap")
	void AddDamageComponent(UPrimitiveComponent* DamageComponent);

	UFUNCTION(BlueprintCallable, Category="Trap")
	virtual void AddTriggerComponent(UPrimitiveComponent* TriggerComponent);

	UFUNCTION(BlueprintCallable, Category="Trap")
	virtual void AttemptRetrigger(float Seconds);

	UFUNCTION(BlueprintCallable, Category="Trap")
	virtual void FinishTrigger();

	UFUNCTION(BlueprintCallable)
	void GameplayCue_Abilities_Activation_Traps(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TArray<UFortAlterationItemDefinition*> GetAlterations() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	float GetArmTime();

	UFUNCTION(BlueprintPure, Category="Trap")
	ABuildingSMActor* GetBuildingAttachedTo() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual FVector GetCenter();

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual float GetDamageDelay() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual float GetDurabilityPercent() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual float GetFireDelay() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual float GetMaxDurability() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	float GetReloadTime();

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual TArray<AActor*> GetTouchingDamageTargets(const FFortTargetFilter& Filter) const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual int32 GetTrapLevel() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual int32 GetTrapRating() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	virtual bool HasDurability() const;

	UFUNCTION()
	void OnBlockingBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDestroy();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishedBuilding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModifyTrapIncomingDamage(float Damage, AController* EventInstigator, AActor* DamageCauser, float& OutDamage, bool& bOutConsumeEvent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnOutOfDurability();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlaced();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnReloadBegin();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnReloadEnd();

	UFUNCTION()
	virtual void OnTriggerEndTouch(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void OnTriggerTouch(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void ResetTrapLevel();

	UFUNCTION(BlueprintCallable, Category="Trap")
	void SetAttachedTo(ABuildingSMActor* ActorAttachedTo);

	UFUNCTION(BlueprintCallable, Category="Trap")
	void SpawnedFromItemDefinition(const UFortTrapItemDefinition* ItemDef, int32 InTrapLevel = 1);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintCosmetic, Category="Trap")
	void SwitchToAlternateMaterial();

	UFUNCTION(BlueprintCallable, Category="Targeted")
	bool UseAttachedToWhenTargeted();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Trap", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> TraceLocation;

	UPROPERTY(EditAnywhere, Category="Mesh")
	TObjectPtr<USkeletalMesh> PlacementSkeletalMesh;

	UPROPERTY(EditAnywhere, Category="Mesh")
	FVector PlacementSkeletalMeshRelativeLocation;

	UPROPERTY(EditAnywhere, Category="Mesh")
	FRotator PlacementSkeletalMeshRelativeRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	TObjectPtr<UStaticMesh> TrapRangeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	TObjectPtr<UStaticMesh> TrapPreviewMesh;

	UPROPERTY(EditAnywhere, Category="Mesh")
	FVector PreviewOverrideScale;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, SaveGame, Replicated, Category="BuildingTrap")
	TObjectPtr<UFortTrapItemDefinition> TrapData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	FText AttachmentHintText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trap")
	bool bShouldAffectAllPawnsInMinigames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trap")
	FFortTargetFilter TriggerFilter;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	FVector TrapPlacementOffset;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	bool bTriggerAbilityOnEndoverlap;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TObjectPtr<UFortAbilitySet> AbilitySet;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Trap", meta=(DisplayName="IsValidTarget"))
	bool BP_IsValidTarget(const AActor* PossibleTarget) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Trap", meta=(DisplayName="OnTriggered"))
	void BP_OnTrigger(const TArray<AActor*>& TouchingActors, bool& bOutConsumeEvent);

	UFUNCTION(BlueprintNativeEvent, Category="Trap", meta=(DisplayName="ShouldTrigger"))
	bool BP_ShouldTrigger(const TArray<AActor*>& TouchingActors) const;

	UFUNCTION(BlueprintPure, Category="Trap")
	FGameplayTag GetActivateTrapGameplayCueTag() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	FGameplayTag GetDelayBeginGameplayCueTag() const;

	UFUNCTION(BlueprintNativeEvent, Category="Attachment")
	int32 GetNumberOfRemainingDelayedAttachingAttempts() const;

	UFUNCTION(BlueprintPure, Category="Trap")
	FGameplayTag GetReloadBeginGameplayCueTag() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitAlteration(UFortAlterationItemDefinition* NewAlteration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitCosmeticAlterations(FFortCosmeticModification CosmeticMod);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitTeam();

	UFUNCTION()
	virtual void OnRep_AttachedTo();

	UFUNCTION()
	virtual void OnRep_ReplicatedAppliedAlterations();

	UFUNCTION(BlueprintCallable)
	void OverrideMarkerDisplayInfo(const FMarkedActorDisplayInfo& NewDisplayInfo);

	UFUNCTION()
	void ResetTeamOnMinigameEnd();

	UFUNCTION()
	void SetTeamForMinigameStart();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Trap")
	virtual bool TriggerIfAppropriate();

	UFUNCTION(BlueprintCallable, Category="Trap")
	virtual void TriggerOverlapEnd(AActor* OtherActor);

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_ReplicatedAppliedAlterations)
	TArray<TObjectPtr<UFortAlterationItemDefinition>> AppliedAlterations;

	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> AlterationAbilitySetHandles;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_AttachedTo)
	TObjectPtr<ABuildingSMActor> AttachedTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Targeted")
	bool bTargetWithAttachedTo;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> LastAttachedTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lifespan")
	float DelayBeforeDestroyAfterDurabilityExpired;

	UPROPERTY(SaveGame)
	float SavedDurabilityPct;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	float ObstructedTargetRecheckInterval;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	TArray<FVector> ShouldTriggerTraceOffsets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UPrimitiveComponent>> TriggerComponents;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	bool bIgnoreBuildingObstructions;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	bool bOwnAllFacesOfAttachedToActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trap")
	TObjectPtr<UMaterialInstance> AlternateMaterialInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trap")
	TObjectPtr<UMaterialInstance> UnattachedMaterialInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Trap", meta=(EditInline="true"))
	TObjectPtr<UAthenaTrapAIPerceptionStimuliSourceComponent> StimSourceComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FVector MarkerPositionOffset;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer AnalyticsTags;

private:
	UFUNCTION()
	void OnRep_bTrapRecharging();

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UPrimitiveComponent>> DamageComponents;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> StaticMeshes;

	UPROPERTY(SaveGame, Replicated)
	int32 TrapLevel;

	UPROPERTY(SaveGame, Replicated)
	int32 OriginalTrapLevel;

	UPROPERTY(ReplicatedUsing=OnRep_bTrapRecharging)
	bool bTrapRecharging;

};


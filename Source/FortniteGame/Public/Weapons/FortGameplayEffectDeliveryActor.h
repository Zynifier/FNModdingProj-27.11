// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "GameplayCueInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Types/TargetingSystemTypes.h"
#include "Abilities/FortGameplayEffectContainerSpec.h"
#include "Curie/FortCurieInterface.h"
#include "FortSpawnContext.h"
#include "FortSpawnContextObjectInterface.h"
#include "FortTeamActorInterface.h"
#include "FortGameplayEffectDeliveryActor.generated.h"

class AActor;
class APawn;
class UFortWorldItemDefinition;
class UNavArea;
class UPrimitiveComponent;
class UTargetingPreset;

USTRUCT(BlueprintType)
struct FOverlapRestrictions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="OverlapRestrictions")
	int32 OverlapsPerActor;

	UPROPERTY(EditDefaultsOnly, Category="OverlapRestrictions")
	FGameplayTag OverlapActorTagRestrictions;

};

UCLASS(Abstract, MinimalAPI, HideCategories=("Navigation", "Game|Damage"))
class AFortGameplayEffectDeliveryActor : public AActor, public IFortTeamActorInterface, public IFortSpawnContextObjectInterface, public IGameplayCueInterface, public IFortCurieInterface, public INavRelevantInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Delivery")
	FORTNITEGAME_API void AddAdditionalExplodeEffectContainer(const FFortGameplayEffectContainerSpec& ExplodeContainer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API void ChangeInstigator(APawn* NewInstigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API virtual void DoExplosion();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API virtual void DoExplosionAsync();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API virtual void DoExplosionAtLocation(const FVector& ExplosionLocation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API virtual void DoSingleActorHit(const FHitResult& Hit, const bool bBroadcastHit = true);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Gameplay")
	FORTNITEGAME_API const UFortWorldItemDefinition* GetAssociatedItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Collision")
	FORTNITEGAME_API UPrimitiveComponent* GetCollisionComponent() const;

	UFUNCTION()
	FORTNITEGAME_API void HandleMoveIgnoredActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintPure, Category="Delivery")
	FORTNITEGAME_API virtual bool IsBeingKilled() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Delivery")
	FORTNITEGAME_API virtual void Kill();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnDisableForKill();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnExploded(const TArray<AActor*>& HitActors, const TArray<FHitResult>& HitResults);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnTouched(AActor* OtherActor, UPrimitiveComponent* OtherComp, const FHitResult& HitResult, bool bIsOverlap);

	UFUNCTION(BlueprintCallable, Category="Collision")
	FORTNITEGAME_API void SetCollisionComponent(UPrimitiveComponent* NewCollisionComponent);

	UFUNCTION(BlueprintCallable, Category="Collision")
	FORTNITEGAME_API void SetIgnoreInstigatorCollision(bool bShouldIgnore);

	UFUNCTION(BlueprintCallable, Category="Delivery")
	FORTNITEGAME_API void SetNoiseMakingInstigatorOverride(AActor* NewActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Delivery")
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnTouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Delivery")
	bool bKillOnExplode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Delivery")
	bool bSetHiddenOnKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Delivery")
	bool bKillOnMaxTargetsTouched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Delivery")
	bool bSkipRecaptureSourceActorTagsOnTouch;

	UPROPERTY(BlueprintReadOnly, Category="Delivery")
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode;

	UPROPERTY(BlueprintReadOnly, Category="Delivery")
	TArray<FFortGameplayEffectContainerSpec> AdditionalExplodeEffectContainers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Delivery")
	float LifespanAfterKill;

	UPROPERTY(EditAnywhere, Category="Delivery", meta=(ClampMin="0.0", UIMin="0.0"))
	float TouchingActorsEffectApplicationUpdateTime;

protected:
	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void BroadcastExplosion(const TArray<AActor*>& HitActors, const TArray<FHitResult>& HitResults);

	UFUNCTION()
	FORTNITEGAME_API virtual void KillTimerExpired();

	UFUNCTION(BlueprintNativeEvent, Category="Gameplay")
	FORTNITEGAME_API void OnAssociatedItemDefinitionSet(const UFortWorldItemDefinition* NewAssociatedWID);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnComponentTouch(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_HasExplodedReplay();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_IsBeingKilled(bool bPreviousValue);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delivery")
	TArray<FOverlapRestrictions> OverlapRestrictions;

	UPROPERTY(ReplicatedUsing=OnRep_IsBeingKilled)
	uint8 bIsBeingKilled : 1;

	UPROPERTY(ReplicatedUsing=OnRep_HasExplodedReplay)
	uint8 bHasExploded : 1;

	UPROPERTY(EditDefaultsOnly, Category="Perf")
	uint8 bNeedsHitTargetsOnExplode : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision")
	uint8 bIgnoreInstigatorCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision")
	uint8 bIgnoreVehicleAndAttachedActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="Performance")
	uint8 bDisableClientOverlapEvents : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bAddHitResultToTouchApplication : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bExplosionTransformIgnoresRotation : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bCanExplodeMultipleTimes : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bRegisterForEndOverlaps : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bSpawnNavAreaModifierOverTargetSelectionShape : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(EditCondition="bSpawnNavAreaModifierOverTargetSelectionShape"))
	TSubclassOf<UNavArea> NavAreaClass;

	UPROPERTY(EditDefaultsOnly, Category="CurieIdentification", meta=(Categories="Curie.Element,Curie.Material"))
	FGameplayTag CurieIdentifier;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> CollisionComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItemDefinition> AssociatedItemDef;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="SpawnContext")
	FFortSpawnContext SpawnContext;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayEffectDeliveryActor")
	TObjectPtr<UTargetingPreset> AsyncExplosionTargetingPreset;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer AnalyticsTags;

private:
	UPROPERTY(Transient)
	uint8 bDoExplosionReentrancyGuard : 1;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> InstigatorActorsAdded;

	UPROPERTY(Transient)
	FTargetingRequestHandle AsyncExplosionTargetingHandle;

};


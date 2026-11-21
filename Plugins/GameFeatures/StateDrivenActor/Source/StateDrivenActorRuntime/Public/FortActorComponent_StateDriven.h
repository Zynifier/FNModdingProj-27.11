// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayCueInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Components/FortActorComponent_FortInteractExtension.h"
#include "FortInteractInterface.h"
#include "Items/FortItemEntry.h"
#include "StateDrivenActorTypes.h"
#include "FortActorComponent_StateDriven.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortPawn;
class UPrimitiveComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortActorComponent_StateDriven : public UFortActorComponent_FortInteractExtension
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Interaction")
	FText GetFailedInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted = FirstInteraction) const;

	UFUNCTION(BlueprintPure, Category="Interaction")
	FText GetInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted = FirstInteraction) const;

	UFUNCTION(BlueprintPure)
	FText GetSlottedItemDisplayName() const;

	UFUNCTION(BlueprintPure)
	const FFortItemEntry& GetSlottedItemEntry() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHandleStateTreeEvent(const FGameplayTag TransitionTag, const FGameplayCueTag BurstGameplayCueTag);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnMulticastStateTreeEvent(const FGameplayTag TransitionTag, const FGameplayCueTag BurstGameplayCueTag);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void PlayBurstGameplayCue(const FGameplayTag GameplayCueTag) const;

	UFUNCTION(BlueprintCallable)
	void PopSlottedItem();

	UFUNCTION(BlueprintCallable)
	void SetCurrentState(const FStateDrivenState& InCurrentState);

	UFUNCTION(BlueprintCallable)
	void TriggerCustomEvent(const FGameplayTag& EventTag);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnResetCollisionSettings();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupDamageEventSettings();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupInteractionEventSettings();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupOverlapEventSettings();

	UPROPERTY(BlueprintReadOnly, Category="FortActorComponent_StateDriven")
	float OverlapRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActorComponent_StateDriven")
	FVector SlottedItemPopOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortActorComponent_StateDriven")
	TArray<FGameplayTagQuery> VariableTagQueries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortActorComponent_StateDriven")
	TArray<float> VariableFloats;

private:
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void HandleInteraction(ABuildingActor* SelfActor, AFortPawn* InteractingPawn);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActorComponent_StateDriven", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UStaticMeshComponent> MeshComponentPtr;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActorComponent_StateDriven", meta=(AllowPrivateAccess))
	TWeakObjectPtr<USphereComponent> OverlapComponentPtr;

	UPROPERTY(Transient, Replicated)
	FFortItemEntry SlottedItemEntry;

};


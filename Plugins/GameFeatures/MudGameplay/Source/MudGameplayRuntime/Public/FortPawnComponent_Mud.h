// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "GameplayTagContainer.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_Mud.generated.h"

class AActor;
class AFortPlayerPawn;
class UFortAbilitySystemComponent;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class MUDGAMEPLAYRUNTIME_API UFortPawnComponent_Mud : public UFortPawnComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAttachedParentCoveredInMud(const FGameplayEventData& Payload);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreatureSprintingTagCountChanged(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurieFireTagCountChanged(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnteredMud();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitedMud();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSlidingTagCountChanged(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSprintingTagCountChanged(const FGameplayTag Tag, int32 NewCount);

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTag CurieFireTag;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTag SlidingTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tags")
	FGameplayTag SprintingTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tags")
	FGameplayTag AttachParentCoveredEventTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tags|Wildlife")
	FGameplayTag CreatureSprintingTag;

private:
	UFUNCTION()
	void HandleASCInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* AffectedPawn);

	UFUNCTION()
	void HandleSurfaceTypeChanged(AActor* SurfaceActor, EPhysicalSurface CurrentSurfaceType, EPhysicalSurface PrevSurfaceType);

};


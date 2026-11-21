// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "FortGameplayEffectVolumeComponent.generated.h"

class AActor;
class UGameplayAbility;
class UGameplayEffect;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameplayEffectVolumeComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApplyWhileOverlapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> AbilitiesToGrantWhileOverlapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<FGameplayTag> LooseTagsToApplyWhileOverlapping;

protected:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};


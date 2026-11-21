// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayAbilitySpecHandle.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortPlayerStateComponent_EventGameplayAbilityManager.generated.h"

class APawn;

USTRUCT()
struct FGameplayAbilityEventKeyArrayAndHandle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> EventKeys;

	UPROPERTY()
	FGameplayAbilitySpecHandle SpecHandle;

};

USTRUCT()
struct FGameplayEffectEventKeyArrayAndHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	FActiveGameplayEffectHandle EffectHandle;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	float Level;

	UPROPERTY()
	TArray<FName> EventKeys;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_EventGameplayAbilityManager : public UFortPlayerStateComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnChanged(APawn* NewPawn);

};


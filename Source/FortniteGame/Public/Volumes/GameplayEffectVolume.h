// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "GameplayEffectVolume.generated.h"

class AActor;
class UGameplayEffect;

UCLASS(HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AGameplayEffectVolume : public APhysicsVolume
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ApplyGameplayEffect(AActor* Actor);

	UFUNCTION()
	void RemoveGameplayEffect(AActor* Actor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectVolume")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectVolume")
	int32 GameplayEffectLevel;

};


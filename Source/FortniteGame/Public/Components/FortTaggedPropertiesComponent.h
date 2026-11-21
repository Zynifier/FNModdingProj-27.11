// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "FortTaggedPropertiesComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortTaggedPropertiesComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortTaggedPropertiesComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="FortTaggedPropertiesComponent")
	TMap<FGameplayTag, FGameplayTagQuery> TagQueries;

};


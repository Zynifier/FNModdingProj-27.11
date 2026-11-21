// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortSquadStart.generated.h"

class USceneComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Replication", "Rendering", "Collision", "Actor", "Input", "LOD", "Cooking"))
class AFortSquadStart : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortSquadStart")
	FTransform GetPlayerStartTransform(const int32 Index = 0) const;

	UFUNCTION(BlueprintPure, Category="FortSquadStart")
	const FGameplayTagContainer& GetSquadStartGameplayTags() const;

protected:
	UPROPERTY(EditDefaultsOnly, Export, Category="FortSquadStart", meta=(EditInline="true"))
	TArray<TObjectPtr<USceneComponent>> PlayerStarts;

	UPROPERTY(EditAnywhere, Category="FortSquadStart")
	FGameplayTagContainer GameplayTags;

};


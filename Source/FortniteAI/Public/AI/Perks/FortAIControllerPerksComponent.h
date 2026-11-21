// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortAIControllerPerksComponent.generated.h"

class UFortAIPerkBase;

USTRUCT()
struct FWeightedAIPerk
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeightedAIPerk")
	TSubclassOf<UFortAIPerkBase> PerkClass;

	UPROPERTY(EditAnywhere, Category="WeightedAIPerk")
	FScalableFloat RandomWeight;

};

USTRUCT()
struct FPerkAvailabilityContainer
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PerkAvailabilityContainer")
	FString Description;
#endif

	UPROPERTY(EditAnywhere, Category="PerkAvailabilityContainer")
	TArray<FWeightedAIPerk> AvailablePerks;

	UPROPERTY(EditAnywhere, Category="PerkAvailabilityContainer")
	int32 DesiredPerkCount;

};

UCLASS(MinimalAPI, HideCategories=("ComponentTick", "ComponentReplication", "Tags", "Activation", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"))
class UFortAIControllerPerksComponent : public UFortControllerComponent
{
	GENERATED_BODY()

};


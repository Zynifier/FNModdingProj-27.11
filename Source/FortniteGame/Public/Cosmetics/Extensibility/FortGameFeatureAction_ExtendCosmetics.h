// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureAction_InterfaceWithGameInstanceSubsystem.h"
#include "FortGameFeatureAction_ExtendCosmetics.generated.h"

class UFortCosmeticStep;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortGameFeatureAction_ExtendCosmetics : public UFortGameFeatureAction_InterfaceWithGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_ExtendCosmetics")
	TArray<TSoftClassPtr<UFortCosmeticStep>> Extensions;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureAction_InterfaceWithGameInstanceSubsystem.h"
#include "FortGameFeatureAction_RegisterCosmeticStat.generated.h"

class UFortCosmeticStatObject;

UCLASS(MinimalAPI, meta=(DisplayName="Register Cosmetic Stat"))
class UFortGameFeatureAction_RegisterCosmeticStat : public UFortGameFeatureAction_InterfaceWithGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_RegisterCosmeticStat")
	TArray<TSoftClassPtr<UFortCosmeticStatObject>> CosmeticStatObjects;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticExtensibilityTypes.h"
#include "GameFeatures/FortGameFeatureAction_InterfaceWithGameInstanceSubsystem.h"
#include "FortGameFeatureAction_AddCosmeticOptions.generated.h"

class UFortCosmeticFlowOption;

USTRUCT()
struct FCosmeticKeyOptionsPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CosmeticKeyOptionsPair")
	FCosmeticFlowOptionSetKey Key;

	UPROPERTY(EditDefaultsOnly, Category="CosmeticKeyOptionsPair")
	TArray<TSoftClassPtr<UFortCosmeticFlowOption>> Options;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortGameFeatureAction_AddCosmeticOptions : public UFortGameFeatureAction_InterfaceWithGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddCosmeticOptions")
	TArray<FCosmeticKeyOptionsPair> KeyOptionsPairs;

};


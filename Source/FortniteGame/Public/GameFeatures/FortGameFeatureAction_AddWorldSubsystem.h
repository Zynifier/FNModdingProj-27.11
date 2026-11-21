// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddWorldSubsystem.generated.h"

class UWorldSubsystem;

UCLASS(MinimalAPI, meta=(DisplayName="Add World Subsystem"))
class UFortGameFeatureAction_AddWorldSubsystem : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_AddWorldSubsystem", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UWorldSubsystem> SubsystemToAdd;

};


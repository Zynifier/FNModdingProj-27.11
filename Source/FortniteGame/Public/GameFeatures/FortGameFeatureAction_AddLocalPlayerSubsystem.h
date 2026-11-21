// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddLocalPlayerSubsystem.generated.h"

class UFortLocalPlayerSubsystem;

UCLASS(MinimalAPI, meta=(DisplayName="Add Local Player Subsystem"))
class UFortGameFeatureAction_AddLocalPlayerSubsystem : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_AddLocalPlayerSubsystem", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortLocalPlayerSubsystem> SubsystemToAdd;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureAction_InterfaceWithGameInstanceSubsystem.h"
#include "FortGameFeatureAction_RequestExtensibility.generated.h"

UCLASS()
class UFortGameFeatureAction_RequestExtensibility : public UFortGameFeatureAction_InterfaceWithGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_RequestExtensibility")
	FString RequestReason;

};


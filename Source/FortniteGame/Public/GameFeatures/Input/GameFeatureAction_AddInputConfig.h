// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddInputConfig.generated.h"

class UInputTypeConfiguration;

UCLASS(MinimalAPI)
class UGameFeatureAction_AddInputConfig : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameFeatureAction_AddInputConfig")
	TArray<TObjectPtr<UInputTypeConfiguration>> InputConfigs;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddToFrontEnd.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Plugin To Front End"))
class UFortGameFeatureAction_AddToFrontEnd : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Front End")
	FName PluginName;

	UPROPERTY(EditAnywhere, Category="Front End")
	bool bShouldUnloadWhenDeactivating;

};


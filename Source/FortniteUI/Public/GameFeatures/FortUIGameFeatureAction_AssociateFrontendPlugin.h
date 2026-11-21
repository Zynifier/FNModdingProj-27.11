// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AssociateFrontendPlugin.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Associate Frontend Plugin"))
class UFortUIGameFeatureAction_AssociateFrontendPlugin : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AssociateFrontendPlugin")
	FString PluginName;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AssociateFrontendPlugin")
	TArray<FString> AssociatedMnemonics;

};


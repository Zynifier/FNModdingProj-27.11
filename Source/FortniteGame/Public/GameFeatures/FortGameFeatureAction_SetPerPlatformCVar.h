// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_SetPerPlatformCVar.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Set Per Platform CVar"))
class UGameFeatureAction_SetPerPlatformCVar : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameFeatureAction_SetPerPlatformCVar")
	FString VariableName;

	UPROPERTY(EditAnywhere, Category="GameFeatureAction_SetPerPlatformCVar", meta=(AssetBundles="Client"))
	bool bEnableDefaultValue;

	UPROPERTY(EditAnywhere, Category="GameFeatureAction_SetPerPlatformCVar", meta=(AssetBundles="Client", EditCondition="bEnableDefaultValue"))
	FString DefaultValue;

	UPROPERTY(EditAnywhere, Category="GameFeatureAction_SetPerPlatformCVar", meta=(AssetBundles="Client"))
	TMap<FString, FString> PerPlatformValues;

};


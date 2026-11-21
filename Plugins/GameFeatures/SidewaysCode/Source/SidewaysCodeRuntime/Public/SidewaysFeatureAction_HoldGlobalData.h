// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "SidewaysFeatureAction_HoldGlobalData.generated.h"

class UMaterialParameterCollection;

UCLASS(meta=(DisplayName="Sideways Global Data"))
class USidewaysFeatureAction_HoldGlobalData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Sideways", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialParameterCollection> SidewaysMaterialParameterCollection;

	UPROPERTY(EditDefaultsOnly, Category="Sideways")
	FName SidewaysBubbleLocationParameterNamesForLocalPlayers[2];

	UPROPERTY(EditDefaultsOnly, Category="Sideways")
	FName SidewaysBubbleRadiusParameterNamesForLocalPlayers[2];

};


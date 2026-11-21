// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_SetAdditionalDeviceProfileSuffix.generated.h"

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Set Additional Device Profile Suffix"))
class UFortGameFeatureAction_SetAdditionalDeviceProfileSuffix : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString DeviceProfileSuffix;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "FortGameFeatureAction_SetAccountItemDefinitionOverrideManager.generated.h"

class UObject;

UCLASS(MinimalAPI, meta=(DisplayName="Set Account Item Definition Override Manager"))
class UFortGameFeatureAction_SetAccountItemDefinitionOverrideManager : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_SetAccountItemDefinitionOverrideManager")
	FGameplayTag PlaylistTag;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_SetAccountItemDefinitionOverrideManager", meta=(MustImplement="/Script/FortniteGame.FortAccountItemDefinitionOverrideManagerInterface"))
	TSubclassOf<UObject> AccountItemDefinitionOverrideManagerClass;

};


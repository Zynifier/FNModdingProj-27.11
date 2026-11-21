// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Online/FortReplicationGraph.h"
#include "FortGameFeatureAction_UpdateGlobalRepGraphActorClassSettings.generated.h"

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Update Global RepGraph Actor Class Settings"))
class UFortGameFeatureAction_UpdateGlobalRepGraphActorClassSettings : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Class Settings")
	TArray<FRepGraphActorClassSettings> NewClassSettings;

	UPROPERTY(Config)
	bool bApplyNewSettings;

};


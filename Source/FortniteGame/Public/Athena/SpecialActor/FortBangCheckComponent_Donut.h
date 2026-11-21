// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SpecialActor/FortEventLevelNavigationBangCheckComponent.h"
#include "FortBangCheckComponent_Donut.generated.h"

class UFortChallengeBundleItemDefinition;

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortBangCheckComponent_Donut : public UFortEventLevelNavigationBangCheckComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortBangCheckComponent_Donut")
	TArray<TObjectPtr<UFortChallengeBundleItemDefinition>> DonutBundles;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SpecialActor/FortEventLevelNavigationBangCheckComponent.h"
#include "FortBangCheckComponent_Customization.generated.h"

class UAthenaRewardEventGraph;

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortBangCheckComponent_Customization : public UFortEventLevelNavigationBangCheckComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Category="FortBangCheckComponent_Customization")
	TObjectPtr<UAthenaRewardEventGraph> CustomizationRewardGraph;

};


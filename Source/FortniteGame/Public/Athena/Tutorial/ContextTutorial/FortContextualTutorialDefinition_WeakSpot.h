// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_WeakSpot.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_WeakSpot : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeakSpot")
	int32 NumerOfWeakSpotHitRequired;

};


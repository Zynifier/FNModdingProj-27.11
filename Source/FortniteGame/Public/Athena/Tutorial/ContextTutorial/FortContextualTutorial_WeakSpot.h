// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_WeakSpot.generated.h"

UCLASS()
class UFortContextualTutorial_WeakSpot : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	int32 NumberOfWeakSpotHit;

};


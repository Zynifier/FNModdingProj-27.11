// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayTagVolumeInterface.generated.h"

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortGameplayTagVolumeInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortGameplayTagVolumeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void ApplyTags();

};


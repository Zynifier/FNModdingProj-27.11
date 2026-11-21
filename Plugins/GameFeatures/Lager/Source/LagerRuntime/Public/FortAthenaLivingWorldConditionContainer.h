// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaLivingWorldConditionContainer.generated.h"

class UObject;

USTRUCT()
struct FFortAthenaLivingWorldConditionContainer
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> Owner;

};


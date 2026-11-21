// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSettingValueDiscrete.h"
#include "FortSettingValueDiscreteSupervised.generated.h"

UCLASS(MinimalAPI)
class UFortSettingValueDiscreteSupervised : public UFortSettingValueDiscrete
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortSettingValueDiscreteContentRatingSupervised : public UFortSettingValueDiscreteSupervised
{
	GENERATED_BODY()

};


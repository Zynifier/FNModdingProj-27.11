// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/FortPlayerInput.h"
#include "FortPlayerInputAthena.generated.h"

class UFortGamepadSettings;

UCLASS()
class UFortPlayerInputAthena : public UFortPlayerInput
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortGamepadSettings> GamepadSettings;

};


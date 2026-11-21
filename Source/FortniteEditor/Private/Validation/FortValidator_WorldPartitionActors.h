// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_WorldPartitionActors.generated.h"

UCLASS(Config=Editor)
class UFortValidator_WorldPartitionActors : public UFortEditorValidator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	bool bEnabled;

};


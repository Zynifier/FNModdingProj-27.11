// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseFortniteBRTeamCollection.generated.h"

UCLASS(Abstract)
class UVerseFortniteBRTeamCollection : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnActiveTeamArrayBuilt();

};


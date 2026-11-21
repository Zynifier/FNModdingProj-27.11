// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaCustomTimeDilationManager.generated.h"

class UCurveFloat;

UCLASS()
class UFortAthenaCustomTimeDilationManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UCurveFloat> TimeDilationCurve;

};


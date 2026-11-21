// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPoiTracker.generated.h"

class AFortPawn;

UCLASS()
class UFortPoiTracker : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleEndSkydiving();

	UFUNCTION()
	void HandlePawnChanged(AFortPawn* NewPawn);

};


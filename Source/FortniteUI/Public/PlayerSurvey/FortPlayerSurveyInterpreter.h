// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlayerSurveyInterpreter.generated.h"

class UCMSContext;
class UFortPlayerSurveyCMSTracker;

UCLASS()
class UFortPlayerSurveyInterpreter : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UCMSContext> CMSContext;

	UPROPERTY()
	TObjectPtr<UFortPlayerSurveyCMSTracker> CMSTracker;

};


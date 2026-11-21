// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMatchAnalytics.h"
#include "FortMatchClientAnalytics.generated.h"

class AController;

UCLASS()
class UFortMatchClientAnalytics : public UFortMatchAnalytics
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnEnterAircraft(AController* InController);

	UFUNCTION()
	void OnExitAircraft(AController* InController);

};


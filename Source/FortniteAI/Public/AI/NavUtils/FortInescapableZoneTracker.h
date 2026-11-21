// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortInescapableZoneTracker.generated.h"

class AFortNavigationGraph;

UCLASS()
class UFortInescapableZoneTracker : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortNavigationGraph> NavGraph;

};


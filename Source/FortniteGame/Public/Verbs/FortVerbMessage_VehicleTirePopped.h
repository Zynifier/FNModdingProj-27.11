// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_VehicleBase.h"
#include "FortVerbMessage_VehicleTirePopped.generated.h"

USTRUCT()
struct FFortVerbMessage_VehicleTirePopped : public FFortVerbMessage_VehicleBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleTirePopped")
	bool bAllTiresPopped;

};


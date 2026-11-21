// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_VehicleBase.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_VehicleMod.generated.h"

USTRUCT()
struct FFortVerbMessage_VehicleMod : public FFortVerbMessage_VehicleBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleMod")
	FSubjectTagsPair VehicleMod;

};


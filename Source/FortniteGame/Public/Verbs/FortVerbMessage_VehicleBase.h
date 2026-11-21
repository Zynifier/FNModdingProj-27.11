// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/Helpers/FortVerbHelper.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_VehicleBase.generated.h"

USTRUCT()
struct FFortVerbMessage_VehicleBase : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleBase")
	FSubjectTagsPair Vehicle;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleBase")
	FSubjectTagsPair Driver;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleBase")
	TArray<FFortVerb_ObjectWrapper> Passengers;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleBase")
	float VehicleHealthPercent;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehicleBase")
	float VehicleFuelPercent;

};


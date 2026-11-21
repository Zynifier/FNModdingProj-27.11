// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_VehicleBase.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_VehiclePartDisabled.generated.h"

USTRUCT()
struct FFortVerbMessage_VehiclePartDisabled : public FFortVerbMessage_VehicleBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehiclePartDisabled")
	FSubjectTagsPair VehiclePart;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehiclePartDisabled")
	float DamageDone;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_VehiclePartDisabled")
	bool bWasCriticalHit;

};


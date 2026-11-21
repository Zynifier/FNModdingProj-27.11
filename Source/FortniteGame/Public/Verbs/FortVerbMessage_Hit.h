// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDamageZoneEnum.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Hit.generated.h"

USTRUCT()
struct FFortVerbMessage_Hit : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Hit")
	double Distance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Hit")
	FSubjectTagsPair DamageSource;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Hit")
	FSubjectTagsPair DamagedActor;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Hit")
	FSubjectTagsPair DamageType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Hit")
	TEnumAsByte<EFortDamageZone::Type> DamageZone;

};


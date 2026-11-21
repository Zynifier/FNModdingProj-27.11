// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDamageZoneEnum.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_DamageDone.generated.h"

USTRUCT()
struct FFortVerbMessage_DamageDone : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	int32 Damage;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	int32 UncappedDamage;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	double Distance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	FSubjectTagsPair DamageSource;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	FSubjectTagsPair DamagedActor;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	FSubjectTagsPair DamageType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageDone")
	TEnumAsByte<EFortDamageZone::Type> DamageZone;

};


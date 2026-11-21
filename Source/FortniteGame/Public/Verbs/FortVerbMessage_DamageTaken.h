// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_DamageTaken.generated.h"

USTRUCT()
struct FFortVerbMessage_DamageTaken : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageTaken")
	int32 Damage;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageTaken")
	double Distance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageTaken")
	FSubjectTagsPair DamageSource;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DamageTaken")
	FSubjectTagsPair DamageType;

};


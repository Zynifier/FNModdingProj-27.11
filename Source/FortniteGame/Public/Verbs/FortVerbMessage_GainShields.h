// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_GainShields.generated.h"

USTRUCT()
struct FFortVerbMessage_GainShields : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	FSubjectTagsPair ShieldGainSource;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	FSubjectTagsPair ShieldGainType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	bool bGainedFullShields;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	bool bGainedShieldsFromTeammate;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	float AmountOfShieldsGained;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	float ShieldsGainedOverFullAmount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_GainShields")
	float ShieldPercentGained;

};


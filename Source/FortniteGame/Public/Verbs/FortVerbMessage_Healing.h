// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Healing.generated.h"

USTRUCT()
struct FFortVerbMessage_Healing : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Healing")
	FSubjectTagsPair HealingType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Healing")
	bool bHealedToFull;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Healing")
	float AmountHealedToHealth;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Healing")
	float HealthOverHealingAmount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Healing")
	float PercentHealed;

};


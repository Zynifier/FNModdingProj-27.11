// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Repair.generated.h"

USTRUCT()
struct FFortVerbMessage_Repair : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Repair")
	FSubjectTagsPair ActorRepaired;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Repair")
	FSubjectTagsPair RepairType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Repair")
	bool bFullyRepaired;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Repair")
	float AmountRepaired;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Repair")
	float PercentRepaired;

};


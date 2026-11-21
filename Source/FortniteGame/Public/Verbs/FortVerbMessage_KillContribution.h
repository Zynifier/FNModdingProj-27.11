// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_KillContribution.generated.h"

USTRUCT()
struct FFortVerbMessage_KillContribution : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillContribution")
	bool bAuthorIsKiller;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillContribution")
	FSubjectTagsPair KilledActor;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillContribution")
	FSubjectTagsPair KillerTags;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillContribution")
	int32 DamageDoneToPawn;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_KillContribution")
	float PercentOfTotalDamageDone;

};


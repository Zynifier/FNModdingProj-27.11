// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_Healing.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_HealingDone.generated.h"

USTRUCT()
struct FFortVerbMessage_HealingDone : public FFortVerbMessage_Healing
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_HealingDone")
	bool bHealedTeammate;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_HealingDone")
	FSubjectTagsPair SubjectHealed;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_Healing.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_HealingReceived.generated.h"

USTRUCT()
struct FFortVerbMessage_HealingReceived : public FFortVerbMessage_Healing
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_HealingReceived")
	bool bHealedByTeammate;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_HealingReceived")
	FSubjectTagsPair HealSource;

};


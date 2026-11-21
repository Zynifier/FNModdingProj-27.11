// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortDeathTypes.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PawnDied.generated.h"

USTRUCT()
struct FFortVerbMessage_PawnDied : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnDied")
	FSubjectTagsPair DeathTags;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PawnDied")
	FDeathInfo DeathInfo;

};


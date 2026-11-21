// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_RevivedFromDBNO.generated.h"

USTRUCT()
struct FFortVerbMessage_RevivedFromDBNO : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_RevivedFromDBNO")
	FSubjectTagsPair RevivingPlayer;

};


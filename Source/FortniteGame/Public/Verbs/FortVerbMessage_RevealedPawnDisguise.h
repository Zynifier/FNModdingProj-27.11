// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_RevealedPawnDisguise.generated.h"

USTRUCT()
struct FFortVerbMessage_RevealedPawnDisguise : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_RevealedPawnDisguise")
	FSubjectTagsPair RevealedPawn;

};


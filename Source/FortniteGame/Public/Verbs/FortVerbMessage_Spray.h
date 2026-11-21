// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Spray.generated.h"

USTRUCT()
struct FFortVerbMessage_Spray : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Spray")
	FSubjectTagsPair Spray;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Spray")
	FSubjectTagsPair Target;

};


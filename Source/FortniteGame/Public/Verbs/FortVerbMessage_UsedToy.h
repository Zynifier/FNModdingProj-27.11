// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_UsedToy.generated.h"

USTRUCT()
struct FFortVerbMessage_UsedToy : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_UsedToy")
	FSubjectTagsPair Toy;

};


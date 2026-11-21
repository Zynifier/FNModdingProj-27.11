// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_AugmentSelected.generated.h"

USTRUCT()
struct FFortVerbMessage_AugmentSelected : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AugmentSelected")
	FSubjectTagsPair Augment;

};


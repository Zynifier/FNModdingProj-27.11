// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_AugmentsRerolled.generated.h"

UENUM()
enum class EAugmentReRollType : uint8
{
	Any = 0,
	Free = 1,
	SpentBars = 2,
};

USTRUCT()
struct FFortVerbMessage_AugmentsRerolled : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_AugmentsRerolled")
	EAugmentReRollType ReRollType;

};


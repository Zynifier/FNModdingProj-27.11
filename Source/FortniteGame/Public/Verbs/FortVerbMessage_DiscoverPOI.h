// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_DiscoverPOI.generated.h"

USTRUCT()
struct FFortVerbMessage_DiscoverPOI : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DiscoverPOI")
	FSubjectTagsPair POI;

};


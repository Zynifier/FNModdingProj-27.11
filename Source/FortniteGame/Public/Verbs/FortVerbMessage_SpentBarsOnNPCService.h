// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_SpentBarsOnNPCService.generated.h"

USTRUCT()
struct FFortVerbMessage_SpentBarsOnNPCService : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SpentBarsOnNPCService")
	FSubjectTagsPair NPC;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SpentBarsOnNPCService")
	int32 BarsSpent;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_SpentBarsOnNPCService")
	FGameplayTagContainer ServiceProviderTags;

};


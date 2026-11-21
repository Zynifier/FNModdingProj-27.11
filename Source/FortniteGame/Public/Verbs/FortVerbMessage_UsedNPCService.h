// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_UsedNPCService.generated.h"

USTRUCT()
struct FFortVerbMessage_UsedNPCService : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_UsedNPCService")
	FSubjectTagsPair NPC;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_UsedNPCService")
	FGameplayTagContainer ServiceType;

};


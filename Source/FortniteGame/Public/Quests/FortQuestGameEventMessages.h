// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortQuestGameEventMessages.generated.h"

class UFortQuestItemDefinition_Athena;

USTRUCT()
struct FFortPinQuest_CompletedQuest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition_Athena> CompletedQuest;

};


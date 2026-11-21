// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "LocalizableMessageParameterAgent.generated.h"

class APawn;

USTRUCT()
struct FLocalizableMessageParameterAgent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl Value;

	UPROPERTY()
	APawn* AgentPawn;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/IQuestInstanceManagerInterface.h"
#include "IFortQuestInstanceManagerInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortQuestInstanceManagerInterface : public UQuestInstanceManagerInterface
{
	GENERATED_BODY()
};

class IFortQuestInstanceManagerInterface : public IQuestInstanceManagerInterface
{
	GENERATED_BODY()

};


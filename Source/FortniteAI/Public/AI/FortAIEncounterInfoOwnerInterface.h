// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIEncounterInfoOwnerInterface.generated.h"

class UFortAIEncounterInfo;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAIEncounterInfoOwnerInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEAI_API IFortAIEncounterInfoOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Encounter")
	virtual UFortAIEncounterInfo* GetEncounterInfo() const;

};


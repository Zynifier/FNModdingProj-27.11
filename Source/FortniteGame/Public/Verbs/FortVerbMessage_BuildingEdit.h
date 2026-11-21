// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_BuildingEdit.generated.h"

USTRUCT()
struct FFortVerbMessage_BuildingEdit : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_BuildingEdit")
	int32 CurrentBuildingLevel;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_BuildingEdit")
	FSubjectTagsPair Building;

};


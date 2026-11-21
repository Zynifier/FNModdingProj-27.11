// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_DestroyBuilding.generated.h"

USTRUCT()
struct FFortVerbMessage_DestroyBuilding : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DestroyBuilding")
	FSubjectTagsPair DestroyedBuilding;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DestroyBuilding")
	FSubjectTagsPair DamageSource;

};


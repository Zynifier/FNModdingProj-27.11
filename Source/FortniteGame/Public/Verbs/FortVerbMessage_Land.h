// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Land.generated.h"

USTRUCT()
struct FFortVerbMessage_Land : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Land", meta=(DisplayName="Surface Type"))
	TEnumAsByte<EPhysicalSurface> AllowedSurfaces;

};


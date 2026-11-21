// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScriptedObjectMovementUtilities.generated.h"

USTRUCT()
struct FScriptedObjectMovementCalendarEventData
{
	GENERATED_BODY()

};

USTRUCT()
struct FScriptedObjectMovement_StaticPathCalendarCheatDefinitionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPathCalendarCheatDefinitionData")
	FString EventName;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPathCalendarCheatDefinitionData", meta=(ClampMin="0.000000"))
	float DurationTimeSeconds;

	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_StaticPathCalendarCheatDefinitionData", meta=(ClampMin="0.000000"))
	float DelayStartTimeSeconds;

};

UCLASS(BlueprintType, Blueprintable)
class UScriptedObjectMovement_CalendarCheatDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ScriptedObjectMovement_CalendarCheatDefinition")
	TArray<FScriptedObjectMovement_StaticPathCalendarCheatDefinitionData> CheatCalendarEvents;

};


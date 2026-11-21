// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaAITargetHandler.generated.h"

class AActor;
class ABuildingActor;

USTRUCT()
struct FBotDelayedStimulus
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> SourceActor;

};

USTRUCT()
struct FBotPerceivedSound
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> SourceActor;

};

USTRUCT()
struct FFortBotTargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> SourceActor;

	UPROPERTY(Transient)
	TObjectPtr<AActor> SupportingActor;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> AlternateTargetingActor;

};

USTRUCT()
struct FFortBotTargetHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortBotTargetInfo> Targets;

};

USTRUCT()
struct FFortBotThreatActorInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AActor> ThreatActor;

};


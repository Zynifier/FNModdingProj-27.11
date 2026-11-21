// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "FortAutomationRpcManager.generated.h"

class AActor;

UENUM()
enum class EFortRpcCategory : uint8
{
	/* Gathering information on the status of any actors.*/
	ActorInfo = 0,
	/* Anything involving friends or parties or stuff like that*/
	SocialActions = 1,
	/* Mostly input mapping stuff etc, shooting, building, moving*/
	GameplayActions = 2,
	/* Item Grants, setting health/shield, teleporting, anything that requires the cheat system to be enabled */
	CheatCommands = 3,
	/* Anything that changes the behavior of Client Pilots on the fly*/
	PilotCommands = 4,
	/* Start/Stop recording videos, stats, etc*/
	RecordingCommands = 5,
	/* Anything related to UI navigation */
	UICommands = 6,
	/* Default category*/
	Unknown = 7,
};

UCLASS()
class AFortAutomationRpcTrackedActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	AActor* TrackedActor;

	UPROPERTY(Replicated)
	FString ActorName;

};

UCLASS()
class FORTNITEGAME_API UFortAutomationRpcManager : public UObject
{
	GENERATED_BODY()

};


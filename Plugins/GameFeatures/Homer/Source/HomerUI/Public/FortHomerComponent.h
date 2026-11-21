// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortHomerComponent.generated.h"

class AFortPawn;
class AFortPlayerStateAthena;
class UFortItemDefinition;

UENUM()
enum class EHomerClipEventType : uint8
{
	Emote = 0,
	Elimination = 1,
	COUNT = 2 UMETA(Hidden),
};

UCLASS()
class UFortHomerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleLocalPlayerEliminatedPlayer(const AFortPlayerStateAthena* Player);

	UFUNCTION()
	void HandlePawnEmoteStopped(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

};


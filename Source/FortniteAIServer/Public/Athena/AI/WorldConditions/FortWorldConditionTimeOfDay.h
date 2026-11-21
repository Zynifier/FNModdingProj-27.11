// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortWorldConditionTimeOfDay.generated.h"

enum class EFortDayPhase : uint8;

USTRUCT(meta=(DisplayName="(Fortnite) Match Time Of Day (TOD)"))
struct FFortWorldConditionTimeOfDay : public FWorldConditionCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Default", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorContextRef;

	UPROPERTY(EditAnywhere, Category="Default", meta=(BitMask, BitmaskEnum="/Script/FortniteGame.EFortDayPhase"))
	int32 ValidTimesOfDay;

};

UCLASS()
class UFortWorldConditionTimeOfDayState : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleTimeOfDayPhaseChange(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

};


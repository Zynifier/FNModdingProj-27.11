// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DaySequenceSubsystem.generated.h"

class ADaySequenceActor;

UCLASS()
class DAYSEQUENCE_API UDaySequenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DaySequence")
	ADaySequenceActor* GetDaySequenceActor() const;

};


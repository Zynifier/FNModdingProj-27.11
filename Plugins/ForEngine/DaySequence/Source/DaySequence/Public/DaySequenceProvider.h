// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DaySequenceProvider.generated.h"

class UDaySequence;

UCLASS()
class ADaySequenceProvider : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sequence", meta=(AllowedClasses="/Script/DaySequence.DaySequence"))
	TArray<TObjectPtr<UDaySequence>> DaySequenceAssets;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneSequencePlayer.h"
#include "DaySequencePlayer.generated.h"

UCLASS(BlueprintType)
class DAYSEQUENCE_API UDaySequencePlayer : public UMovieSceneSequencePlayer
{
	GENERATED_BODY()

public:
	UDaySequencePlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tracks/MovieSceneSubTrack.h"
#include "DaySequenceTrack.generated.h"

UCLASS(MinimalAPI)
class UDaySequenceTrack : public UMovieSceneSubTrack
{
	GENERATED_BODY()

public:
	UDaySequenceTrack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};


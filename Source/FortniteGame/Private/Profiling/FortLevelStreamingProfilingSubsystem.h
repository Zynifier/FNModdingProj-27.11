// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProfilingDebugging/LevelStreamingProfilingSubsystem.h"
#include "FortLevelStreamingProfilingSubsystem.generated.h"

UCLASS(MinimalAPI)
class UFortLevelStreamingProfilingSubsystem : public ULevelStreamingProfilingSubsystem
{
	GENERATED_BODY()

public:
	UFortLevelStreamingProfilingSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};


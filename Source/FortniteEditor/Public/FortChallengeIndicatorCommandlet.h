// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "FortChallengeIndicatorCommandlet.generated.h"

UCLASS(Config=Editor, DefaultConfig)
class UFortChallengeIndicatorCommandlet : public UCommandlet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FString> AdditionalMapQualifiedPaths;

};


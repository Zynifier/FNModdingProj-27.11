// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReleaseVersion.h"
#include "FortSeasonPostCopyInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortSeasonPostCopyInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortSeasonPostCopyInterface
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION()
	virtual bool SeasonPostCopyFixup(const int32 SeasonNum, const FFortReleaseVersion& ReleaseVersion, const FString& NewSeasonPluginRoot);
#endif

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReleaseVersion.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEVERSION_API FFortReleaseVersion
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Version")
	FName VersionName;

};


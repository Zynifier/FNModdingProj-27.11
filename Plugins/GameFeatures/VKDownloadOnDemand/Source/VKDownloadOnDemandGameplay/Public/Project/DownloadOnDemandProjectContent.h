// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "DownloadOnDemandProjectContent.generated.h"

class UFortItemDefinition;

UCLASS()
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandProjectContent : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ContentItemDefinitions;

	UPROPERTY(Transient)
	TArray<FSoftObjectPath> ContentSoftObjectPaths;

	UPROPERTY(Transient)
	TArray<FSoftObjectPath> LoadFailedContentObjectPaths;

};


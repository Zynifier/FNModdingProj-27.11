// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DownloadOnDemandProject.generated.h"

class UDownloadOnDemandProjectContent;
class UDownloadOnDemandProjectDescriptor;

UCLASS()
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandProject : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProjectDescriptor> Descriptor;

	UPROPERTY(Transient)
	TMap<FString, TObjectPtr<UDownloadOnDemandProjectContent>> Contents;

};


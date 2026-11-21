// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DownloadOnDemandProjectDescriptor.generated.h"

class UDownloadOnDemandProjectImage;

UCLASS()
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandProjectDescriptor : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProjectImage> Image;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DownloadOnDemandProjectImage.generated.h"

class UTexture2DDynamic;

UCLASS()
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandProjectImage : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UTexture2DDynamic> PreviewTexture;

};


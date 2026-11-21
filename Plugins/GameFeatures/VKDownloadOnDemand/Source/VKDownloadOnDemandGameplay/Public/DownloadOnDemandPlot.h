// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DownloadOnDemandPlot.generated.h"

class UDownloadOnDemandProject;

UCLASS()
class VKDOWNLOADONDEMANDGAMEPLAY_API UDownloadOnDemandPlot : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UDownloadOnDemandProject>> ActiveProjects;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UDownloadOnDemandProject>> PendingProjects;

};


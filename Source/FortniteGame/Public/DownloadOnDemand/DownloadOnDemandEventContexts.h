// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DownloadOnDemandEventContexts.generated.h"

UENUM(BlueprintType)
enum class EVkEditStatus : uint8
{
	DEFAULT = 0 UMETA(Hidden),
	UpToDate = 1,
	RefreshRequested = 2,
	RefreshRequired = 3,
	Uploading = 4,
	Staging = 5,
	Preparing = 6,
	Downloading = 7,
	LoadingProject = 8,
	Error = 9,
	NumStatuses = 10 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FEditConnectionChangedContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EditConnectionChangedContext")
	int32 NumConnections;

};

USTRUCT(BlueprintType)
struct FVkEditStatusEventContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="VkEditStatusEventContext")
	EVkEditStatus Status;

};


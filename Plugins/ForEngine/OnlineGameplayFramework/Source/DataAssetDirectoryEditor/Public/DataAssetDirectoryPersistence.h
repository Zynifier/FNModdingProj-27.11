// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryPersistence.generated.h"

UENUM()
enum class EDataAssetDirectoryPersistenceJobError : uint8
{
	Success = 0,
	IncompatibleBuildCL = 1,
	FailedToGetAsset = 2,
	FailedDeserializeJson = 3,
	PrimaryAssetIdMissing = 4,
	AssetNotFound = 5,
	FailedToGetAssetObject = 6,
	FailedToPatchAsset = 7,
	SourceControlDisabled = 8,
	SourceControlUnavailable = 9,
	SourceControlCheckOutFailure = 10,
	SourceControlCheckInFailure = 11,
};

UENUM()
enum class EDataAssetDirectoryPersistenceResult : uint8
{
	Success = 0,
	UnknownError = 1,
	ServiceError = 2,
	PatchError = 3,
	PerforceError = 4,
};

UCLASS(Config=Editor)
class DATAASSETDIRECTORYEDITOR_API UDataAssetDirectoryPersistence : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString GameId;

	UPROPERTY(Config)
	FString BaseServiceUrl;

	UPROPERTY(Config)
	FString BaseAdminServiceUrl;

	UPROPERTY(Config)
	FString GetNextJobUrl;

	UPROPERTY(Config)
	FString GetAssetUrl;

	UPROPERTY(Config)
	FString CompleteJobUrl;

	UPROPERTY(Config)
	FString FailJobUrl;

	UPROPERTY(Config)
	float RequestTimeout;

};


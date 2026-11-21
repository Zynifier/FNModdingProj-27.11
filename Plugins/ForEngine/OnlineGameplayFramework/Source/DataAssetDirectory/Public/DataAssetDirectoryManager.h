// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryManager.generated.h"

class UObject;

UENUM()
enum class EDataAssetDirectoryUpdateStatus : uint8
{
	/** Failed to update assets */
	Failed = 0,
	/** Assets updated successfully  */
	Success = 1,
	/** Asset update check succeeded, but there were no changes applied */
	SuccessNoChange = 2,
};

UCLASS(Config=Engine)
class DATAASSETDIRECTORY_API UDataAssetDirectoryManager : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<UObject>> PatchedAssets;

	UPROPERTY()
	FDateTime LastUpdateCheck;

	UPROPERTY(Config)
	uint32 UpdateCheckLimitSeconds;

	UPROPERTY(Config)
	bool bEnabled;

	UPROPERTY(Config)
	bool bFailOnError;

	UPROPERTY(Config)
	bool bAnalyticsEnabled;

};


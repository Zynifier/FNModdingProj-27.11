// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryExporter.generated.h"

UCLASS(Config=Editor)
class DATAASSETDIRECTORYEDITOR_API UDataAssetDirectoryExporter : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString GameId;

	UPROPERTY(Config)
	FString JsonFileName;

	UPROPERTY(Config)
	FString BaseServiceUrl;

	UPROPERTY(Config)
	FString ExportContentUrl;

	UPROPERTY(Config)
	float RequestTimeout;

};


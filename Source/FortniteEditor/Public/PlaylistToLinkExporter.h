// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlaylistToLinkExporter.generated.h"

UCLASS(Config=Editor)
class UPlaylistToLinkExporter : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString BulkCreateLinksUrl;

	UPROPERTY(Config)
	FString LinksNamespace;

	UPROPERTY(Config)
	FString DummyUserId;

	UPROPERTY(Config)
	FString CreatorName;

	UPROPERTY(Config)
	FString LinkType;

	UPROPERTY(Config)
	float RequestTimeout;

	UPROPERTY(Config)
	int32 RequestBatchSize;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "FortActivityImageContext.generated.h"

class UFortGameActivity;

USTRUCT()
struct FFortActivityCompressedImageCache
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> CompressedImage;

};

USTRUCT()
struct FFortActivityImageCache
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortActivityImagePayload
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortActivityImageRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortGameActivity>> GameActivities;

};

UCLASS(MinimalAPI)
class UFortActivityImageContext : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FString, FFortActivityImageCache> SmallCachedImageMap;

	UPROPERTY()
	TMap<FString, FFortActivityImageCache> LargeCachedImageMap;

	UPROPERTY()
	TMap<FString, FFortActivityCompressedImageCache> CompressedImageMap;

	UPROPERTY()
	TMap<FString, FFortActivityImageRequest> PendingImageKeys;

	UPROPERTY()
	TMap<FString, FFortActivityImageRequest> PendingCompressedImageKeys;

};


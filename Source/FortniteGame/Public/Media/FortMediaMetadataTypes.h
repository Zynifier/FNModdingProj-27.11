// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicMediaMetadataTypes.h"
#include "FortMediaMetadataTypes.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaAudioOnlyPeriodDataExt : public FEpicMediaAudioOnlyPeriodDataExt
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaImageDataExt : public FEpicMediaImageDataExt
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaMetadataExt : public FEpicMediaMetadataExt
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaPlaylistExt : public FEpicMediaPlaylistExt
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaRegionLockExt : public FEpicMediaRegionLockExt
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortMediaVolumeChangeDataExt : public FEpicMediaVolumeChangeDataExt
{
	GENERATED_BODY()

};


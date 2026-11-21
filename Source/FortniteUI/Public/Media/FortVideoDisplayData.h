// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/PrimaryAssetId.h"
#include "FortVideoDisplayData.generated.h"

class UFortActivatableVideoPanel;
class UFortMediaSubtitlesPlayer;
class ULocalizedOverlays;
class UMediaPlayer;
class UMediaSource;
class UTexture2D;

USTRUCT()
struct FFortVideoInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortVideoInfo")
	FName ID;

	UPROPERTY(EditAnywhere, Category="FortVideoInfo")
	TObjectPtr<UTexture2D> PreviewImage;

	UPROPERTY(EditAnywhere, Category="FortVideoInfo")
	TObjectPtr<UMediaSource> VideoSource;

	UPROPERTY(EditAnywhere, Category="FortVideoInfo")
	TObjectPtr<ULocalizedOverlays> SubtitleOverlays;

	UPROPERTY(EditAnywhere, Category="UI")
	FName QuestObjectiveName;

	UPROPERTY(EditAnywhere, Category="UI", meta=(EditCondition="bIsQuestDrivenVideo"))
	FPrimaryAssetId RequiredActiveQuest;

};

UCLASS()
class UFortVideoDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UMediaPlayer> FortVideoPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UFortMediaSubtitlesPlayer> SubtitlePlayer;

	UPROPERTY(EditDefaultsOnly, Category="Player")
	TSubclassOf<UFortActivatableVideoPanel> VideoActivatablePanelClass;

	UPROPERTY(EditDefaultsOnly, Category="Player")
	TMap<FString, int32> LocaleAudioTrackIndexMap;

	UPROPERTY(EditDefaultsOnly, Category="Videos")
	TArray<FFortVideoInfo> Videos;

};


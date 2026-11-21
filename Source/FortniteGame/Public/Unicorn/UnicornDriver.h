// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "UnicornDriver.generated.h"

class UUnicornSocialComponent;
class UUnicornWebAPIComponent;
class UWorld;

UCLASS(Config=Game, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AUnicornDriver : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleDemoPlaybackFinish(UWorld* InWorld);

	UFUNCTION()
	void HandleDemoRecordingFinish(UWorld* InWorld);

	UFUNCTION(Exec)
	void UnicornClearDebugPlayer();

	UFUNCTION(Exec)
	void UnicornCreateAndPlayServerGameHighlights(int32 TargetSeconds, uint8 ReelId, uint8 MessageSetting, bool bExportSequenceFile);

	UFUNCTION(Exec)
	void UnicornDebugCurrentPlayerPlayerLog();

	UFUNCTION(Exec)
	void UnicornDebugCurrentPlayerSampler();

	UFUNCTION(Exec)
	void UnicornDebugCurrentReplayPlayer();

	UFUNCTION(Exec)
	void UnicornDebugHighlight(int32 HighlightId);

	UFUNCTION(Exec)
	void UnicornDebugHighlightTime(int32 HighlightId);

	UFUNCTION(Exec)
	void UnicornDebugPlayerWithIdString(const FString& PlayerIdString);

	UFUNCTION(Exec)
	void UnicornDebugUploadPayloadFile();

	UFUNCTION(Exec)
	void UnicornFakeAndUpload(int32 NumHighlights);

	UFUNCTION(Exec)
	void UnicornFakeAndUploadAndShutdown(int32 NumHighlights);

	UFUNCTION(Exec)
	void UnicornFollowPlayerWithHighlight(int32 HighlightId);

	UFUNCTION(Exec)
	void UnicornPlayHighlight(int32 HighlightId);

	UFUNCTION(Exec)
	void UnicornPlayLastEliminationHighlights(int32 NumHighlights, uint8 ReelId);

	UFUNCTION(Exec)
	void UnicornPlayOrderedHighlightsWithFeature(int32 FeatureAsInt, uint8 ReelId);

	UFUNCTION(Exec)
	void UnicornPlayOrderedHighlightsWithSocialFeature(int32 FeatureAsInt, uint8 ReelId);

	UFUNCTION(Exec)
	void UnicornPlayThroughPlayerHighlightReel(uint8 ReelId, uint8 MessageSettings, bool bExportSequenceFile);

	UFUNCTION(Exec)
	void UnicornPlayTopEliminationHighlights(int32 NumHighlights, uint8 ReelId);

	UFUNCTION(Exec)
	void UnicornPlayTopHighlights(int32 NumHighlights, uint8 ReelId, uint8 MessageSetting, bool bExportSequenceFile);

	UFUNCTION(Exec)
	void UnicornPlayUnionAllPlayersHighlights(uint8 ReelId, uint8 MessageSettings, bool bExportSequenceFile);

	UFUNCTION(Exec)
	void UnicornResetAll();

	UFUNCTION(Exec)
	void UnicornSetLoggingEnabled(bool bEnabled);

	UFUNCTION(Exec)
	void UnicornStartStreamPlayback();

	UFUNCTION(Exec)
	void UnicornStartStreamPlaybackToNow();

	UFUNCTION(Exec)
	void UnicornStartStreamRecording();

	UFUNCTION(Exec)
	void UnicornStopStreamRecording();

	UPROPERTY(Config)
	int32 MaxHighlightsToSave;

	UPROPERTY(Config)
	float MinHighlightScore;

	UPROPERTY(Config)
	float DefaultShotLeadTime;

	UPROPERTY(Config)
	float DefaultShotTailTime;

	UPROPERTY(Config)
	float HighlightAnnotationTime;

	UPROPERTY(Config)
	int32 MinimumPlacementForHighlight;

	UPROPERTY(Config)
	bool bEnsureChronologicalHighlights;

private:
	UFUNCTION(Exec)
	void RunHighlightExtractors();

	UPROPERTY(Config)
	bool bEnable_MainHighlightReel;

	UPROPERTY(Config)
	bool bEnable_ShorterExtendedHighlightReel;

	UPROPERTY(Config)
	bool bEnable_ShortHighlightReel;

	UPROPERTY(Config)
	bool bEnable_ShortExtendedHighlightReel;

	UPROPERTY(Config)
	bool bEnable_MediumHighlightReel;

	UPROPERTY(Config)
	bool bEnable_MediumExtendedighlightReel;

	UPROPERTY(Config)
	bool bEnable_PlayerSpotlightReel;

	UPROPERTY(Config)
	bool bEnable_PlayerSpotlightNoDeathsReel;

	UPROPERTY(Config)
	bool bEnable_VATReel;

	UPROPERTY(Config)
	float ShorterReelMaxClipDuration;

	UPROPERTY(Config)
	float ShorterReelMaxLookback;

	UPROPERTY(Config)
	float ShorterReelMaxTailTime;

	UPROPERTY(Config)
	float ShorterReelEliminationLookbackTime;

	UPROPERTY(Config)
	float ShortReelMaxClipDuration;

	UPROPERTY(Config)
	float ShortReelMaxLookback;

	UPROPERTY(Config)
	float ShortReelMaxTailTime;

	UPROPERTY(Config)
	float ShortReelEliminationLookbackTime;

	UPROPERTY(Config)
	float ShortExtendedReelMaxClipDuration;

	UPROPERTY(Config)
	float ShortExtendedReelMaxLookback;

	UPROPERTY(Config)
	float ShortExtendedReelMaxTailTime;

	UPROPERTY(Config)
	float ShortExtendedReelEliminationLookbackTime;

	UPROPERTY(Config)
	float MediumReelMaxClipDuration;

	UPROPERTY(Config)
	float MediumReelMaxLookback;

	UPROPERTY(Config)
	float MediumReelMaxTailTime;

	UPROPERTY(Config)
	float MediumExtendedReelMaxClipDuration;

	UPROPERTY(Config)
	float MediumExtendedReelMaxLookback;

	UPROPERTY(Config)
	float MediumExtendedReelMaxTailTime;

	UPROPERTY(Config)
	float VATReelEliminationLookbackTime;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUnicornSocialComponent> SocialComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUnicornWebAPIComponent> WebAPIComponent;

	UPROPERTY(Config)
	bool bShouldUploadHighlightsPayload;

};


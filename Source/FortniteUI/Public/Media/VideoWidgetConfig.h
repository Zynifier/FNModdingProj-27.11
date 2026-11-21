// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "VideoWidgetConfig.generated.h"

class UFortStreamMediaSource;
class USoundClass;
class USoundMix;

USTRUCT(BlueprintType)
struct FVideoWidgetConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	TObjectPtr<UFortStreamMediaSource> StreamingMediaSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FName VideoString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FName VideoDisplayDataID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FName FallbackVideoID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bCheckAutoPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bForceAutoPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bStreamingEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FString VideoUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bShouldBeModal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bUseSkipBoundaries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bHoldToSkip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bFadeFromColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bEndFadeFromColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bFadeUpToColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bAllowSkipping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FString MimeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FString VideoURL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bEnableLooping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bAutoClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bHideControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bHideBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bHideBackgroundUntilVideoDetected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bStartMTTransparent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	TObjectPtr<USoundMix> SoundMixOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bOverrideSoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	TObjectPtr<USoundClass> SoundClassOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bControlWorldRendering;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bControlShaderPipelineCacheBatching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bDisablePiP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	float PartySyncStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bDisableCursor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bDisableStreamLimitsFromWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bStartHidden;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bAudioOnlyHandlingFromMetadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bTreatAudioOnlyAsColorFades;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bEnableDebugCommands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	FLinearColor FadeColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bPrePostRollNoAudioMix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bAllowGlobalForceGC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoWidgetConfig")
	bool bInstanceForceGC;

};


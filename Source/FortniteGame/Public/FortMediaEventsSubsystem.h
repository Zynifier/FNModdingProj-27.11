// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "FortMediaEventsSubsystem.generated.h"

class UFortStreamMediaSource;
class UMaterialInterface;
class UMediaPlayer;
class UMediaTexture;
class USoundClass;
class USoundMix;
class USoundSourceBus;
class USoundSubmixBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsClearStreams, FString, StreamAssetName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsSubsystemEnableFullScreenPiPOption, bool, bEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsSubsystemEnable, bool, InEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsSubsystemMediaSourceReturn, UFortStreamMediaSource*, ReturnSource);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsSubsystemOnSourceSelected, const UFortStreamMediaSource*, SelectedSource);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortMediaEventsSubsystemRequestMediaSource);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortMediaEventsSubsystemResume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortMediaEventsSubsystemSuspend);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortMediaEventsSubsystemToggleFullScreenPiP);

USTRUCT(BlueprintType)
struct FFortMediaEventsStreamAssets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	bool bAutoActivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<UMediaTexture> VideoTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<UMaterialInterface> VideoMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<USoundSourceBus> SoundSourceBus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<USoundMix> ActiveSoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<USoundSubmixBase> DefaultSubmix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaEventsStreamAssets")
	TObjectPtr<UMediaPlayer> ExternalVideoPlayer;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaEventsVideoStreams, const FFortMediaEventsStreamAssets&, VideoStreamAssets);

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortMediaEventsSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastStreamAssets(const FFortMediaEventsStreamAssets& InAssets);

	UFUNCTION(BlueprintCallable)
	bool CanEnablePartnerPIP();

	UFUNCTION(BlueprintCallable)
	void ClearStreamAssets(const FString& StreamAssetName);

	UFUNCTION(BlueprintCallable)
	void EnableFullScreenPiPOption(const bool bEnable);

	UFUNCTION(BlueprintPure)
	bool IsHudAdEnabled() const;

	UFUNCTION(BlueprintCallable)
	void RequestExternalMediaControllerMediaSource();

	UFUNCTION(BlueprintCallable)
	void ResumeExternalMediaControllers();

	UFUNCTION(BlueprintCallable)
	void SetExternalMediaControllerEnabled(bool InEnabled);

	UFUNCTION(BlueprintCallable)
	void SetHudAdEnabled(const bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SuspendExternalMediaControllers();

	UFUNCTION(BlueprintCallable)
	void ToggleFullScreenPiP();

	UPROPERTY(BlueprintAssignable)
	FFortMediaEventsSubsystemOnSourceSelected OnMediaSourceSelected;

	UPROPERTY(BlueprintAssignable)
	FFortMediaEventsSubsystemMediaSourceReturn MediaSourceReturn;

};


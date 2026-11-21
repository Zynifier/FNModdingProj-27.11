// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "LiveStreamHUDElement.generated.h"

class USoundSourceBus;
class USoundSubmixBase;

UCLASS(Abstract)
class ULiveStreamHUDElement : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CreateVideoPlayer();

	UFUNCTION(BlueprintImplementableEvent)
	void DestroyVideoPlayer();

	UFUNCTION()
	void FireMirroredPIPAnalytics(bool bInStarted);

	UFUNCTION(BlueprintCallable)
	static int32 GetMirrorScreen();

	UFUNCTION(BlueprintCallable)
	static bool GetPIPAutoClose();

	UFUNCTION(BlueprintCallable)
	static TArray<float> GetPIPCDNWeights();

	UFUNCTION(BlueprintCallable)
	static bool GetPIPDisableInstructions();

	UFUNCTION(BlueprintCallable)
	static bool GetPIPForceEnabled();

	UFUNCTION(BlueprintCallable)
	static bool GetPIPLive();

	UFUNCTION(BlueprintCallable)
	static float GetPIPStartTIme();

	UFUNCTION(BlueprintCallable)
	static FString GetPIPVideoUID();

	UFUNCTION(BlueprintCallable)
	static float GetPIPVolumeMultiplier();

	UFUNCTION(BlueprintCallable)
	static bool IsUsingMirrorScreen();

	UFUNCTION(BlueprintCallable)
	static void SetMirroredPIPAnalyicsMetadata(const FName& MediaName, const int64 CurrentProgressTimecode, const FName& MediaPlayerName);

	UFUNCTION(BlueprintCallable)
	static void SetMirrorPIPAudioDisable(bool bInDisable);

	UFUNCTION(BlueprintCallable)
	static void SetMirrorPIPAudioSubmix(bool bInDefault, bool bForce = false);

	UFUNCTION(BlueprintCallable)
	static void SetMirrorScreen(int32 ScreenIndex);

	UFUNCTION(BlueprintCallable)
	static void SetPIPAutoClose(bool bAutoClose);

	UFUNCTION(BlueprintCallable)
	static void SetPIPCDNWeights(const TArray<float> InWeights);

	UFUNCTION(BlueprintCallable)
	static void SetPIPDisableInstructions(bool bDisable);

	UFUNCTION(BlueprintCallable)
	static void SetPIPEOSGSBlackout(bool bInEnable);

	UFUNCTION(BlueprintCallable)
	static void SetPIPForceEnabled(bool bForced);

	UFUNCTION(BlueprintCallable)
	static void SetPIPLive(bool bInLive);

	UFUNCTION(BlueprintCallable)
	static void SetPIPStartTime(float InStartTime);

	UFUNCTION(BlueprintCallable)
	static void SetPIPVideoUID(const FString& InVideoUID);

	UFUNCTION(BlueprintCallable)
	static void SetPIPVolumeMultiplier(float InMultiplayer);

private:
	UPROPERTY(EditAnywhere, Category="LiveStreamHUDElement")
	TObjectPtr<USoundSourceBus> SourceBus;

	UPROPERTY(EditAnywhere, Category="LiveStreamHUDElement")
	TObjectPtr<USoundSubmixBase> DefaultAudioSubmix;

	UPROPERTY(EditAnywhere, Category="LiveStreamHUDElement")
	TObjectPtr<USoundSubmixBase> LicensedAudioSubmix;

};


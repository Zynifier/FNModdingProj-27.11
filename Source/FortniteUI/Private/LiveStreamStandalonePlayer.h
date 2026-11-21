// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LiveStreamStandalonePlayer.generated.h"

class UFortStreamMediaSource;
class UFortVideoPlayerWidget;
enum class ELiveStreamStandaloneBlocked : uint8;

UENUM(BlueprintType)
enum class ELiveStreamStandaloneBlocked : uint8
{
	StreamInWorldActive = 0,
};

UCLASS(Abstract)
class ULiveStreamStandalonePlayer : public UUserWidget
{
	GENERATED_BODY()

public:
	ULiveStreamStandalonePlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	static void BlockPlayer(ELiveStreamStandaloneBlocked BlockedReason);

	UFUNCTION()
	void FireStandalonePIPAnalytics(bool bInStarted);

	UFUNCTION(BlueprintCallable)
	static bool GetPIPIgnorePartySync();

	UFUNCTION(BlueprintCallable)
	static bool GetPIPStandaloneError();

	UFUNCTION(BlueprintCallable)
	static bool GetPlayerIsBlocked();

	UFUNCTION(BlueprintImplementableEvent)
	void PIPReadyToRender();

	UFUNCTION(BlueprintCallable)
	void Play();

	UFUNCTION(BlueprintCallable)
	static void ResetPIPState();

	UFUNCTION(BlueprintCallable)
	static void SetPIPCDNDistribution(const TArray<float>& Weights);

	UFUNCTION(BlueprintCallable)
	static void SetPIPIgnorePartySync(bool bIgnore);

	UFUNCTION(BlueprintCallable)
	static void SetPIPLive(bool bInLive);

	UFUNCTION(BlueprintCallable)
	static void SetPIPMediaID(const FString& InVideoUID);

	UFUNCTION(BlueprintCallable)
	static void SetPIPStartTime(float InStartTime);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintCallable)
	static void UnblockPlayer(ELiveStreamStandaloneBlocked BlockedReason);

protected:
	UPROPERTY(EditDefaultsOnly, Category="LiveStreamStandalonePlayer")
	TObjectPtr<UFortStreamMediaSource> StreamMediaSource;

	UPROPERTY(BlueprintReadOnly, Export, Category="LiveStreamStandalonePlayer", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVideoPlayerWidget> VideoPlayerWidget;

private:
	UFUNCTION()
	void CheckMediaStarted();

	UFUNCTION()
	void DisableSharing(bool bInDisable);

	UFUNCTION()
	void OnRetrieveVideoUrlFailure(const FString& Url);

	UFUNCTION()
	void OnRetrieveVideoUrlSuccess(const FString& Url);

};


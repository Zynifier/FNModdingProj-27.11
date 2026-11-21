// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMediaEventsSubsystem.h"
#include "PictureInPictureMediaController.h"
#include "PictureInPicturePartnerSource.h"
#include "PictureInPictureFNEventsController.generated.h"

class ULiveEventHUDAd;
class UPictureInPictureFNEventsClient;
enum class PictureInPictureAction : uint8;

UCLASS(BlueprintType, Blueprintable)
class PICTUREINPICTUREFNEVENTS_API UPictureInPictureFNEventsController : public UPictureInPictureMediaController
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UPictureInPictureFNEventsClient> FNEventsClient;

protected:
	UFUNCTION()
	void HandleFNMediaEventsStreams(const FFortMediaEventsStreamAssets& VideoStreamAssets);

	UFUNCTION()
	void HandleFNMediaRemoveEventsStream(const FString& InEventName);

private:
	UFUNCTION()
	void AddPartnerActionAnalytics(const FString& InPartnerName, PictureInPictureAction InActionType);

	UFUNCTION()
	void ExitEvent();

	UFUNCTION()
	void OnClientLoginSuccess();

	UFUNCTION()
	void OnClientLogoutSuccess();

	UFUNCTION()
	void UpdateClientLoginState(const TArray<FPiPPartnerSource>& UpdatedSources);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<ULiveEventHUDAd> HUDAdvertWidget;

};


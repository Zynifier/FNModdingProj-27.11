// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Media/FortActivatableVideoPanel.h"
#include "FortActivatableMovieWidget_Monolithic.generated.h"

class UFortStreamMediaSource;
class UImage;
class UMediaPlayer;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMediaOpenedMono, FString, OpenedURL);

USTRUCT(BlueprintType)
struct FVideoConfig_Mono
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	TObjectPtr<UFortStreamMediaSource> StreamingMediaSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FName VideoString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FName StreamingVideoID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FName FallbackVideoID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FString ProdLinkID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FString GamedevLinkID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bIsAutoPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bForceAutoPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bStreamingEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	FString VideoUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bShouldBeModal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bUseSkipBoundaries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bKairosPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VideoConfig_Mono")
	bool bHoldToSkip;

};

UCLASS(Abstract)
class UFortActivatableMovieWidget_Monolithic : public UFortActivatableVideoPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EnableFadeInFromWhite(bool bInEnable);

	UFUNCTION(BlueprintCallable)
	void LoadStreamingVideo(FVideoConfig_Mono config, UFortStreamMediaSource* StreamMediaSource, bool& bNoAutoPlay, bool bStartWithWhite = false);

	UFUNCTION(BlueprintCallable)
	void Play();

	UFUNCTION(BlueprintImplementableEvent)
	void StartFadeFromWhite();

	UPROPERTY(BlueprintAssignable)
	FOnMediaOpenedMono MediaOpenedMono;

private:
	UFUNCTION()
	void StreamedVideoOnUrlFailure(const FString& URL);

	UFUNCTION()
	void StreamedVideoOnUrlSuccess(const FString& URL);

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget_Monolithic")
	TObjectPtr<UFortStreamMediaSource> MediaSourceMono;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget_Monolithic")
	TObjectPtr<UMediaPlayer> StreamedMediaPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FortActivatableMovieWidget_Monolithic", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PressToSkipAction;

	UPROPERTY(EditDefaultsOnly, Category="FortActivatableMovieWidget_Monolithic", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HoldToSkipAction;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortActivatableMovieWidget_Monolithic", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_White;

};


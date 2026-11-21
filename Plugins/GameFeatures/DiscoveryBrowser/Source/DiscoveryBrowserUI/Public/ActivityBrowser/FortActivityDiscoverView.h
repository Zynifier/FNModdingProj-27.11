// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserRowView.h"
#include "FortActivityDiscoverView.generated.h"

class UFortActivatableMovieWidget;
class UFortActivityDetailsDisplay;
class UPanelWidget;
class UTexture;
class UWidgetAnimation;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityDiscoverView : public UFortActivityBrowserRowView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	const UTexture* GetCurrentTexture() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	UWidgetAnimation* GetKeyArtOutroAnimation() const;

	UFUNCTION(BlueprintPure)
	UFortActivatableMovieWidget* GetMovieWidget() const;

	UFUNCTION(BlueprintPure)
	UFortActivatableMovieWidget* GetPromotedMovieWidget() const;

	UFUNCTION(BlueprintPure)
	bool IsImageLoading() const;

	UFUNCTION(BlueprintPure)
	bool IsInOutroState() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingPromotedContent() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingSeasonalContent() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoviePlayingChanged(const bool bIsPlaying);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoviePreEndEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayKeyArtIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayKeyArtOutro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateDetailsDisplay();

private:
	UFUNCTION()
	void CheckUpdateDetailsDelay();

	UFUNCTION()
	void HandleMovieWidgetMediaPreEndEvent();

	UFUNCTION()
	void HandleMovieWidgetMediaStarted();

	UPROPERTY(EditDefaultsOnly, Category="FortActivityDiscoverView")
	bool bPlayDetailsAnimationOnScreenOpen;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityDiscoverView")
	float DetailsDisplayUpdateDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityDiscoverView")
	TSubclassOf<UFortActivatableMovieWidget> MovieWidgetClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityDetailsDisplay> DetailsDisplay_SelectedActivity;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDiscoverView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityDetailsDisplay> DetailsDisplay_PromotedActivity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_VideoSlot;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_PromotedVideoSlot;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivatableMovieWidget> ActivityMovieWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivatableMovieWidget> PromotedActivityMovieWidget;

	UPROPERTY(Transient)
	TObjectPtr<UWidgetAnimation> BoundKeyArtOutroAnimation;

};


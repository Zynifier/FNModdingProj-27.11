// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserRow.h"
#include "FortActivityBrowserRowHero.generated.h"

class UFortActivityDetailsDisplay;
class UFortActivityListView;
class UFortActivityVideoCycle;
class UFortSwipePanel;
class UTexture;
class UWidgetAnimation;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivityBrowserRowHero : public UFortActivityBrowserRow
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CycleNextActivity();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	const UTexture* GetCurrentTexture() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	UWidgetAnimation* GetKeyArtOutroAnimation() const;

	UFUNCTION(BlueprintPure)
	bool IsImageLoading() const;

	UFUNCTION(BlueprintPure)
	bool IsInOutroState() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingSeasonalContent() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnListViewFinishedAddingEntries(int32 ActivityCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayKeyArtIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayKeyArtOutro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryActivitiesFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryStatusChanged(bool bIsActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRowHeroFocusChanged(bool bHasFocus);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateDetailsDisplay();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVideoEndReached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVideoStarted();

protected:
	UFUNCTION(BlueprintPure)
	float GetCyclingDelay() const;

	UFUNCTION(BlueprintPure)
	float GetCyclingPauseDelay() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnTileClicked();

private:
	UFUNCTION()
	void CheckUpdateDetailsDelay();

	UFUNCTION()
	void HandleActivityVideoCycleEndReached();

	UFUNCTION()
	void HandleActivityVideoCycleStarted();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowHero", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UFortActivityListView* ListView_Activities;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_Navigation;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowserRowHero")
	bool bPlayDetailsAnimationOnScreenOpen;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowserRowHero")
	float DetailsDisplayUpdateDelay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowHero", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UFortActivityDetailsDisplay* DetailsDisplay_SelectedActivity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityVideoCycle> ActivityVideoCycleWidget;

	UPROPERTY(Transient)
	TObjectPtr<UWidgetAnimation> BoundKeyArtOutroAnimation;

	UPROPERTY(BlueprintReadOnly, Category="FortActivityBrowserRowHero", meta=(AllowPrivateAccess))
	bool bShouldAutoCycle;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sound/SlateSound.h"
#include "EpicCMSTileCarousel.generated.h"

class UCommonWidgetCarousel;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class EPICCMSUIFRAMEWORK_API UEpicCMSTileCarousel : public UUserWidget
{
	GENERATED_BODY()

public:
	UEpicCMSTileCarousel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Carousel")
	void AddTilePage(UWidget* TilePageWidget);

	UFUNCTION(BlueprintCallable, Category="Carousel")
	void BeginAutoScrolling();

protected:
	UFUNCTION(BlueprintPure, Category="Carousel")
	int32 GetCurrentPageIndex() const;

	UFUNCTION(BlueprintNativeEvent, Category="Carousel")
	void HandleTilePageAdded(UWidget* TileWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="Navigation")
	void NavigationVisibilityChanged(bool bShowNavigation);

	UFUNCTION(BlueprintCallable, Category="Carousel")
	void NextPage();

	UFUNCTION(BlueprintCallable, Category="Carousel")
	void PreviousPage();

	UFUNCTION(BlueprintCallable, Category="Carousel")
	void SetCurrentPageByIndex(const int32 PageIndex);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	FSlateSound PreviousButtonSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	FSlateSound NextButtonSound;

	UPROPERTY(BlueprintReadOnly, Export, Category="Carousel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetCarousel> Carousel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Navigation", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> NextPageButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="Navigation", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> PreviousPageButton;

	UPROPERTY(EditAnywhere, Category="Navigation")
	bool bShouldShowNavigationOnlyOnHover;

	UPROPERTY(EditAnywhere, Category="Navigation")
	bool bInputActionsForPaging;

	UPROPERTY()
	bool bIsShowingNavigation;

};


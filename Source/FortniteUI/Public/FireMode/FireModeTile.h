// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "UI/HUDLayoutTool/HUDLayoutToolTypes.h"
#include "FireModeTile.generated.h"

class UButton;
class UCommonTextBlock;
class UFireModeCustomOptionButton;
class UFortFireModeStreamingVideo;
class UMediaTexture;

UCLASS(meta=(DisableNativeTick))
class UFireModeTile : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetIsCustomOptionsPanelOpen(bool bIsOpen);

	UFUNCTION(BlueprintCallable)
	void UpdateDisplayedText();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCustomOptionsPanelToggled(const bool bIsOpen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoviePlaybackChanged(const bool bIsPlaying);

	UPROPERTY(EditDefaultsOnly, Category="Fire mode info")
	TMap<EFireModeType, FText> FireModeNames;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	FText FireModeDescription;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	FText RecommendedTag;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	FText CustomOptionsTabName;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	EFireModeType PresetFireModeType;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	EFireModeType CustomOption1;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	EFireModeType CustomOption2;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	FString VideoUID;

	UPROPERTY(EditAnywhere, Category="Fire mode info")
	TObjectPtr<UMediaTexture> VideoTexture;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RecommendedTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CustomOptionsTabName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_ToggleCustomOptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFireModeCustomOptionButton> Button_CustomOption1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFireModeCustomOptionButton> Button_CustomOption2;

	UPROPERTY()
	TObjectPtr<UFortFireModeStreamingVideo> VideoPlayer;

private:
	UFUNCTION()
	void HandleToggleCustomOptionsClicked();

	UFUNCTION()
	void HandleVideoPlayerPlaybackResumed();

};


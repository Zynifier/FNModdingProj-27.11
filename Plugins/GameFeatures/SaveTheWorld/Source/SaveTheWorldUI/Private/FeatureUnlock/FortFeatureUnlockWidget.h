// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortFeatureUnlockWidget.generated.h"

class UCommonLazyImage;
class UCommonWidgetSwitcherLegacy;
class UFortVideoPlayerWidget;
class UMediaSource;
class UTexture2D;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortFeatureUnlockWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortFeatureUnlock")
	void SetData(const FString& ItemTemplateId);

protected:
	UFUNCTION(BlueprintPure, Category="FortFeatureUnlock")
	FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="FortFeatureUnlock")
	TSoftObjectPtr<UTexture2D> GetLargeIcon() const;

	UFUNCTION(BlueprintPure, Category="FortFeatureUnlock")
	TSoftObjectPtr<UTexture2D> GetSmallIcon() const;

	UFUNCTION(BlueprintPure, Category="FortFeatureUnlock")
	FText GetTitle() const;

	UFUNCTION(BlueprintPure, Category="FortFeatureUnlock")
	UMediaSource* GetVideo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortFeatureUnlock", meta=(DisplayName="Refresh Data"))
	void RefreshDataBP();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFeatureUnlock", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> MediaSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFeatureUnlock", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VideoContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFeatureUnlock", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ImageContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFeatureUnlock", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVideoPlayerWidget> VideoWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFeatureUnlock", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> ImageWidget;

};


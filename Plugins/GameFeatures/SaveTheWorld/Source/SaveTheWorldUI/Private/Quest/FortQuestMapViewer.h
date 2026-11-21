// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Styling/SlateColor.h"
#include "FortQuestMapViewer.generated.h"

class UCanvasPanel;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortQuestMapNodeLayout;
class UFortQuestMapScreen;
class USizeBox;
class UUserWidget;
enum class EViewerNavigationDirection : uint8;

UENUM(BlueprintType)
enum class EViewerNavigationDirection : uint8
{
	Previous = 0,
	Next = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapViewerRequestNavigation, EViewerNavigationDirection, NavigationDirection);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapViewer : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quest Map Viewer")
	void HandleLayoutOutroAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Viewer")
	void OnPlayLayoutFadeInAnimation();

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Viewer")
	void OnPlayLayoutOutroAnimation(EViewerNavigationDirection TravelDirection);

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Viewer")
	void OnTryUpdateUserWidgetColor(UUserWidget* Widget, FSlateColor OverrideColor);

	UFUNCTION(BlueprintCallable, Category="Quest Map Viewer")
	void UpdateViewerData();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageRight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Page;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Viewer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_Cosmetic;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapScreen> ParentScreen;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapNodeLayout> NodeLayout;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Types/SlateEnums.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "BacchusButton.generated.h"

class UButton;
class UImage;
class UPaperSprite;
class URadialBacchusButtonBase;
class USizeBox;
class UUserWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBacchusButton : public UBacchusHUDElement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FORTNITEUI_API void SetButtonDisplayScale(float NewDisplayScale);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FORTNITEUI_API void SetButtonSize(float NewButtonSize);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Events")
	FORTNITEUI_API void OnClicked();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Events")
	FORTNITEUI_API void SetButtonSprite(UPaperSprite* NewSprite);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void SetDefaultIcon(UPaperSprite* Icon);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void SetIconPressed(bool bIsPressed);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	TObjectPtr<UPaperSprite> DefaultIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Display", meta=(sRGB="true"))
	FLinearColor PressedColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Display", meta=(sRGB="true"))
	FLinearColor UnpressedColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Interaction")
	TEnumAsByte<EButtonClickMethod::Type> ClickMethod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Interaction")
	TEnumAsByte<EButtonTouchMethod::Type> TouchMethod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float ButtonSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float ButtonDisplayScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radial Progress")
	bool ShowRadialProgress;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Radial Progress")
	FGameplayTag ListenedGamePlayTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

private:
	UFUNCTION()
	FORTNITEUI_API void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_ButtonSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<URadialBacchusButtonBase> RadialButton_ButtonCooldown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UButton> Button_InternalButton;

};


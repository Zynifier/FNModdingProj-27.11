// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "MobileHUDVisual.generated.h"

class UImage;
class UPaperSprite;
class USizeBox;

UCLASS(meta=(DisableNativeTick))
class UMobileHUDVisual : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTag GetVisualType() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Type")
	FGameplayTag VisualType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float Opacity;

};

UCLASS()
class UMobileHUDButtonVisual : public UMobileHUDVisual
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetButtonSprite(UPaperSprite* NewSprite);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float ButtonSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float ButtonDisplayScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	TObjectPtr<UPaperSprite> DefaultIcon;

	UPROPERTY(BlueprintReadWrite, Export, Category="MobileHUDButtonVisual", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<USizeBox> OuterSizeBox;

	UPROPERTY(BlueprintReadWrite, Export, Category="MobileHUDButtonVisual", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<USizeBox> InnerSizeBox;

	UPROPERTY(BlueprintReadWrite, Export, Category="MobileHUDButtonVisual", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UImage> Image_Icon;

};


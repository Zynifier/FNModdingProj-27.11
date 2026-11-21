// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "LetoHudOverlay.generated.h"

class UHorizontalBox;
class ULetoPlayerAvatar;
class USpacer;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULetoHudOverlay : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Container;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_PlayerOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_PlayerTwo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_PlayerOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_PlayerTwo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<ULetoPlayerAvatar> LetoAvatar_PlayerOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<ULetoPlayerAvatar> LetoAvatar_PlayerTwo;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Viewport Width"))
	float DesignTime_ViewportWidth;
#endif

};


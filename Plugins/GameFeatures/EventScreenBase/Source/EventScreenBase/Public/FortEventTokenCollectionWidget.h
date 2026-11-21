// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEventTokenCollectionWidget.generated.h"

class UCommonLazyImage;
class UFortTokenType;
class UImage;
class UTexture2D;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventTokenCollectionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEventTokenCollectionWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshIcon(const bool IsCollected, const bool bIsFirstViewAfterCollection);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTokenCollectionWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_GhostIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTokenCollectionWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_CompletedIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTokenCollectionWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Glow;

	UPROPERTY(EditDefaultsOnly, Category="FortEventTokenCollectionWidget")
	TSoftObjectPtr<UTexture2D> FallbackBrush;

	UPROPERTY(EditAnywhere, Category="FortEventTokenCollectionWidget")
	TSoftObjectPtr<UFortTokenType> TokenDefinition;

};


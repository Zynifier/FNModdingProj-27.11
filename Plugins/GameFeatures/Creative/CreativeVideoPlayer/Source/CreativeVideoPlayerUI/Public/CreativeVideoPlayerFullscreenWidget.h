// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "CheckDismissableActivatableWidget.h"
#include "CreativeVideoPlayerFullscreenWidget.generated.h"

class UAudioComponent;
class UCommonButtonLegacy;
class UImage;
class UMediaTexture;
class USoundClass;
class USoundSourceBus;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCreativeFullScreenPlayerAction);

UCLASS(BlueprintType, Blueprintable)
class CREATIVEVIDEOPLAYERUI_API UCreativeVideoPlayerFullScreenWidget : public UCommonActivatableWidget, public ICheckDismissableActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetExternalComponents(UMediaTexture* VideoTextureExt, USoundSourceBus* ExtSourceBus);

private:
	UFUNCTION()
	void OnSkipButtonActionComplete();

	UFUNCTION()
	void OnSkipButtonActionProgress(float HeldPercent);

	UPROPERTY(EditAnywhere, Category="Video Player Widget")
	TObjectPtr<USoundSourceBus> SourceBus;

	UPROPERTY(EditAnywhere, Category="Video Player Widget")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(EditDefaultsOnly, Category="Video Player Widget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HoldToSkipAction;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Skip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_VideoTexture;

	UPROPERTY(EditDefaultsOnly, Category="Video Player Widget")
	float SkipButtonTimeout;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SoundComponent;

};


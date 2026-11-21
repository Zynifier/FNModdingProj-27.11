// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaMapGameInfo.generated.h"

class AFortVolume;
class APlayerState;
class UCommonTextBlock;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapGameInfo : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleClientEnterVolume(APlayerState* PlayerState, AFortVolume* Volume);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlaylistName;

};


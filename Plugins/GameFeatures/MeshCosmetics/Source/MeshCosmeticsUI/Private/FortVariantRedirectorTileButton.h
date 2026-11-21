// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortVariantRedirectorTileButton.generated.h"

class UFortLazyImage;
class UOverlay;

UENUM(BlueprintType)
enum class ERedirectorTileDisplayMode : uint8
{
	DisplaySprayTexture = 0,
	ChangeOpacity = 1,
	SwitchTextures = 2,
};

UCLASS(Abstract, meta=(Category="MeshCosmetics UI", DisableNativeTick))
class UFortVariantRedirectorTileButton : public UCommonButtonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantRedirectorTileButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> ImageOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantRedirectorTileButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_TileIcon;

	UPROPERTY(EditAnywhere, Category="Display Mode")
	ERedirectorTileDisplayMode DisplayMode;

	UPROPERTY(EditAnywhere, Category="Change Opacity Display Mode")
	float SlotOpacitySprayAssigned;

	UPROPERTY(EditAnywhere, Category="Change Opacity Display Mode")
	float SlotOpacitySprayNotAssigned;

};

